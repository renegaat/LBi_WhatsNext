//
//  RouteViewController.m
//  WhatsNew
//
//  Created by Arjan van Rees on 27-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import "RouteViewController.h"

@interface RouteViewController ()

@end

@implementation RouteViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
    
}

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    // Uber Voucher
    self.uberVoucherButton.adjustsImageWhenHighlighted = NO;
    
    [self.uberVoucherButton setBackgroundImage:[UIImage imageNamed:@"button"] forState:UIControlStateNormal];
    [self.uberVoucherButton setBackgroundImage:[UIImage imageNamed:@"button-selected"] forState:UIControlStateHighlighted];
    [self.uberVoucherButton setTitleColor:[UIColor colorWithRed: 255.0/255.0 green: 255.0/255.0 blue: 255.0/255.0 alpha:1] forState:UIControlStateNormal];
    
    self.uberVoucherButton.titleLabel.font = [UIFont fontWithName:@"Gotham-Book" size:15.0];
    self.uberVoucherButton.hidden = YES;
    
    // Car button
    self.startMapsButton.adjustsImageWhenHighlighted = NO;
    
    [self.startMapsButton setBackgroundImage:[UIImage imageNamed:@"button-alt"] forState:UIControlStateNormal];
    [self.startMapsButton setBackgroundImage:[UIImage imageNamed:@"button-alt-selected"] forState:UIControlStateHighlighted];
    [self.startMapsButton setTitleColor:[UIColor colorWithRed: 255.0/255.0 green: 255.0/255.0 blue: 255.0/255.0 alpha:1] forState:UIControlStateNormal];
    
    self.startMapsButton.titleLabel.font = [UIFont fontWithName:@"Gotham-Book" size:15.0];
    
    // Change Background Image
    if([[UIScreen mainScreen] bounds].size.height == 480) {
        
        self.routeImage.image = [UIImage imageNamed:@"route-2X"];
        
    }
    
    if([[UIScreen mainScreen] bounds].size.height >= 568) {
        
        self.routeImage.image = [UIImage imageNamed:@"route-R4"];

    }
    
}

- (void)didReceiveMemoryWarning {
    
    [super didReceiveMemoryWarning];

}

- (IBAction)startMaps:(id)sender {
    
    UIActionSheet *sheet = [[UIActionSheet alloc] initWithTitle:@"Get directions to Junkersdorfer Strasse 1" delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:nil otherButtonTitles:@"Apple Maps", @"Google Maps", nil];
    
    [sheet showInView:self.view];
    
}

-(void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex {
    
    if (buttonIndex == 0) {
        
        NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:@"http://maps.apple.com/?daddr=Junkersdorfer+Strasse+1,50933+K%%F6ln"]];
        
        if (![[UIApplication sharedApplication] canOpenURL:url]) {
            
            UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Can't Find Apple Maps" message:@"It's impossible for us to start Apple Maps. Use Google Maps instead." delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
            
            [message show];
            
        } else {
            
            [[UIApplication sharedApplication] openURL:url];
            
        }
        
    } else if (buttonIndex == 1) {

        NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:@"comgooglemaps://?saddr=&daddr=Junkersdorfer+Strasse+1,50933+K%%F6ln&directionsmode=driving"]];
        
        if (![[UIApplication sharedApplication] canOpenURL:url]) {
            
            UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Can't Find Google Maps" message:@"It looks like Google Maps isn't installed. Please install Google Maps." delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
            
            [message show];

        } else {
            
            [[UIApplication sharedApplication] openURL:url];
            
        }
        
    }
    
}

@end
