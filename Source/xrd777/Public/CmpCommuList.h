#pragma once
#include "CoreMinimal.h"
#include "UIScene.h"
#include "CmpCommuList.generated.h"

class ACmpMainActor;
class AUICmpCommu;

UCLASS(Blueprintable)
class XRD777_API UCmpCommuList : public UUIScene {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AUICmpCommu* Context_;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AUICmpCommu* pParent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACmpMainActor* pMainActor;
    
public:
    UCmpCommuList();
};
