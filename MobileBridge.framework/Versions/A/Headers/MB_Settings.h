//
//  MB_Settings.h
//  MobileBridge
//
//  Created by Lior Lavon on 01-02-13.
//  Copyright (c) 2013 Lior Lavon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SetToken.h"

typedef enum
{
	_2DaysBefore = 0,
    _1DayBefore = 1,
    _12HoursBefore = 2,
    _6HoursBefore = 3
}TimeReminderType;

typedef enum
{
	_500meters = 0,
    _1Km = 1,
    _2Km = 2,
    _4Km = 3
}LocationReminderType;

typedef enum
{
    _unknown = -1,
    _female = 0,
	_male = 1
}GenderType;


@protocol MB_SettingsDelegate <NSObject>
@required
- (void)SettingEventReply:(NSDictionary*)response;
@end

@interface MB_Settings : NSObject <SetTokenDelegate >
{
    __weak id <MB_SettingsDelegate> delegate;
}
@property (weak) id <MB_SettingsDelegate> delegate;

// notification
-(void)SetNotificationEnabled:(BOOL)status delegate:(id<MB_SettingsDelegate>)_delegate showAlert:(BOOL)_showAlert;

// time reminder
-(void)SetTimeReminderEnabled:(BOOL)_alarmReminderStatus delegate:(id<MB_SettingsDelegate>)_delegate showAlert:(BOOL)_showAlert;
-(void)SetTimeReminderInterval:(TimeReminderType)alarmInterval delegate:(id<MB_SettingsDelegate>)_delegate showAlert:(BOOL)_showAlert;

// Location reminder
-(void)SetLocationReminderEnabled:(BOOL)_locationReminderStatus delegate:(id<MB_SettingsDelegate>)_delegate showAlert:(BOOL)_showAlert;
-(void)SetLocationReminderInterval:(LocationReminderType)locationInterval delegate:(id<MB_SettingsDelegate>)_delegate showAlert:(BOOL)_showAlert;

// Beacon reminder
-(void)SetBeaconReminderEnabled:(BOOL)_beaconReminderStatus delegate:(id<MB_SettingsDelegate>)_delegate showAlert:(BOOL)_showAlert;

-(BOOL)GetNotificationStatus;
-(BOOL)GetTimeReminderStatus;
-(TimeReminderType)GetTimeReminderInterval;
-(BOOL)GetLocationReminderStatus;
-(LocationReminderType)GetLocationReminderInterval;
-(BOOL)GetBeaconStatus;

@end
