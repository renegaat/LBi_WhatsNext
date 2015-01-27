//
//  AgendaViewCell.h
//  WhatsNew
//
//  Created by Arjan van Rees on 25-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AgendaViewCell : UITableViewCell
@property (strong, nonatomic) IBOutlet UILabel *agendaTime;
@property (strong, nonatomic) IBOutlet UILabel *agendaDescription;
@property (strong, nonatomic) IBOutlet UILabel *agendaSpeaker;

@end
