//
//  DeviceLocation.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 22-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@protocol DeviceLocationDelegate <NSObject>
@required
- (void)DeviceLocationFinished;
@end

@interface DeviceLocation : NSObject <CLLocationManagerDelegate>
{
    __weak id <DeviceLocationDelegate> delegate;
    CLLocationManager *locationManager;
    int locationUpdateCounter;
    BOOL updateLastOnline;
}
@property (weak) id <DeviceLocationDelegate> delegate;
@property (nonatomic, strong) CLLocationManager *locationManager;
@property (nonatomic) BOOL updateLastOnline;
-(id)initDeviceLocation:(BOOL)_updateLastOnline;

@end
