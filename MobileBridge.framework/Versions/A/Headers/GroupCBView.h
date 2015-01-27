//
//  GroupCBView
//  ConnexxtionTV
//
//  Created by Eyal Oster on 10-01-12.
//  Copyright (c) 2012 Ai-Pixel B.V. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "lib_UICheckView.h"

@protocol GroupCBViewDelegate <NSObject>
@optional
-(void)GroupCBView_UserSelect:(int)type parentRow:(int)parentRow r:(int)r;
@end



@interface GroupCBView : UIView <UITableViewDelegate, UITableViewDataSource, lib_UICheckViewDelegate>
{
    int groupCBType;
    __weak id <GroupCBViewDelegate> delegate;
    int row;
}
@property (nonatomic) int groupCBType;
@property (weak) id <GroupCBViewDelegate> delegate;
@property (nonatomic) int row;

- (id)initWithFrameAndOptions:(CGRect)frame groupCBType:(int)_groupCBType options:(NSString*)options;
- (id)initWithFrameAndArray:(CGRect)frame groupCBType:(int)_groupCBType optionArr:(NSArray*)optionArr;
- (void)SetUserSelection:(NSArray*)_pUserSelection;

-(void)ShowView;

@end
