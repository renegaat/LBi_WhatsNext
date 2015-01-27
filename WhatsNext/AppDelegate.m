//
//  AppDelegate.m
//  WhatsNext
//
//  Created by Arjan van Rees on 22-09-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

@synthesize mbLib;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
    
    // NavigationBar styling
    [[UINavigationBar appearance] setBackgroundImage:[UIImage imageNamed:@"navbar-top"] forBarMetrics:UIBarMetricsDefault];
    [[UINavigationBar appearance] setShadowImage:[UIImage imageNamed:@"navbar-top-shadow"]];
    
    [[UINavigationBar appearance] setTintColor:[UIColor colorWithRed:255.0/255.0 green:255.0/255.0 blue:255.0/255.0 alpha:1]];
    
    [[UINavigationBar appearance] setTitleTextAttributes: [NSDictionary dictionaryWithObjectsAndKeys: [UIColor colorWithRed: 255.0/255.0 green: 255.0/255.0 blue: 255.0/255.0 alpha: 1.0], NSForegroundColorAttributeName, [UIFont fontWithName: @"Gotham-Book" size: 17.0], NSFontAttributeName, nil]];
    
    [[UINavigationBar appearance] setBackIndicatorImage:[UIImage imageNamed:@"navbar-button-back"]];
    [[UINavigationBar appearance] setBackIndicatorTransitionMaskImage:[UIImage imageNamed:@"navbar-button-back"]];
    
    // TabBar styling
    [[UITabBar appearance] setBackgroundImage:[UIImage imageNamed:@"tabbar"]];
    [[UITabBar appearance] setShadowImage:[UIImage imageNamed:@"tabbar-shadow"]];
    
    [[UITabBar appearance] setTintColor:[UIColor colorWithRed: 118.0/255.0 green: 116.0/255.0 blue: 115.0/255.0 alpha:1]];
    [[UITabBar appearance] setSelectedImageTintColor:[UIColor colorWithRed:237.0/255.0 green:28.0/255.0 blue:38.9/255.0 alpha:1]];
    
    [[UITabBarItem appearance] setTitleTextAttributes:[NSDictionary dictionaryWithObjectsAndKeys:[UIFont fontWithName:@"Gotham-Book" size:10], NSFontAttributeName, nil] forState:UIControlStateNormal];
    
    // Segmented Control styling
    [[UISegmentedControl appearance] setTitleTextAttributes:[NSDictionary dictionaryWithObjectsAndKeys:[UIFont fontWithName:@"Gotham-Book" size:13.0], NSFontAttributeName, nil] forState:UIControlStateNormal];
    [[UISegmentedControl appearance] setBackgroundImage:[UIImage imageNamed:@"segmented-control"] forState:UIControlStateNormal barMetrics:UIBarMetricsDefault];
    [[UISegmentedControl appearance] setBackgroundImage:[UIImage imageNamed:@"segmented-control-selected"] forState:UIControlStateSelected barMetrics:UIBarMetricsDefault];
    [[UISegmentedControl appearance] setBackgroundImage:[UIImage imageNamed:@"segmented-control-highlighted"] forState:UIControlStateHighlighted barMetrics:UIBarMetricsDefault];
    
    [[UISegmentedControl appearance] setDividerImage:[UIImage imageNamed:@"segmented-control-divider"] forLeftSegmentState:UIControlStateNormal rightSegmentState:UIControlStateNormal barMetrics:UIBarMetricsDefault];
    [[UISegmentedControl appearance] setDividerImage:[UIImage imageNamed:@"segmented-control-divider"] forLeftSegmentState:UIControlStateSelected rightSegmentState:UIControlStateNormal barMetrics:UIBarMetricsDefault];
    [[UISegmentedControl appearance] setDividerImage:[UIImage imageNamed:@"segmented-control-divider"] forLeftSegmentState:UIControlStateNormal rightSegmentState:UIControlStateSelected barMetrics:UIBarMetricsDefault];
    
    // Init MobileBridge Library
    NSString* activationCode = @"mGAC9vdmlvLI8VqbftlrM3zrGBrDXuZ0pGMX5G6GvtXox4acWNZi/8U1BEZ3x8CW";
    
    mbLib = [MobileBridgeLibrary InitLibrary:activationCode];
    if(mbLib!=nil) {
        
        mbLib.delegate = self;
        
        [mbLib MB_SetApplicationName:@"What's Next"];
        [mbLib MB_ClearUserHistory];
        
        [self performSelector:@selector(StartBeaconRanging) withObject:nil afterDelay:3.0];
        
        NSLog(@"Library initiated properly");
        
    } else {
        
        NSLog(@"%@",@"MobileBridge Library failed initialization.");
        
    }
    
    [self performSelector:@selector(RegisterForPushNotification) withObject:nil afterDelay:1.0];
    
    NSDictionary *remoteNotif = [launchOptions valueForKey:UIApplicationLaunchOptionsRemoteNotificationKey];
    
    if (remoteNotif!=nil) {
        [self performSelector:@selector(PerformNotificationCommand:) withObject:[remoteNotif objectForKey:@"extra"] afterDelay:1];
    }
    
    UILocalNotification *localNotif = [launchOptions objectForKey:UIApplicationLaunchOptionsLocalNotificationKey];
    
    if (localNotif!=nil) {
        [self performSelector:@selector(PerformNotificationCommand:) withObject:localNotif.userInfo afterDelay:1];
    }
    
    // MobileBridge Colors
    [self SetColorTemplate];
    
    return YES;
}

-(void)PerformNotificationCommand:(NSDictionary*)pPayload {
    [[NSNotificationCenter defaultCenter]postNotificationName:@"performNotification" object:pPayload];
}

-(void)StartBeaconRanging {
    [mbLib MB_SetBeaconReminderEnabled:TRUE delegate:self showAlert:FALSE];
    
    NSLog(@"StartBeaconRanging");
}

-(void)RegisterForPushNotification {
    
    if([mbLib MB_GetNotificationStatus] == YES) {
        
        NSLog(@"Registering for push notifications...");
        
        if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0) {
            [[UIApplication sharedApplication] registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge) categories:nil]];
            [[UIApplication sharedApplication] registerForRemoteNotifications];
        } else {
            [[UIApplication sharedApplication] registerForRemoteNotificationTypes:(UIUserNotificationTypeBadge | UIUserNotificationTypeSound | UIUserNotificationTypeAlert)];
        }
        
    } else {
        
        NSLog(@"User notifications are not enabled");
        
    }
    
}

- (void)application:(UIApplication *)app didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [mbLib MB_SetToken:[NSString stringWithFormat:@"%@",deviceToken]];
    NSLog(@"%@",[NSString stringWithFormat:@"Device Token=%@",deviceToken]);
}

- (void)application:(UIApplication *)app didFailToRegisterForRemoteNotificationsWithError:(NSError *)err {
    NSString *str = [NSString stringWithFormat: @"Error: %@", err];
    NSLog(@"%@",str);
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    
    if ( application.applicationState == UIApplicationStateActive ) {
        NSString* msg = [[NSString alloc] initWithString:[((NSDictionary*)[((NSDictionary*) [userInfo objectForKey:@"aps"]) objectForKey:@"alert"]) objectForKey:@"body"]];
        
        MyAlertView *pAlert = [[MyAlertView alloc] initWithTitle:@"What's Next" message:msg delegate:self cancelButtonTitle:NSLocalizedString(@"Close", @"") otherButtonTitles:NSLocalizedString(@"View", @""), nil];
        
        [pAlert SetPayload:[userInfo objectForKey:@"extra"]];
        
        pAlert.delegate = self;
        [pAlert show];
    } else {
        [[NSNotificationCenter defaultCenter]postNotificationName:@"performNotification" object:[userInfo objectForKey:@"extra"]];
    }
    
}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {
    
    if ( application.applicationState == UIApplicationStateActive ) {
        MyAlertView *pAlert = [[MyAlertView alloc] initWithTitle:@"What's Next" message:notification.alertAction delegate:self cancelButtonTitle:NSLocalizedString(@"Close", @"") otherButtonTitles:NSLocalizedString(@"View", @""), nil];
        
        [pAlert SetPayload:notification.userInfo];
        
        pAlert.delegate = self;
        [pAlert show];
    } else {
        [[NSNotificationCenter defaultCenter]postNotificationName:@"performNotification" object:notification.userInfo];
    }
    
}

- (void)alertView:(UIAlertView *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex {
    
    if (buttonIndex != 0) {
        NSDictionary* pPayload = [[NSDictionary alloc] initWithDictionary:[(MyAlertView*)actionSheet GetPayload]];
        [[NSNotificationCenter defaultCenter]postNotificationName:@"performNotification" object:pPayload];
    }
    
}

-(void)SetColorTemplate {
    
    //Retrieve the AppDelegate class
    AppDelegate *pAppDelegate = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    
    // Define the array that will hold the colors
    NSMutableArray *pColorTemplate = [[NSMutableArray alloc] init];
    
    // Tab Colors
    [self AddColor:pColorTemplate key:@"SEGMENTED_COLOR" value:0xFFB6B4B3];
    [self AddColor:pColorTemplate key:@"SEGMENTED_COLOR_BORDER" value:0xFFB6B4B3];
    [self AddColor:pColorTemplate key:@"SEGMENTED_TITLE_COLOR_SELECTED" value:0xFFFFFFFF];
    [self AddColor:pColorTemplate key:@"SEGMENTED_TITLE_COLOR_NOT_SELECTED" value:0xFFB6B4B3];
    
    // Wallet Colors
    [self AddColor:pColorTemplate key:@"ALARM_ICON_ON_BACK_COLOR" value:0xFFFFFFFF];
    [self AddColor:pColorTemplate key:@"PIN_ICON_ON_BACK_COLOR" value:0xFFFFFFFF];
    [self AddColor:pColorTemplate key:@"WALLET_LIST_CELL_ACTIVATION_COLOR" value:0xFFFFFFFF];
    [self AddColor:pColorTemplate key:@"WALLET_LIST_EMPTY_MESSAGE_COLOR" value:0xFFB6B4B3];
    
    // Call MB_SetColorTemplate:
    [pAppDelegate.mbLib MB_SetColorTemplate:pColorTemplate];
    
}

-(void)AddColor:(NSMutableArray*)pColorTemplate key:(NSString*)key value:(int)value {
    
    NSDictionary *pColorItem = [[NSDictionary alloc] initWithObjectsAndKeys:key, @"key", [NSNumber numberWithInt:value], @"value", nil];
    [pColorTemplate addObject:pColorItem];
    
}

- (void)MB_SettingEventReply:(NSDictionary*)response {
    
}

- (void)MB_NetworkAlertPrompt:(int)alertId {
    
}

- (void)MB_LocationUpdate:(int)position max:(int)max {
    
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
