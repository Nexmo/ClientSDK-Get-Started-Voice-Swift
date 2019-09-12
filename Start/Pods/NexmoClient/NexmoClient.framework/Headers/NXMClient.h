//
//  NXMClient.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NXMClientDelegate.h"
#import "NXMConversation.h"
#import "NXMCall.h"

/*!
 * @brief You use a <i>NXMClient</i> instance to utilise the services provided by NexmoConversation API in your app.
 * <p>
 * A session is the period during which your app is connected to NexmoConversation API.
 * Sessions are established for the length of time given when the authToken was created.
 * <p>
 * Tokens also have a lifetime and can optionally be one-shot which will allow a single login only, before
 * the authToken becomes invalid for another login attempt. If the authToken is revoked while a session is active the
 * session may be terminated by the server.
 * It is only possible to have a single session active over a socket.io connection at a time.
 * Session multiplexing is not supported. {@link NXMClient#InitWithToken:NSString*}</p>
 *
 * <strong>Note</strong>: The connection uses socket.io for both web and mobile clients.
 * Upon a successful socket.io connection the client needs to authenticate itself.
 * This is achieved by sending a login request via {@link NXMClient#login} and get the answer in the delegate {@link NXMCLient#setDelegate}.</p>
 *
 * <p>Unless otherwise specified, all the methods invoked by this client are executed asynchronously.</p>
 *
 * <p>For the security of your Nexmo account, you should not embed directly your NexmoConversation credential authToken as strings in the app you submit to the Google Play Store.</p>
 * <p>
 * First step is to acquire a {@link NXMClient} instance based on user credentials.
 * <p>To construct a {@link NXMClient} the required parameters are:</p>
 * <ul>
 * <li>Token:  The user specific authToken.</li>
 * </ul>
 * <p>
 * Im oreder to get the answer you must call {@link NXMClient#setDelegate}
 * Remember to logout when needed in order to remove current user and disconnect from the underlying connection.
 * <p>Example usage:</p>
 * <pre>
 *     myClient.logout
 * </pre>
 * <p>
 * @code [myClient.call:usernames, callHandler:NXMCallHandlerInApp delegate:self completion:(void(^_Nullable)(NSError * _Nullable error, NXMCall * _Nullable call)){
        if (call){
            //You got the call object
        }
 *     })];
 */


@interface NXMClient : NSObject

/*!
 * @brief Shared instance of the NXMClient object
 * @code NXMClient.shared
 */
@property (class, nonatomic, readonly, nonnull) NXMClient *shared;

/*!
 * @brief Get the current connection state
 * @code NXMConnectionStatus currentConnectionStatus = [myNXNClient  getConnectionStatus];
*/
@property (nonatomic, assign, readonly, getter=getConnectionStatus) NXMConnectionStatus connectionStatus;

/*!
 * @brief Get the current user, the current user is the determine in the login by the token
 * @code NXMUser currentUser = [myNXNClient  getUser];
 */
@property (nonatomic, readonly, nullable, getter=getUser) NXMUser *user;


/*!
 * @brief Get the current user authToken
 * @code NSString currentToken = [myNXNClient  getToken];
 */
@property (nonatomic, readonly, nullable, getter=getToken) NSString *authToken;


/*!
 * @brief Set NXMClient delegate
 * @code [myNXNClient setDelegate:clientDelegate];
 *  @param delegate a `NXMClientDelegate` object.
 */
- (void)setDelegate:(nonnull id <NXMClientDelegate>)delegate;


/*!
 * @brief login with current authToken the response in NXMClientDelegate:didChangeConnectionStatus
 * @param authToken user authentication authToken
 * @code [myNXNClient loginWithAuthToken:(NSString *)authToken];
 */
- (void)loginWithAuthToken:(nonnull NSString *)authToken;

/*!
 * @brief Refresh the current user authToken
 * @code [myNXNClient refreshAuthToken:authToken];
 * @param authToken user authentication authToken
 */
- (void)updateAuthToken:(nonnull NSString *)authToken;


/*!
 * @brief logout the current user, the response in NXMClientDelegate:didChangeConnectionStatus
 * @code [myNXNClient logout];
 */
- (void)logout;

#pragma mark - Conversation

/**
 Get a conversation object by id
 @brief getConversation With a specific Id
 @param uuid     conversation id
 @param completionHandler         completion block
 @code [myNXNClient getConversationWithUUid:conversationId completion:(void(^_Nullable)(NSError * _Nullable error, NXMConversation * _Nullable conversation))completion{
 if (!error){
        NXMConversation myConversation = conversation;
    }
 }];
 */
- (void)getConversationWithUUid:(nonnull NSString *)uuid
              completionHandler:(void(^_Nullable)(NSError * _Nullable error, NXMConversation * _Nullable conversation))completionHandler;


/**
 @brief Create a new conversation with specific name: it is a unique per nexmo application
 @param name                conversation name
 @param completionHandler          completion block
 @code [myNXNClient createConversationWithName:uniqueName completion:(void(^_Nullable)(NSError * _Nullable error, NXMConversation * _Nullable conversation)){
 if (!error)
 NXMConvertion myNamedConversation = convetsation;
 }];
 */
- (void)createConversationWithName:(nonnull NSString *)name
                 completionHandler:(void(^_Nullable)(NSError * _Nullable error, NXMConversation * _Nullable conversation))completionHandler;

#pragma mark - Call

/**
 @brief  Create a new call to users
 @param callee         user ids/name or pstn number to call
 @param callHandler     type of the call (InApp/SERVER)
 @param completionHandler      completion block
 @code [myNXNClient call:usernames callHandler:NXMCallHandlerInApp delegate:callDelegate completion:(void(^_Nullable)(NSError * _Nullable error, NXMCall * _Nullable call)){
 if (!error){
 NXMCall myCall = call;
 }];
 */
- (void)call:(nonnull NSString *)callee
    callHandler:(NXMCallHandler)callHandler
completionHandler:(void(^_Nullable)(NSError * _Nullable error, NXMCall * _Nullable call))completionHandler;

#pragma mark - Push Notifications

/**
 @brief  Enable push notification for specific device
 @param deviceToken     the device token
 @param isPushKit       is the app using PushKit
 @param isSandbox       is apple sandbox enviroment
 @param completionHandler      completion block
 @code [myNXNClient enablePushNotificationsWithDeviceToken:deviceToken isPushKit:isPushKit isSandbox:isSandbox completion:(void(^_Nullable)(NSError * _Nullable error))completion{
 }];
 */
- (void)enablePushNotificationsWithDeviceToken:(nonnull NSData *)deviceToken
                                     isPushKit:(BOOL)isPushKit
                                     isSandbox:(BOOL)isSandbox
                             completionHandler:(void(^_Nullable)(NSError * _Nullable error))completionHandler;

/**
 @brief  Disable push notification for current device
 @param completionHandler      completion block
 @code [myNXNClient disablePushNotificationsWithCompletion:(void(^_Nullable)(NSError * _Nullable error))completion{
 }];
 */
- (void)disablePushNotifications:(void(^_Nullable)(NSError * _Nullable error))completionHandler;

/**
 @brief  Check if a push notification is a NexmoPush, Call this method on incoming push
 @param userInfo    pushInfo
 @return true if nexmo push
 @code BOOL isNexmoPush = [myNXNClient isNexmoPushWithUserInfo:userInfo];
 if (isNexmoPush){
 [myNXNClient processNexmoPushWithUserInfo:userInfo completion:(void(^_Nullable)(NSError * _Nullable error)){
 if (!error){
 NSLog(@"Process a Nexmo push");
 }];
 */
- (BOOL)isNexmoPushWithUserInfo:(nonnull NSDictionary *)userInfo;

/**
 @brief process Nexmo push, Call this method when isNexmoPushWithUserInfo:userInfo return true
 @param userInfo    pushInfo
 @param completionHandler  completion block
 @code BOOL isNexmoPush = [myNXNClient isNexmoPushWithUserInfo:userInfo];
 if (isNexmoPush){
 [myNXNClient processNexmoPushWithUserInfo:userInfo completion:(void(^_Nullable)(NSError * _Nullable error)){
 if (!error){
 NSLog(@"Process a Nexmo push");
 }];
 */
- (void)processNexmoPushWithUserInfo:(nonnull NSDictionary *)userInfo
                   completionHandler:(void(^_Nullable)(NSError * _Nullable error))completionHandler;

@end
