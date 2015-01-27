//
//  RouteViewController.h
//  WhatsNew
//
//  Created by Arjan van Rees on 27-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface RouteViewController : UIViewController <UIActionSheetDelegate>

@property (strong, nonatomic) IBOutlet UIImageView *routeImage;
@property (strong, nonatomic) IBOutlet UIButton *uberVoucherButton;
@property (strong, nonatomic) IBOutlet UIButton *startMapsButton;

- (IBAction)startMaps:(id)sender;

@end
