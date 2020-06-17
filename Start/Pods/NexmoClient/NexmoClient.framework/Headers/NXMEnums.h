//
//  NXMEnums.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, NXMConnectionStatus) {
    NXMConnectionStatusDisconnected,
    NXMConnectionStatusConnecting,
    NXMConnectionStatusConnected
};

typedef NS_ENUM(NSInteger, NXMConnectionStatusReason) {
    NXMConnectionStatusReasonUnknown,
    NXMConnectionStatusReasonLogin,
    NXMConnectionStatusReasonLogout,
    NXMConnectionStatusReasonTokenRefreshed,
    NXMConnectionStatusReasonTokenInvalid,
    NXMConnectionStatusReasonTokenExpired,
    NXMConnectionStatusReasonUserNotFound,
    NXMConnectionStatusReasonTerminated
};


typedef NS_ENUM(NSInteger, NXMPushTemplate) {
    NXMPushTemplateDefault,
    NXMPushTemplateCustom
};


typedef NS_ENUM(NSInteger, NXMMemberUpdateType) {
    NXMMemberUpdateTypeState,
    NXMMemberUpdateTypeMedia,
    NXMMemberUpdateTypeLeg
};

typedef NS_ENUM(NSInteger, NXMMediaType) {
    NXMMediaTypeNone = (0),
    NXMMediaTypeAudio = (1 << 0),
    NXMMediaTypeVideo = (1 << 1)
};

typedef NS_ENUM(NSInteger, NXMEventType) {
    NXMEventTypeGeneral,
    NXMEventTypeCustom,
    NXMEventTypeText,
    NXMEventTypeImage,
    NXMEventTypeMessageStatus,
    NXMEventTypeTextTyping,
    NXMEventTypeMedia,
    NXMEventTypeMember,
    NXMEventTypeSip,
    NXMEventTypeDTMF,
    NXMEventTypeLegStatus,
    NXMEventTypeUnknown
};

typedef NS_ENUM(NSInteger, NXMSipStatus){
    NXMSipEventRinging,
    NXMSipEventAnswered,
    NXMSipEventStatus,
    NXMSipEventHangup
};

typedef NS_ENUM(NSInteger, NXMMessageStatusType) {
    NXMMessageStatusTypeNone,
    NXMMessageStatusTypeSeen,
    NXMMessageStatusTypeDelivered,
    NXMMessageStatusTypeDeleted
};

typedef NS_ENUM(NSInteger, NXMTextTypingEventStatus) {
    NXMTextTypingEventStatusOn,
    NXMTextTypingEventStatusOff
};

typedef NS_ENUM(NSInteger, NXMMemberState) {
    NXMMemberStateInvited,
    NXMMemberStateJoined,
    NXMMemberStateLeft
};

typedef NS_ENUM(NSInteger, NXMDirectionType){
    NXMDirectionTypeApp,
    NXMDirectionTypePhone,
    NXMDirectionTypeSIP,
    NXMDirectionTypeWebsocket,
    NXMDirectionTypeVBC,
    NXMDirectionTypeUnknown
};


typedef NS_ENUM(NSInteger, NXMMediaStreamType) {
    NXMMediaStreamTypeNone,
    NXMMediaStreamTypeSend,
    NXMMediaStreamTypeReceive,
    NXMMediaStreamTypeSendReceive
};

typedef NS_ENUM(NSInteger, NXMLegStatus) {
    NXMLegStatusRinging,
    NXMLegStatusStarted,
    NXMLegStatusAnswered,
    NXMLegStatusCanceled,
    NXMLegStatusFailed,
    NXMLegStatusBusy,
    NXMLegStatusTimeout,
    NXMLegStatusRejected,
    NXMLegStatusCompleted
};

typedef NS_ENUM(NSInteger, NXMLegType) {
    NXMLegTypeApp,
    NXMLegTypePhone,
    NXMLegTypeUnknown
};

typedef NS_ENUM(NSInteger, NXMPageOrder) {
    NXMPageOrderAsc,
    NXMPageOrderDesc
};


