//
//  lib_CouponType.h
//  MobileBridge
//
//  Created by Eyal Oster on 01-11-11.
//  Copyright (c) 2011 Ai-Pixel B.V. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface lib_CouponType : NSObject
{
	int couponId;
    NSString* id_md5;
    NSString* title;
    NSString* _description;
    double product_value;
    double product_offer;
    int product_offer_type; // 0=value , 1=precent
    int price_with_float_point; // show the number right to the floating point
    NSString* image;
    NSString* preview_images;
//	NSString*  code;  // activation code
	NSString* product_descr;
	double start_date_time;
	double end_date_time;
	int activation; // bool 1=needs activation , 0=no activation
    int shareable;
    int max_uses; // total number of uses
    int coupon_type; // 0 -> normal coupon, 1->punch, 2->game, 3->free, 4-> campaign, 5->voucher
    int use_count; // counting tot max_uses
    NSString* activation_end_type; //days/hours
    int active_end_time; // number of days/hours
    NSString* tabs; // conteins String with title^^^data###title^^^data or -1
    NSString* url;
    int expiers;
    int uniqueSaveId;
    int extraArticleId; // if not exist then -1
    int extraVideoId;   // if not exist then -1
    int extraPhotogalleryId;    // if not exist then -1
    NSString* extraArticleTitle; // the name of the extra article
    NSString* extraVideoUrl; // the url of the extra video
    double last_modified; // last modified date
    
    int discount_sharing; // is there a facebook discount
    double discount_sharing_price; // the price for discount sharing
    int discount_share_type; // 0=value 1=precent
    int user_shared_coupon; // did the user shared
    int game_type; // type of game , 0=scratch , 1=slotMachin
    int game_played; // user played the game
    int activation_type; // 0==micros / verigate , 2==menual code, 3==local activation
    int activation_trigger_type; // 0==message, 1==code, 2==scan
    NSString* activation_trigger_code; // if(activation_trigger_type==1 | 2) activation_trigger_code holds the code
    int activation_timeout; // if activation_type==2 -> timer timeout
    NSString* activation_bc_code; // if activation_type==1 -> code is a 4 digits, if activation_type==2 -> code is a 12 digits
    NSString* activation_fbcode; // if activation_type==2 and fb share is 1 -> fbcode is a 12 digits
    
    int allowGeoTriggers; // is allow to trigger on geo location
    int activateOnGeoLocation; // if ==1 then allow activation only in one of the geo location
    NSString* unique_coupon_handler; // hander for the specific coupon events view->save->activate
    int total_items_left; // total number of items left
    int geo_locs_active; // 0=no linked location , 1=location is linked
    NSDictionary* pLayout; // coupon layout
    int members_only; // member only restriction
    int poll_id;
    int poll_answered;
    NSArray* tags;
    
    int status; // coupon status -> 0==active , 1==max_used , 2==expierd
}
@property (nonatomic) int couponId;
@property (nonatomic, strong) NSString* id_md5;
@property (nonatomic, strong) NSString* title;
@property (nonatomic, strong) NSString* _description;
@property (nonatomic) double product_value;
@property (nonatomic) double product_offer;
@property (nonatomic) int product_offer_type;
@property (nonatomic) int price_with_float_point;

@property (nonatomic, strong) NSString* image;
@property (nonatomic, strong) NSString* preview_images;
//@property (nonatomic, retain) NSString* code;
@property (nonatomic, strong) NSString* product_descr;
@property (nonatomic) double start_date_time;
@property (nonatomic) double end_date_time;
@property (nonatomic) int activation;
@property (nonatomic) int shareable;
@property (nonatomic) int max_uses; // total number of uses
@property (nonatomic) int coupon_type; 
@property (nonatomic) int use_count; // counting tot max_uses
@property (nonatomic, strong) NSString* activation_end_type; //days/date
@property (nonatomic) int active_end_time; // number of days/date
@property (nonatomic, strong) NSString* tabs;
@property (nonatomic, strong) NSString* url;
@property (nonatomic) int expiers;
@property (nonatomic) int uniqueSaveId;
@property (nonatomic) int extraArticleId;
@property (nonatomic) int extraVideoId;
@property (nonatomic) int extraPhotogalleryId;
@property (nonatomic, strong) NSString* extraArticleTitle; // the name of the extra article
@property (nonatomic, strong) NSString* extraVideoUrl; // the url of the extra video
@property (nonatomic) double last_modified; // last modified date
@property (nonatomic) int discount_sharing;
@property (nonatomic) double discount_sharing_price;
@property (nonatomic) int discount_share_type;
@property (nonatomic) int user_shared_coupon;
@property (nonatomic) int game_type;
@property (nonatomic) int game_played;
@property (nonatomic) int activation_type;
@property (nonatomic) int activation_trigger_type;
@property (nonatomic, strong) NSString* activation_trigger_code;
@property (nonatomic) int activation_timeout;
@property (nonatomic, strong) NSString* activation_bc_code;
@property (nonatomic, strong) NSString* activation_fbcode;

@property (nonatomic) int allowGeoTriggers;
@property (nonatomic) int activateOnGeoLocation;
@property (nonatomic, strong) NSString* unique_coupon_handler;
@property (nonatomic) int total_items_left;
@property (nonatomic) int geo_locs_active;
@property (nonatomic, strong) NSDictionary* pLayout;
@property (nonatomic) int members_only;
@property (nonatomic) int poll_id;
@property (nonatomic) int poll_answered;
@property (nonatomic, strong) NSArray* tags;

@property (nonatomic) int status;


-(id)initWithValue:(NSDictionary*)pCouponInfo command:(int)command;
-(void)description;

@end
