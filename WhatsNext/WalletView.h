//
//  WalletView.h
//  WhatsNew
//
//  Created by Arjan van Rees on 09-09-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import "PromotionView.h"
#import <MobileBridge/MB_WalletView.h>

@interface WalletView : UIViewController <MB_WalletViewDelegate, PromotionViewDelegate>

- (IBAction)clearButton:(id)sender;

@end
