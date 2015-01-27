//
//  MB_PromotionView_new.h
//  MobileBridge
//
//  Created by Lior Lavon on 10/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PromotionManager.h"
#import "PromotionActivationView.h"
#import "lib_SocialView.h"
#import "MessageUI/MessageUI.h"
#import "PromotionLabelView.h"
#import "PromotionTimerView.h"
#import "PromotionButtonView.h"
#import "PromotionDescriptionView.h"
#import "PromotionTabView.h"
#import "PromotionScratchView.h"
#import "PromotionSlotView.h"
#import "SlotGameView.h"
#import "PromotionPunchView.h"
#import "PromotionStatusIconView.h"
#import "PollView.h"

typedef enum
{
	promotion_viewed_from_unknown = 0,
	promotion_viewed_from_notification = 1,
    promotion_viewed_from_banner_view = 2,
    promotion_viewed_from_scanner = 3,
    promotion_viewed_from_wallet_view = 4,
    promotion_viewed_from_public_list_view = 5,
    promotion_viewed_from_radar_view = 6
}PromotionViewFromType;

@protocol MB_PromotionViewDelegate <NSObject>
@optional
- (void)MB_PromotionViewFinished;
@end

@interface MB_PromotionView_new : UIView
{
    __weak id <MB_PromotionViewDelegate> delegate;
}
@property (weak) id <MB_PromotionViewDelegate> delegate;

-(id)initWithScanUrl:(CGRect)frame delegate:(id <MB_PromotionViewDelegate>)_delegate scanUrl:(NSString*)_scanUrl viewFrom:(PromotionViewFromType)viewFrom;
-(id)initWithPromotionId:(CGRect)frame delegate:(id <MB_PromotionViewDelegate>)_delegate promotionIdmd5:(NSString*)promotionIdmd5 viewFrom:(PromotionViewFromType)viewFrom;
- (id)initWithNotificationValue:(CGRect)frame delegate:(id <MB_PromotionViewDelegate>)_delegate notificationData:(NSString*)notificationData viewFrom:(PromotionViewFromType)viewFrom;
@end
