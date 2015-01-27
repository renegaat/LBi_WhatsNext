//
//  AgendaTableView.m
//  WhatsNew
//
//  Created by Arjan van Rees on 25-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import "AgendaTableView.h"

@interface AgendaTableView ()

@end

@implementation AgendaTableView

- (id)initWithStyle:(UITableViewStyle)style {
    
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
    
}

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    UIEdgeInsets inset = UIEdgeInsetsMake(10, 0, 10, 0);
    self.tableView.contentInset = inset;
    
    UIRefreshControl *refresh = [[UIRefreshControl alloc] init];
    [refresh addTarget:self action:@selector(refreshView:) forControlEvents:UIControlEventValueChanged];
    
    self.refreshControl = refresh;
    
    [self loadAgendaList];
    
    [self.tableView reloadData];

}

- (void)refreshView:(UIRefreshControl *)refresh {
    
    [self loadAgendaList];
    
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"HH:mm"];
    NSString *lastUpdated = [NSString stringWithFormat:@"last updated: %@", [formatter stringFromDate:[NSDate date]]];
    
    refresh.attributedTitle = [[NSAttributedString alloc] initWithString:lastUpdated];
    [refresh performSelector:@selector(endRefreshing) withObject:nil afterDelay:1.0];
}

- (void)loadAgendaList {
    
    agendaTableArray = [[NSMutableArray alloc] init];
    
    NSData *xmlData = [[NSData alloc] initWithContentsOfURL:[[NSBundle mainBundle] URLForResource:@"agenda" withExtension:@"xml"]];
    
    tbxml = [[TBXML alloc]initWithXMLData:xmlData error:nil];
    
	if (tbxml.rootXMLElement)
		[self traverseElement:tbxml.rootXMLElement];
    
    
    // load from server... quick hack ;)
    
    NSMutableURLRequest *xmlRequest = [[NSMutableURLRequest alloc] initWithURL:[NSURL URLWithString:@"http://ext.lbi.de/events/dmt/2015/assets/agenda.xml"]];
    [xmlRequest setHTTPMethod:@"GET"];
    
    [NSURLConnection sendAsynchronousRequest:xmlRequest
                                       queue:[NSOperationQueue mainQueue]
                           completionHandler:^(NSURLResponse *response, NSData *data, NSError *connectionError)
     {
         if(!connectionError)
         {
             agendaTableArray = [[NSMutableArray alloc] init];
             tbxml = [[TBXML alloc]initWithXMLData:data error:nil];
             if (tbxml.rootXMLElement)
                 [self traverseElement:tbxml.rootXMLElement];
             [self.tableView reloadData];
         }
     }];
}

- (void)traverseElement:(TBXMLElement *)element {
    do {
        if (element->firstChild)
            [self traverseElement:element->firstChild];
        
        if ([[TBXML elementName:element] isEqualToString:@"item"]) {
            
            // General Speaker Info
            AgendaDetails *agenda = [[AgendaDetails alloc] init];
            
            TBXMLElement *TimeElement = [TBXML childElementNamed:@"time" parentElement:element];
            agenda.itemTime = [TBXML textForElement:TimeElement];
            
            TBXMLElement *TitleElement = [TBXML childElementNamed:@"title" parentElement:element];
            agenda.itemTitle = [TBXML textForElement:TitleElement];
            
            TBXMLElement *SpeakerElement = [TBXML childElementNamed:@"speaker" parentElement:element];
            agenda.itemSpeaker = [TBXML textForElement:SpeakerElement];

            [agendaTableArray addObject:agenda];
            
            agenda = nil;
            
        }
        
    } while ((element = element->nextSibling));
    
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {

    if ([agendaTableArray count] >= 1) {
        
        self.tableView.backgroundView = nil;
        
        return 1;
        
    } else {
        
        UIImageView* messageImage = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height)];
        
        messageImage.image = [UIImage imageNamed:[NSString stringWithFormat:@"internet-error"]];
        messageImage.contentMode = UIViewContentModeCenter;
        
        self.tableView.backgroundView = messageImage;
        self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        
    }
    
    return 0;
    
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {

    return [agendaTableArray count];
    
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    AgendaDetails *ob = [agendaTableArray objectAtIndex:indexPath.row];
    
    if (ob.itemSpeaker.length == 0) {
        return 50.0f;
    }
    else if(ob.itemTitle.length > 20)
    {
        return 95.0f;
    }
    else
    {
        return 70.0f;
    }

}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    AgendaDetails *ob = [agendaTableArray objectAtIndex:indexPath.row];
    
    if (ob.itemSpeaker.length == 0) {
        
        AgendaViewCellSmall *cell = [tableView dequeueReusableCellWithIdentifier:@"AgendaViewCellSmall"];
        
        if (cell == nil) {
            cell = [[AgendaViewCellSmall alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"AgendaViewCellSmall"];
        }
       
        cell.agendaTime.text = [NSString stringWithFormat:@"%@", ob.itemTime];
        cell.agendaDescription.text = [NSString stringWithFormat:@"%@", ob.itemTitle];
        
        return cell;
        
    }
    else if(ob.itemTitle.length > 20)
    {
        AgendaViewCellDoubleLine *cell = [tableView dequeueReusableCellWithIdentifier:@"AgendaViewCellDoubleLine"];
        
        if (cell == nil) {
            cell = [[AgendaViewCellDoubleLine alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"AgendaViewCellDoubleLine"];
        }
        
        cell.agendaTime.text = [NSString stringWithFormat:@"%@", ob.itemTime];
        cell.agendaDescription.text = [NSString stringWithFormat:@"%@", ob.itemTitle];
        cell.agendaSpeaker.text = [NSString stringWithFormat:@"%@", ob.itemSpeaker];
        
        return cell;

    }
    else
    {
        AgendaViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"AgendaViewCell"];
        
        if (cell == nil) {
            cell = [[AgendaViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"AgendaViewCell"];
        }
        
        cell.agendaTime.text = [NSString stringWithFormat:@"%@", ob.itemTime];
        cell.agendaDescription.text = [NSString stringWithFormat:@"%@", ob.itemTitle];
        cell.agendaSpeaker.text = [NSString stringWithFormat:@"%@", ob.itemSpeaker];
        
        return cell;
    }
    
}

- (void)didReceiveMemoryWarning {
    
    [super didReceiveMemoryWarning];
    
}

@end
