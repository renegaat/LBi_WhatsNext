//
//  SpeakerInfoView.m
//  WhatsNew
//
//  Created by Arjan van Rees on 22-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import "SpeakerInfoView.h"

@interface SpeakerInfoView ()

@end

@implementation SpeakerInfoView

static NSString * const CellIdentifier = @"SpeakerInfoCell";

- (id)initWithStyle:(UITableViewStyle)style {
    
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
    
}

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    SpeakerDetails *ob = self.speakerDetailsArray;
    
    self.speakerName.text = [NSString stringWithFormat:@"%@", [ob.speakerName uppercaseString]];
    self.speakerImage.image = [UIImage imageNamed:[NSString stringWithFormat:@"%@", ob.speakerImage]];
    
    if([ob.speakerCompany length] > 0){
        self.speakerFunction.text = [NSString stringWithFormat:@"%@ at %@", ob.speakerFunction, ob.speakerCompany];
    }else{
        self.speakerFunction.text = [NSString stringWithFormat:@"%@", ob.speakerFunction];
    }
    
    [self.speakerName setFont:[UIFont fontWithName:@"Gotham-Medium" size:17.0]];
    
    [self.speakerFunction setFont:[UIFont fontWithName:@"Gotham-Book" size:14.0]];
    [self.speakerFunction setTextColor:[UIColor colorWithRed:118.0/255.0 green:116.0/255.0 blue:115.0/255.0 alpha:1]];
    
    self.segmentedControl.hidden = (ob.sessionInfoDetails.count == 0);
    
    [self.tableView reloadData];
    
    // [self performSelector:@selector(test) withObject:nil afterDelay:0.1];
    
    /* if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0) {
        self.tableView.estimatedRowHeight = 95.0;
        self.tableView.rowHeight = UITableViewAutomaticDimension;
    } */
    
}

- (IBAction)segmentedControl:(id)sender {
    
    UISegmentedControl *segmentedControl = (UISegmentedControl *) sender;
    NSInteger selectedSegment = segmentedControl.selectedSegmentIndex;
    
    if (selectedSegment == 0) {
        
        [self.tableView reloadData];
        
    } else {
        
        [self.tableView reloadData];
        
    }
    
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {

    return 1;
    
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {

    if (_segmentedControl.selectedSegmentIndex == 0)
        return [self.speakerInfoArray count];
    else
        return [self.sessionInfoArray count];
    
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    return [self speakerInfoCellAtIndexPath:indexPath];
    
}

- (SpeakerInfoCell *)speakerInfoCellAtIndexPath:(NSIndexPath *)indexPath {
    
    SpeakerInfoCell *cell = [self.tableView dequeueReusableCellWithIdentifier:CellIdentifier forIndexPath:indexPath];
    [self configureSpeakerInfoCell:cell atIndexPath:indexPath];
    
    return cell;
    
}

- (void)configureSpeakerInfoCell:(SpeakerInfoCell *)cell atIndexPath:(NSIndexPath *)indexPath {
    
    if (_segmentedControl.selectedSegmentIndex == 0) {
        
        SpeakerInfoDetails *speaker = [self.speakerInfoArray objectAtIndex:indexPath.row];
            
        cell.cellTitle.text = [NSString stringWithFormat:@"%@", [speaker.speakerTitle uppercaseString]];
            
        NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
        paragraphStyle.minimumLineHeight = 20.f;
        paragraphStyle.maximumLineHeight = 20.f;
            
        UIFont *font = [UIFont fontWithName:@"Gotham-Book" size:15.0];
            
        cell.cellContent.attributedText = [[NSAttributedString alloc] initWithString:speaker.speakerContent attributes: @{NSParagraphStyleAttributeName:paragraphStyle, NSFontAttributeName:font}];

    } else {
        
        SessionInfoDetails *session = [self.sessionInfoArray objectAtIndex:indexPath.row];
            
        cell.cellTitle.text = [NSString stringWithFormat:@"%@", [session.sessionTitle uppercaseString]];
            
        NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
        paragraphStyle.minimumLineHeight = 20.f;
        paragraphStyle.maximumLineHeight = 20.f;
            
        UIFont *font = [UIFont fontWithName:@"Gotham-Book" size:15.0];
            
        cell.cellContent.attributedText = [[NSAttributedString alloc] initWithString:session.sessionContent attributes: @{NSParagraphStyleAttributeName:paragraphStyle, NSFontAttributeName:font}];
        
    }
    
}

 - (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {


        return [self heightForSpeakerInfoCellAtIndexPath:indexPath];
   

}

- (CGFloat)heightForSpeakerInfoCellAtIndexPath:(NSIndexPath *)indexPath {
    
    static SpeakerInfoCell *sizingCell = nil;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        sizingCell = [self.tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    });
    
    [self configureSpeakerInfoCell:sizingCell atIndexPath:indexPath];
    
    return [self calculateHeightForConfiguredSizingCell:sizingCell];
    
}

- (CGFloat)calculateHeightForConfiguredSizingCell:(UITableViewCell *)sizingCell {
    
    [sizingCell setNeedsLayout];
    [sizingCell layoutIfNeeded];
    
    CGSize size = [sizingCell.contentView systemLayoutSizeFittingSize:UILayoutFittingCompressedSize];
    return size.height;
    
}


- (void)didReceiveMemoryWarning {
    
    [super didReceiveMemoryWarning];
    
}

@end
