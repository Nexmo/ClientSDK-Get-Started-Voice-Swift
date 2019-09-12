//
//  NXMLogger.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, NXMLoggerLevel) {
    NXMLoggerLevelNone,
    NXMLoggerLevelError,
    NXMLoggerLevelDebug,
    NXMLoggerLevelInfo,
    NXMLoggerLevelVerbose
};

@interface NXMLogger : NSObject
+ (void)setLogLevel:(NXMLoggerLevel)logLevel;

/**
 @brief get the log files name, while using NXMLogger
 @return NSMutableArray<NSString*>>
 @code NSMutableArray<NSString*>> filesPathes = [NXMLogger getLogFileNames];
 */
+ (nonnull NSMutableArray *)getLogFileNames;

@end
