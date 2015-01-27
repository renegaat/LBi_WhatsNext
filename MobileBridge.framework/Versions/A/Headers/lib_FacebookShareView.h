//
//  lib_FacebookShareView.h
//  MobileBridge
//
//  Created by Lior Lavon on 29-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

#define UIColorFromRGB(rgbValue) \
[UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 \
alpha:1.0]

@protocol lib_FBShareViewDelegate <NSObject>
@required
-(void)FBDialogDidNotComplete;
-(void)FBDialogCompleteWithUrl:(int)status;
@end

@interface lib_FacebookShareView : UIViewController <UITextViewDelegate>
{
    __weak id <lib_FBShareViewDelegate> delegate;
    UITextView* pPostMessage;
    UIImageView* pPostImageView;
    NSMutableDictionary *postParams;
    UIColor* color;
    NSMutableData *imageData;
    NSURLConnection *imageConnection;
}
@property (weak) id <lib_FBShareViewDelegate> delegate;
@property (nonatomic, strong) UITextView* pPostMessage;
@property (nonatomic, strong) NSMutableDictionary* postParams;
@property (nonatomic, strong) NSMutableData *imageData;
@property (nonatomic, strong) NSURLConnection *imageConnection;
@property (nonatomic, strong) UIImageView* pPostImageView;

@end
