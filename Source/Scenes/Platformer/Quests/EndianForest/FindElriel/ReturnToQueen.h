#pragma once

#include "Engine/Quests/QuestTask.h"

class Elriel;
class Guano;
class QueenLiana;
class QuestLine;
class Scrappy;
class Squally;

class ReturnToQueen : public QuestTask
{
public:
	static ReturnToQueen* create(GameObject* owner, QuestLine* questLine);

	static const std::string MapKeyQuest;

protected:
	ReturnToQueen(GameObject* owner, QuestLine* questLine);
	~ReturnToQueen();

	void onLoad(QuestState questState) override;
	void onActivate(bool isActiveThroughSkippable) override;
	void onComplete() override;
	void onSkipped() override;

private:
	typedef QuestTask super;

	void runCinematicSequence();
	void setPostText();

	Elriel* elriel;
	Guano* guano;
	QueenLiana* queenLiana;
	Scrappy* scrappy;
	Squally* squally;
};
