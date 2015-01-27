//
//  PromotionView.m
//  WhatsNew
//
//  Created by Arjan van Rees on 17-09-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import "PromotionView.h"
#import "AppDelegate.h"
#import <MobileBridge/MobileBridge.h>

@interface PromotionView () <MB_PromotionViewDelegate>

@property (nonatomic) PromotionViewInitType initViewType;
@property (nonatomic, strong) NSString* data;

@end

@implementation PromotionView

@synthesize initViewType;
@synthesize data;
@synthesize delegate;

-(void)SetPromotionValue:(PromotionViewInitType)_initViewType data:(NSString*)_data {
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
    
    UILabel* pTitle = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 172, 35)];
    
    if(pTitle!=nil) {
        pTitle.textAlignment = NSTextAlignmentCenter;
        pTitle.font = [UIFont fontWithName: @"Gotham-Book" size: 17.0];
        pTitle.textColor = [UIColor whiteColor];
        pTitle.text = NSLocalizedString(@"COUPON", @"");
        self.navigationItem.titleView = pTitle;
    }
    
}

-(void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    MB_PromotionView* pPromotionView = (MB_PromotionView*)[self.view viewWithTag:1001];
    if(pPromotionView==nil) {
        PromotionViewFromType viewFrom;
        switch (initViewType) {
            case init_promotion_from_banner_view:
                viewFrom = promotion_viewed_from_banner_view;
                break;
            case init_promotion_from_wallet_view:
                viewFrom = promotion_viewed_from_wallet_view;
                break;
            case init_promotion_from_public_list_view:
                viewFrom = promotion_viewed_from_public_list_view;
                break;
            case init_promotion_from_radar_view:
                viewFrom = promotion_viewed_from_radar_view;
                break;
            case init_promotion_from_notification:
                viewFrom = promotion_viewed_from_notification;
                break;
            case init_promotion_from_scanner:
                viewFrom = promotion_viewed_from_scanner;
                break;
        }
        
        pPromotionView = [[MB_PromotionView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height) viewFrom:viewFrom delegate:self data:data];
        pPromotionView.tag = 1001;
        [self.view addSubview:pPromotionView];
    }
}

-(void)MB_PromotionViewAllowSharing {

}

- (void)MB_PromotionView_ShowGallery:(NSString*)galleryId {

}

- (void)MB_PromotionView_ShowRichMessage:(NSString*)richmessageId {
    /* RichMessageView* pRichMessageView = [[RichMessageView alloc] init];
    if(pRichMessageView!=nil) {
        [pRichMessageView SetRichMessageId:richmessageId];
        [self.navigationController pushViewController:pRichMessageView animated:YES];
    } */
}

- (void)MB_PromotionView_ShowLocations:(NSString*)promotionId {

}

- (void)didMoveToParentViewController:(UIViewController *)parent {
    if(parent==nil) {
        [[self delegate] PromotionViewClosed];
    }
}

-(void)MB_PromotionViewFinishedActivation {

}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
