//
//  SetProfile.h
//  MobileBridge
//
//  Created by Lior Lavon on 24-03-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AsyncPost.h"

@protocol SetProfileDelegate <NSObject>
@required
- (void)SetProfileFinished;
@end

@interface SetProfile : NSObject <AsyncPostDelegate>
{
    __weak id <SetProfileDelegate> delegate;
}
@property (weak) id <SetProfileDelegate> delegate;

-(id)initProfile;
-(BOOL)SetValue:(NSNumber*)answerId forKey:(NSNumber*)questionId;
-(BOOL)SendProfile;
-(void)ClearProfileData;

@end
