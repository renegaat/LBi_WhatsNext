//
//  CouponManager.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 07-11-12.
//  Copyright (c) 2012 Ai-Pixel B.V. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "lib_CouponType.h"

@interface CouponManager : NSObject
{
}

+(void)CheckCouponListExpiration:(int)currentStatus newStatus:(int)newStatus;
+(void)CheckCouponStatus:(lib_CouponType*)pCouponItem reminderTime:(double)reminderTime newStatus:(int)newStatus;
+(void)ChangeCouponStatus:(int)couponId newStatus:(int)newStatus;
+(void)RemoveCouponAlarm:(int)couponId;
+(double)GetAlarmSettings;

@end
