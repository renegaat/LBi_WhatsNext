//
//  PromotionManager.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 07-11-12.
//  Copyright (c) 2012 Ai-Pixel B.V. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "lib_CouponType.h"

@interface PromotionManager : NSObject
{
}

+(void)CheckPromotionListExpiration:(int)currentStatus newStatus:(int)newStatus;
+(void)CheckPromotionStatus:(lib_CouponType*)pCouponItem reminderTime:(double)reminderTime newStatus:(int)newStatus;
+(void)ChangePromotionStatus:(int)couponId newStatus:(int)newStatus;
+(void)RemovePromotionAlarm:(int)couponId;
+(double)GetAlarmSettings;

@end
