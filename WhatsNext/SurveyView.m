//
//  SurveyView.m
//  TestApp
//
//  Created by Lior Lavon on 13/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import "SurveyView.h"
#import "AppDelegate.h"

#define kSurveyViewTag 1006

@interface SurveyView () <MB_SurveyViewDelegate, UIAlertViewDelegate>
@property (nonatomic) SurveyViewInitType initViewType;
@property (nonatomic, strong) NSString* data;
@end

@implementation SurveyView
@synthesize initViewType;
@synthesize data;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

-(void)SetSurveyData:(SurveyViewInitType)_initViewType data:(NSString*)_data {
    initViewType = _initViewType;
    data = [[NSString alloc] initWithString:_data];
}

- (void)viewDidLoad {
    
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];
    
    NSArray *versionCompatibility = [[UIDevice currentDevice].systemVersion componentsSeparatedByString:@"."];
    int iosVersion = [[versionCompatibility objectAtIndex:0] intValue];
    if(iosVersion>=7)
        self.edgesForExtendedLayout = UIRectEdgeNone;
    
    UINavigationBar *navBar = [[UINavigationBar alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 64)];
    navBar.backgroundColor = [UIColor whiteColor];
    
    UINavigationItem *navItem = [[UINavigationItem alloc] init];
    navItem.title = @"QUESTIONS";
    
    UIBarButtonItem *leftButton = [[UIBarButtonItem alloc] initWithTitle:@" " style:UIBarButtonItemStylePlain target:self action:@selector(ModalViewClose)];
    leftButton.image = [UIImage imageNamed:@"icon-close"];
    navItem.leftBarButtonItem = leftButton;
    
    navBar.items = @[ navItem ];
    
    [self.view addSubview:navBar];
    
}

-(UIBarPosition)positionForBar:(id<UIBarPositioning>)bar {
    return UIBarPositionTopAttached;
}

- (void)ModalViewClose {
    [self dismissViewControllerAnimated:YES completion:nil];
}

-(void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    SurveyViewFromType viewFrom;
    
    switch (initViewType) {
        case init_survey_from_scanner: {
            viewFrom = survey_viewed_from_scanner;
        }
            break;
        case init_survey_from_banner_view: {
            viewFrom = survey_viewed_from_banner_view;
        }
            break;
        case init_survey_from_notification: {
            viewFrom = survey_viewed_from_notification;
        }
            break;
        default:
            break;
    }
    
    MB_SurveyView* pSurveyView = [[MB_SurveyView alloc] initWithFrame:CGRectMake(0, 65, self.view.frame.size.width, self.view.frame.size.height-65) viewFrom:viewFrom data:data delegate:self];
    
    if(pSurveyView!=nil) {
        pSurveyView.tag = kSurveyViewTag;
        [self.view addSubview:pSurveyView];
    }

}

// delegate from MB_SurveyView
- (void)MB_SurveyView_SurveyTitle:(NSString*)title {
    
}

// delegate from MB_SurveyView
-(void)MB_SurveyView_SurveyAllreadyAnswered {
    [self MessagePrompt:@"Sorry, it's not necessary to fill the questions more than once. You can ignore this message."];
}

// delegate from MB_SurveyView
- (void)MB_SurveyView_SurveyAnswerd:(NSString*)message {
    [self MessagePrompt:message];
}

// Show network error notification
-(void)MessagePrompt:(NSString *)pMessage; {
    // AppDelegate* pAppDelegate = (AppDelegate*)[[UIApplication sharedApplication] delegate];
    UIAlertView *pAlert = [[UIAlertView alloc] initWithTitle:@"What's Next" message:pMessage delegate:self cancelButtonTitle:NSLocalizedString(@"Close", @"") otherButtonTitles:nil];
    
    [pAlert show];
}

-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
