//
//  SpeakerTableView.m
//  WhatsNew
//
//  Created by Arjan van Rees on 22-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import "SpeakerTableView.h"

@interface SpeakerTableView ()

@end

@implementation SpeakerTableView

- (id)initWithStyle:(UITableViewStyle)style {
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    UIEdgeInsets inset = UIEdgeInsetsMake(15, 0, 15, 0);
    self.tableView.contentInset = inset;
    
    UIRefreshControl *refresh = [[UIRefreshControl alloc] init];
    [refresh addTarget:self action:@selector(refreshView:) forControlEvents:UIControlEventValueChanged];
    
    self.refreshControl = refresh;
    
    [self loadSpeakersList];
    
    [self.tableView reloadData];
    
}

- (void)refreshView:(UIRefreshControl *)refresh {
    
    [self loadSpeakersList];
    
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"HH:mm"];
    NSString *lastUpdated = [NSString stringWithFormat:@"last updated: %@", [formatter stringFromDate:[NSDate date]]];
    
    refresh.attributedTitle = [[NSAttributedString alloc] initWithString:lastUpdated];
    [refresh performSelector:@selector(endRefreshing) withObject:nil afterDelay:1.0];
}

- (void)loadSpeakersList {
    
    speakerTableArray = [[NSMutableArray alloc] init];
    
    NSData *xmlData = [[NSData alloc]initWithContentsOfURL:[[NSBundle mainBundle] URLForResource:@"speakers" withExtension:@"xml"]];
    
    tbxml = [[TBXML alloc]initWithXMLData:xmlData error:nil];
    
	if (tbxml.rootXMLElement)
		[self traverseElement:tbxml.rootXMLElement];
    
    /* for(SpeakerDetails *ob in speakerTableArray) {
        NSLog(@"----------");
        NSLog(@"Name: %@", ob.speakerName);
        NSLog(@"Function: %@", ob.speakerFunction);
        NSLog(@"Company: %@", ob.speakerCompany);
        NSLog(@"Image: %@", ob.speakerImage);
        
        for(SpeakerInfoDetails *speaker in ob.speakerInfoDetails) {
            NSLog(@"----------");
            NSLog(@"SpeakerTitle: %@", speaker.speakerTitle);
            NSLog(@"SpeakerContent: %@", speaker.speakerContent);
        }
        
        for(SessionInfoDetails *session in ob.sessionInfoDetails) {
            NSLog(@"----------");
            NSLog(@"SessionTitle: %@", session.sessionTitle);
            NSLog(@"SessionContent: %@", session.sessionContent);
        }
        
    } */
    
    [self.tableView reloadData];

    // load from server... quick hack ;)
    
    NSMutableURLRequest *xmlRequest = [[NSMutableURLRequest alloc] initWithURL:[NSURL URLWithString:@"http://ext.lbi.de/events/dmt/2015/assets/speakers.xml"]];
    [xmlRequest setHTTPMethod:@"GET"];
    
    [NSURLConnection sendAsynchronousRequest:xmlRequest
                                       queue:[NSOperationQueue mainQueue]
                           completionHandler:^(NSURLResponse *response, NSData *data, NSError *connectionError)
     {
         if(!connectionError)
         {
             speakerTableArray = [[NSMutableArray alloc] init];
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
        
        if ([[TBXML elementName:element] isEqualToString:@"speaker"]) {
            
            // General Speaker Info
            
            SpeakerDetails *ob = [[SpeakerDetails alloc] init];
            
            TBXMLElement *NameElement = [TBXML childElementNamed:@"name" parentElement:element];
           
            if (NameElement != nil) {
                ob.speakerName = [TBXML textForElement:NameElement];
            }
            
            TBXMLElement *FunctionElement = [TBXML childElementNamed:@"function" parentElement:element];
            
            if (FunctionElement != nil) {
                ob.speakerFunction = [TBXML textForElement:FunctionElement];
            }
            
            TBXMLElement *CompanyElement = [TBXML childElementNamed:@"company" parentElement:element];
            
            if (CompanyElement != nil) {
                ob.speakerCompany = [TBXML textForElement:CompanyElement];
            }
            
            TBXMLElement *ImageElement = [TBXML childElementNamed:@"image" parentElement:element];
            
            if (ImageElement != nil) {
                ob.speakerImage = [TBXML textForElement:ImageElement];
            }
            
            // Detailed Speaker Info
            
            TBXMLElement * SpeakerTabElement = [TBXML childElementNamed:@"speaker-tab" parentElement:element];
            
            while (SpeakerTabElement != nil) {
                
                TBXMLElement * SpeakerItemElement = [TBXML childElementNamed:@"item" parentElement:SpeakerTabElement];
                
                while (SpeakerItemElement != nil) {
                    
                    SpeakerInfoDetails *speaker = [[SpeakerInfoDetails alloc] init];
                
                    TBXMLElement * TitleElement = [TBXML childElementNamed:@"title" parentElement:SpeakerItemElement];
                
                    if (TitleElement != nil) {
                        speaker.speakerTitle = [TBXML textForElement:TitleElement];
                    }
                
                    TBXMLElement *ContentElement = [TBXML childElementNamed:@"content" parentElement:SpeakerItemElement];
                
                    if (ContentElement != nil) {
                        speaker.speakerContent = [TBXML textForElement:ContentElement];
                    }
                
                    [ob.speakerInfoDetails addObject:speaker];
                    
                    SpeakerItemElement = [TBXML nextSiblingNamed:@"item" searchFromElement:SpeakerItemElement];
                    
                }
                
                SpeakerTabElement = [TBXML nextSiblingNamed:@"speaker-tab" searchFromElement:SpeakerTabElement];
                
            }
            
            // Detailed Session Info
            
            TBXMLElement * SessionTabElement = [TBXML childElementNamed:@"session-tab" parentElement:element];
            
            while (SessionTabElement != nil) {
                
                TBXMLElement * SessionItemElement = [TBXML childElementNamed:@"item" parentElement:SessionTabElement];
                
                while (SessionItemElement != nil) {
                    
                    SessionInfoDetails *session = [[SessionInfoDetails alloc] init];
                    
                    TBXMLElement * TitleElement = [TBXML childElementNamed:@"title" parentElement:SessionItemElement];
                    
                    if (TitleElement != nil) {
                        session.sessionTitle = [TBXML textForElement:TitleElement];
                    }
                    
                    TBXMLElement *ContentElement = [TBXML childElementNamed:@"content" parentElement:SessionItemElement];
                    
                    if (ContentElement != nil) {
                        session.sessionContent = [TBXML textForElement:ContentElement];
                    }
                    
                    [ob.sessionInfoDetails addObject:session];
                    
                    SessionItemElement = [TBXML nextSiblingNamed:@"item" searchFromElement:SessionItemElement];
                    
                }
                
                SessionTabElement = [TBXML nextSiblingNamed:@"session-tab" searchFromElement:SessionTabElement];
                
            }
            
            [speakerTableArray addObject:ob];
            
            ob = nil;
            
        }
        
    } while ((element = element->nextSibling));
    
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    
    if ([speakerTableArray count] >= 1) {
        
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

    return [speakerTableArray count];
    
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    return 210;
    
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    static NSString *CellIdentifier = @"SpeakerCell";
    
    SpeakerViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    
    if (cell == nil) {
        cell = [[SpeakerViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }
    
    SpeakerDetails *ob = [speakerTableArray objectAtIndex:indexPath.row];
    
    cell.speakerName.text = [NSString stringWithFormat:@"%@", [ob.speakerName uppercaseString]];
    cell.speakerImage.image = [UIImage imageNamed:[NSString stringWithFormat:@"%@", ob.speakerImage]];
    

    if( [ob.speakerCompany length] > 0){
        cell.speakerFunction.text = [NSString stringWithFormat:@"%@ at %@", ob.speakerFunction, ob.speakerCompany];
    }else{
        cell.speakerFunction.text = [NSString stringWithFormat:@"%@", ob.speakerFunction];
    }
    
    return cell;
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    
    if ([[segue identifier] isEqualToString:@"SpeakerInfoDetail"]) {
            
        NSIndexPath *indexPath = [self.tableView indexPathForSelectedRow];
            
        SpeakerDetails *ob = speakerTableArray[indexPath.row];

        SpeakerInfoView *speakerInfoView = segue.destinationViewController;
        
        [speakerInfoView setSpeakerDetailsArray:ob];
        [speakerInfoView setSpeakerInfoArray:ob.speakerInfoDetails];
        [speakerInfoView setSessionInfoArray:ob.sessionInfoDetails];
        
    }
    
}

- (void)didReceiveMemoryWarning {
    
    [super didReceiveMemoryWarning];
    
}

@end
