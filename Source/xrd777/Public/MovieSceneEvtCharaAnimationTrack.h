#pragma once
#include "CoreMinimal.h"
#include "MovieSceneObjectBindingID.h"
#include "MovieScene/Public/Evaluation/MovieSceneEvalTemplate.h"
#include "Compilation/IMovieSceneTrackTemplateProducer.h"
#include "EAtlCharaAnimFireEventsAtPosition.h"
#include "MovieSceneEvtConditionalBranchTrack.h"
#include "MovieSceneEvtCharaAnimationTrack.generated.h"

class UMovieSceneSection;

UCLASS(Blueprintable, MinimalAPI)
class UMovieSceneEvtCharaAnimationTrack : public UMovieSceneEvtConditionalBranchTrack, public IMovieSceneTrackTemplateProducer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bFireEventsWhenForwards : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bFireEventsWhenBackwards : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EAtlCharaAnimFireEventsAtPosition EventPosition;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FMovieSceneObjectBindingID> EventReceivers;

private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    TArray<UMovieSceneSection*> Sections;

public:
    UMovieSceneEvtCharaAnimationTrack(const FObjectInitializer& Init);

    // UMovieSceneTrack interface
    virtual bool IsEmpty() const override;
    virtual void AddSection(UMovieSceneSection& Section) override;
    virtual void RemoveSection(UMovieSceneSection& Section) override;
    virtual void RemoveSectionAt(int32 SectionIndex) override;
    virtual bool SupportsType(TSubclassOf<UMovieSceneSection> SectionClass) const override;
    virtual UMovieSceneSection* CreateNewSection() override;
    virtual const TArray<UMovieSceneSection*>& GetAllSections() const override;
    virtual bool HasSection(const UMovieSceneSection& Section) const override;
    virtual bool SupportsMultipleRows() const override { return true; }

    // IMovieSceneTrackTemplateProducer interface
    virtual FMovieSceneEvalTemplatePtr CreateTemplateForSection(const UMovieSceneSection& InSection) const;

#if WITH_EDITORONLY_DATA
    virtual FText GetDefaultDisplayName() const override;
#endif
};

