//
//  MB_InboxView.h
//  MobileBridge
//
//  Created by Lior Lavon on 9/7/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GetInboxData.h"

@protocol MB_InboxViewDelegate <NSObject>
@required
- (void)MB_NotificationItemSelected:(NSDictionary*)pData;
@end

@interface MB_InboxView : UIView <UITableViewDataSource, UITableViewDelegate, GetInboxDataDelegate>
{
    __weak id <MB_InboxViewDelegate> delegate;
}
@property (weak) id <MB_InboxViewDelegate> delegate;

-(void)RemoveView;

@end
