//
//  CouponScratchView.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 25-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AsyncPost.h"
#import "AlertView.h"
#import "MyUIView.h"

@protocol CouponScratchViewDelegate <NSObject>
@required
-(void)GamePlayed:(float)newPrice;
-(void)SetScrollEnable:(BOOL)enable;
-(void)ShowAlertView:(NSString*)title msg:(NSString*)msg;
@end


@interface CouponScratchView : MyUIView <AsyncPostDelegate, AlertViewDelegate>
{
    __weak id <CouponScratchViewDelegate> delegate;
}
@property (weak) id <CouponScratchViewDelegate> delegate;

- (id)initWithFrame:(CGRect)frame actionType:(int)_actionType imageUrl:(NSString*)_imageUrl imageName:(NSString*)_imageName strokeStatus:(BOOL)_strokeStatus strokeColor:(UIColor*)_strokeColor radius:(int)_radius;
-(void)SetCouponInfo:(NSString*)_couponIdMD5 fp:(BOOL)_fp;
-(void)setActionType:(int)_actionType;
-(void)Stop;
-(BOOL)CanCloseView;

@end
