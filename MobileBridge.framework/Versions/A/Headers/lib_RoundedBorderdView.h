//
//  lib_RoundedBorderdView.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 25-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyUIView.h"

@interface lib_RoundedBorderdView : MyUIView <UITextViewDelegate>
{
    unsigned int fill_R,fill_G,fill_B,fill_A; // fill
    unsigned int stroke_R,stroke_G,stroke_B,stroke_A; // stroke
    BOOL stroke;
    int corner;
}

@property (nonatomic) BOOL stroke;
@property (nonatomic) int radius;

- (id)initWithFrameAndRGBAndStrokeAndRadius:(CGRect)frame r:(float)_r g:(float)_g b:(float)_b a:(float)_a stroke:(BOOL)_stroke radius:(int)_radius gradient:(int)_gradient;
- (id)initWithFrameAndColorAndStrokeAndRadius:(CGRect)frame color:(unsigned int)_color stroke:(BOOL)_stroke radius:(int)_radius;

-(void)SetStrokeColorWithRed:(float)_r green:(float)_g blue:(float)_b alfa:(float)_a;
-(void)SetStrokeColorWithColor:(unsigned int)_color;

@end
