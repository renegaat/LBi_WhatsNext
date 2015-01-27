//
//  SurveyView.h
//  TestApp
//
//  Created by Lior Lavon on 13/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MobileBridge/MobileBridge.h>

typedef enum {
	init_survey_from_notification = 0,
	init_survey_from_banner_view = 1,
	init_survey_from_scanner = 2
} SurveyViewInitType;

@interface SurveyView : UIViewController <UINavigationBarDelegate>

-(void)SetSurveyData:(SurveyViewInitType)_initViewType data:(NSObject*)_data;
@property (strong, nonatomic) IBOutlet UINavigationBar *navBar;


@end
