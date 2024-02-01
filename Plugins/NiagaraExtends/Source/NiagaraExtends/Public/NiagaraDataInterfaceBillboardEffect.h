#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NiagaraDataInterface.h"
#include "NiagaraDataInterfaceBillboardEffect.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UNiagaraDataInterfaceBillboardEffect : public UNiagaraDataInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlayerControllerIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LockAxis;
    
    UNiagaraDataInterfaceBillboardEffect();
};
