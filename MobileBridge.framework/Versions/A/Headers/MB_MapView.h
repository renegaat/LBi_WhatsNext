//
//  MB_MapView.h
//  MobileBridge
//
//  Created by Lior Lavon on 9/19/13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RadarAnnotation.h"

@protocol MB_MapViewDelegate <NSObject>
@required
-(void)MB_MapViewPromotionSelected:(NSString*)promotionIdMD5;
-(void)MB_MapViewLocationSelected:(NSDictionary*)pLocationItem;
@end

@interface MB_MapView : UIView <MKMapViewDelegate, CLLocationManagerDelegate >
{
    __weak id <MB_MapViewDelegate> delegate;
}
@property (weak) id <MB_MapViewDelegate> delegate;

-(id)initWithFrame:(CGRect)frame delegate:(id <MB_MapViewDelegate>)_delegate promotionId:(NSString*)_promotionId;
-(void)ShowListGeoLocatios;
-(void)StopPopulateAnnotations;

@end
