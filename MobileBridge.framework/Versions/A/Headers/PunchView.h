//
//  PunchView.h
//  MobileBridge
//
//  Created by Lior Lavon on 8/14/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PunchViewDelegate <NSObject>
@optional
-(void)PunchActivation:(int)status;
@end

@interface PunchView : UIView
{
    __weak id <PunchViewDelegate> delegate;
    unsigned int fill_R,fill_G,fill_B,fill_A;
}
@property (weak) id <PunchViewDelegate> delegate;
-(void)setStatus:(int)_status color:(int)_color;
-(void)setPosition:(int)_position;


@end
