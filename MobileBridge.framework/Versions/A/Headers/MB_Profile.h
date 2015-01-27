//
//  MB_Profile.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 23-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

// delegate
@protocol ProfileDelegate <NSObject>
@required
- (void)GetProfileFinished:(NSString*)_data;
- (void)SetProfileFinished:(NSString*)_data;
@end

@interface MB_Profile : NSObject 
{
    __weak id <ProfileDelegate> delegate;
}
@property (weak) id <ProfileDelegate> delegate;

- (id)initProfile:(id<ProfileDelegate>)_delegate type:(NSString*)type;
- (BOOL)SetValue:(NSNumber*)answerId forKey:(NSNumber*)questionId;
- (void)SendProfileData;
- (BOOL)SendProfileToServer;
//- (void)ClearProfileData;

@end
