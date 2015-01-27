//
//  GetSystemIds.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 23-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AsyncPost.h"

@protocol GetSystemIdDelegate <NSObject>
@required
- (void)GetSystemIdFinished;
@end

@interface GetSystemIds : NSObject <AsyncPostDelegate>
{
    __weak id <GetSystemIdDelegate> delegate;
    int waitForNetworkCounter;
}
@property (weak) id <GetSystemIdDelegate> delegate;
-(id)initGetSystemIds;

@end
