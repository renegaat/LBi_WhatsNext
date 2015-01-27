//
//  CouponTabView.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 25-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyUIView.h"

@protocol CouponTabViewDelegate <NSObject>
@optional
-(void)CouponTabViewChangeHeight:(int)tag deltaHeight:(float)deltaHeight;
@end

@interface CouponTabView : MyUIView <UIWebViewDelegate>
{
    __weak id <CouponTabViewDelegate> delegate;
}
@property (weak) id <CouponTabViewDelegate> delegate;

- (id)initWithFrameAndDataAndStroke:(CGRect)frame tagId:(int)_tagId data:(NSString*)_data fillColor:(UIColor*)_fillColor strokeColor:(UIColor*)_strokeColor strokeStatus:(BOOL)strokeStatus pFontStyle:(NSDictionary*)pFontStyle;
@end
