//
//  UpdateToken.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 22-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AsyncPost.h"

@protocol UpdateTokenDelegate <NSObject>
@required
- (void)UpdateTokenFinished;
@end

@interface UpdateToken : NSObject <AsyncPostDelegate>
{
    __weak id <UpdateTokenDelegate> delegate;
}
@property (weak) id <UpdateTokenDelegate> delegate;

-(id)initUpdateToken:(NSString*)pToken;

@end
