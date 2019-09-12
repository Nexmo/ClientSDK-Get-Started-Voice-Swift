//
//  NXMErrors.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString * _Nonnull const NXMErrorDomain;

typedef NS_ENUM(NSInteger, NXMErrorCode) {
    NXMErrorCodeNone,

    NXMErrorCodeUnknown,
    
    NXMErrorCodeSessionUnknown,
    NXMErrorCodeSessionInvalid,           // @"system:error:invalid-session"
    NXMErrorCodeSessionDisconnected,
    NXMErrorCodeMaxOpenedSessions,
    
    NXMErrorCodeTokenUnknown,
    NXMErrorCodeTokenInvalid,             // @"system:error:invalid-token"
    NXMErrorCodeTokenExpired,             // @"system:error:expired-token"
    
    NXMErrorCodeMemberUnknown,
    NXMErrorCodeMemberNotFound,           // @"member:error:not-found"
    NXMErrorCodeMemberAlreadyRemoved,     // @"conversation:error:invalid-member-state"
    NXMErrorCodeNotAMemberOfTheConversation,
    
    NXMErrorCodeEventUnknown,
    NXMErrorCodeEventUserNotFound,        // @"user:error:not-found"
    NXMErrorCodeEventUserAlreadyJoined,   // @"conversation:error:member-already-joined"
    NXMErrorCodeEventInvalid,             // @"conversation:error:invalid-event"
    NXMErrorCodeEventBadPermission,
    NXMErrorCodeEventNotFound,
    
    NXMErrorCodeConversationRetrievalFailed,
    NXMErrorCodeConversationNotFound,
    NXMErrorCodeConversationInvalidMember,
    NXMErrorCodeConversationExpired,
    
    NXMErrorCodeMediaNotSupported,
    NXMErrorCodeMediaNotFound,
    NXMErrorCodeInvalidMediaRequest,
    NXMErrorCodeMediaTooManyRequests,
    NXMErrorCodeMediaBadRequest,
    NXMErrorCodeMediaInternalError,
    
    NXMErrorCodePushNotAStitchPush,
    NXMErrorCodePushParsingFailed,
    
    NXMErrorCodeNotImplemented,
    NXMErrorCodeMissingDelegate,
    NXMErrorCodePayloadTooBig,
    
    NXMErrorCodeSDKDisconnected,
    
    NXMErrorCodeDTMFIllegal
};
