// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
struct FTransform;
#ifdef TOTHEBEAT_MusicBlockSpawner_generated_h
#error "MusicBlockSpawner.generated.h already included, missing '#pragma once' in MusicBlockSpawner.h"
#endif
#define TOTHEBEAT_MusicBlockSpawner_generated_h

#define ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_SPARSE_DATA
#define ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAreNotesDone); \
	DECLARE_FUNCTION(execSetDelay); \
	DECLARE_FUNCTION(execSetDirection); \
	DECLARE_FUNCTION(execAddTransform);


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAreNotesDone); \
	DECLARE_FUNCTION(execSetDelay); \
	DECLARE_FUNCTION(execSetDirection); \
	DECLARE_FUNCTION(execAddTransform);


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMusicBlockSpawner(); \
	friend struct Z_Construct_UClass_AMusicBlockSpawner_Statics; \
public: \
	DECLARE_CLASS(AMusicBlockSpawner, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToTheBeat"), NO_API) \
	DECLARE_SERIALIZER(AMusicBlockSpawner)


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMusicBlockSpawner(); \
	friend struct Z_Construct_UClass_AMusicBlockSpawner_Statics; \
public: \
	DECLARE_CLASS(AMusicBlockSpawner, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToTheBeat"), NO_API) \
	DECLARE_SERIALIZER(AMusicBlockSpawner)


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMusicBlockSpawner(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMusicBlockSpawner) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMusicBlockSpawner); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMusicBlockSpawner); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMusicBlockSpawner(AMusicBlockSpawner&&); \
	NO_API AMusicBlockSpawner(const AMusicBlockSpawner&); \
public:


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMusicBlockSpawner(AMusicBlockSpawner&&); \
	NO_API AMusicBlockSpawner(const AMusicBlockSpawner&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMusicBlockSpawner); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMusicBlockSpawner); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMusicBlockSpawner)


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_BPMusicBlock() { return STRUCT_OFFSET(AMusicBlockSpawner, m_BPMusicBlock); } \
	FORCEINLINE static uint32 __PPO__m_Tracks() { return STRUCT_OFFSET(AMusicBlockSpawner, m_Tracks); } \
	FORCEINLINE static uint32 __PPO__m_FileBeats() { return STRUCT_OFFSET(AMusicBlockSpawner, m_FileBeats); } \
	FORCEINLINE static uint32 __PPO__m_FileLetters() { return STRUCT_OFFSET(AMusicBlockSpawner, m_FileLetters); } \
	FORCEINLINE static uint32 __PPO__m_BPM() { return STRUCT_OFFSET(AMusicBlockSpawner, m_BPM); }


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_12_PROLOG
#define ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_PRIVATE_PROPERTY_OFFSET \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_SPARSE_DATA \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_RPC_WRAPPERS \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_INCLASS \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_PRIVATE_PROPERTY_OFFSET \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_SPARSE_DATA \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_INCLASS_NO_PURE_DECLS \
	ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TOTHEBEAT_API UClass* StaticClass<class AMusicBlockSpawner>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ToTheBeat_Source_ToTheBeat_Public_MusicBlockSpawner_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
