//
//  MB_CouponView.h
//  MobileBridge
//
//  Created by Lior Lavon on 27-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CouponManager.h"
#import "AsyncPost.h"
#import "CouponActivationView.h"
#import "lib_SocialView.h"
#import "MessageUI/MessageUI.h"
#import "FBManager.h"
#import "lib_FacebookShareView.h"
#import "CouponActivationTriggerView.h"
#import "AlertView.h"
#import "CouponLabelView.h"
#import "CouponTimerView.h"
#import "CouponButtonView.h"
#import "CouponDescriptionView.h"
#import "CouponTabView.h"
#import "CouponScratchView.h"
#import "CouponSlotView.h"
#import "CouponPunchView.h"
#import "CouponStatusIconView.h"
#import "PollView.h"

typedef enum
{
	CouponViewType_ViewController = 0,
    CouponViewType_ModalView = 1
}CouponViewType;

@interface MB_CouponView : UIViewController <AsyncPostDelegate, lib_SocialViewDelegate, FBManagerDelegate, lib_FBShareViewDelegate, MFMailComposeViewControllerDelegate, UIAlertViewDelegate, CouponActivationTriggerViewDelegate, AlertViewDelegate, CouponActivationViewDelegate, CouponLabelViewDelegate, CouponButtonViewDelegate, CouponTimerViewDelegate, CouponDescriptionViewDelegate, CouponTabViewDelegate, CouponScratchViewDelegate, CouponSlotViewDelegate, CouponPunchViewDelegate, CouponStatusIconViewDelegate, PollViewDelegate>
{
}

-(id)initWithNotificationValue:(NSDictionary*)pNotificationData couponViewType:(int)_couponViewType shareType:(int)_shareType viewFrom:(NSString*)viewFrom;
-(id)initWithScanUrl:(NSString*)_scanUrl couponViewType:(int)_couponViewType shareType:(int)_shareType viewFrom:(NSString*)viewFrom;
-(id)initWithCouponId:(NSString*)md5CouponId couponViewType:(int)_couponViewType shareType:(int)_shareType viewFrom:(NSString*)viewFrom;
-(id)initWithPromotionId:(NSString*)promotionId couponViewType:(int)_couponViewType shareType:(int)_shareType viewFrom:(NSString*)viewFrom;


@end
