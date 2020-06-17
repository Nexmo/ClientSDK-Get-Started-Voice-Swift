//
//  NXMImageInfo.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, NXMImageSize) {
    NXMImageSizeMedium,
    NXMImageSizeOriginal,
    NXMImageSizeThumbnail
};

@interface NXMImageInfo : NSObject
@property (nonatomic, readonly, nonnull) NSString *imageUuid;
@property (nonatomic, readonly, nonnull) NSURL *url;
@property (readonly) NSInteger sizeInBytes;
@property (readonly) NXMImageSize size;

@end
