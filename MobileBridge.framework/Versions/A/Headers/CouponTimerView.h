//
//  CouponTimerView.h
//  template
//
//  Created by Lior Lavon on 12/6/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyUIView.h"

@protocol CouponTimerViewDelegate <NSObject>
@optional
- (void)CouponTimerViewUpdateHeight:(int)tag height:(float)height;
@end

@interface CouponTimerView : MyUIView
{
    __weak id <CouponTimerViewDelegate> delegate;
}
@property (weak) id <CouponTimerViewDelegate> delegate;

- (id)initWithFrameAndData:(CGRect)frame tagId:(int)_tagId expirationTime:(double)_expirationTime fontStyle:(NSDictionary*)pFontStyle;
-(void)SetStrokeParam:(BOOL)_stroke radius:(int)_radius color:(UIColor*)color;

-(void)StartTimer;
-(void)StopTimer;

@end
