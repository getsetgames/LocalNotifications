//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "LocalNotificationsPrivatePCH.h"

DEFINE_LOG_CATEGORY(LogLocalNotifications);

#define LOCTEXT_NAMESPACE "LocalNotifications"

class FLocalNotifications : public ILocalNotifications
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FLocalNotifications, LocalNotifications )

void FLocalNotifications::StartupModule()
{

}


void FLocalNotifications::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE
