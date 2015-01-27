//
//  GenderManager.h
//  MobileBridge
//
//  Created by Lior Lavon on 7/11/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MB_Settings.h"

@protocol GenderManagerDelegate <NSObject>
@required
- (void)GenderManagerFinished;
@end

@interface GenderManager : NSObject
{
    __weak id <GenderManagerDelegate> delegate;
    
}
@property (weak) id <GenderManagerDelegate> delegate;

-(id)init;
-(id)initGender:(GenderType)gender;
-(GenderType)GetGender;

@end
