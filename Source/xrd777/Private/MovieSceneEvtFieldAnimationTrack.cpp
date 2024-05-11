#include "MovieSceneEvtFieldAnimationTrack.h"
#include <xrd777/Public/MovieSceneEvtFieldAnimationSection.h>

#define LOCTEXT_NAMESPACE "MovieSceneEvtFadeAnimationTrack"

UMovieSceneEvtFieldAnimationTrack::UMovieSceneEvtFieldAnimationTrack(const FObjectInitializer& Init)
	: Super(Init)
{
	bFireEventsWhenForwards = true;
	bFireEventsWhenBackwards = true;
}

bool UMovieSceneEvtFieldAnimationTrack::IsEmpty() const
{
	return Sections.Num() == 0;
}


void UMovieSceneEvtFieldAnimationTrack::AddSection(UMovieSceneSection& Section)
{
	Sections.Add(&Section);
}


void UMovieSceneEvtFieldAnimationTrack::RemoveSection(UMovieSceneSection& Section)
{
	Sections.Remove(&Section);
}

void UMovieSceneEvtFieldAnimationTrack::RemoveSectionAt(int32 SectionIndex)
{
	Sections.RemoveAt(SectionIndex);
}

bool UMovieSceneEvtFieldAnimationTrack::SupportsType(TSubclassOf<UMovieSceneSection> SectionClass) const
{
	return SectionClass == UMovieSceneEvtFieldAnimationSection::StaticClass();
}

UMovieSceneSection* UMovieSceneEvtFieldAnimationTrack::CreateNewSection()
{
	return NewObject<UMovieSceneEvtFieldAnimationSection>(this, NAME_None, RF_Transactional);
}

const TArray<UMovieSceneSection*>& UMovieSceneEvtFieldAnimationTrack::GetAllSections() const
{
	return Sections;
}


bool UMovieSceneEvtFieldAnimationTrack::HasSection(const UMovieSceneSection& Section) const
{
	return Sections.Contains(&Section);
}


#if WITH_EDITORONLY_DATA
FText UMovieSceneEvtFieldAnimationTrack::GetDefaultDisplayName() const
{
	return LOCTEXT("DisplayName", "Evt Field Anim");
}
#endif

#undef LOCTEXT_NAMESPACE