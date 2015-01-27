//
//  BirthdateManager.h
//  MobileBridge
//
//  Created by Lior Lavon on 7/11/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol BirthdateManagerDelegate <NSObject>
@required
- (void)BirthdateManagerFinished;
@end

@interface BirthdateManager : NSObject
{
    __weak id <BirthdateManagerDelegate> delegate;
 
}
@property (weak) id <BirthdateManagerDelegate> delegate;

-(id)init;
-(id)initBirthdate:(long)utcDate;
-(long)GetBirthdate;


@end
