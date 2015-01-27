//
//  MB_WalletView.h
//  MobileBridge
//
//  Created by Lior Lavon on 07/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol MB_WalletViewDelegate <NSObject>
@required
- (void)MB_WalletItemSelected:(NSString*)promotionId;
- (UITableViewCell*)MB_WalletCellView_cellForRowAtIndexPath:(UITableView*)pTableView promotionItem:(NSDictionary*)promotionItem;
- (int)MB_WalletCellView_heightForRowAtIndexPath;
@end


@interface MB_WalletView : UIView <UITableViewDelegate, UITableViewDataSource>
{
    __weak id <MB_WalletViewDelegate> delegate;
}
@property (weak) id <MB_WalletViewDelegate> delegate;

- (id)initWithFrame:(CGRect)frame delegate:(id <MB_WalletViewDelegate>)_delegate;

-(void)SetPromotionType:(int)promotionType tagId:(int)tagId;

@end
