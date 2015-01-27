//
//  CouponImageView.h
//  template
//
//  Created by Lior Lavon on 12/4/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyUIView.h"

@protocol CouponImageViewDelegate <NSObject>
@optional
- (void)ImageButtonClicked:(int)answerId;
@end

@interface CouponImageView : MyUIView
{
    __weak id <CouponImageViewDelegate> delegate;
}
@property (weak) id <CouponImageViewDelegate> delegate;

- (id)initWithFrameAndData:(CGRect)frame imageUrl:(NSString*)imageUrl imageName:(NSString*)imageName radius:(int)radius strokeStatus:(BOOL)strokeStatus strokeColor:(UIColor*)strokeColor;

-(void)setImageButtonFlag:(int)_imageButtonFlag answerId:(int)_answerId pollQuestionType:(NSString*)_pollQuestionType;
-(BOOL)isSelected;
-(int)GetAnswerId;

@end
