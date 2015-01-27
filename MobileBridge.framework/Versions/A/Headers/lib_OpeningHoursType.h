//
//  lib_OpeningHoursType.h
//  MobileBridge
//
//  Created by Lior Lavon on 9/21/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface lib_OpeningHoursType : NSObject
{
    int location_id;
    int day;
    int closed;
    NSDate* open_time;
    NSDate* close_time;
}
@property (nonatomic) int location_id;
@property (nonatomic) int day;
@property (nonatomic) int closed;
@property (nonatomic, strong) NSDate* open_time;
@property (nonatomic, strong) NSDate* close_time;

-(void)description;

@end
