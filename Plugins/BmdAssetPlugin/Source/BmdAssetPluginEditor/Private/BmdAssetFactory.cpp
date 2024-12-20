// (C)ATLUS. (C)SEGA. :3
#include "BmdAssetFactory.h"

UBmdAssetFactory::UBmdAssetFactory()
{
	SupportedClass = UBmdAsset::StaticClass();
	bCreateNew = true;
}

UObject* UBmdAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) {
	return NewObject<UBmdAsset>(InParent, Class, Name, Flags, Context);
}