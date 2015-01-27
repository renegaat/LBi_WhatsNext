//
//  MB_QuestionerView.h
//  MobileBridge
//
//  Created by Lior Lavon on 09-02-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AsyncPost.h"
#import "lib_UICheckView.h"

#import "lib_UICheckView.h"
#import "MySliderView.h"
#import "GroupCBView.h"

#import "lib_SocialView.h"
#import "MessageUI/MessageUI.h"
#import "FBManager.h"
#import "lib_FacebookShareView.h"
#import "FBAlertView.h"
#import "AlertView.h"

typedef enum
{
	QuestionerViewType_ViewController = 0,
    QuestionerViewType_ModalView = 1
}QuestionerViewType;

@interface MB_QuestionerView : UIViewController <UITableViewDelegate, UITableViewDataSource, UITextFieldDelegate, UITextViewDelegate , UIPickerViewDelegate, UIPickerViewDataSource, AlertViewDelegate, GroupCBViewDelegate, MySliderViewDelegate, AsyncPostDelegate, lib_UICheckViewDelegate, lib_SocialViewDelegate, FBManagerDelegate, lib_FBShareViewDelegate, MFMailComposeViewControllerDelegate, FBAlertViewDelegate>
{
}

- (id)initWithNotificationValue:(NSDictionary*)_pNotificationValue questionerViewType:(QuestionerViewType)_questionerViewType;
- (id)initWithScanValue:(NSString*)_pScanValue questionerViewType:(QuestionerViewType)_questionerViewType;

@end
