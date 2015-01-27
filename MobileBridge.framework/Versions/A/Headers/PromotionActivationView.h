//
//  PromotionActivationView.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 25-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PromotionActivationViewDelegate <NSObject>
@optional
-(void)ActivateOK:(NSString*)activationCode;
-(void)CloseCouponView:(NSString*)message;
@end

@interface PromotionActivationView : UIView <UITextFieldDelegate>
{
    __weak id <PromotionActivationViewDelegate> delegate;
}
@property (weak) id <PromotionActivationViewDelegate> delegate;

-(void)setCouponId:(int)_couponId;
-(void)setTimeout:(int)_timeoutCounter;
-(void)StartTimeoutCounter;
-(void)setActivationCode:(NSString*)_activationCode;
-(BOOL)CloseViewFromCouponView;
-(void)ScanResult:(NSNotification *)note;
- (id)initWithFrameActivationTypeAndPunch:(CGRect)frame _activationType:(int)_activationType saveId:(int)_saveId isPunched:(int)_isPunched;
@end


