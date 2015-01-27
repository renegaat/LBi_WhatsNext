//
//  SpeakerInfoView.h
//  WhatsNew
//
//  Created by Arjan van Rees on 22-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBXML.h"
#import "SpeakerDetails.h"
#import "SpeakerInfoDetails.h"
#import "SessionInfoDetails.h"
#import "SpeakerInfoView.h"
#import "SpeakerInfoCell.h"

@interface SpeakerInfoView : UITableViewController <UITableViewDelegate, UITableViewDataSource> {
    TBXML *tbxml;
}

@property (strong, nonatomic) NSMutableArray *speakerDetailsArray;
@property (strong, nonatomic) NSMutableArray *speakerInfoArray;
@property (strong, nonatomic) NSMutableArray *sessionInfoArray;

@property (strong, nonatomic) IBOutlet UIImageView *speakerImage;
@property (strong, nonatomic) IBOutlet UILabel *speakerName;
@property (strong, nonatomic) IBOutlet UILabel *speakerFunction;

@property (strong, nonatomic) IBOutlet UISegmentedControl *segmentedControl;
- (IBAction)segmentedControl:(id)sender;

@end
