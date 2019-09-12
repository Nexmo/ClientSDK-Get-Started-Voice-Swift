//
//  AppToAppCallViewController.swift
//  GettingStarted
//
//  Created by Paul Ardeleanu on 11/09/2019.
//  Copyright © 2019 Nexmo. All rights reserved.
//

import UIKit
import NexmoClient


class AppToAppCallViewController: UIViewController {

    var user: User!
    let client = NXMClient.shared
    var call: NXMCall?
    var callStatus: CallStatus = .unknown
    
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    @IBOutlet weak var statusLabel: UILabel!
    @IBOutlet weak var callButton: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.navigationItem.setHidesBackButton(true, animated: false)
    
        title = "App to App Call"
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
    
    
    @IBAction func call(_ sender: Any) {
        // start a new call (if one doesn't already exists)
        guard let call = call else {
            startCall()
            return
        }
        // or end an existing call
        end(call: call)
    }
    
    private func startCall() {
        callStatus = .initiated
        client.call(user.callee.rawValue, callHandler: .inApp) { [weak self] (error, call) in
            guard let self = self else { return }
            // Handle create call failure
            guard let call = call else {
                if let error = error {
                    // Handle create call failure
                    print("✆  ‼️ call not created: \(error.localizedDescription)")
                } else {
                    // Handle unexpected create call failure
                    print("✆  ‼️ call not created: unknown error")
                }
                self.callStatus = .error
                self.call = nil
                self.updateInterface()
                return
            }
            
            // Handle call created successfully.
            // callDelegate's  statusChanged: will be invoked with needed updates.
            call.setDelegate(self)
            self.call = call
            self.updateInterface()
        }
        updateInterface()
    }
    
    
    private func end(call: NXMCall) {
        call.hangup()
        callStatus = .completed
        self.call = nil
        updateInterface()
    }
    
}



//MARK:- NXMClientDelegate

extension AppToAppCallViewController: NXMClientDelegate {
    
    func client(_ client: NXMClient, didChange status: NXMConnectionStatus, reason: NXMConnectionStatusReason) {
        print("👁👁👁 connectionStatusChanged - status: \(status.description()) - reason: \(reason.description())")
        updateInterface()
    }
    
    func client(_ client: NXMClient, didReceiveError error: Error) {
        print("✆  ‼️ connection error: \(error.localizedDescription)")
        updateInterface()
    }
    
    func client(_ client: NXMClient, didReceive call: NXMCall) {
        print("✆  📲 Incoming Call: \(call)")
        DispatchQueue.main.async { [weak self] in
            self?.displayIncomingCallAlert(call: call)
        }
    }

    func displayIncomingCallAlert(call: NXMCall) {
        let names: [String] = call.otherCallMembers.compactMap({ participant -> String? in
            return (participant as? NXMCallMember)?.user.name
        })
        let alert = UIAlertController(title: "Incoming call from", message: names.joined(separator: ", "), preferredStyle: .alert)
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
        call.answer { [weak self] error in
            if let error = error {
                print("✆  ‼️ error answering call: \(error.localizedDescription)")
            }
            self?.updateInterface()
        }
    }
    
    //MARK: Incoming call - Reject
    
    private func reject(call: NXMCall) {
        call.reject { [weak self] error in
            if let error = error {
                print("✆  ‼️ error declining call: \(error.localizedDescription)")
            }
            self?.updateInterface()
        }
    }
}



//MARK:- NXMCallDelegate

extension AppToAppCallViewController: NXMCallDelegate {
    func call(_ call: NXMCall, didUpdate callMember: NXMCallMember, with status: NXMCallMemberStatus) {
        print("✆  🤙 Call Status update | member: \(callMember.user.displayName) | status: \(String(describing: callMember.status.description()))")
        
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
        print("✆  ‼️  call error: \(error.localizedDescription)")
        updateInterface()
    }
    
    
}
