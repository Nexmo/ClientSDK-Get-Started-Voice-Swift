//
//  NXMHelper.h
//  NexmoClient
//
//  Copyright © 2020 Vonage. All rights reserved.
//

#import "NXMEnums.h"

/*!
 * @brief Helper methods.
*/
@interface NXMHelper : NSObject

/*!
* @brief Provides a textual description for a given NXMEventType
* @param eventType event type
* @code NSString *eventTypeDescription = [NXMHelper descriptionForEventType:eventType];
*/
+ (nonnull NSString *)descriptionForEventType:(NXMEventType)eventType;

@end
