//
//  SessionInfoDetails.h
//  WhatsNew
//
//  Created by Arjan van Rees on 26-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SessionInfoDetails : NSObject {
    NSString *sessionTitle;
    NSString *sessionContent;
}

@property (nonatomic, retain) NSString *sessionTitle;
@property (nonatomic, retain) NSString *sessionContent;

@end
