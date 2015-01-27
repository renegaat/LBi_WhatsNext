//
//  MB_PollView.h
//  MobileBridge
//
//  Created by Lior Lavon on 25/03/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum
{
    poll_viewed_from_notification = 0,
    poll_viewed_from_banner_view = 1,
    poll_viewed_from_scanner = 2
}PollViewFromType;

@interface MB_PollView : UIView <UIAlertViewDelegate>
{
    
}

- (id)initWithFrame:(CGRect)frame viewFrom:(PollViewFromType)viewFrom data:(NSString*)_data; // delegate:(id <MB_SurveyViewDelegate>)_delegate;

@end
