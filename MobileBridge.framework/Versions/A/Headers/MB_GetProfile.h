//
//  MB_GetProfile.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 23-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AsyncPost.h"

// delegate
@protocol GetProfileDelegate <NSObject>
@required
- (void)GetProfileFinished:(NSString*)_data;
@end

@interface MB_GetProfile : NSObject <AsyncPostDelegate>
{
    __weak id <GetProfileDelegate> delegate;
}
@property (weak) id <GetProfileDelegate> delegate;

- (id)initGetProfile:(id<GetProfileDelegate>)_delegate;

@end
