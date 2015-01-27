//
//  innerPollView.h
//  MobileBridge
//
//  Created by Lior Lavon on 25/03/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyUIView.h"

@protocol innerPollViewDelegate <NSObject>
@required
- (void)PollUpdateHeight:(int)tag deltaHeight:(int)deltaHeight;
- (void)PollAnswered:(NSString*)messageReplay;
- (void)PollCoverViewClicked;
- (void)PollViewLoadDateTimePicker:(int)_tagView;
@end

@interface innerPollView : MyUIView
{
    __weak id <innerPollViewDelegate> delegate;
}
@property (weak) id <innerPollViewDelegate> delegate;

- (id)initWithFrame:(CGRect)frame viewTag:(int)_viewTag pollId_md5:(NSString*)_pollId_md5 notificationTag:(NSString*)_notificationTag actionType:(int)_actionType couponIdmd5:(NSString*)_couponIdmd5;
-(void)SetPollStrokeWithColor:(BOOL)_strokeStatus stroke_r:(float)_stroke_r stroke_g:(float)_stroke_g stroke_b:(float)_stroke_b;
-(void)EditBoxViewSetDate:(int)viewTag secondsFrom1970:(NSTimeInterval)ti;

@end
