#pragma once
#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "CustomizedRawInputDeviceButtonProperties.generated.h"

USTRUCT(BlueprintType)
struct CUSTOMIZEDRAWINPUT_API FCustomizedRawInputDeviceButtonProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bEnabled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FKey Key;
    
    FCustomizedRawInputDeviceButtonProperties();
};

