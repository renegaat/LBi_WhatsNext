//
//  lib_HelpView.h
//  ANWB
//
//  Created by Lior Lavon on 10/11/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol lib_HelpViewDelegate <NSObject>
@required
- (void)HelpView_Close:(int)status;
@end

@interface lib_HelpView : UIView
{
    __weak id <lib_HelpViewDelegate> delegate;
    int status;
}
@property (weak) id <lib_HelpViewDelegate> delegate;
@property (nonatomic) int status;

- (id)initWithFrameAndType:(CGRect)frame type:(int)type;

@end
