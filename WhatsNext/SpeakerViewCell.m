//
//  SpeakerViewCell.m
//  WhatsNew
//
//  Created by Arjan van Rees on 22-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import "SpeakerViewCell.h"

@implementation SpeakerViewCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        // Initialization code
    }
    return self;
}

- (void)awakeFromNib {
    // Initialization code
    
    [self.speakerName setFont:[UIFont fontWithName:@"Gotham-Medium" size:17.0]];
    
    [self.speakerFunction setFont:[UIFont fontWithName:@"Gotham-Book" size:14.0]];
    [self.speakerFunction setTextColor:[UIColor colorWithRed:118.0/255.0 green:116.0/255.0 blue:115.0/255.0 alpha:1]];
    
    self.backgroundView = [[UIImageView alloc] initWithImage:[[UIImage imageNamed:@"speaker-item"] stretchableImageWithLeftCapWidth:0.0 topCapHeight:5.0]];
    self.selectedBackgroundView = [[UIImageView alloc] initWithImage:[[UIImage imageNamed:@"speaker-item-selected"] stretchableImageWithLeftCapWidth:0.0 topCapHeight:5.0]];
    
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
