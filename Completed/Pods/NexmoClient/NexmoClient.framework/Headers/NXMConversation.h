//
//  NXMConversation.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NXMConversationDelegate.h"
#import "NXMMember.h"

typedef NS_ENUM(NSInteger, NXMAttachmentType) {
    NXMAttachmentTypeImage
};

/*!
 @interface NXMConversation
 @brief The NXMConversation object represent a conversation.
 @discussion NXMConversation can be used for messaging and media.
 */
@interface NXMConversation : NSObject

/// Conversation unique identifier.
@property (readonly, nonatomic, nonnull) NSString *uuid;

/// Conversation unique name.
@property (readonly, nonatomic, nonnull) NSString *name;

/// Conversation display name.
@property (readonly, nonatomic, nullable) NSString *displayName;
@property (readonly, nonatomic) NSInteger lastEventId;

/// Conversation creation date
@property (readonly, nonatomic, nonnull) NSDate *creationDate;

/// The current user member
@property (readonly, nonatomic, nullable) NXMMember *myMember;

/// Conversation all members
@property (readonly, nonatomic, nonnull) NSArray<NXMMember *> *allMembers;

/// Conversation events delegate
@property (nonatomic, weak, nullable) id <NXMConversationDelegate> delegate;

/// Conversation updates delegate
@property (nonatomic, weak, nullable) id <NXMConversationUpdateDelegate> updatesDelegate;

/*!
 * @brief invite the user as a member of the conversation
 * @param completion A block with param NSError if one occured
 * @code [conversation inviteMemberWithUsername:username completion:^(NSError error){
 if (!error) {
 NSLog(@"invited username to the conversation failed");
 return;
 }
 
 NSLog(@"invited username the conversation");
 }];
 */
- (void)inviteMemberWithUsername:(nonnull NSString *)username
                      completion:(void (^_Nullable)(NSError * _Nullable error))completion;

/*!
 * @brief Join the current user as a member of the conversation
 * @param completionHandler A block with two params an NSError if one occured and NXMMember
 * @code [conversation joinWithCompletion:^(NSError error, NXMMember member){
 if (!error) {
 NSLog(@"join the conversation failed");
 return;
 }
 
 NSLog(@"joined the conversation");
 }];
 */
- (void)join:(void (^_Nullable)(NSError * _Nullable error, NXMMember * _Nullable member))completionHandler;

/*!
 * @brief Join a specific user as a member of the conversation
 * @param username the user identifier
 * @param completion A block with two params NSError if one occured and NXMMember
 * @code [conversation joinMemberWithUsername:theUsername :^(NSError error, NXMMember member){
     if (!error) {
     NSLog(@"join the conversation failed");
     return;
     }
 
     NSLog(@"theUserId joined the conversation");
     }];
*/
- (void)joinMemberWithUsername:(nonnull NSString *)username
                completion:(void (^_Nullable)(NSError * _Nullable error, NXMMember * _Nullable member))completion;


/*!
 * @brief Current user's member leaves the conversation
 * @param completionHandler A completion block with an error object if one occured
 * @code [conversation leave:theUserId :^(NSError error, NXMMember member){
 if (!error) {
 NSLog(@"leave the conversation failed");
 return;
 }
 
 NSLog(@"Current user's member left the conversation");
 }];
 */
- (void)leave:(void (^_Nullable)(NSError * _Nullable error))completionHandler;


/**
 Kicks a member from participating in the conversation
 
 @param memberId
 The id of the member to kick
 
 @param completion
 A completion block with an error object if one occured
 */
- (void)kickMemberWithMemberId:(nonnull NSString *)memberId
                     completion:(void (^_Nullable)(NSError * _Nullable error))completion;

/**
 Enable media for the current user member
 */
- (void)enableMedia;

/**
 Disable media for the current user member
 */
- (void)disableMedia;

/**
 Send a custom event in the conversation
 
 @param customType
 The customType name
 
 @param data
 The custom event data
 
 @param completionHandler
 A completion block with an error object if one occured
 */
- (void)sendCustomWithEvent:(nonnull NSString *)customType
                       data:(nonnull NSDictionary *)data
          completionHandler:(void (^_Nullable)(NSError * _Nullable error))completionHandler;

/**
 Sends a text message to the members of the conversation
 
 @param text
 The text to send
 
 @param completionHandler
 A completion block with an error object if one occured
 */
- (void)sendText:(nonnull NSString *)text
     completionHandler:(void (^_Nullable)(NSError * _Nullable error))completionHandler;


/**
 Sends an attachment message to the members of the conversation
 
 @param type
 The type of the attachment following NXMAttachmentType enum
 
 @param name
 A name identifier of the attachment
 
 @param data
 The data of the attachment in a NSData representation
 
 @param completionHandler
 A completion block with an error object if one occured
 */
- (void)sendAttachmentWithType:(NXMAttachmentType)type
                          name:(nonnull NSString *)name
                          data:(nonnull NSData *)data
             completionHandler:(void (^_Nullable)(NSError * _Nullable error))completionHandler;

/**
  Sends an indication that the current user's member has seen a message
 
 @param message
 The message identifier of the message that has been seen by the current user
 
 @param completionHandler
 A completion block with an error object if one occured
 */

- (void)sendMarkSeenMessage:(NSInteger)message
          completionHandler:(void (^_Nullable)(NSError * _Nullable error))completionHandler;

/**
 Sends an indication that the current user's member started typing
 
 @param completionHandler
 A completion block with an error object if one occured
 */
- (void)sendStartTyping:(void (^_Nullable)(NSError * _Nullable error))completionHandler;


/**
 Sends an indication that the current user's member stopped typing
 
 @param completionHandler
 A completion block with an error object if one occured
 */
- (void)sendStopTyping:(void (^_Nullable)(NSError * _Nullable error))completionHandler;

/*!
 * @brief get all conversation events
 */
- (void)getEvents:(void (^_Nullable)(NSError * _Nullable error, NSArray<NXMEvent *> * _Nonnull))completionHandler;
@end
