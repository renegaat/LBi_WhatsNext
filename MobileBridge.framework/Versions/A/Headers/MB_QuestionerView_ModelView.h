//
//  MB_QuestionerView_ModelView.h
//  MobileBridge
//
//  Created by Lior Lavon on 09-02-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MB_QuestionerView_ModelView : UINavigationController
{
    
}

-(id)initWithNotificationValue:(NSDictionary*)_pNotificationValue;
-(id)initWithScanValue:(NSString*)_pScanVal;

@end
