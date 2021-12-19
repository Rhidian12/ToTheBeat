// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToTheBeat/ToTheBeatGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeToTheBeatGameModeBase() {}
// Cross Module References
	TOTHEBEAT_API UClass* Z_Construct_UClass_AToTheBeatGameModeBase_NoRegister();
	TOTHEBEAT_API UClass* Z_Construct_UClass_AToTheBeatGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ToTheBeat();
// End Cross Module References
	void AToTheBeatGameModeBase::StaticRegisterNativesAToTheBeatGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AToTheBeatGameModeBase_NoRegister()
	{
		return AToTheBeatGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AToTheBeatGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AToTheBeatGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ToTheBeat,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AToTheBeatGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ToTheBeatGameModeBase.h" },
		{ "ModuleRelativePath", "ToTheBeatGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AToTheBeatGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AToTheBeatGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AToTheBeatGameModeBase_Statics::ClassParams = {
		&AToTheBeatGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AToTheBeatGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AToTheBeatGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AToTheBeatGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AToTheBeatGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AToTheBeatGameModeBase, 162795854);
	template<> TOTHEBEAT_API UClass* StaticClass<AToTheBeatGameModeBase>()
	{
		return AToTheBeatGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AToTheBeatGameModeBase(Z_Construct_UClass_AToTheBeatGameModeBase, &AToTheBeatGameModeBase::StaticClass, TEXT("/Script/ToTheBeat"), TEXT("AToTheBeatGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AToTheBeatGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
