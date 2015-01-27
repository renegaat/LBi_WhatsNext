//
//  MainViewController.m
//  WhatsNext
//
//  Created by Arjan van Rees on 22-09-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import "MainViewController.h"

@interface MainViewController ()

@end

@implementation MainViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(NotificationCommandReceived:) name:@"performNotification" object:nil];
    
}

- (void)NotificationCommandReceived:(NSNotification *)note {
    
    NSDictionary* pNotificationData = (NSDictionary*)[note object];
    [self PerformNotificationCommand:pNotificationData];
    
}

- (void)PerformNotificationCommand:(NSDictionary*)pNotificationData {
    
    [self.navigationController popToRootViewControllerAnimated:NO];
    [self dismissViewControllerAnimated:NO completion:nil];
    
    //Display the promotion view
    NSString* pType = [pNotificationData objectForKey:@"type"];
    
    if([pType isEqualToString:@"PROMOTION"]) {
        
        PromotionView* pPromotionView = [[PromotionView alloc] init];
        
        if(pPromotionView!=nil) {
            pPromotionView.delegate = nil;
            [pPromotionView SetPromotionValue:init_promotion_from_notification data:[pNotificationData objectForKey:@"data"]];
            
            [self presentViewController:pPromotionView animated:YES completion:nil];
        }
        
    }
    
    //Display the survey view
    else if([pType isEqualToString:@"SURVEY"]) {
        
        SurveyView* pSurveyView = [[SurveyView alloc] init];
        
        if(pSurveyView!=nil) {
            [pSurveyView SetSurveyData:init_survey_from_notification data:[pNotificationData objectForKey:@"data"]];
            
            [self presentViewController:pSurveyView animated:YES completion:nil];
        }
        
    }
    
    //Display the poll view
    else if([pType isEqualToString:@"POLL"]) {
        /* AppDelegate* pAppDelegate = (AppDelegate *)[[UIApplication sharedApplication] delegate];
        
        MB_PollView* pPollView= [pAppDelegate.mbLib MB_PollViewWithNotificationValue:pNotificationData];
        
        [self.view addSubview:pPollView]; */
    }
    
    //Display the rich message view
    else if([pType isEqualToString:@"ARTICLE"]) {
        RichMessageView* pRichMessageView = [[RichMessageView alloc] init];
        
        if(pRichMessageView!=nil) {
            [pRichMessageView SetRichMessageData:rich_message_viewed_from_notification data:[pNotificationData objectForKey:@"data"]];
            
            [self presentViewController:pRichMessageView animated:YES completion:nil];
        }
    }
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
