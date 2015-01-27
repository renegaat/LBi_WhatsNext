//
//  MB_SurveyView_v2.h
//  MobileBridge
//
//  Created by Lior Lavon on 09-02-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AsyncPost.h"
#import "lib_UICheckView.h"
#import "PromotionButtonView.h"

#import "lib_UICheckView.h"
#import "MySliderView.h"
#import "lib_GroupCBView.h"

#import "lib_SocialView.h"
#import "MessageUI/MessageUI.h"
#import "AlertView.h"
#import "SurveyQuestionView.h"

typedef enum
{
	SurveyViewType_ViewController = 0,
    SurveyViewType_ModalView = 1
}SurveyViewType;

@interface MB_SurveyView_v2 : UIViewController <AsyncPostDelegate, SurveyQuestionViewDelegate, PromotionLabelViewDelegate, PromotionButtonViewDelegate>
{
}

- (id)initTmp;
- (id)initWithNotificationValue:(NSDictionary*)_pNotificationValue surveyViewType:(SurveyViewType)_surveyViewType;
- (id)initWithScanValue:(NSString*)_pScanValue surveyViewType:(SurveyViewType)_surveyViewType;

@end
