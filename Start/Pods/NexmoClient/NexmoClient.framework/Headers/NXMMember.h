//
//  NXMMember.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NXMEnums.h"
#import "NXMUser.h"
#import "NXMMediaSettings.h"
#import "NXMChannel.h"
#import "NXMInitiator.h"

@interface NXMMember : NSObject

@property (nonatomic, copy, nonnull) NSString *conversationUuid;
@property (nonatomic, copy, nonnull) NSString *memberUuid;
@property (nonatomic, readonly, nonnull) NXMUser *user;
@property (nonatomic, readonly) NXMMemberState state;
@property (nonatomic, readonly, nullable) NXMMediaSettings *media;
@property (nonatomic, readonly, nullable) NXMChannel *channel;


@end
