//
//  AppTrigger.h
//  MobileBridge
//
//  Created by Lior Lavon on 7/11/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AsyncPost.h"

@protocol AppTriggerDelegate <NSObject>
@required
- (void)AppTriggerFinished;
@end

@interface AppTrigger : NSObject <AsyncPostDelegate>
{
    __weak id <AppTriggerDelegate> delegate;
    
}
@property (weak) id <AppTriggerDelegate> delegate;

-(id)init;


@end
