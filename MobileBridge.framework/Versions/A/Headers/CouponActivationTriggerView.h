//
//  CouponActivationTriggerView.h
//  MobileBridge
//
//  Created by Lior Lavon on 06-06-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CouponActivationTriggerViewDelegate <NSObject>
@required
- (void)ActivationTriggerViewOK; // close the view and open the activation view
@end

@interface CouponActivationTriggerView : UIView <UITextFieldDelegate>
{
     __weak id <CouponActivationTriggerViewDelegate> delegate;
}
@property (weak) id <CouponActivationTriggerViewDelegate> delegate;
- (id)initWithFrameAndCode:(CGRect)frame code:(NSString*)code;
-(void)ScanResult:(NSNotification *)note;

@end
