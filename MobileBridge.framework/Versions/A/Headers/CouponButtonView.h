//
//  CouponButtonView.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 25-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyUIView.h"

@protocol CouponButtonViewDelegate <NSObject>
@optional
-(void)CouponButtonActivate:(NSString*)action;
-(void)SetScrollEnable:(BOOL)enable;
-(void)PollButtonClicked:(NSString*)action;
@end

@interface CouponButtonView : MyUIView <UITextViewDelegate>
{
    __weak id <CouponButtonViewDelegate> delegate;
}
@property (weak) id <CouponButtonViewDelegate> delegate;

- (id)initWithFrame:(CGRect)frame action:(NSString*)_action fillColor:(UIColor*)_fillColor strokeStatus:(BOOL)_strokeStatus strokeColor:(UIColor*)_strokeColor knobColor:(UIColor*)_knobColor radius:(int)_radius type:(NSString*)_type  fontStyle:(NSDictionary*)pFontStyle gradient:(int)_gradient disclosur:(int)_disclosur disclosurColor:(UIColor*)_disclosurColor;
-(void)SetLabel:(NSString*)_strLabel;
-(UIColor *)GetDarkerColorForColor:(UIColor *)c;

-(void)SetYouTubePlayer:(NSString*)pUrl;
-(void)setPollFlag:(int)_pollFlag;

@end
