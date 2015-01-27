//
//  MB_ContactView.h
//  MobileBridge
//
//  Created by Lior Lavon on 08-02-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AsyncPost.h"
#import "lib_UICheckView.h"
#import "FBAlertView.h"

typedef enum
{
	ContactViewType_ViewController = 0,
    ContactViewType_ModalView = 1
}ContactViewType;

@interface MB_ContactView : UIViewController <UITableViewDelegate, UITableViewDataSource, UITextFieldDelegate, UITextViewDelegate , UIPickerViewDelegate, UIPickerViewDataSource, UIAlertViewDelegate, AsyncPostDelegate, lib_UICheckViewDelegate, FBAlertViewDelegate>
{
}
-(id)initWithContactViewType:(ContactViewType)_contactViewType;
@end
