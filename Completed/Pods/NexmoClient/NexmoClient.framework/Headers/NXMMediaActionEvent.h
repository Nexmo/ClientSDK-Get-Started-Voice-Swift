//
//  NXMMediaActionEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import "NXMEvent.h"

@interface NXMMediaActionEvent : NXMEvent
@property (nonatomic, strong, nonnull) NSString *toMemberUuid;
@property (nonatomic) NXMMediaType mediaType;
@property (nonatomic) NXMMediaActionType actionType;

@end
