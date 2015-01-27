//
//  SpeakerDetails.h
//  WhatsNew
//
//  Created by Arjan van Rees on 22-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SpeakerDetails : NSObject {
    NSString *speakerName;
    NSString *speakerImage;
    NSString *speakerFunction;
    NSString *speakerCompany;
    
    NSMutableArray *speakerInfoDetails;
    NSMutableArray *sessionInfoDetails;
}

@property (nonatomic, retain) NSString *speakerName;
@property (nonatomic, retain) NSString *speakerImage;
@property (nonatomic, retain) NSString *speakerFunction;
@property (nonatomic, retain) NSString *speakerCompany;

@property (nonatomic, retain) NSMutableArray *speakerInfoDetails;
@property (nonatomic, retain) NSMutableArray *sessionInfoDetails;

@end
