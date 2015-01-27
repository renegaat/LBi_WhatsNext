//
//  SpeakerInfoDetails.h
//  WhatsNew
//
//  Created by Arjan van Rees on 26-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SpeakerInfoDetails : NSObject {
    NSString *speakerTitle;
    NSString *speakerContent;
}

@property (nonatomic, retain) NSString *speakerTitle;
@property (nonatomic, retain) NSString *speakerContent;

@end
