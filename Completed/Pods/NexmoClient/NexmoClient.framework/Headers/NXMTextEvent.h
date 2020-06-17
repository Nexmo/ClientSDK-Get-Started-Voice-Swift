//
//  NXMTextEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import "NXMMessageEvent.h"

@interface NXMTextEvent : NXMMessageEvent
@property (nonatomic, nullable, readonly) NSString *text;
@end
