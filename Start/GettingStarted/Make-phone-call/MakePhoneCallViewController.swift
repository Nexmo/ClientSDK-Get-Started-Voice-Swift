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
        
    }
    
    
    @objc func logout() {
        call?.hangup()
        client.logout()
        navigationController?.popViewController(animated: true)
    }

    
    @IBAction func callNumber(_ sender: Any) {
        
    }
    
    
    private func end(call: NXMCall) {
       
    }
    
}



//MARK:- NXMClientDelegate

extension MakePhoneCallViewController: NXMClientDelegate {
    
    func client(_ client: NXMClient, didChange status: NXMConnectionStatus, reason: NXMConnectionStatusReason) {
        
    }
    
    func client(_ client: NXMClient, didReceiveError error: Error) {
        
    }
    
}



//MARK:- NXMCallDelegate

extension MakePhoneCallViewController: NXMCallDelegate {
    
    func call(_ call: NXMCall, didUpdate callMember: NXMCallMember, with status: NXMCallMemberStatus) {
        
    }
    
    func call(_ call: NXMCall, didUpdate callMember: NXMCallMember, isMuted muted: Bool) {
        
    }
    
    func call(_ call: NXMCall, didReceive error: Error) {
        
    }
    
    
}

