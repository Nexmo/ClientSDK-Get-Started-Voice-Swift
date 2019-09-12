
//
//  NXMClientDelegate.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "NXMUser.h"
#import "NXMEnums.h"

@class NXMCall;
@class NXMConversation;
@class NXMClient;

@protocol NXMClientDelegate <NSObject>
- (void)client:(nonnull NXMClient *)client didChangeConnectionStatus:(NXMConnectionStatus)status reason:(NXMConnectionStatusReason)reason;
- (void)client:(nonnull NXMClient *)client didReceiveError:(nonnull NSError *)error;
@optional
- (void)client:(nonnull NXMClient *)client didReceiveCall:(nonnull NXMCall *)call;
- (void)client:(nonnull NXMClient *)client didReceiveConversation:(nonnull NXMConversation *)conversation;

@end
