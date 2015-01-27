//
//  LocationManager.h
//  MobileBridge
//
//  Created by Lior Lavon on 24-03-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "lib_OpeningHoursType.h"

@protocol LocationManagerDelegate <NSObject>
@required
- (void)LocationManagerUpdate:(int)position max:(int)max;
- (void)LocationManagerFinished;
@end

@interface LocationManager : NSObject 
{
    __weak id <LocationManagerDelegate> delegate;
}
@property (weak) id <LocationManagerDelegate> delegate;

-(id)initLocationManager;
-(void)GetLocationList;
-(NSMutableArray*)ConstractOpeningHoursType:(int)locationId openingHoursArr:(NSArray*)pOpeningHoursArr;
-(void)ParsResult:(NSDictionary*)data;
@end
