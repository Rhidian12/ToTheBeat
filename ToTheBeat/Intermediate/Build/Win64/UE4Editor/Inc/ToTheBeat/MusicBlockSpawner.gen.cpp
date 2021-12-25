// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToTheBeat/Public/MusicBlockSpawner.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMusicBlockSpawner() {}
// Cross Module References
	TOTHEBEAT_API UClass* Z_Construct_UClass_AMusicBlockSpawner_NoRegister();
	TOTHEBEAT_API UClass* Z_Construct_UClass_AMusicBlockSpawner();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ToTheBeat();
// End Cross Module References
	void AMusicBlockSpawner::StaticRegisterNativesAMusicBlockSpawner()
	{
	}
	UClass* Z_Construct_UClass_AMusicBlockSpawner_NoRegister()
	{
		return AMusicBlockSpawner::StaticClass();
	}
	struct Z_Construct_UClass_AMusicBlockSpawner_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMusicBlockSpawner_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ToTheBeat,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMusicBlockSpawner_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MusicBlockSpawner.h" },
		{ "ModuleRelativePath", "Public/MusicBlockSpawner.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMusicBlockSpawner_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMusicBlockSpawner>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMusicBlockSpawner_Statics::ClassParams = {
		&AMusicBlockSpawner::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMusicBlockSpawner_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMusicBlockSpawner_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMusicBlockSpawner()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMusicBlockSpawner_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMusicBlockSpawner, 679889969);
	template<> TOTHEBEAT_API UClass* StaticClass<AMusicBlockSpawner>()
	{
		return AMusicBlockSpawner::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMusicBlockSpawner(Z_Construct_UClass_AMusicBlockSpawner, &AMusicBlockSpawner::StaticClass, TEXT("/Script/ToTheBeat"), TEXT("AMusicBlockSpawner"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMusicBlockSpawner);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
