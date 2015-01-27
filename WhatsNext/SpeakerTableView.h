    //
//  SpeakerTableView.h
//  WhatsNew
//
//  Created by Arjan van Rees on 22-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import "SpeakerDetails.h"
#import "SpeakerInfoDetails.h"
#import "SessionInfoDetails.h"
#import "SpeakerViewCell.h"
#import "SpeakerInfoView.h"
#import "TBXML.h"

@interface SpeakerTableView : UITableViewController <UITableViewDelegate, UITableViewDataSource> {
    NSMutableArray *speakerTableArray;
    NSMutableArray *speakerTableArrayFull;
    
    TBXML *tbxml;
}

@property (strong, nonatomic) IBOutlet UITableView *speakerTable;

- (void)traverseElement:(TBXMLElement *)element;

@end
