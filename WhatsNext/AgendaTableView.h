//
//  AgendaTableView.h
//  WhatsNew
//
//  Created by Arjan van Rees on 25-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBXML.h"
#import "AgendaViewCell.h"
#import "AgendaDetails.h"
#import "AgendaViewCellSmall.h"
#import "AgendaViewCellDoubleLine.h"

@interface AgendaTableView : UITableViewController <UITableViewDelegate, UITableViewDataSource> {
    NSMutableArray *agendaTableArray;
    
    TBXML *tbxml;
}

@property (strong, nonatomic) IBOutlet UITableView *agendaTable;

- (void)traverseElement:(TBXMLElement *)element;

@end
