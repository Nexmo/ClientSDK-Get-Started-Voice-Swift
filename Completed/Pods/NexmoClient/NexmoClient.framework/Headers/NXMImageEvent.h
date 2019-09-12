//
//  NXMImageEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import "NXMMessageEvent.h"
#import "NXMImageInfo.h"

@interface NXMImageEvent : NXMMessageEvent
@property (nonatomic, strong, nonnull) NSString *imageUuid;
@property (nonatomic, strong, nonnull) NXMImageInfo *mediumImage;
@property (nonatomic, strong, nonnull) NXMImageInfo *originalImage;
@property (nonatomic, strong, nonnull) NXMImageInfo *thumbnailImage;
@end
