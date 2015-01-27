//
//  CouponStatusIconView.h
//  template
//
//  Created by Lior Lavon on 12/9/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyUIView.h"

@protocol CouponStatusIconViewDelegate <NSObject>
@optional
-(void)ShowAlertView:(NSString*)title msg:(NSString*)msg;
@end

@interface CouponStatusIconView : MyUIView
{
    __weak id <CouponStatusIconViewDelegate> delegate;
}
@property (weak) id <CouponStatusIconViewDelegate> delegate;

-(void)SetStatus:(int)status;
- (id)initWithFrame:(CGRect)frame type:(NSString*)_type imageUrl:(NSString*)imageUrl imageName:(NSString*)imageName onColor:(UIColor*)_onColor offColor:(UIColor*)_offColor radius:(int)_radius strokeStatus:(BOOL)_strokeStatus strokeColor:(UIColor*)_strokeColor;

@end
