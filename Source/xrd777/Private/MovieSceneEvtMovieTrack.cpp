#include "MovieSceneEvtMovieTrack.h"
#include <xrd777/Public/MovieSceneEvtMovieSection.h>
#include <xrd777/Public/MovieSceneEvtMovieTemplate.h>
#include "Tracks/MovieSceneSpawnTrack.h"
#include "IMovieSceneTracksModule.h"
#include "Evaluation/MovieSceneEvaluationTrack.h"

#define LOCTEXT_NAMESPACE "MovieSceneEvtMovieTrack"

UMovieSceneEvtMovieTrack::UMovieSceneEvtMovieTrack(const FObjectInitializer& Init)
	: Super(Init)
{
	bFireEventsWhenForwards = true;
	bFireEventsWhenBackwards = true;
}

bool UMovieSceneEvtMovieTrack::IsEmpty() const
{
	return Sections.Num() == 0;
}


void UMovieSceneEvtMovieTrack::AddSection(UMovieSceneSection& Section)
{
	Sections.Add(&Section);
}


void UMovieSceneEvtMovieTrack::RemoveSection(UMovieSceneSection& Section)
{
	Sections.Remove(&Section);
}

void UMovieSceneEvtMovieTrack::RemoveSectionAt(int32 SectionIndex)
{
	Sections.RemoveAt(SectionIndex);
}

bool UMovieSceneEvtMovieTrack::SupportsType(TSubclassOf<UMovieSceneSection> SectionClass) const
{
	return SectionClass == UMovieSceneEvtMovieSection::StaticClass();
}

UMovieSceneSection* UMovieSceneEvtMovieTrack::CreateNewSection()
{
	return NewObject<UMovieSceneEvtMovieSection>(this, NAME_None, RF_Transactional);
}

const TArray<UMovieSceneSection*>& UMovieSceneEvtMovieTrack::GetAllSections() const
{
	return Sections;
}


bool UMovieSceneEvtMovieTrack::HasSection(const UMovieSceneSection& Section) const
{
	return Sections.Contains(&Section);
}


#if WITH_EDITORONLY_DATA
FText UMovieSceneEvtMovieTrack::GetDefaultDisplayName() const
{
	return LOCTEXT("DisplayName", "Evt Movie");
}
#endif

void UMovieSceneEvtMovieTrack::PostCompile(FMovieSceneEvaluationTrack& Track, const FMovieSceneTrackCompilerArgs& Args) const {
	Track.SetEvaluationGroup(IMovieSceneTracksModule::GetEvaluationGroupName(EBuiltInEvaluationGroup::SpawnObjects));
	Track.SetEvaluationPriority(UMovieSceneSpawnTrack::GetEvaluationPriority() - 100);
	Track.SetEvaluationMethod(EEvaluationMethod::Swept);

	for (int i = 0; i < Track.GetChildTemplates().Num(); i++) {
		((FMovieSceneEvtMovieTemplate&)Track.GetChildTemplate(i)).CondBranchData = CondBranchData;
	}
}

FMovieSceneEvalTemplatePtr UMovieSceneEvtMovieTrack::CreateTemplateForSection(const UMovieSceneSection& InSection) const {
	return FMovieSceneEvtMovieTemplate(*CastChecked<UMovieSceneEvtMovieSection>(&InSection));
}

#undef LOCTEXT_NAMESPACE