//
//  AppToAppCallViewController+Interface.swift
//  GettingStarted
//
//  Created by Paul Ardeleanu on 11/09/2019.
//  Copyright © 2019 Nexmo. All rights reserved.
//

import Foundation
import NexmoClient


extension AppToAppCallViewController {
    
    func updateInterface() {
        DispatchQueue.main.async { [weak self] in
            guard let self = self else { return }
            
            self.activityIndicator.stopAnimating()
            self.statusLabel.text = "Ready."
            self.callButton.alpha = 0
            self.navigationItem.leftBarButtonItem = UIBarButtonItem(title: "Logout", style: .done, target: self, action: #selector(self.logout))
            
            let interfaceState = InterfaceState.computeFor(client: self.client, callStatus: self.callStatus, call: self.call)
            print("📱📱📱 interfaceState: \(interfaceState)")
            
            switch interfaceState {
                
            case .notAuthenticated:
                self.call = nil
                self.statusLabel.text = "Not Authenticated."
                
            case .connecting:
                self.activityIndicator.startAnimating()
                self.statusLabel.text = "Connecting..."
                
            case .disconnected:
                self.statusLabel.text = "Disconnected"
                
            case .loggedIn:
                self.statusLabel.text = "Connected as \(self.user.rawValue)"
                self.callButton.alpha = 1
                self.callButton.setTitle("Call \(self.user.callee.rawValue)", for: .normal)
                
            case .callInitiated:
                self.navigationItem.leftBarButtonItem = nil
                self.statusLabel.text = "Connecting you to \(self.user.callee.rawValue)..."
                self.callButton.alpha = 1
                self.callButton.setTitle("End call", for: .normal)
                
            case .callRinging:
                self.navigationItem.leftBarButtonItem = nil
                self.statusLabel.text = "Ringing"
                self.callButton.alpha = 1
                self.callButton.setTitle("End call", for: .normal)
            
            case .inCall:
                self.navigationItem.leftBarButtonItem = nil
                self.statusLabel.text = "Speaking with \(self.user.callee.rawValue)..."
                self.callButton.alpha = 1
                self.callButton.setTitle("End call", for: .normal)
                
            case .callError:
                self.statusLabel.text = "Could not call \(self.user.callee.rawValue)"
                self.callButton.alpha = 1
                self.callButton.setTitle("Call \(self.user.callee.rawValue)", for: .normal)
                
            case .callRejected:
                self.statusLabel.text = "Call rejected by \(self.user.callee.rawValue)"
                self.callButton.alpha = 1
                self.callButton.setTitle("Call \(self.user.callee.rawValue)", for: .normal)
                
            case .callEnded:
                self.statusLabel.text = "Call with \(self.user.callee.rawValue) ended."
                self.callButton.alpha = 1
                self.callButton.setTitle("Call \(self.user.callee.rawValue)", for: .normal)
               
            }
            
            
        }
    }
    
}

