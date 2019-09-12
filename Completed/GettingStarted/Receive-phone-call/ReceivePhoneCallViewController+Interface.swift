//
//  ReceivePhoneCallViewController+Interface.swift
//  GettingStarted
//
//  Created by Paul Ardeleanu on 11/09/2019.
//  Copyright © 2019 Nexmo. All rights reserved.
//

import Foundation
import NexmoClient


extension ReceivePhoneCallViewController {
    
    func updateInterface() {
        DispatchQueue.main.async { [weak self] in
            guard let self = self else { return }
            
            self.activityIndicator.stopAnimating()
            self.statusLabel.text = "Ready."
            self.callButton.alpha = 0
            
            let interfaceState = InterfaceState.computeFor(client: self.client, callStatus: self.callStatus, call: self.call)
            print("✆  interfaceState: \(interfaceState)")
            
            
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
                
            case .callInitiated:
                self.activityIndicator.startAnimating()
                self.statusLabel.text = "Connecting you..."
                
            case .callRinging:
                self.activityIndicator.startAnimating()
                self.statusLabel.text = "Ringing"
                
            case .inCall:
                self.statusLabel.text = "Speaking..."
                self.callButton.alpha = 1
                
            case .callError:
                self.statusLabel.text = "Could not call \(User.calleePhoneNumber)"
                
            case .callRejected:
                self.statusLabel.text = "Call rejected"
                
            case .callEnded:
                self.statusLabel.text = "Call from \(User.calleePhoneNumber) ended."
                
            }
            
            
        }
    }
    
}

