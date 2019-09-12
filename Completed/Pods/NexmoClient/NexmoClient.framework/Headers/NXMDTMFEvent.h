//
//  NXMDTMFEvent.h
//  NexmoClient
//
//  Copyright © 2019 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NXMEvent.h"

@interface NXMDTMFEvent : NXMEvent

@property (nullable, nonatomic, readonly, copy) NSString *digit;
@property (nullable, nonatomic, readonly, copy) NSNumber *duration;

@end

