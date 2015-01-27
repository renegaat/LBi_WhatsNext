//
//  MB_CView_ModelView.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 25-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MB_CView_ModelView : UINavigationController
{
    
}
-(id)initWithScanUrl:(NSString*)_scanUrl viewFrom:(NSString*)viewFrom;
-(id)initWithNotificationValue:(NSDictionary*)_pNotificationData viewFrom:(NSString*)viewFrom;
-(id)initWithPromotionId:(NSString*)promotionId viewFrom:(NSString*)viewFrom;

@end
