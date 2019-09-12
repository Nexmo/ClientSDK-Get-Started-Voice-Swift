//
//  NXMMessageEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import "NXMEvent.h"

@interface NXMMessageEvent : NXMEvent
@property (nonatomic, strong,nonnull) NSMutableDictionary<NSNumber *,NSMutableDictionary<NSString *, NSDate *> *> *state;
@end
