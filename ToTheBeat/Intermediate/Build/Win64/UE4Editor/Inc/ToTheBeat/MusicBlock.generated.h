// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TOTHEBEAT_MusicBlock_generated_h
#error "MusicBlock.generated.h already included, missing '#pragma once' in MusicBlock.h"
#endif
#define TOTHEBEAT_MusicBlock_generated_h

#define ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_SPARSE_DATA
#define ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_RPC_WRAPPERS
#define ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_RPC_WRAPPERS_NO_PURE_DECLS
#define ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMusicBlock(); \
	friend struct Z_Construct_UClass_AMusicBlock_Statics; \
public: \
	DECLARE_CLASS(AMusicBlock, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToTheBeat"), NO_API) \
	DECLARE_SERIALIZER(AMusicBlock)


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_INCLASS \
private: \
	static void StaticRegisterNativesAMusicBlock(); \
	friend struct Z_Construct_UClass_AMusicBlock_Statics; \
public: \
	DECLARE_CLASS(AMusicBlock, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToTheBeat"), NO_API) \
	DECLARE_SERIALIZER(AMusicBlock)


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMusicBlock(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMusicBlock) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMusicBlock); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMusicBlock); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMusicBlock(AMusicBlock&&); \
	NO_API AMusicBlock(const AMusicBlock&); \
public:


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMusicBlock(AMusicBlock&&); \
	NO_API AMusicBlock(const AMusicBlock&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMusicBlock); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMusicBlock); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMusicBlock)


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_pTextRenderComponent() { return STRUCT_OFFSET(AMusicBlock, m_pTextRenderComponent); } \
	FORCEINLINE static uint32 __PPO__m_MaxSpeed() { return STRUCT_OFFSET(AMusicBlock, m_MaxSpeed); }


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_21_PROLOG
#define ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_PRIVATE_PROPERTY_OFFSET \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_SPARSE_DATA \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_RPC_WRAPPERS \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_INCLASS \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_PRIVATE_PROPERTY_OFFSET \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_SPARSE_DATA \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_INCLASS_NO_PURE_DECLS \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TOTHEBEAT_API UClass* StaticClass<class AMusicBlock>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ToTheBeat_Source_ToTheBeat_Public_MusicBlock_h


#define FOREACH_ENUM_MUSICBLOCKTYPE(op) \
	op(MusicBlockType::Normal) \
	op(MusicBlockType::Slowdown) \
	op(MusicBlockType::Bomb) 

enum class MusicBlockType;
template<> TOTHEBEAT_API UEnum* StaticEnum<MusicBlockType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
