#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FldShortcutNameTableRowBase.generated.h"

USTRUCT(BlueprintType)
struct FFldShortcutNameTableRowBase : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    XRD777_API FFldShortcutNameTableRowBase();
};
