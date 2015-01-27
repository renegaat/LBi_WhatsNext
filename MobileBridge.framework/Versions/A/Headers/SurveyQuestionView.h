//
//  SurveyQuestionView.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 25-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MyUIView.h"
#import "PromotionLabelView.h"
#import "lib_GroupCBView.h"
#import "MySliderView.h"

typedef enum
{
	MC = 0,
    SC = 1,
    OPEN_QUESTION = 2,
    TEXT_FIELD = 3, 
    EMAIL = 4,
    DATE = 5,
    TIME = 6,
    SCALE = 7,
    PROFILE = 8
}SurveyQuestionType;


@protocol SurveyQuestionViewDelegate <NSObject>
@required
- (void)SurveyQuestionViewHeightUpdate:(int)tagView posInJSON:(int)posInJSON viewHeight:(int)viewHeight;
- (void)SurveyQuestionViewLoadDateTimePicker:(int)viewTag fieldType:(int)fieldType date:(NSDate*)date;
- (void)SurveyQuestionViewRemoveDateTimePicker;
@end

@interface SurveyQuestionView : MyUIView <UITextViewDelegate, PromotionLabelViewDelegate, lib_GroupCBViewDelegate, UITextFieldDelegate, MySliderViewDelegate, UITextViewDelegate>
{
    __weak id <SurveyQuestionViewDelegate> delegate;
}

@property (weak) id <SurveyQuestionViewDelegate> delegate;

- (id)initWithFrameAndData:(CGRect)frame viewTag:(int)_viewTag stroke:(BOOL)_stroke strokeColor:(UIColor*)_strokeColor radius:(int)_radius;
- (void)SetQuestionData:(NSDictionary*)_pQuestionData fontQuestionStyle:(NSDictionary*)fontQuestionStyle fontAnswerStyle:(NSDictionary*)_fontAnswerStyle indicator_color:(NSDictionary*)_indicator_color imageCBType:(int)_imageCBType;
-(void)DateTimeQuestionSetTest:(NSString*)type secondsFrom1970:(NSTimeInterval)secondsFrom1970;
-(NSArray*)GetUserAnswer;

@end
