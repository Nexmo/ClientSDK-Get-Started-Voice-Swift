//
//  NXMImageEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import "NXMMessageEvent.h"
#import "NXMImageInfo.h"

@interface NXMImageEvent : NXMMessageEvent
@property (nonatomic, readonly, nonnull) NSString *imageUuid;
@property (nonatomic, readonly, nonnull) NXMImageInfo *mediumImage;
@property (nonatomic, readonly, nonnull) NXMImageInfo *originalImage;
@property (nonatomic, readonly, nonnull) NXMImageInfo *thumbnailImage;
@end
