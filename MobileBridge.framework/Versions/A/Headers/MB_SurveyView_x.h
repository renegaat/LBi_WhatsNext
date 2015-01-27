//
//  MB_SurveyView_x.h
//  MobileBridge
//
//  Created by Lior Lavon on 12/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "lib_UICheckView.h"
#import "PromotionButtonView.h"

#import "lib_UICheckView.h"
#import "MySliderView.h"
#import "lib_GroupCBView.h"

#import "MessageUI/MessageUI.h"
#import "AlertView.h"
#import "SurveyQuestionView.h"

@protocol MB_SurveyViewDelegate <NSObject>
@required
- (void)MB_SurveyView_SurveyTitle:(NSString*)title;
- (void)MB_SurveyView_SurveyAnswerd:(NSString*)message;
- (void)MB_SurveyView_SurveyAllreadyAnswerd;
@end


@interface MB_SurveyView_x : UIView <SurveyQuestionViewDelegate, PromotionLabelViewDelegate, PromotionButtonViewDelegate, AlertViewDelegate>
{
    __weak id <MB_SurveyViewDelegate> delegate;
}
@property (weak) id <MB_SurveyViewDelegate> delegate;

//- (id)initTmp;
- (id)initWithNotificationValue:(CGRect)frame delegate:(id <MB_SurveyViewDelegate>)_delegate pNotificationValue:(NSDictionary*)pNotificationValue;
- (id)initWithScanValue:(CGRect)frame delegate:(id <MB_SurveyViewDelegate>)_delegate scanValue:(NSString*)_scanValue;
- (id)initWithBannerId:(CGRect)frame delegate:(id <MB_SurveyViewDelegate>)_delegate bannerId:(NSString*)_bannerId;

@end
