//
//  EditboxView.h
//  MobileBridge
//
//  Created by Lior Lavon on 01/04/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyUIView.h"

@protocol EditboxViewDelegate <NSObject>
@optional
- (void)EditBoxViewLoadDateTimePicker:(int)tagId;
@end

@interface EditboxView : MyUIView <UITextFieldDelegate>
{
    __weak id <EditboxViewDelegate> delegate;
}
@property (weak) id <EditboxViewDelegate> delegate;

- (id)initWithFrameAndData:(CGRect)frame tagId:(int)_tagId  fontStyle:(NSDictionary*)pFontStyle questionTypeId:(int)_questionTypeId;
- (NSString*)GetUserText;
- (void)SetUserText:(NSString*)pUserText;

@end
