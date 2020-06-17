//
//  NXMConversationsPage.h
//  NexmoClient
//
//  Copyright © 2019 Vonage. All rights reserved.
//

#import "NXMConversation.h"
#import "NXMPage.h"

@interface NXMConversationsPage : NXMPage

/*!
 * @brief Conversations contained in the page. The array size could be smaller than the page size.
 * @code NSArray<NXMConversation *> *conversations = myNXMConversationsPage.conversations;
 */
@property (nonatomic, nonnull, readonly) NSArray<NXMConversation *> *conversations;

/*!
 * @brief Retrieves the next page. If the current page is the last, completionHandler will be called with an error.
 * @code [myNXMConversationsPage nextPage:^(NSError * _Nullable error, NXMConversationsPage * _Nullable page) {
     // ... use page...
 }];
 */
- (void)nextPage:(void(^_Nonnull)(NSError * _Nullable error, NXMConversationsPage * _Nullable page))completionHandler;

/*!
 * @brief Retrieves the previous page. If the current page is the first, completionHandler will be called with an error.
 * @code [myNXMConversationsPage previousPage:^(NSError * _Nullable error, NXMConversationsPage * _Nullable page) {
 // ... use page...
 }];
 */
- (void)previousPage:(void(^_Nonnull)(NSError * _Nullable error, NXMConversationsPage * _Nullable page))completionHandler;

@end
