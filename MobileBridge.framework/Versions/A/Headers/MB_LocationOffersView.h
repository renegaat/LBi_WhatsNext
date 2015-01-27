//
//  MB_LocationOffersView.h
//  MobileBridge
//
//  Created by Lior Lavon on 7/14/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MB_LocationOffersViewDelegate <NSObject>
@required
- (void)LocationOfferSelected:(NSDictionary*)pData;
@end

@interface MB_LocationOffersView : UIView <UITableViewDataSource, UITableViewDelegate>
{
    __weak id <MB_LocationOffersViewDelegate> delegate;

}
@property (weak) id <MB_LocationOffersViewDelegate> delegate;


- (id)initWithFrame:(CGRect)frame data:(NSDictionary*)pNotificationData;
//-(void)GetLocationsOffersFromServer:(int)_locationId locationEvent:(int)locationEvent;

@end
