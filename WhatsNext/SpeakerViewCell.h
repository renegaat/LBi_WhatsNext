//
//  SpeakerViewCell.h
//  WhatsNew
//
//  Created by Arjan van Rees on 22-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SpeakerViewCell : UITableViewCell

@property (strong, nonatomic) IBOutlet UIImageView *speakerImage;
@property (strong, nonatomic) IBOutlet UILabel *speakerName;
@property (strong, nonatomic) IBOutlet UILabel *speakerFunction;

@end
