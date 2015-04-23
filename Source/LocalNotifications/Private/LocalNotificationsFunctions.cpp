//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "LocalNotificationsPrivatePCH.h"

TArray<ULocalNotification*> ULocalNotificationsFunctions::GetScheduledLocalNotifications()
{
	TArray<ULocalNotification*> Result;
	
#if PLATFORM_IOS
	for (UILocalNotification* Note in [UIApplication sharedApplication].scheduledLocalNotifications)
	{
		Result.Add(ULocalNotification::ConstructLocalNotification(Note));
	}
#endif
	
	return Result;
}

void ULocalNotificationsFunctions::CancelAllLocalNotifications()
{
#if PLATFORM_IOS
	[[UIApplication sharedApplication] cancelAllLocalNotifications];
#endif
}
