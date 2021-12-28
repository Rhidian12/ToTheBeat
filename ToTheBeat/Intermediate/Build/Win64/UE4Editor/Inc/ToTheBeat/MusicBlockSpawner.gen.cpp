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
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
// End Cross Module References
	DEFINE_FUNCTION(AMusicBlockSpawner::execAddTransform)
	{
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddTransform(Z_Param_Out_transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMusicBlockSpawner::execAddMaterial)
	{
		P_GET_OBJECT(UMaterial,Z_Param_pMaterial);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddMaterial(Z_Param_pMaterial);
		P_NATIVE_END;
	}
	void AMusicBlockSpawner::StaticRegisterNativesAMusicBlockSpawner()
	{
		UClass* Class = AMusicBlockSpawner::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddMaterial", &AMusicBlockSpawner::execAddMaterial },
			{ "AddTransform", &AMusicBlockSpawner::execAddTransform },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics
	{
		struct MusicBlockSpawner_eventAddMaterial_Parms
		{
			const UMaterial* pMaterial;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_pMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_pMaterial;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics::NewProp_pMaterial_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics::NewProp_pMaterial = { "pMaterial", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MusicBlockSpawner_eventAddMaterial_Parms, pMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics::NewProp_pMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics::NewProp_pMaterial_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics::NewProp_pMaterial,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "Add Material to assign to blocks" },
		{ "ModuleRelativePath", "Public/MusicBlockSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMusicBlockSpawner, nullptr, "AddMaterial", nullptr, nullptr, sizeof(MusicBlockSpawner_eventAddMaterial_Parms), Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics
	{
		struct MusicBlockSpawner_eventAddTransform_Parms
		{
			FTransform transform;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_transform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_transform;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics::NewProp_transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics::NewProp_transform = { "transform", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MusicBlockSpawner_eventAddTransform_Parms, transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics::NewProp_transform_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics::NewProp_transform_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics::NewProp_transform,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "Add Transform for block to spawn" },
		{ "ModuleRelativePath", "Public/MusicBlockSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMusicBlockSpawner, nullptr, "AddTransform", nullptr, nullptr, sizeof(MusicBlockSpawner_eventAddTransform_Parms), Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMusicBlockSpawner_AddTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMusicBlockSpawner_AddTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMusicBlockSpawner_NoRegister()
	{
		return AMusicBlockSpawner::StaticClass();
	}
	struct Z_Construct_UClass_AMusicBlockSpawner_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
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
	const FClassFunctionLinkInfo Z_Construct_UClass_AMusicBlockSpawner_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMusicBlockSpawner_AddMaterial, "AddMaterial" }, // 507474711
		{ &Z_Construct_UFunction_AMusicBlockSpawner_AddTransform, "AddTransform" }, // 3883105057
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
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(AMusicBlockSpawner, 305073850);
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
