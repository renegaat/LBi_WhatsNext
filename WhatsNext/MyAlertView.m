//
//  MyAlertView.m
//  WhatsNew
//
//  Created by Arjan van Rees on 19-08-14.
//  Copyright (c) 2014 DigitasLBi Netherlands B.V. All rights reserved.
//

#import "MyAlertView.h"

@implementation MyAlertView
@synthesize pData;

- (id)initWithFrame:(CGRect)frame
{
	self = [super initWithFrame:frame];
	if (self)
	{
        
	}
	return self;
}

-(void)SetPayload:(NSDictionary*)pPayload {
	pData = [[NSDictionary alloc] initWithDictionary:pPayload];
}

-(NSDictionary*)GetPayload {
	return pData ;
}

-(void)dealloc {
	pData = nil;
	// [super dealloc];
}

@end