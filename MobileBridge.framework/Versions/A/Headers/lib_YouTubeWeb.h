//
//  lib_YouTubeWeb.h
//  MobileBridge
//
//  Created by Lior Lavon on 30-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface lib_YouTubeWeb : UIWebView
{
}

- (lib_YouTubeWeb *)initWithStringAsURL:(NSString *)urlString frame:(CGRect)frame;
-(void)SetURL:(NSString*)urlString;
@end