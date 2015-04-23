//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "ModuleManager.h"

class ILocalNotifications : public IModuleInterface
{

public:

	static inline ILocalNotifications& Get()
	{
		return FModuleManager::LoadModuleChecked< ILocalNotifications >( "LocalNotifications" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "LocalNotifications" );
	}
};

