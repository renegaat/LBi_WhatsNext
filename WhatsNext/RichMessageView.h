//
//  RichMessageView.h
//  TestApp
//
//  Created by Lior Lavon on 11/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MobileBridge/MobileBridge.h>

@interface RichMessageView : UIViewController <UINavigationBarDelegate>

-(void)SetRichMessageData:(RichMessageViewFromType)_viewFrom data:(NSString*)_data;
// -(void)SetRichMessageId:(int)_richMessageId;
// -(void)SetRichMessageNotificationData:(NSDictionary*)_pNotification;

@end
