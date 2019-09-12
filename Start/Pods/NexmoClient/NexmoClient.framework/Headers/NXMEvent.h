//
//  NXMEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NXMEnums.h"
#import "NXMMember.h"


@interface NXMEvent : NSObject

@property (nonatomic, copy, nonnull) NSString *conversationUuid;
@property (nonatomic, readonly, nullable) NXMMember *fromMember;
@property (nonatomic, copy, nonnull) NSDate *creationDate;
@property (nonatomic, copy, nullable) NSDate *deletionDate;
@property NXMEventType type;
@property NSInteger uuid;

@end
