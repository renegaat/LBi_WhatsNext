//
//  WalletView.m
//  WhatsNew
//
//  Created by Arjan van Rees on 09-09-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import "WalletView.h"

#define testTag 10005

@interface WalletView ()

@property (nonatomic) int couponViewStatus;

@end

@implementation WalletView

@synthesize couponViewStatus;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
    
}

- (void)viewDidLoad {
    
    [super viewDidLoad];

    MB_WalletView* pWalletView = (MB_WalletView*)[self.view viewWithTag:testTag];
    
    if(pWalletView==nil) {
        pWalletView = [[MB_WalletView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height) delegate:self];
        pWalletView.tag = testTag;
        [self.view addSubview:pWalletView];
    }
    
}

- (void)didReceiveMemoryWarning {
    
    [super didReceiveMemoryWarning];

}

- (void)MB_WalletItemSelected:(NSString*)promotionId {
    
    PromotionView* pPromotionView = [[PromotionView alloc] init];
    
    if(pPromotionView!=nil) {
        pPromotionView.delegate = self;
        [pPromotionView SetPromotionValue:init_promotion_from_wallet_view data:promotionId];
        [self.navigationController pushViewController:pPromotionView animated:YES];
    }
    
}

- (int)MB_WalletCellView_heightForRowAtIndexPath {
    
    return 250;
    
}

- (UITableViewCell*)MB_WalletCellView_cellForRowAtIndexPath:(UITableView*)pTableView promotionItem:(NSDictionary*)promotionItem {
    
    UITableViewCell *cell = [pTableView dequeueReusableCellWithIdentifier:@"promotion_cell_identifier"];
    
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"promotion_cell_identifier"];
        
        cell.backgroundColor = [UIColor clearColor];
        cell.backgroundView = [[UIImageView alloc] initWithImage:[[UIImage imageNamed:@"voucher-background"] stretchableImageWithLeftCapWidth:0.0 topCapHeight:5.0]];
        cell.selectedBackgroundView =  [[UIImageView alloc] initWithImage:[[UIImage imageNamed:@"voucher-background-selected"] stretchableImageWithLeftCapWidth:0.0 topCapHeight:5.0]];
        
        
        UIImageView* pImageView = [[UIImageView alloc] initWithFrame:CGRectMake(60, 22, 200, 60)];
        pImageView.tag = 1;
        // pImageView.backgroundColor = [UIColor blackColor];
        [cell.contentView addSubview:pImageView];
        
        // Label
        UILabel* pTitle = [[UILabel alloc] initWithFrame:CGRectMake(0, 109, 320, 24)];
        pTitle.backgroundColor = [UIColor clearColor];
        pTitle.tag = 2;
        pTitle.textAlignment = NSTextAlignmentCenter;
        
        [pTitle setFont:[UIFont fontWithName:@"Gotham-Medium" size:17.0]];
        
        [cell.contentView addSubview:pTitle];
        
        // Description
        UILabel* pDescription = [[UILabel alloc] initWithFrame:CGRectMake(0, 141, 320, 30)];
        pDescription.tag = 3;
        pDescription.textAlignment = NSTextAlignmentCenter;
        pDescription.numberOfLines = 4;
        pDescription.backgroundColor = [UIColor clearColor];
        
        [pDescription setFont:[UIFont fontWithName:@"Gotham-Book" size:14.0]];
        [pDescription setTextColor:[UIColor colorWithRed:118.0/255.0 green:116.0/255.0 blue:115.0/255.0 alpha:1]];
        
        [cell.contentView addSubview:pDescription];
        
    }

    UIImageView* pImageView = (UIImageView*)[cell.contentView viewWithTag:1];
    
    if(pImageView!=nil) {
       
        NSString *imageURI = [NSString stringWithFormat:@"%@%@", [promotionItem objectForKey:@"image_url"], [promotionItem objectForKey:@"image_name"]];
        
        NSURL * imageURL = [NSURL URLWithString:imageURI];
        NSData * imageData = [NSData dataWithContentsOfURL:imageURL];
        
        pImageView.image = [UIImage imageWithData:imageData];
        pImageView.contentMode = UIViewContentModeScaleAspectFill;
        
        // [NSThread detachNewThreadSelector:@selector(loadImageThread:) toTarget:self withObject:pImageView];
    }
    
    UILabel* pTitle = (UILabel*)[cell.contentView viewWithTag:2];
    if(pTitle!=nil)
        pTitle.text = [[promotionItem objectForKey:@"title"] uppercaseString];
    
    
    UILabel* pDescription = (UILabel*)[cell.contentView viewWithTag:3];
    if(pDescription!=nil)
        pDescription.text = [promotionItem objectForKey:@"description"];
    
    return cell;
    
}

-(void)UpdatePromotionList:(int)promotionType {
    
}

- (void)PromotionViewClosed {
    MB_WalletView* pWalletView = (MB_WalletView*)[self.view viewWithTag:testTag];
    if(pWalletView!=nil)
        [pWalletView SetPromotionType:couponViewStatus tagId:-1];
}


- (IBAction)clearButton:(id)sender {
    
    AppDelegate* pAppDelegate = (AppDelegate*)[[UIApplication sharedApplication] delegate];
   
    if(pAppDelegate!=nil) {
        [pAppDelegate.mbLib MB_ClearUserHistory];
    }

    
}

@end
