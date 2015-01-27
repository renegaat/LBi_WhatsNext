//
//  MB_WalletView_uiview.h
//  MobileBridge
//
//  Created by Lior Lavon on 07/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SyncPromotions.h"

@protocol MB_WalletViewDelebate <NSObject>
@required
- (void)MB_WalletItemSelected:(NSString*)promotionIdMD5;
@end

@interface MB_WalletView_uiview : UIView <UITableViewDelegate, UITableViewDataSource, SyncPromotionsDelegate>
{
    __weak id <MB_WalletViewDelebate> delegate;
}
@property (weak) id <MB_WalletViewDelebate> delegate;

- (id)initWithFrame:(CGRect)frame delegate:(id <MB_WalletViewDelebate>)_delegate;

-(void)reloadData;

-(void)UpdatePromotionList:(int)promotionType;
-(void)StartView;
-(void)StopView;

@end
