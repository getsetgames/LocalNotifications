//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "LocalNotification.generated.h"

UCLASS(BlueprintType)
class ULocalNotification : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Local Notifications")
	static ULocalNotification* ConstructLocalNotification(FDateTime FireDate, FString TimeZone, FString AlertTitle, FString AlertBody, FString AlertAction, bool HasAction, int32 ApplicationIconBadgeNumber);
	
#if PLATFORM_IOS
	static ULocalNotification* ConstructLocalNotification(UILocalNotification* Notification);
#endif
	
	UFUNCTION(BlueprintCallable, Category = "Local Notifications")
	void Schedule();

	UFUNCTION(BlueprintPure, Category = "Local Notifications")
	FDateTime GetFireDate();
	
	UFUNCTION(BlueprintCallable, Category = "Local Notifications")
	void SetFireDate(FDateTime FireDate);

	UFUNCTION(BlueprintPure, Category = "Local Notifications")
	FString GetTimeZone();
	
	UFUNCTION(BlueprintCallable, Category = "Local Notifications")
	void SetTimeZone(FString TimeZone);

	UFUNCTION(BlueprintPure, Category = "Local Notifications")
	FString GetAlertTitle();
	
	UFUNCTION(BlueprintCallable, Category = "Local Notifications")
	void SetAlertTitle(FString AlertTitle);

	UFUNCTION(BlueprintPure, Category = "Local Notifications")
	FString GetAlertBody();
	
	UFUNCTION(BlueprintCallable, Category = "Local Notifications")
	void SetAlertBody(FString AlertBody);

	UFUNCTION(BlueprintPure, Category = "Local Notifications")
	FString GetAlertAction();
	
	UFUNCTION(BlueprintCallable, Category = "Local Notifications")
	void SetAlertAction(FString AlertAction);

	UFUNCTION(BlueprintPure, Category = "Local Notifications")
	bool GetHasAction();
	
	UFUNCTION(BlueprintCallable, Category = "Local Notifications")
	void SetHasAction(bool HasAction);

	UFUNCTION(BlueprintPure, Category = "Local Notifications")
	int32 GetApplicationIconBadgeNumber();

	UFUNCTION(BlueprintCallable, Category = "Local Notifications")
	void SetApplicationIconBadgeNumber(int32 BadgeNumber);

private:
	void Setup(FDateTime FireDate, FString TimeZone, FString AlertTitle, FString AlertBody, FString AlertAction, bool HasAction, int32 ApplicationIconBadgeNumber);
	
#if PLATFORM_IOS
	UILocalNotification* NotificationIOS;

	void Setup(UILocalNotification* Notification);
#endif

};
