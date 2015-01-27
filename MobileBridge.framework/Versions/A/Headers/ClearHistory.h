//
//  ClearHistory.h
//  MobileBridge
//
//  Created by Lior Lavon on 30/08/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ClearHistoryDelegate <NSObject>
@required
-(void)ClearUserHistoryFinished;
@end

@interface ClearHistory : NSObject
{
    __weak id <ClearHistoryDelegate> delegate;
    
}
@property (weak) id <ClearHistoryDelegate> delegate;

@end
