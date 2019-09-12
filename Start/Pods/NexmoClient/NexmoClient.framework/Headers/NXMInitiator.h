//
//  NXMInitiator.h
//  NexmoClient
//
//  Copyright © 2019 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @interface NXMInitiator
 
 @brief The NXMInitiator object represent the member state initiator
 
 @discussion In case that the initiator is not part of the conversation the memberUuid proprety has null value and the userId proprety has the user id value. In case that the initiator is part of the conversation the memberUuid has the initiator member id value. In case that the initiator is done by webhook the isSystem has the value true, the memberUuid and the user id has the value null.
 */
@interface NXMInitiator : NSObject

/// True when the member state initiator is not a user.
@property (nonatomic, readonly) BOOL isSystem;

/// Indicates the initiator user id of the member state ,has value when the initiator is not part of the conversation.
@property (nonatomic, copy, nullable) NSString *userId;

/// Indicates the initiator member id of the member state, has value when the initiator is part of the conversation.
@property (nonatomic, copy, nullable) NSString *memberId;

/// Indicates the time when the initiator changed the member state.
@property (nonatomic, copy, nonnull) NSDate *time;

@end

