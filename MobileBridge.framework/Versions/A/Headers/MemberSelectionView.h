//
//  MemberSelectionView.h
//  MobileBridge
//
//  Created by Lior Lavon on 9/8/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MemberSelectionViewDelegate <NSObject>
@optional
- (void)clickedButtonAtIndex:(id)view viewTag:(int)viewTag index:(int)index;
@end


@interface MemberSelectionView : UIView
{
    __weak id <MemberSelectionViewDelegate> delegate;
}
@property (weak) id <MemberSelectionViewDelegate> delegate;

- (id)initWithFrameAndData:(CGRect)frame viewtag:(int)_viewtag _title:(NSString*)_title _description1:(NSMutableAttributedString*)_description1 _description2:(NSString*)_description2 _pButtonArray:(NSArray*)_pButtonArray;
- (id)initWithFrameIconAndString:(CGRect)frame viewtag:(int)_viewtag _icon:(UIImage*)_icon _description1:(NSMutableAttributedString*)_description1 _description2:(NSString*)_description2;

@end
