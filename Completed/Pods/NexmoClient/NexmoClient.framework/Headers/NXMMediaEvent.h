//
//  NXMMediaEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NXMEvent.h"
#import "NXMMediaSettings.h"

@interface NXMMediaEvent : NXMEvent
@property (nonatomic, readonly) bool isEnabled;
@property (nonatomic, readonly) bool isSuspended;
@end
