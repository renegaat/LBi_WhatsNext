//
//  AsyncPost.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 21-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AsyncPostDelegate <NSObject>
@required
- (void)requestFinished:(NSString*)response;
- (void)requestFailed:(NSString *)response;

@end

@interface AsyncPost : NSObject
{
    __weak id <AsyncPostDelegate> delegate;
    NSMutableData* httpResponse;
    NSMutableDictionary* postData;
    NSURLConnection* postConnection;
}
@property (weak) id <AsyncPostDelegate> delegate;
@property (nonatomic, strong) NSMutableData* httpResponse;
@property (nonatomic, strong) NSMutableDictionary* postData;

- (void)SendPostRequest:(NSString*)url;
- (void)SendGetRequest:(NSString*)url body:(NSString*)requestBody;
- (void)SetPostValue:(id <NSObject>)value forKey:(NSString *)key;
- (void)SetDelegate:(id<AsyncPostDelegate>)_delegate;
- (void)CloseConnection;


@end
