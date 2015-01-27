//
//  ScannerView.h
//  MobileBridge
//
//  Created by Lior Lavon on 23/08/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVcaptureSession.h>
#import <AVFoundation/AVFoundation.h>

@protocol ScannerViewDelegate <NSObject>
@optional
- (void)ScanningFinished;
@end

@interface ScannerView : UIView <AVCaptureMetadataOutputObjectsDelegate>
{
    __weak id <ScannerViewDelegate> delegate;
}
@property (weak) id <ScannerViewDelegate> delegate;

@end
