//
//  GetProfileData.h
//  MobileBridge
//
//  Created by Lior Lavon on 12/04/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AsyncPost.h"

@protocol GetProfileDataDelegate <NSObject>
@required
- (void)GetProfileDataFinishedOK:(NSString*)pData;
- (void)GetProfileDataFinishedERROR;
@end

@interface GetProfileData : NSObject <AsyncPostDelegate>
{
    __weak id <GetProfileDataDelegate> delegate;
}
@property (weak) id <GetProfileDataDelegate> delegate;

-(id)init; //:(id<GetProfileDataDelegate>)_delegate;

@end
