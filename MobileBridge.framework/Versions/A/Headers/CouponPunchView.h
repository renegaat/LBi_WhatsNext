//
//  CouponPunchView.h
//  MobileBridge
//
//  Created by Lior Lavon on 12/24/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyUIView.h"
#import "PunchView.h"

@protocol CouponPunchViewDelegate <NSObject>
@required
- (void)PunchActivation:(int)status;
- (void)CouponPunchViewUpdateHeight:(int)tag height:(float)height;
@end

@interface CouponPunchView : MyUIView <PunchViewDelegate>
{
    __weak id <CouponPunchViewDelegate> delegate;
}
@property (weak) id <CouponPunchViewDelegate> delegate;

- (id)initWithFrame:(CGRect)frame tagId:(int)_tagId actionType:(int)_actionType strokeStatus:(BOOL)_strokeStatus strokeColor:(UIColor*)_strokeColor fillColor:(UIColor*)_fillColor activeColor:(int)_activeColor inactiveColor:(int)_inactiveColor freeColor:(int)_freeColor;
-(void)SetPunchData:(int)_max_uses use_count:(int)_use_count;

@end
