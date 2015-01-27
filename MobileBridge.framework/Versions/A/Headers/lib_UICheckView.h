//
//  lib_UICheckView.h
//  KnapWerk
//
//  Created by Eyal Oster on 06-11-11.
//  Copyright (c) 2011 Ai-Pixel B.V. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol lib_UICheckViewDelegate <NSObject>
@optional
-(void)CheckBoxSelected:(UIView*)view row:(int)row status:(int)status parentRow:(int)parentRow;
@end

@interface lib_UICheckView : UIView
{
    __weak id <lib_UICheckViewDelegate> delegate;
    
}
@property (weak) id <lib_UICheckViewDelegate> delegate;

-(void)SetRow:(int)_row;
-(void)SetStatus:(int)stat;
-(void)setParentRow:(int)_parentRow;
- (id)initWithFrame:(CGRect)frame imageType:(int)_imageType indicator_color:(NSDictionary*)_indicator_color;

@end
