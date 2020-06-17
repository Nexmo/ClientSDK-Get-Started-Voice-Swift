//
//  NXMPushEvent.h
//  NexmoClient
//
//  Copyright © 2020 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NXMEnums.h"

@interface NXMPushPayload : NSObject

@property (nonatomic, readonly, nullable) NSDictionary *customData;
@property (nonatomic, readonly, nullable) NSDictionary *eventData;
@property (nonatomic, readonly) NXMPushTemplate template;

@end


