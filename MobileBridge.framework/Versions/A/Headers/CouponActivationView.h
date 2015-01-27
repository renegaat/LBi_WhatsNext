//
//  CouponActivationView.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 25-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AsyncPost.h"
#import "AlertView.h"

@protocol CouponActivationViewDelegate <NSObject>
@optional
-(void)ActivateOK:(NSString*)activationCode;
-(void)CloseCouponView:(NSString*)message;
@end

@interface CouponActivationView : UIView <AsyncPostDelegate, AlertViewDelegate, UITextFieldDelegate>
{
    __weak id <CouponActivationViewDelegate> delegate;
}
@property (weak) id <CouponActivationViewDelegate> delegate;

-(int)SetActivationBarcode:(NSString *)aCode fakeACode:(NSString*)fakeACode;
-(void)setCouponId:(int)_couponId;
-(void)setTimeoutCounter:(int)_timeoutCounter;
-(void)setActivationCode:(NSString*)_activationCode;
-(BOOL)CloseViewFromCouponView;
-(void)ScanResult:(NSNotification *)note;
- (id)initWithFrameActivationTypeAndPunch:(CGRect)frame _activationType:(int)_activationType isPunched:(int)_isPunched;
@end


