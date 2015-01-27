//
//  MB_LocationView.h
//  MobileBridge
//
//  Created by Lior Lavon on 9/19/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MB_LocationViewDelegate <NSObject>
@required
- (void)MB_LocationView_LocationSelected:(NSDictionary*)pLocation;
- (int)MB_LocationCellView_heightForRowAtIndexPath;
- (UITableViewCell*)MB_LocationCellView_cellForRowAtIndexPath:(UITableView*)pTableView locationItem:(NSDictionary*)locationItem;
@end

@interface MB_LocationView : UIView <UITableViewDelegate, UITableViewDataSource>
{
    __weak id <MB_LocationViewDelegate> delegate;
}
@property (weak) id <MB_LocationViewDelegate> delegate;

- (id)initWithFrame:(CGRect)frame delegate:(id <MB_LocationViewDelegate>)_delegate promotionId:(NSString*)_promotionId;

@end
