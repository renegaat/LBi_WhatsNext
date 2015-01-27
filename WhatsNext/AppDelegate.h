//
//  AppDelegate.h
//  WhatsNext
//
//  Created by Arjan van Rees on 22-09-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyAlertView.h"
#import "MainViewController.h"
#import <MobileBridge/MobileBridge.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate, MobileBridgeLibraryDelegate> {
    MobileBridgeLibrary* mbLib;
}

@property (strong, nonatomic) UIWindow *window;
@property (nonatomic, retain) MobileBridgeLibrary* mbLib;

- (void)MB_SettingEventReply:(NSDictionary*)response;
- (void)MB_NetworkAlertPrompt:(int)alertId;
- (void)MB_LocationUpdate:(int)position max:(int)max;

@end

