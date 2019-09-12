//
//  MakePhoneCallViewController.swift
//  GettingStarted
//
//  Created by Paul Ardeleanu on 11/09/2019.
//  Copyright © 2019 Nexmo. All rights reserved.
//

import UIKit
import NexmoClient

class MakePhoneCallViewController: UIViewController {
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
        title = "Make a phone call"
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

    
    @IBAction func callNumber(_ sender: Any) {
        // call initiated but not yet active
        if callStatus == .initiated && call == nil {
            callStatus = .unknown
            self.call = nil
            updateInterface()
            return
        }
        // start a new call (check if a call already exists)
        guard let call = call else {
            startCall()
            return
        }
        end(call: call)
    }
    
    private func startCall() {
        callStatus = .initiated
        client.call(User.calleePhoneNumber, callHandler: .server) { [weak self] (error, call) in
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
    }
    
}



//MARK:- NXMClientDelegate

extension MakePhoneCallViewController: NXMClientDelegate {
    
    func client(_ client: NXMClient, didChange status: NXMConnectionStatus, reason: NXMConnectionStatusReason) {
        print("✆  connectionStatusChanged - status: \(status.description()) - reason: \(reason.description())")
        updateInterface()
    }
    
    func client(_ client: NXMClient, didReceiveError error: Error) {
        print("✆  ‼️ connection error: \(error.localizedDescription)")
        updateInterface()
    }
    
}



//MARK:- NXMCallDelegate

extension MakePhoneCallViewController: NXMCallDelegate {
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

