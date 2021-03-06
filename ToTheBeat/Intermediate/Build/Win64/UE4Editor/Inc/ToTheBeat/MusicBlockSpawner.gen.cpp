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
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	TOTHEBEAT_API UClass* Z_Construct_UClass_AMusicBlock_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AMusicBlockSpawner::execAreNotesDone)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AreNotesDone();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMusicBlockSpawner::execSetDelay)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_delay);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetDelay(Z_Param_delay);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMusicBlockSpawner::execSetDirection)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_direction);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetDirection(Z_Param_Out_direction);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMusicBlockSpawner::execAddTransform)
	{
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddTransform(Z_Param_Out_transform);
		P_NATIVE_END;
	}
	void AMusicBlockSpawner::StaticRegisterNativesAMusicBlockSpawner()
	{
		UClass* Class = AMusicBlockSpawner::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddTransform", &AMusicBlockSpawner::execAddTransform },
			{ "AreNotesDone", &AMusicBlockSpawner::execAreNotesDone },
			{ "SetDelay", &AMusicBlockSpawner::execSetDelay },
			{ "SetDirection", &AMusicBlockSpawner::execSetDirection },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
	struct Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone_Statics
	{
		struct MusicBlockSpawner_eventAreNotesDone_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MusicBlockSpawner_eventAreNotesDone_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MusicBlockSpawner_eventAreNotesDone_Parms), &Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "Have all notes been spawned" },
		{ "ModuleRelativePath", "Public/MusicBlockSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMusicBlockSpawner, nullptr, "AreNotesDone", nullptr, nullptr, sizeof(MusicBlockSpawner_eventAreNotesDone_Parms), Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics
	{
		struct MusicBlockSpawner_eventSetDelay_Parms
		{
			float delay;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_delay_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_delay;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics::NewProp_delay_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics::NewProp_delay = { "delay", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MusicBlockSpawner_eventSetDelay_Parms, delay), METADATA_PARAMS(Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics::NewProp_delay_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics::NewProp_delay_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics::NewProp_delay,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "SetSpawnDelay" },
		{ "ModuleRelativePath", "Public/MusicBlockSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMusicBlockSpawner, nullptr, "SetDelay", nullptr, nullptr, sizeof(MusicBlockSpawner_eventSetDelay_Parms), Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMusicBlockSpawner_SetDelay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMusicBlockSpawner_SetDelay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics
	{
		struct MusicBlockSpawner_eventSetDirection_Parms
		{
			FVector direction;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_direction_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_direction;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics::NewProp_direction_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics::NewProp_direction = { "direction", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MusicBlockSpawner_eventSetDirection_Parms, direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics::NewProp_direction_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics::NewProp_direction_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics::NewProp_direction,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "Set Direction for Blocks" },
		{ "ModuleRelativePath", "Public/MusicBlockSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMusicBlockSpawner, nullptr, "SetDirection", nullptr, nullptr, sizeof(MusicBlockSpawner_eventSetDirection_Parms), Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMusicBlockSpawner_SetDirection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMusicBlockSpawner_SetDirection_Statics::FuncParams);
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_BPMusicBlock_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_m_BPMusicBlock;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_m_Tracks_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_Tracks_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_m_Tracks;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_FileBeats_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_m_FileBeats;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_FileLetters_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_m_FileLetters;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_BPM_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_BPM;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMusicBlockSpawner_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ToTheBeat,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMusicBlockSpawner_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMusicBlockSpawner_AddTransform, "AddTransform" }, // 3883105057
		{ &Z_Construct_UFunction_AMusicBlockSpawner_AreNotesDone, "AreNotesDone" }, // 1270088575
		{ &Z_Construct_UFunction_AMusicBlockSpawner_SetDelay, "SetDelay" }, // 3867268894
		{ &Z_Construct_UFunction_AMusicBlockSpawner_SetDirection, "SetDirection" }, // 4037775647
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMusicBlockSpawner_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MusicBlockSpawner.h" },
		{ "ModuleRelativePath", "Public/MusicBlockSpawner.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_BPMusicBlock_MetaData[] = {
		{ "Category", "MusicBlockSpawner" },
		{ "ModuleRelativePath", "Public/MusicBlockSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_BPMusicBlock = { "m_BPMusicBlock", nullptr, (EPropertyFlags)0x0044000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMusicBlockSpawner, m_BPMusicBlock), Z_Construct_UClass_AMusicBlock_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_BPMusicBlock_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_BPMusicBlock_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_Tracks_Inner = { "m_Tracks", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_Tracks_MetaData[] = {
		{ "Category", "MusicBlockSpawner" },
		{ "ModuleRelativePath", "Public/MusicBlockSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_Tracks = { "m_Tracks", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMusicBlockSpawner, m_Tracks), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_Tracks_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_Tracks_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_FileBeats_MetaData[] = {
		{ "Category", "MusicBlockSpawner" },
		{ "ModuleRelativePath", "Public/MusicBlockSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_FileBeats = { "m_FileBeats", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMusicBlockSpawner, m_FileBeats), METADATA_PARAMS(Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_FileBeats_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_FileBeats_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_FileLetters_MetaData[] = {
		{ "Category", "MusicBlockSpawner" },
		{ "ModuleRelativePath", "Public/MusicBlockSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_FileLetters = { "m_FileLetters", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMusicBlockSpawner, m_FileLetters), METADATA_PARAMS(Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_FileLetters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_FileLetters_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_BPM_MetaData[] = {
		{ "Category", "MusicBlockSpawner" },
		{ "ModuleRelativePath", "Public/MusicBlockSpawner.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_BPM = { "m_BPM", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMusicBlockSpawner, m_BPM), METADATA_PARAMS(Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_BPM_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_BPM_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMusicBlockSpawner_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_BPMusicBlock,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_Tracks_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_Tracks,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_FileBeats,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_FileLetters,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMusicBlockSpawner_Statics::NewProp_m_BPM,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMusicBlockSpawner_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMusicBlockSpawner>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMusicBlockSpawner_Statics::ClassParams = {
		&AMusicBlockSpawner::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMusicBlockSpawner_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMusicBlockSpawner_Statics::PropPointers),
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
	IMPLEMENT_CLASS(AMusicBlockSpawner, 1299847726);
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
