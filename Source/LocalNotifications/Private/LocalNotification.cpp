//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "LocalNotificationsPrivatePCH.h"

void ULocalNotification::Setup(FDateTime FireDate, FString TimeZone, FString AlertTitle, FString AlertBody, FString AlertAction, bool HasAction, int32 ApplicationIconBadgeNumber)
{
#if PLATFORM_IOS
	NotificationIOS = [[UILocalNotification alloc] init];
	
	if (NotificationIOS == nil)
	{
		return;
	}
	
	SetFireDate(FireDate);
	SetTimeZone(TimeZone);
	SetAlertTitle(AlertTitle);
	SetAlertBody(AlertBody);
	SetAlertAction(AlertAction);
	SetHasAction(HasAction);
	SetApplicationIconBadgeNumber(ApplicationIconBadgeNumber);
#endif
}

ULocalNotification* ULocalNotification::ConstructLocalNotification(FDateTime FireDate, FString TimeZone, FString AlertTitle, FString AlertBody, FString AlertAction, bool HasAction, int32 ApplicationIconBadgeNumber)
{
	ULocalNotification* NewLocalNotification = NewObject<ULocalNotification>();
	NewLocalNotification->Setup(FireDate, TimeZone, AlertTitle, AlertBody, AlertAction, HasAction, ApplicationIconBadgeNumber);
	return NewLocalNotification;
}

#if PLATFORM_IOS
void ULocalNotification::Setup(UILocalNotification* Notification)
{
	NotificationIOS = Notification;
}

ULocalNotification* ULocalNotification::ConstructLocalNotification(UILocalNotification* Notification)
{
	ULocalNotification* NewLocalNotification = NewObject<ULocalNotification>();
	NewLocalNotification->Setup(Notification);
	return NewLocalNotification;
}
#endif

void ULocalNotification::Schedule()
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		[[UIApplication sharedApplication] scheduleLocalNotification:NotificationIOS];
	}
#endif
}

FDateTime ULocalNotification::GetFireDate()
{
	FDateTime Result;
	
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		NSDateComponents *components = [[NSCalendar currentCalendar] components:NSCalendarUnitDay|NSCalendarUnitMonth|NSCalendarUnitYear|NSCalendarUnitHour|NSCalendarUnitMinute|NSCalendarUnitSecond fromDate:NotificationIOS.fireDate];
		
		Result = FDateTime([components year],[components month],[components day],[components hour],[components minute],[components second]);
	}
#endif

	return Result;
}

void ULocalNotification::SetFireDate(FDateTime FireDate)
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		NSCalendar *Calendar = [NSCalendar autoupdatingCurrentCalendar];
		NSDateComponents *DateComps = [[NSDateComponents alloc] init];
		[DateComps setDay:FireDate.GetDay()];
		[DateComps setMonth:FireDate.GetMonth()];
		[DateComps setYear:FireDate.GetYear()];
		[DateComps setHour:FireDate.GetHour()];
		[DateComps setMinute:FireDate.GetMinute()];
		[DateComps setSecond:FireDate.GetSecond()];
		NSDate *NoteDate = [Calendar dateFromComponents:DateComps];
		
		NotificationIOS.fireDate = NoteDate;
	}
#endif
}

FString ULocalNotification::GetTimeZone()
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		return FString(NotificationIOS.timeZone.abbreviation);
	}
#endif

	return FString();
}

void ULocalNotification::SetTimeZone(FString TimeZone)
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		NotificationIOS.timeZone = TimeZone.Len() > 0 ? [NSTimeZone timeZoneWithAbbreviation:TimeZone.GetNSString()] : [NSTimeZone systemTimeZone];
	}
#endif
}

FString ULocalNotification::GetAlertTitle()
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		return FString(NotificationIOS.alertTitle);
	}
#endif

	return FString();
}

void ULocalNotification::SetAlertTitle(FString AlertTitle)
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		NotificationIOS.alertTitle = AlertTitle.GetNSString();
	}
#endif
}

FString ULocalNotification::GetAlertBody()
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		return FString(NotificationIOS.alertBody);
	}
#endif

	return FString();
}

void ULocalNotification::SetAlertBody(FString AlertBody)
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		NotificationIOS.alertBody = AlertBody.GetNSString();
	}
#endif
}

FString ULocalNotification::GetAlertAction()
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		return FString(NotificationIOS.alertAction);
	}
#endif

	return FString();
}

void ULocalNotification::SetAlertAction(FString AlertAction)
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		NotificationIOS.alertAction = AlertAction.GetNSString();
	}
#endif
}

bool ULocalNotification::GetHasAction()
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		return NotificationIOS.hasAction;
	}
#endif
	
	return false;
}

void ULocalNotification::SetHasAction(bool HasAction)
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		NotificationIOS.hasAction = HasAction;
	}
#endif
}

int32 ULocalNotification::GetApplicationIconBadgeNumber()
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		return NotificationIOS.applicationIconBadgeNumber;
	}
#endif
	
	return 0;
}

void ULocalNotification::SetApplicationIconBadgeNumber(int32 BadgeNumber)
{
#if PLATFORM_IOS
	if (NotificationIOS)
	{
		NotificationIOS.applicationIconBadgeNumber = BadgeNumber;
	}
#endif
}
