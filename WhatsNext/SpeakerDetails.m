//
//  SpeakerDetails.m
//  WhatsNew
//
//  Created by Arjan van Rees on 22-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import "SpeakerDetails.h"

@implementation SpeakerDetails

@synthesize speakerName;
@synthesize speakerImage;
@synthesize speakerFunction;
@synthesize speakerCompany;
@synthesize speakerInfoDetails;
@synthesize sessionInfoDetails;

- (id) init {
	self = [super init];
	if (self != nil) {
		speakerInfoDetails = [[NSMutableArray alloc] initWithCapacity:10];
        
        sessionInfoDetails = [[NSMutableArray alloc] initWithCapacity:10];
	}
	return self;
}



@end
