//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "LocalNotificationsComponent.generated.h"

UCLASS(ClassGroup=LocalNotifications, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class ULocalNotificationsComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FApplicationReceivedLocalNotificationDynDelegate, ULocalNotification*, Notification);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FApplicationHandleActionForLocalNotificationDynDelegate, FString, Action, ULocalNotification*, Notification);

	UPROPERTY(BlueprintAssignable)
	FApplicationReceivedLocalNotificationDynDelegate ApplicationReceivedLocalNotification;

	UPROPERTY(BlueprintAssignable)
	FApplicationHandleActionForLocalNotificationDynDelegate ApplicationHandleActionForLocalNotification;

	void OnRegister() override;
	void OnUnregister() override;
	
private:
	void ApplicationReceivedLocalNotification_Handler(void* Notification);
	void ApplicationHandleActionForLocalNotification_Handler(FString Action, void* Notification);
};
