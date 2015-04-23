//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "LocalNotificationsPrivatePCH.h"

void ULocalNotificationsComponent::OnRegister()
{
	Super::OnRegister();
	
	FCoreDelegates::ApplicationReceivedLocalNotificationDelegate.AddUObject(this, &ULocalNotificationsComponent::ApplicationReceivedLocalNotification_Handler);
	FCoreDelegates::ApplicationHandleActionForLocalNotificationDelegate.AddUObject(this, &ULocalNotificationsComponent::ApplicationHandleActionForLocalNotification_Handler);
}

void ULocalNotificationsComponent::OnUnregister()
{
	Super::OnUnregister();
	
	FCoreDelegates::ApplicationReceivedLocalNotificationDelegate.RemoveAll(this);
	FCoreDelegates::ApplicationHandleActionForLocalNotificationDelegate.RemoveAll(this);
}

void ULocalNotificationsComponent::ApplicationReceivedLocalNotification_Handler(void* Notification)
{
	if (ApplicationReceivedLocalNotification.IsBound())
	{
		ULocalNotification* Note = nullptr;
#if PLATFORM_IOS
		if (Notification)
		{
			if ([(id)Notification isKindOfClass:[UILocalNotification class]])
			{
				Note = ULocalNotification::ConstructLocalNotification((UILocalNotification*)Notification);
			}
		}
#endif
		ApplicationReceivedLocalNotification.Broadcast(Note);
	}
}

void ULocalNotificationsComponent::ApplicationHandleActionForLocalNotification_Handler(FString Action, void* Notification)
{
	if (ApplicationHandleActionForLocalNotification.IsBound())
	{
		ULocalNotification* Note = nullptr;
#if PLATFORM_IOS
		if (Notification)
		{
			if ([(id)Notification isKindOfClass:[UILocalNotification class]])
			{
				Note = ULocalNotification::ConstructLocalNotification((UILocalNotification*)Notification);
			}
		}
#endif
		ApplicationHandleActionForLocalNotification.Broadcast(Action, Note);
	}
}
