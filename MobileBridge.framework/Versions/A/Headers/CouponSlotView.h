//
//  CouponSlotView.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 25-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AsyncPost.h"
#import "AlertView.h"
#import "MyUIView.h"

@protocol CouponSlotViewDelegate <NSObject>
@required
-(void)GamePlayed:(float)newPrice;
-(void)ShowAlertView:(NSString*)title msg:(NSString*)msg;
@end

@interface CouponSlotView : MyUIView <UIScrollViewDelegate, AlertViewDelegate, AsyncPostDelegate>
{
    __weak id <CouponSlotViewDelegate> delegate;
}
@property (weak) id <CouponSlotViewDelegate> delegate;

- (id)initWithFrame:(CGRect)frame actionType:(int)_actionType strokeStatus:(BOOL)_strokeStatus strokeColor:(UIColor*)_strokeColor;
-(void)SetCouponInfo:(NSString*)_couponIdMD5 fp:(BOOL)_fp;
-(void)StartSpin;
-(void)StopSpin;
-(BOOL)CanCloseView;

@end
