//
//  NXMTextTypingEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import "NXMEvent.h"
#import "NXMEnums.h"

@interface NXMTextTypingEvent : NXMEvent
@property (nonatomic, readonly) NXMTextTypingEventStatus status;
@end

