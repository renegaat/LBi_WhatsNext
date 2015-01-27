//
//  CouponLabelView.h
//  template
//
//  Created by Lior Lavon on 12/6/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyUIView.h"

@protocol CouponLabelViewDelegate <NSObject>
@optional
- (void)CouponLabelViewUpdateHeight:(int)tag height:(float)height;
@end

@interface CouponLabelView : MyUIView
{
    __weak id <CouponLabelViewDelegate> delegate;
}
@property (weak) id <CouponLabelViewDelegate> delegate;

- (id)initWithFrameAndData:(CGRect)frame tagId:(int)_tagId text:(NSString*)_text heightType:(NSString*)_heightType fontStyle:(NSDictionary*)pFontStyle stroke:(BOOL)_stroke radius:(int)_radius color:(UIColor*)color;
@end
