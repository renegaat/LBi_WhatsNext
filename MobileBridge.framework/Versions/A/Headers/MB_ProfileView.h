//
//  MB_ProfileView.h
//  MobileBridge
//
//  Created by Lior Lavon on 9/7/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AsyncPost.h"
#import "lib_UICheckView.h"
#import "lib_GroupCBView.h"

@protocol MB_ProfileViewDelegate <NSObject>
@required
//- (void)MB_NotificationItemSelected:(NSDictionary*)pData;
@end

@interface MB_ProfileView : UIView <UITableViewDataSource, UITableViewDelegate, AsyncPostDelegate, lib_UICheckViewDelegate, lib_GroupCBViewDelegate>
{
    __weak id <MB_ProfileViewDelegate> delegate;
}
@property (weak) id <MB_ProfileViewDelegate> delegate;

-(void)RemoveView;

@end
