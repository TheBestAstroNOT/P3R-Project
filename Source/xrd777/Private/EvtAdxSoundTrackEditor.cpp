// (C)ATLUS. (C)SEGA. :3

#if WITH_EDITORONLY_DATA // Crimes against hunanity

#pragma once

#include "EvtAdxSoundTrackEditor.h"
#include "Core/Public/Math/RangeBound.h"

#define LOCTEXT_NAMESPACE "FEvtAdxSoundFadeEditor"

// Constructors

TSharedRef<ISequencerTrackEditor> FEvtAdxSoundTrackEditor::CreateTrackEditor(TSharedRef<ISequencer> InSequencer) {
	return MakeShareable(new FEvtAdxSoundTrackEditor(InSequencer));
}

FEvtAdxSoundTrackEditor::FEvtAdxSoundTrackEditor(TSharedRef<ISequencer> InSequencer)
	: FMovieSceneTrackEditor(InSequencer)
{

}

/*
TSharedRef<ISequencerSection> FEvtAdxSoundTrackEditor::MakeSectionInterface(UMovieSceneSection& SectionObject, UMovieSceneTrack& Track, FGuid ObjectBinding) {
	return MakeShareable(new FEvtAdxSoundFadeSection(SectionObject));
}
*/

// Methods

void FEvtAdxSoundTrackEditor::BuildAddTrackMenu(FMenuBuilder& MenuBuilder) {
	MenuBuilder.AddMenuEntry(
		LOCTEXT("AddEvtAdxSoundTrack", "Atlus Event ADX Sound Track"),
		LOCTEXT("AddEvtAdxSoundTrackTooltip", "TODO: Description"),
		FSlateIcon(FEditorStyle::GetStyleSetName(), "Sequencer.Tracks.Audio"),
		FUIAction(
			FExecuteAction::CreateRaw(this, &FEvtAdxSoundTrackEditor::HandleAddEvtAdxSoundTrackMenuEntryExecute),
			FCanExecuteAction::CreateRaw(this, &FEvtAdxSoundTrackEditor::HandleAddEvtAdxSoundTrackMenuEntryCanExecute)
		)
	);
}

bool FEvtAdxSoundTrackEditor::SupportsSequence(UMovieSceneSequence* InSequence) const {
	return true; // Force this to be true, checking if track is supported normally doesn't work
	ETrackSupport TrackSupported = InSequence ? InSequence->IsTrackSupported(UMovieSceneEvtAdxSoundTrack::StaticClass()) : ETrackSupport::NotSupported;
	return TrackSupported == ETrackSupport::Supported;
}

bool FEvtAdxSoundTrackEditor::SupportsType(TSubclassOf<UMovieSceneTrack> Type) const {
	return (Type == UMovieSceneEvtAdxSoundTrack::StaticClass());
}

const FSlateBrush* FEvtAdxSoundTrackEditor::GetIconBrush() const
{
	return FEditorStyle::GetBrush("Sequencer.Tracks.Audio");
}

// Callbacks

void FEvtAdxSoundTrackEditor::HandleAddEvtAdxSoundTrackMenuEntryExecute() {
	UMovieScene* MovieScene = GetFocusedMovieScene();
	if (MovieScene == nullptr || MovieScene->IsReadOnly()) {
		return;
	}
	const FScopedTransaction Transaction(LOCTEXT("AddEvtAdxSoundTrack_Transaction", "P3RE Event ADX Sound Track"));
	MovieScene->Modify();
	UMovieSceneEvtAdxSoundTrack* NewTrack = MovieScene->AddMasterTrack<UMovieSceneEvtAdxSoundTrack>();
	ensure(NewTrack);
	UMovieSceneSection* NewSection = NewTrack->CreateNewSection();
	NewTrack->AddSection(*NewSection);
	if (GetSequencer().IsValid()) {
		GetSequencer()->OnAddTrack(NewTrack, FGuid());
	}
}

bool FEvtAdxSoundTrackEditor::HandleAddEvtAdxSoundTrackMenuEntryCanExecute() const
{
	UMovieScene* FocusedMovieScene = GetFocusedMovieScene();
	return FocusedMovieScene != nullptr;
}

#undef LOCTEXT_NAMESPACE

#endif