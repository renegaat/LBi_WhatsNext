//
//  PromotionView.h
//  WhatsNew
//
//  Created by Arjan van Rees on 17-09-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PromotionViewDelegate <NSObject>
@required
- (void)PromotionViewClosed;
@end

@interface PromotionView : UIViewController {
    __weak id <PromotionViewDelegate> delegate;
}

@property (weak) id <PromotionViewDelegate> delegate;

typedef enum {
    init_promotion_from_notification = 0,
    init_promotion_from_banner_view = 1,
    init_promotion_from_scanner = 2,
    init_promotion_from_wallet_view = 3,
    init_promotion_from_public_list_view = 4,
    init_promotion_from_radar_view = 5
} PromotionViewInitType;

-(void)SetPromotionValue:(PromotionViewInitType)_initViewType data:(NSString*)_data;

@end