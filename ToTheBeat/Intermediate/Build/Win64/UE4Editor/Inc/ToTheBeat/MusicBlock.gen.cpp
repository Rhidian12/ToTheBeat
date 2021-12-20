// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToTheBeat/Public/MusicBlock.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMusicBlock() {}
// Cross Module References
	TOTHEBEAT_API UClass* Z_Construct_UClass_AMusicBlock_NoRegister();
	TOTHEBEAT_API UClass* Z_Construct_UClass_AMusicBlock();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ToTheBeat();
// End Cross Module References
	void AMusicBlock::StaticRegisterNativesAMusicBlock()
	{
	}
	UClass* Z_Construct_UClass_AMusicBlock_NoRegister()
	{
		return AMusicBlock::StaticClass();
	}
	struct Z_Construct_UClass_AMusicBlock_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_Speed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_Speed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMusicBlock_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ToTheBeat,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMusicBlock_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MusicBlock.h" },
		{ "ModuleRelativePath", "Public/MusicBlock.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_Speed_MetaData[] = {
		{ "Category", "MusicBlock" },
		{ "ModuleRelativePath", "Public/MusicBlock.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_Speed = { "m_Speed", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMusicBlock, m_Speed), METADATA_PARAMS(Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_Speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_Speed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMusicBlock_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_Speed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMusicBlock_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMusicBlock>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMusicBlock_Statics::ClassParams = {
		&AMusicBlock::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMusicBlock_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMusicBlock_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMusicBlock_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMusicBlock_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMusicBlock()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMusicBlock_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMusicBlock, 3884183582);
	template<> TOTHEBEAT_API UClass* StaticClass<AMusicBlock>()
	{
		return AMusicBlock::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMusicBlock(Z_Construct_UClass_AMusicBlock, &AMusicBlock::StaticClass, TEXT("/Script/ToTheBeat"), TEXT("AMusicBlock"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMusicBlock);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
