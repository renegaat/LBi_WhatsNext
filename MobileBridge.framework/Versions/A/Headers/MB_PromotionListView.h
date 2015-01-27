//
//  MB_PromotionListView.h
//  MobileBridge
//
//  Created by Lior Lavon on 9/19/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MB_PromotionListViewDelegate <NSObject>
@optional
- (void)MB_PromotionListItemSelected:(NSString*)promotionIdMD5;
- (int)MB_PromotionListCellView_heightForRowAtIndexPath;
- (UITableViewCell*)MB_PromotionListCellView_cellForRowAtIndexPath:(UITableView*)pTableView promotionItem:(NSDictionary*)promotionItem;
@end

@interface MB_PromotionListView : UIView <UITableViewDelegate, UITableViewDataSource>
{
    __weak id <MB_PromotionListViewDelegate> delegate;
}
@property (weak) id <MB_PromotionListViewDelegate> delegate;

- (id)initWithFrame:(CGRect)frame delegate:(id <MB_PromotionListViewDelegate>)_delegate;
- (void)FilterByTag:(int)tagId;

@end
