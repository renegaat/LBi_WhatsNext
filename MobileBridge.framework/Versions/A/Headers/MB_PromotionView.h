//
//  MB_PromotionView.h
//  MobileBridge
//
//  Created by Lior Lavon on 10/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PromotionManager.h"
#import "PromotionActivationView.h"
#import "MessageUI/MessageUI.h"
#import "innerPollView.h"

typedef enum
{
	promotion_viewed_from_notification = 0,
    promotion_viewed_from_banner_view = 1,
    promotion_viewed_from_scanner = 2,
    promotion_viewed_from_wallet_view = 3,
    promotion_viewed_from_public_list_view = 4,
    promotion_viewed_from_radar_view = 5
}PromotionViewFromType;

typedef enum
{
	share_on_facebook = 0,
	share_on_twitter = 1,
	share_on_qr = 2,
	share_on_whatsapp = 3,
	share_on_email = 4
}PromotionViewShareType;

@protocol MB_PromotionViewDelegate <NSObject>
@required
- (void)MB_PromotionViewAllowSharing;
- (void)MB_PromotionViewFinishedActivation;
- (void)MB_PromotionView_ShowGallery:(NSString*)galleryId;
- (void)MB_PromotionView_ShowRichMessage:(NSString*)_richmessageId;
- (void)MB_PromotionView_ShowLocations:(NSString*)promotionId;
@end

@interface MB_PromotionView : UIView
{
    __weak id <MB_PromotionViewDelegate> delegate;
}
@property (weak) id <MB_PromotionViewDelegate> delegate;

- (id)initWithFrame:(CGRect)frame viewFrom:(PromotionViewFromType)viewFrom delegate:(id <MB_PromotionViewDelegate>)_delegate data:(NSString*)_data;
-(void)ShareWith:(PromotionViewShareType)shareWith;

@end
