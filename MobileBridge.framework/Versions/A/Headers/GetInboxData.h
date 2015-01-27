//
//  GetInboxData.h
//  MobileBridge
//
//  Created by Lior Lavon on 04/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AsyncPost.h"

typedef enum
{
	get_inbox_data = 0,
    delete_all_and_get_inbox_data = 1,
    delete_segment_and_get_inbox_data = 2
}MB_InboxActionType;

@protocol GetInboxDataDelegate <NSObject>
@required
- (void)InboxDataReceived:(NSDictionary*)dataarray;
@end

@interface GetInboxData : NSObject <AsyncPostDelegate>
{
    __weak id <GetInboxDataDelegate> delegate;
}
@property (weak) id <GetInboxDataDelegate> delegate;

-(id)init:(MB_InboxActionType)actionType inboxId:(int)inboxId delegate:(id <GetInboxDataDelegate>)_delegate;

@end
