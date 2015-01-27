//
//  RichMessageView.m
//  TestApp
//
//  Created by Lior Lavon on 11/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import "RichMessageView.h"

#define kRichMessageViewTag 1007

@interface RichMessageView () <MB_RichMessageViewDelegate>
@property (nonatomic, strong) NSString* data;
@property (nonatomic) RichMessageViewFromType viewFrom;
@end

@implementation RichMessageView
@synthesize data;
@synthesize viewFrom;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

-(void)SetRichMessageData:(RichMessageViewFromType)_viewFrom data:(NSString*)_data {
    viewFrom = _viewFrom;
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
    navItem.title = @"MESSAGE";
    
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

    // init MB_RichMessageView with messageId
    MB_RichMessageView* pRichMessageView = (MB_RichMessageView*)[self.view viewWithTag:kRichMessageViewTag];
    
    if(pRichMessageView==nil) {
        pRichMessageView = [[MB_RichMessageView alloc] initWithFrame:CGRectMake(0, 65, self.view.frame.size.width, self.view.frame.size.height-65) delegate:self viewFrom:viewFrom data:data ];
        pRichMessageView.tag = kRichMessageViewTag;
        [self.view addSubview:pRichMessageView];
    }

}

// delegate from MB_RichMessageView
- (void)MB_RichMessageTitle:(NSString*)messageTitle {

}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
