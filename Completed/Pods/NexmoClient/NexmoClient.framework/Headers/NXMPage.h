//
//  NXMPage.h
//  NexmoClient
//
//  Copyright © 2019 Vonage. All rights reserved.
//

#import "NXMEnums.h"

@interface NXMPage : NSObject

/*!
 * @brief Page size. Size could be greater than elements array's size.
 * @code NXMPageOrder order = myNXMPage.size;
 */
@property (nonatomic, assign, readonly) NSUInteger size;

/*!
 * @brief Elements date order in the page.
 * @code NXMPageOrder order = myNXMPage.order;
 */
@property (nonatomic, assign, readonly) NXMPageOrder order;

/*!
 * @brief Checks if there's a next page.
 * @code BOOL hasNextPage = [myNXMPage hasNextPage];
 */
- (BOOL)hasNextPage;

/*!
 * @brief Checks if there's a previous page.
 * @code BOOL hasPreviousPage = [myNXMPage hasPreviousPage];
 */
- (BOOL)hasPreviousPage;

@end
