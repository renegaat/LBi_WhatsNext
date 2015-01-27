//
//  AgendaDetails.h
//  WhatsNew
//
//  Created by Arjan van Rees on 25-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AgendaDetails : NSObject {
    NSString *itemTime;
    NSString *itemTitle;
    NSString *itemSpeaker;
}

@property (nonatomic, retain) NSString *itemTime;
@property (nonatomic, retain) NSString *itemTitle;
@property (nonatomic, retain) NSString *itemSpeaker;

@end
