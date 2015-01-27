//
//  MB_SurveyView.h
//  MobileBridge
//
//  Created by Lior Lavon on 12/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "lib_UICheckView.h"

#import "lib_UICheckView.h"
#import "MySliderView.h"
#import "lib_GroupCBView.h"

#import "MessageUI/MessageUI.h"

typedef enum
{
    survey_viewed_from_notification = 0,
    survey_viewed_from_banner_view = 1,
    survey_viewed_from_scanner = 2
}SurveyViewFromType;


@protocol MB_SurveyViewDelegate <NSObject>
@required
- (void)MB_SurveyView_SurveyTitle:(NSString*)title;
- (void)MB_SurveyView_SurveyAnswerd:(NSString*)message;
- (void)MB_SurveyView_SurveyAllreadyAnswerd;
@end


@interface MB_SurveyView : UIView 
{
    __weak id <MB_SurveyViewDelegate> delegate;
}
@property (weak) id <MB_SurveyViewDelegate> delegate;


- (id)initWithFrame:(CGRect)frame viewFrom:(SurveyViewFromType)viewFrom data:(NSString*)_data delegate:(id <MB_SurveyViewDelegate>)_delegate;

@end
