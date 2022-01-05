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
	TOTHEBEAT_API UEnum* Z_Construct_UEnum_ToTheBeat_MusicBlockType();
	UPackage* Z_Construct_UPackage__Script_ToTheBeat();
	TOTHEBEAT_API UClass* Z_Construct_UClass_AMusicBlock_NoRegister();
	TOTHEBEAT_API UClass* Z_Construct_UClass_AMusicBlock();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UTextRenderComponent_NoRegister();
// End Cross Module References
	static UEnum* MusicBlockType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ToTheBeat_MusicBlockType, Z_Construct_UPackage__Script_ToTheBeat(), TEXT("MusicBlockType"));
		}
		return Singleton;
	}
	template<> TOTHEBEAT_API UEnum* StaticEnum<MusicBlockType>()
	{
		return MusicBlockType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_MusicBlockType(MusicBlockType_StaticEnum, TEXT("/Script/ToTheBeat"), TEXT("MusicBlockType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ToTheBeat_MusicBlockType_Hash() { return 1185308873U; }
	UEnum* Z_Construct_UEnum_ToTheBeat_MusicBlockType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ToTheBeat();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("MusicBlockType"), 0, Get_Z_Construct_UEnum_ToTheBeat_MusicBlockType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "MusicBlockType::Normal", (int64)MusicBlockType::Normal },
				{ "MusicBlockType::Slowdown", (int64)MusicBlockType::Slowdown },
				{ "MusicBlockType::Bomb", (int64)MusicBlockType::Bomb },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Bomb.Name", "MusicBlockType::Bomb" },
				{ "ModuleRelativePath", "Public/MusicBlock.h" },
				{ "Normal.Name", "MusicBlockType::Normal" },
				{ "Slowdown.Name", "MusicBlockType::Slowdown" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ToTheBeat,
				nullptr,
				"MusicBlockType",
				"MusicBlockType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_pTextRenderComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_pTextRenderComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_MaxSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_MaxSpeed;
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_pTextRenderComponent_MetaData[] = {
		{ "Category", "MusicBlock" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MusicBlock.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_pTextRenderComponent = { "m_pTextRenderComponent", nullptr, (EPropertyFlags)0x0040000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMusicBlock, m_pTextRenderComponent), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_pTextRenderComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_pTextRenderComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_MaxSpeed_MetaData[] = {
		{ "Category", "MusicBlock" },
		{ "ModuleRelativePath", "Public/MusicBlock.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_MaxSpeed = { "m_MaxSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMusicBlock, m_MaxSpeed), METADATA_PARAMS(Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_MaxSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_MaxSpeed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMusicBlock_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_pTextRenderComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMusicBlock_Statics::NewProp_m_MaxSpeed,
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
	IMPLEMENT_CLASS(AMusicBlock, 3007658228);
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
