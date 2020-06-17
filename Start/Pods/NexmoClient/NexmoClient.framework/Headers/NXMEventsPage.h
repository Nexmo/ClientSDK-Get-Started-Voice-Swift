//
//  NXMEventsPage.h
//  NexmoClient
//
//  Copyright © 2019 Vonage. All rights reserved.
//

#import "NXMEvent.h"
#import "NXMPage.h"

@interface NXMEventsPage : NXMPage

/*!
 * @brief Events contained in the page. The array size could be smaller than the page size.
 * @code NSArray<NXMEvents *> *events = myNXMEventsPage.events;
 */
@property (nonatomic, nonnull, readonly) NSArray<NXMEvent *> *events;

/*!
 * @brief Retrieves the next page. If the current page is the last, completionHandler will be called with an error.
 * @code [myNXMEventsPage nextPage:^(NSError * _Nullable error, NXMEventsPage * _Nullable page) {
     // ... use page...
 }];
 */
- (void)nextPage:(void(^_Nonnull)(NSError * _Nullable error, NXMEventsPage * _Nullable page))completionHandler;

/*!
 * @brief Retrieves the previous page. If the current page is the first, completionHandler will be called with an error.
 * @code [myNXMEventsPage previousPage:^(NSError * _Nullable error, NXMEventsPage * _Nullable page) {
 // ... use page...
 }];
 */
- (void)previousPage:(void(^_Nonnull)(NSError * _Nullable error, NXMEventsPage * _Nullable page))completionHandler;

@end
