//
//  lib_GroupCBView
//  ConnexxtionTV
//
//  Created by Eyal Oster on 10-01-12.
//  Copyright (c) 2012 Ai-Pixel B.V. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "lib_UICheckView.h"

@protocol lib_GroupCBViewDelegate <NSObject>
@optional
-(void)GroupCBView_UserSelect:(int)parentRow r:(int)r;

@end



@interface lib_GroupCBView : UIView <UITableViewDelegate, UITableViewDataSource, lib_UICheckViewDelegate>
{
    int groupCBType;
    __weak id <lib_GroupCBViewDelegate> delegate;
    int row;
}
@property (nonatomic) int groupCBType;
@property (weak) id <lib_GroupCBViewDelegate> delegate;
@property (nonatomic) int row;

- (id)initWithFrameAndArray:(CGRect)frame groupCBType:(int)_groupCBType fontStyle:(NSDictionary*)_fontStyle indicator_color:(NSDictionary*)_indicator_color optionArr:(NSArray*)optionArr;
- (void)SetUserSelection:(NSArray*)_pUserSelection;

-(void)ShowView;

@end
