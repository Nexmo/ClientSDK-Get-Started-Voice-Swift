//
//  Utils.swift
//  GetStarted
//
//  Created by Paul Ardeleanu on 11/09/2019.
//  Copyright © 2019 Nexmo. All rights reserved.
//

import Foundation
import NexmoClient


enum CallStatus {
    case unknown
    case initiated
    case inProgress
    case error
    case rejected
    case completed
}


enum InterfaceState {
    case notAuthenticated
    case connecting
    case disconnected
    case loggedIn
    case callInitiated
    case callRinging
    case callError
    case inCall
    case callRejected
    case callEnded
    
    static func computeFor(client: NXMClient, callStatus: CallStatus, call: NXMCall?) -> InterfaceState {
        
        // Disconnected or currently Connecting
        switch client.connectionStatus {
        case .disconnected:
            return .disconnected
        case .connecting:
            return .connecting
        case .connected:
            break
        @unknown default:
            return .disconnected
        }
        print("✆  client.user: \(String(describing: client.user?.name))")
        
        guard let call = call else {
            switch callStatus {
            case .unknown:
                return .loggedIn
            case .initiated:
                return .callInitiated
            case .inProgress:
                // this should never happen
                return .loggedIn
            case .error:
                return .callError
            case .rejected:
                return .callRejected
            case .completed:
                return .callEnded
            }
        }
        
        guard let otherMember = call.otherCallMembers.firstObject as? NXMCallMember else {
            return .callInitiated
        }
        switch otherMember.status  {
        case .started:
            return .callInitiated
        case .ringing:
            return .callRinging
        case .failed, .timeout, .busy:
            return .callError
        case .answered:
            return .inCall
        case .rejected:
            return .callRejected
        case .canceled, .completed:
            return .callEnded
        @unknown default:
            return .disconnected
        }
    }
}


extension NXMConnectionStatus {
    func description() -> String {
        switch self {
        case .connected:
            return "Connected"
        case .connecting:
            return "Connecting"
        case .disconnected:
            return "Disconnected"
        @unknown default:
            return "Unknown"
        }
    }
}

extension NXMConnectionStatusReason {
    func description() -> String {
        switch self {
        case .unknown:
            return "Unknown"
        case .login:
            return "Login"
        case .logout:
            return "Logout"
        case .tokenRefreshed:
            return "Token refreshed"
        case .tokenInvalid:
            return "Token invalid"
        case .tokenExpired:
            return "Token expired"
        case .terminated:
            return "Terminated"
        @unknown default:
            return "Unknown"
        }
    }
}


extension NXMCallMemberStatus {
    func description() -> String {
        switch self {
        case .ringing:
            return "Ringing"
        case .started:
            return "Started"
        case .answered:
            return "Answered"
        case .canceled:
            return "Cancelled"
        case .failed:
            return "Failed"
        case .busy:
            return "Busy"
        case .timeout:
            return "Timeout"
        case .rejected:
            return "Rejected"
        case .completed:
            return "Completed"
        @unknown default:
            return "Unknown"
        }
    }
}
