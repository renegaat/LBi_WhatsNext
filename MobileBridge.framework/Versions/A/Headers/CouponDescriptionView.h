//
//  CouponDescriptionView.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 25-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyUIView.h"

@protocol CouponDescriptionViewDelegate <NSObject>
@optional
-(void)CouponDescriptionViewChangeHeight:(int)tag deltaHeight:(float)deltaHeight;
@end

@interface CouponDescriptionView : MyUIView <UIWebViewDelegate>
{
    __weak id <CouponDescriptionViewDelegate> delegate;
}
@property (weak)id <CouponDescriptionViewDelegate> delegate;

- (id)initWithFrameAndData:(CGRect)frame tagId:(int)_tagId desc:(NSString*)desc fillColor:(UIColor*)_fillColor strokeStatus:(BOOL)_strokeStatus strokeColor:(UIColor*)_strokeColor radius:(int)_radius;

@end
