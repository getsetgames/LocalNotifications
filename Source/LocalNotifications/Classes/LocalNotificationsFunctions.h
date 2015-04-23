//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "LocalNotificationsFunctions.generated.h"

UCLASS(NotBlueprintable)
class ULocalNotificationsFunctions : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category="Local Notifications")
	static TArray<ULocalNotification*> GetScheduledLocalNotifications();

	UFUNCTION(BlueprintCallable, Category="Local Notifications")
	static void CancelAllLocalNotifications();
};
