// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hello.generated.h"

/**
 * 
 */
UCLASS()
class UOBJECTSYSTEM_API UHello : public UObject
{
	GENERATED_BODY()

		// UObjectSystem_Source_UObjectSystem_Public_Hello_h_14_GENERATED_BODY
		//PRAGMA_DISABLE_DEPRECATION_WARNINGS 
public: 
		//UObjectSystem_Source_UObjectSystem_Public_Hello_h_14_PRIVATE_PROPERTY_OFFSET 
		//UObjectSystem_Source_UObjectSystem_Public_Hello_h_14_SPARSE_DATA 
		//UObjectSystem_Source_UObjectSystem_Public_Hello_h_14_RPC_WRAPPERS_NO_PURE_DECLS 
		//UObjectSystem_Source_UObjectSystem_Public_Hello_h_14_INCLASS_NO_PURE_DECLS 

private: 
	static void StaticRegisterNativesUHello(); 
	friend struct Z_Construct_UClass_UHello_Statics; 

private: 
	UHello& operator=(UHello&&);   
	UHello& operator=(const UHello&);   
	NO_API static UClass* GetPrivateStaticClass();
public: 
	/** Bitwise union of #EClassFlags pertaining to this class.*/ 
	enum { StaticClassFlags = COMPILED_IN_FLAGS(0) }; 
	/** Typedef for the base class ({{ typedef-type }}) */ 
	typedef UObject Super;
	/** Typedef for {{ typedef-type }}. */ 
	typedef UHello ThisClass; 
	/** Returns a UClass object representing this class at runtime */ 
	inline static UClass* StaticClass() 
	{ 
		return GetPrivateStaticClass(); 
	} 
	/** Returns the package this class belongs in */ 
	inline static const TCHAR* StaticPackage() 
	{ 
		return TEXT("/Script/UObjectSystem");
	} 
	/** Returns the static cast flags for this class */ 
	inline static EClassCastFlags StaticClassCastFlags() 
	{ 
		return CASTCLASS_None;
	} 
	/** For internal use only; use StaticConstructObject() to create new objects. */ 
	inline void* operator new(const size_t InSize, EInternal InInternalOnly, UObject* InOuter = (UObject*)GetTransientPackage(), FName InName = NAME_None, EObjectFlags InSetFlags = RF_NoFlags) 
	{ 
		return StaticAllocateObject(StaticClass(), InOuter, InName, InSetFlags); 
	} 
	/** For internal use only; use StaticConstructObject() to create new objects. */ 
	inline void* operator new(const size_t InSize, EInternal* InMem) 
	{ 
		return (void*)InMem; 
	}
public:
	friend FArchive& operator<<(FArchive& Ar, UHello*& Res) 
	{ 
		return Ar << (UObject*&)Res; 
	} 
		friend void operator<<(FStructuredArchive::FSlot InSlot, UHello*& Res) 
	{ 
		InSlot << (UObject*&)Res; 
	}

		/** Standard constructor, called after all reflected properties have been initialized */ 
		NO_API UHello(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; 
private: 
		/** Private move- and copy-constructors, should never be used */ 
		NO_API UHello(UHello&&); 
		NO_API UHello(const UHello&); 
public: 
		DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHello); 
		DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHello); 
		DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHello)
private: 
		//PRAGMA_ENABLE_DEPRECATION_WARNINGS
};
