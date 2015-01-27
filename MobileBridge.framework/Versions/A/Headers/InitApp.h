//
//  InitApp.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 23-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocationManager.h"


@protocol InitAppDelegate <NSObject>
@required
- (void)InitAppFinished;
@end

@interface InitApp : NSObject
{
    __weak id <InitAppDelegate> delegate;
}
@property (weak) id <InitAppDelegate> delegate;

-(id)initApp:(id <LocationManagerDelegate>)_delegate;

@end
