//
//  MainViewController.h
//  WhatsNext
//
//  Created by Arjan van Rees on 22-09-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import "PromotionView.h"
#import "SurveyView.h"
#import "RichMessageView.h"

@interface MainViewController : UITabBarController

- (void)PerformNotificationCommand:(NSDictionary*)pNotificationData;
- (void)NotificationCommandReceived:(NSNotification *)note;

@end
