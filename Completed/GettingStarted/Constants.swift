//
//  Constants.swift
//  GetStarted
//
//  Created by Paul Ardeleanu on 11/09/2019.
//  Copyright © 2019 Nexmo. All rights reserved.
//

import Foundation


enum User: String {
    case jane = "Jane"
    case joe = "Joe"
    
    var uuid: String {
        switch self {
        case .jane:
            return "" //TODO: swap with Jane's user uuid
        case .joe:
            return "" //TODO: swap with Joe's user uuid
        }
    }
    
    var jwt: String {
        switch self {
        case .jane:
            return "" //TODO: swap with a token for Jane
        case .joe:
            return "" //TODO: swap with a token for Joe
        }
    }
    
    var callee: User {
        switch self {
        case .jane:
            return .joe
        case .joe:
            return .jane
        }
    }
    
    static let calleePhoneNumber = "" //TODO: swap with a phone number to call
}

