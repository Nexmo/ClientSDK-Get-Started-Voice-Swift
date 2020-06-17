//
//  NXMMessageStatusEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import "NXMEvent.h"

@interface NXMMessageStatusEvent : NXMEvent
@property (nonatomic, readonly) NSInteger referenceEventUuid;
@property (nonatomic, readonly) NXMMessageStatusType status;
@end

