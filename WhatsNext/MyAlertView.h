//
//  MyAlertView.h
//  WhatsNew
//
//  Created by Arjan van Rees on 19-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MyAlertView : UIAlertView
{
	NSDictionary* pData;
}
@property (nonatomic, strong) NSDictionary* pData;

-(void)SetPayload:(NSDictionary*)pPayload;
-(NSDictionary*)GetPayload;

@end