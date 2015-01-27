//
//  lib_YouTubeView.h
//  MobileBridge
//
//  Created by Lior Lavon on 30-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "lib_YouTubeWeb.h"

@protocol lib_YouTubeViewDelegate <NSObject>
@optional
-(void)CloseVideoView;
@end


@interface lib_YouTubeView : UIView <UIWebViewDelegate>
{
    __weak id <lib_YouTubeViewDelegate> delegate;
    
    UIWebView* pWebView;
    lib_YouTubeWeb* pYoutubeView;
    NSString* pUrl;
    int webViewFinished;
    
}
@property (weak) id <lib_YouTubeViewDelegate> delegate;
@property (nonatomic, strong) NSString* pUrl;

- (id)initWithFrame:(CGRect)frame;
-(void)SetURL:(NSString*)url;

@end
