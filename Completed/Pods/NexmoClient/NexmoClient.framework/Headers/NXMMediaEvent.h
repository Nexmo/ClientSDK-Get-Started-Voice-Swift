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
@property (nonatomic) NXMMediaSettings *mediaSettings; //TODO: add support to multiple media types
@end
