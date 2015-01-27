//
//  MB_GetInboxData.h
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

@protocol MB_GetInboxDataDelegate <NSObject>
@required
- (void)MB_InboxDataReceived:(NSDictionary*)dataarray;
@end

@interface MB_GetInboxData : NSObject <AsyncPostDelegate>
{
    __weak id <MB_GetInboxDataDelegate> delegate;
}
@property (weak) id <MB_GetInboxDataDelegate> delegate;

-(id)init:(MB_InboxActionType*)actionType inboxId:(int)inboxId delegate:(id <MB_GetInboxDataDelegate>)_delegate;

@end
