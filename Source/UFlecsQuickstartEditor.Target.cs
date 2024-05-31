// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UFlecsQuickstartEditorTarget : TargetRules
{
	public UFlecsQuickstartEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		ExtraModuleNames.AddRange( new string[] { "UFlecsQuickstart", "FlecsLibrary", "UnrealFlecs", "MainGameplay" });
	}
}
