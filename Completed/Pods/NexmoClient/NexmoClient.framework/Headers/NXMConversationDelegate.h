//
//  NXMConversationDelegate.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "NXMCoreEvents.h"
#import "NXMMember.h"

@class NXMConversation;

/*!
 @protocol NXMConversationUpdateDelegate
 
 @brief The NXMConversationUpdateDelegate protocol notify on member updates
 */
@protocol NXMConversationUpdateDelegate <NSObject>
//@optional
/*!
 * @brief member properties updated.
 * @param member A NXMMember object, the member that updates.
 * @param type A NXMMemberUpdateType enum.
 */
- (void)conversation:(nonnull NXMConversation *)conversation didUpdateMember:(nonnull NXMMember *)member withType:(NXMMemberUpdateType)type;
@end
/*!
 @protocol NXMConversationDelegate
 
 @brief The NXMConversationDelegate protocol notify on conversation events
 */
@protocol NXMConversationDelegate <NSObject>
- (void)conversation:(nonnull NXMConversation *)conversation didReceive:(nonnull NSError *)error;
@optional
#pragma events
- (void)conversation:(nonnull NXMConversation *)conversation didReceiveCustomEvent:(nonnull NXMCustomEvent *)event;
- (void)conversation:(nonnull NXMConversation *)conversation didReceiveTextEvent:(nonnull NXMTextEvent *)event;
- (void)conversation:(nonnull NXMConversation *)conversation didReceiveImageEvent:(nonnull NXMImageEvent *)event;
- (void)conversation:(nonnull NXMConversation *)conversation didReceiveMessageStatusEvent:(nonnull NXMMessageStatusEvent *)event;
- (void)conversation:(nonnull NXMConversation *)conversation didReceiveTypingEvent:(nonnull NXMTextTypingEvent *)event;
- (void)conversation:(nonnull NXMConversation *)conversation didReceiveMemberEvent:(nonnull NXMMemberEvent *)event;
- (void)conversation:(nonnull NXMConversation *)conversation didReceiveLegStatusEvent:(nonnull NXMLegStatusEvent *)event;
- (void)conversation:(nonnull NXMConversation *)conversation didReceiveMediaEvent:(nonnull NXMMediaEvent *)event;
- (void)conversation:(nonnull NXMConversation *)conversation didReceiveDTMFEvent:(nonnull NXMDTMFEvent *)event;
@end
