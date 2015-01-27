//
//  SegmentedControl.h
//  MobileBridge
//
//  Created by Lior Lavon on 7/29/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SegmentedControlDelegate <NSObject>
@required
- (void)SegmentSelected:(int)selectedPos;
@end

@interface SegmentedControl : UIView
{
    __weak id <SegmentedControlDelegate> delegate;
}
@property (weak) id <SegmentedControlDelegate> delegate;

- (id)initWithFrameAndTabCount:(CGRect)frame tabCount:(int)_tabCount strokeColor:(int)_strokeColor;
-(void)setSelectedSegmentIndex:(int)selectPos;
-(int)getSelected;

@end
