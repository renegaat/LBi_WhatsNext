//
//  AgendaViewCellSmall.m
//  WhatsNew
//
//  Created by Arjan van Rees on 25-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import "AgendaViewCellSmall.h"

@implementation AgendaViewCellSmall

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        // Initialization code
    }
    return self;
}

- (void)awakeFromNib {
    
    [self.agendaTime setFont:[UIFont fontWithName:@"Gotham-Book" size:15.0]];
    
    [self.agendaDescription setFont:[UIFont fontWithName:@"Gotham-Medium" size:15.0]];
    [self.agendaDescription setTextColor:[UIColor colorWithRed:237.0/255.0 green:28.0/255.0 blue:39.0/255.0 alpha:1]];
    
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
