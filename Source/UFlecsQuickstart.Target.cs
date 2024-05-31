// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UFlecsQuickstartTarget : TargetRules
{
	public UFlecsQuickstartTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		ExtraModuleNames.AddRange( new string[] { "UFlecsQuickstart", "FlecsLibrary", "UnrealFlecs", "MainGameplay"} );
	}
}
