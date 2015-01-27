//
//  MySliderView.h
//  MobileBridge
//
//  Created by Eyal Oster on 24-01-12.
//  Copyright (c) 2012 Ai-Pixel B.V. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MySliderViewDelegate <NSObject>
@optional
-(void)SliderPosition:(int)row pos:(int)pos pScaleTitle:(UILabel*)pScaleTitle;
@end


@interface MySliderView : UIView
{
    __weak id <MySliderViewDelegate> delegate;
}
@property (weak) id <MySliderViewDelegate> delegate;

-(void)SetRow:(int)_row;
-(void)SetStepCount:(int)_stepCount;
-(void)SetScaleTitle:(UILabel *)_pScaleTitle;
-(void)SetDogPosition:(int)_dogPosition;
@end
