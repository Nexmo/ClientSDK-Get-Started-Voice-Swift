//
//  NXMMessageEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import "NXMEvent.h"

@interface NXMMessageEvent : NXMEvent
@property (nonatomic, readonly, nonnull) NSDictionary<NSNumber *, NSDictionary<NSString *, NSDate *> *> *state;
@end
