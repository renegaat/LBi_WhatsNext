//
//  FBManager.h
//  MobileBridge
//
//  Created by Lior Lavon on 29-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol FBManagerDelegate <NSObject>
@required
-(void)FBSessionChanged:(NSString*)pStatus;
@end

@interface FBManager : NSObject
{
    __weak id <FBManagerDelegate> delegate;
}

@property (weak) id <FBManagerDelegate> delegate;
- (BOOL)FBOpenSession:(BOOL)showUI;
- (void)FBCloseSession;

@end
