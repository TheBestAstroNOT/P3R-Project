#pragma once
#include "CoreMinimal.h"
#include "MovieSceneNameableTrack.h"
#include "MovieSceneObjectBindingID.h"
#include "Compilation/IMovieSceneTrackTemplateProducer.h"
#include "EFireEventsAtPositionggg.h"
#include "MovieSceneEvtDialogueOptionsTrack.generated.h"

class UMovieSceneSection;

UCLASS(Blueprintable, MinimalAPI)
class UMovieSceneEvtDialogueOptionsTrack : public UMovieSceneNameableTrack, public IMovieSceneTrackTemplateProducer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bFireEventsWhenForwards : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bFireEventsWhenBackwards : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EFireEventsAtPositionggg EventPosition;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FMovieSceneObjectBindingID> EventReceivers;

private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    TArray<UMovieSceneSection*> Sections;

public:
    UMovieSceneEvtDialogueOptionsTrack(const FObjectInitializer& Init);

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
    virtual void PostCompile(FMovieSceneEvaluationTrack& Track, const FMovieSceneTrackCompilerArgs& Args) const override;

    // IMovieSceneTrackTemplateProducer interface
    virtual FMovieSceneEvalTemplatePtr CreateTemplateForSection(const UMovieSceneSection& InSection) const;

#if WITH_EDITORONLY_DATA
    virtual FText GetDefaultDisplayName() const override;
#endif
};

