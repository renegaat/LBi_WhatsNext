//
//  RadarAnnotation.h
//  MobileBridgeLibrary
//
//  Created by Lior Lavon on 24-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

typedef enum
{
	radarAnnotationTypeLocation = 0,
    radarAnnotationTypeUserLocation = 1
}RadarAnnotationType;

@interface RadarAnnotation : NSObject <MKAnnotation>
{
	CLLocationCoordinate2D coordinate;
//    NSMutableArray* pItemList;
	int geoId;
	int promotionId;
	RadarAnnotationType annotationType;
}

@property (nonatomic) CLLocationCoordinate2D coordinate;
@property (nonatomic) RadarAnnotationType annotationType;
@property (nonatomic) int geoId;
@property (nonatomic) int promotionId;
//@property (nonatomic, strong) NSMutableArray* pItemList;

-(id)initWithCoordinate:(CLLocationCoordinate2D)coord;
-(void)UpdateCoordinate:(CLLocationCoordinate2D)coord;
//-(void)AddItem:(int)couponId geoId:(int)geoId;
-(void)SetGeoId:(int)_geoId;
-(int)GetGeoId;
-(void)SetPromotionId:(int)_geoId;
-(int)GetPromotionId;

//-(void)PrintGeoLocation;

@end
