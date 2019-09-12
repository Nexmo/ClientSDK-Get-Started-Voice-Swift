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
        
    }
    
    
    @objc func logout() {
        call?.hangup()
        client.logout()
        navigationController?.popViewController(animated: true)
    }
    
    
    @IBAction func call(_ sender: Any) {
        
    }
    
}



//MARK:- NXMClientDelegate

extension AppToAppCallViewController: NXMClientDelegate {
    
    func client(_ client: NXMClient, didChange status: NXMConnectionStatus, reason: NXMConnectionStatusReason) {
        
    }
    
    func client(_ client: NXMClient, didReceiveError error: Error) {
        
    }
    
    func client(_ client: NXMClient, didReceive call: NXMCall) {
        
    }

    
    //MARK: Incoming call - Accept
    
    private func answer(call: NXMCall) {
        
    }
    
    //MARK: Incoming call - Reject
    
    private func reject(call: NXMCall) {
        
    }
}



//MARK:- NXMCallDelegate

extension AppToAppCallViewController: NXMCallDelegate {
    func call(_ call: NXMCall, didUpdate callMember: NXMCallMember, with status: NXMCallMemberStatus) {
        
    }
    
    func call(_ call: NXMCall, didUpdate callMember: NXMCallMember, isMuted muted: Bool) {
        
    }
    
    func call(_ call: NXMCall, didReceive error: Error) {
        
    }
    
    
}
