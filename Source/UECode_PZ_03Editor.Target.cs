// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UECode_PZ_03EditorTarget : TargetRules
{
	public UECode_PZ_03EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("UECode_PZ_03");
	}
}
