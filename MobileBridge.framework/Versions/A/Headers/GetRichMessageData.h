//
//  GetRichMessageData.h
//  MobileBridge
//
//  Created by Lior Lavon on 04/09/14.
//  Copyright (c) 2014 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
	rich_message_viewed_from_notification = 0,
    rich_message_viewed_from_promotion_view = 1
}RichMessageViewFromType;

@protocol GetRichMessageDataDelegate <NSObject>
@required
- (void)RichMessageDataReceived:(NSDictionary*)data;
@end

@interface GetRichMessageData : NSObject
{
    __weak id <GetRichMessageDataDelegate> delegate;
}
@property (weak) id <GetRichMessageDataDelegate> delegate;

-(id)initWithRichMessageId:(RichMessageViewFromType)viewFrom data:(NSString*)_data delegate:(id <GetRichMessageDataDelegate>)_delegate;

@end
