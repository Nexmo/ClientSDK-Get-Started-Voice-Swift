//
//  NXMMessageStatusEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import "NXMEvent.h"

@interface NXMMessageStatusEvent : NXMEvent
@property NSInteger referenceEventUuid;
@property (nonatomic) NXMMessageStatusType status;
@end

