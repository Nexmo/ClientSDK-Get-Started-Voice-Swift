//
//  NXMCustomEvent.h
//  NexmoClient
//
//  Copyright © 2019 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NXMEvent.h"
#import "NXMCustomEvent.h"

@interface NXMCustomEvent : NXMEvent

@property (nonatomic, copy, nullable) NSString *customType;
@property (nonatomic, readonly, nullable) NSString *data;

@end

