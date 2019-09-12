//
//  NXMBlocks.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^NXMSuccessCallback)(void);
typedef void(^NXMSuccessCallbackWithId)(NSString * _Nullable value);
typedef void(^NXMSuccessCallbackWithObject)(NSObject * _Nullable object);
typedef void(^NXMSuccessCallbackWithObjects)(NSArray * _Nullable objects);
typedef void(^NXMErrorCallback)(NSError * _Nullable error);
typedef void(^NXMCompletionCallback)(NSError * _Nullable error);
