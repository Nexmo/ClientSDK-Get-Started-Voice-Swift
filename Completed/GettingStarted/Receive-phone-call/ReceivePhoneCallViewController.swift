//
//  ReceivePhoneCallViewController.swift
//  GettingStarted
//
//  Created by Paul Ardeleanu on 11/09/2019.
//  Copyright © 2019 Nexmo. All rights reserved.
//

import UIKit
import NexmoClient

class ReceivePhoneCallViewController: UIViewController {
    let user = User.jane
    let client = NXMClient.shared
    var call: NXMCall?
    var callStatus: CallStatus = .unknown
    
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    @IBOutlet weak var statusLabel: UILabel!
    @IBOutlet weak var callButton: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.setHidesBackButton(true, animated: false)
        navigationItem.leftBarButtonItem = UIBarButtonItem(title: "Logout", style: .done, target: self, action: #selector(self.logout))
        title = "Receive a phone call"
        updateInterface()
        setupNexmoClient()
    }
    
    
    //MARK: Setup Nexmo Client
    
    func setupNexmoClient() {
        client.setDelegate(self)
        client.login(withAuthToken: user.jwt)
    }
    
    
    @objc func logout() {
        call?.hangup()
        client.logout()
        navigationController?.popViewController(animated: true)
    }


    @IBAction func endCall(_ sender: Any) {
        guard let call = call else {
            updateInterface()
            return
        }
        call.hangup()
    }
    
}



//MARK:- NXMClientDelegate

extension ReceivePhoneCallViewController: NXMClientDelegate {
    
    func client(_ client: NXMClient, didChange status: NXMConnectionStatus, reason: NXMConnectionStatusReason) {
        print("✆  connectionStatusChanged - status: \(status.description()) - reason: \(reason.description())")
        updateInterface()
    }
    
    func client(_ client: NXMClient, didReceiveError error: Error) {
        print("✆  ‼️ connection error: \(error.localizedDescription)")
        updateInterface()
    }
    
    func client(_ client: NXMClient, didReceive call: NXMCall) {
        print("✆  Incoming Call: \(call)")
        DispatchQueue.main.async { [weak self] in
            self?.displayIncomingCallAlert(call: call)
        }
    }
    
    func displayIncomingCallAlert(call: NXMCall) {
        var from = "Unknown"
        if let otherParty = call.otherCallMembers.firstObject as? NXMCallMember {
            print("Type: \(String(describing: otherParty.channel?.from.type))")
            print("Number: \(String(describing: otherParty.channel?.from.data))")
            from = otherParty.channel?.from.data ?? "Unknown"
        }
        let alert = UIAlertController(title: "Incoming call from", message: from, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Answer", style: .default, handler: { _ in
            self.answer(call: call)
        }))
        alert.addAction(UIAlertAction(title: "Reject", style: .default, handler: { _ in
            self.reject(call: call)
        }))
        self.present(alert, animated: true, completion: nil)
    }
    
    //MARK: Incoming call - Accept
    
    private func answer(call: NXMCall) {
        self.call = call
        self.call?.setDelegate(self)
        call.answer { [weak self] error in
            if let error = error {
                print("error answering call: \(error.localizedDescription)")
            }
            self?.updateInterface()
        }
    }
    
    //MARK: Incoming call - Reject
    
    private func reject(call: NXMCall) {
        call.reject { [weak self] error in
            if let error = error {
                print("error declining call: \(error.localizedDescription)")
            }
            self?.updateInterface()
        }
    }
    
}



//MARK:- NXMCallDelegate

extension ReceivePhoneCallViewController: NXMCallDelegate {
    func call(_ call: NXMCall, didUpdate callMember: NXMCallMember, with status: NXMCallMemberStatus) {
        print("✆  🤙 Call Status update | member: \(callMember.user.displayName) | status: \(callMember.statusDescription)")
        
        // call ended
        if call.myCallMember == callMember, status == .completed {
            self.callStatus = .completed
            self.call?.hangup()
            self.call = nil
        }
        
        // call error
        if call.otherCallMembers.contains(callMember), [NXMCallMemberStatus.failed, NXMCallMemberStatus.busy, NXMCallMemberStatus.timeout].contains(callMember.status) {
            self.callStatus = .rejected
            self.call?.hangup()
            self.call = nil
        }
        
        // call rejected
        if call.otherCallMembers.contains(callMember), callMember.status == .rejected {
            self.callStatus = .rejected
            self.call?.hangup()
            self.call = nil
        }
        
        // call ended
        if call.otherCallMembers.contains(callMember), callMember.status == .completed {
            self.callStatus = .completed
            self.call?.hangup()
            self.call = nil
        }
        
        updateInterface()
        
    }
    
    func call(_ call: NXMCall, didUpdate callMember: NXMCallMember, isMuted muted: Bool) {
        updateInterface()
    }
    
    func call(_ call: NXMCall, didReceive error: Error) {
        print("✆  ‼️ call error: \(error.localizedDescription)")
        updateInterface()
    }
    
    
}
