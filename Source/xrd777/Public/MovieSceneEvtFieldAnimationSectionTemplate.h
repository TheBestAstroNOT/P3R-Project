// (C)ATLUS. (C)SEGA. :3

#pragma once
#include "CoreMinimal.h"
#include "Evaluation/MovieSceneEvalTemplate.h"
#include "MovieSceneObjectBindingID.h"
#include "MovieSceneEvtConditionalBranchData.h"
#include "MovieSceneEvtFieldAnimationSection.h"
#include "MovieSceneEvtFieldAnimationSectionData.h"
#include "MovieSceneEvtFieldAnimationSectionTemplate.generated.h"

USTRUCT(BlueprintType)
struct FMovieSceneEvtFieldAnimationSectionTemplate : public FMovieSceneEvalTemplate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneEvtFieldAnimationSectionData EventData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMovieSceneObjectBindingID> EventReceivers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bFireEventsWhenForwards: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bFireEventsWhenBackwards: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneEvtConditionalBranchData CondBranchData;
    
    XRD777_API FMovieSceneEvtFieldAnimationSectionTemplate();
    FMovieSceneEvtFieldAnimationSectionTemplate(const UMovieSceneEvtFieldAnimationSection& Section);
private:
    virtual UScriptStruct& GetScriptStructImpl() const override { return *StaticStruct(); }
    virtual void Evaluate(const FMovieSceneEvaluationOperand& Operand, const FMovieSceneContext& Context, const FPersistentEvaluationData& PersistentData, FMovieSceneExecutionTokens& ExecutionTokens) const override;
};

