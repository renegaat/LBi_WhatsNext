//
//  MobileBridgeLibrary.h
//  MobileBridge
//
//  Created by Lior Lavon on 27-01-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MB_WalletView.h"
#import "MB_MapView.h"
#import "MB_LocationView.h"
#import "MB_PromotionListView.h"
#import "MB_PromotionView.h"
#import "MB_GalleryView.h"
#import "MB_RichMessageView.h"
#import "MB_SurveyView.h"
#import "MB_PollView.h"

#import "MB_LocationOffersView.h"

#import "MB_BannerView.h"
#import "MB_InboxView.h"
//#import "MB_ProfileView.h"
#import "MB_Settings.h"
#import "DeviceLocation.h"
#import "LocationManager.h"
#import "GenderManager.h"
#import "BirthdateManager.h"
#import "SetToken.h"
#import "MB_Profile.h"
#import "InitApp.h"
#import "ClearHistory.h"

@protocol MobileBridgeLibraryDelegate <NSObject>
@required
- (void)MB_SettingEventReply:(NSDictionary*)response;
- (void)MB_NetworkAlertPrompt:(int)alertId;
- (void)MB_LocationUpdate:(int)position max:(int)max;
@end

@protocol MB_ProfileDelegate <NSObject>
@required
- (void)MB_GetProfileReply:(NSString*)data;
- (void)MB_SetProfileReply:(NSString*)data;
@end

// Inbox Data Delegate
@protocol MB_GetInboxDataDelegate <NSObject>
@required
- (void)MB_GetInboxDataFinished:(NSDictionary*)data;
@end

// Rich Message Data Delegate
@protocol MB_GetRichMessageDataDelegate <NSObject>
@required
- (void)MB_GetRichMessageDataFinished:(NSDictionary*)data;
@end

@interface MobileBridgeLibrary : NSObject <MB_SettingsDelegate, DeviceLocationDelegate, LocationManagerDelegate, BirthdateManagerDelegate, GenderManagerDelegate, SetTokenDelegate, ProfileDelegate, InitAppDelegate, ClearHistoryDelegate, GetInboxDataDelegate>
{
    __weak id <MobileBridgeLibraryDelegate> delegate;
    __weak id <MB_ProfileDelegate> profileDelegate;
    __weak id <MB_GetInboxDataDelegate> getInboxDataDelegate;
    __weak id <MB_GetRichMessageDataDelegate> getRichMessageDataDelegate;
}
@property (weak) id <MobileBridgeLibraryDelegate> delegate;
@property (weak) id <MB_ProfileDelegate> profileDelegate;
@property (weak) id <MB_GetInboxDataDelegate> getInboxDataDelegate;
@property (weak) id <MB_GetRichMessageDataDelegate> getRichMessageDataDelegate;



// Initiate the library
+ (id) InitLibrary:(NSString*)encryptionId;

// Set Phone Token
- (BOOL)MB_SetToken:(NSString*)pToken;

// Promotion View
-(MB_BannerView*)MB_BannerView;

// LocationOffersView
-(MB_LocationOffersView*)MB_LocationOffersView:(CGRect)frame data:(NSDictionary*)pNotificationData;

// InboxView
-(MB_InboxView*)MB_InboxView:(CGRect)frame;
-(void)MB_GetInboxData:(MB_InboxActionType)inboxAction inboxId:(int)_inboxId delegate:(id <MB_GetInboxDataDelegate>)_delegate;

// richmessage
-(void)MB_GetRichMessageData:(RichMessageViewFromType)viewFrom data:(NSString*)_data delegate:(id <MB_GetRichMessageDataDelegate>)_delegate;

// ProfileView
-(void)MB_GetProfileData:(id<MB_ProfileDelegate>)_delegate;

// Settings / Set
-(void)MB_SetNotificationEnabled:(BOOL)status delegate:(id <MobileBridgeLibraryDelegate>)_delegate showAlert:(BOOL)showAlert; // default status = TRUE
-(void)MB_SetTimeReminderEnabled:(BOOL)status delegate:(id <MobileBridgeLibraryDelegate>)_delegate showAlert:(BOOL)showAlert; // default status = TRUE
-(void)MB_SetTimeReminderInterval:(TimeReminderType)alarmInterval delegate:(id <MobileBridgeLibraryDelegate>)_delegate showAlert:(BOOL)showAlert; // default status = TRUE
-(void)MB_SetLocationReminderEnabled:(BOOL)status delegate:(id <MobileBridgeLibraryDelegate>)_delegate showAlert:(BOOL)showAlert; // default status = TRUE
-(void)MB_SetLocationReminderRadius:(LocationReminderType)locationRadius delegate:(id <MobileBridgeLibraryDelegate>)_delegate showAlert:(BOOL)showAlert; // default status = TRUE
-(void)MB_SetBeaconReminderEnabled:(BOOL)status delegate:(id <MobileBridgeLibraryDelegate>)_delegate showAlert:(BOOL)showAlert;
-(BOOL)MB_GetBeaconStatus;

// Settings / Get
-(BOOL)MB_GetNotificationStatus;

-(BOOL)MB_GetTimeReminderStatus;
-(TimeReminderType)MB_GetTimeReminderInterval;

-(BOOL)MB_GetLocationReminderStatus;
-(LocationReminderType)MB_GetLocationReminderRadius;

-(NSString*)MB_GetLibraryVersion; // get library version
-(NSString*)MB_GetLibraryGroupId; // get library group id

-(BOOL)MB_SetProfileValue:(NSNumber*)value forKey:(NSNumber*)key;
-(BOOL)MB_SendProfileUpdate;
//-(void)MB_ClearProfileData;

-(void)MB_SetColorTemplate:(NSArray*)pColorArray;

-(BOOL)MB_SetGender:(GenderType)gender;
-(GenderType)MB_GetGender;
-(BOOL)MB_SetDateOfBirth:(long)utcDate;
-(long)MB_GetDateOfBirth;

-(BOOL)MB_SetScanValue:(NSString*)scanValue; // set the activation_code or trigger_code and pass it to the message center

//Set/Get Member flag
-(BOOL)MB_SetMemberFlag:(BOOL)_memberFlag;
-(BOOL)MB_GetMemberFlag;

-(NSString*)MB_GetDeviceId;
-(void)MB_SetApplicationName:(NSString*)applicationName;

-(void)MB_ClearUserHistory;

-(NSArray*)MB_GetTagsArray;

@end
