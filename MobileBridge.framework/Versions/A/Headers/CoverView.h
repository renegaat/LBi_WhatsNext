//
//  CoverView.h
//  MobileBridge
//
//  Created by Lior Lavon on 04/04/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CoverViewDelegate <NSObject>
@required
-(void)CoverViewClicked;
@end

@interface CoverView : UIView
{
    __weak id <CoverViewDelegate> delegate;
}
@property (weak) id <CoverViewDelegate> delegate;

@end
