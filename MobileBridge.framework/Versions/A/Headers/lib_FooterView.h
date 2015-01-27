//
//  lib_FooterView.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 23-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol lib_FooterViewDelegate <NSObject>
@optional
-(void)ClearCouponSelected;
@end

@interface lib_FooterView : UIView
{
    __weak id <lib_FooterViewDelegate> delegate;
}

@property (weak) id <lib_FooterViewDelegate> delegate;

-(void)AddCouponClearButton;
-(void)UpdateBackgroundColor:(int)bColor;
-(void)SetLabel:(NSString*)pMessage;
-(void)SetEmptyBackground;
-(void)SetActivityView;

@end
