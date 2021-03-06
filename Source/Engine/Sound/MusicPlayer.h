#pragma once
#include <queue>
#include "Engine/GlobalNode.h"

class Music;

class MusicPlayer : public GlobalNode
{
public:
	static void registerGlobalNode();

	static void popMusic();
	static void play(Music* music, bool repeat = true, float startDelay = 0.0f);
	static void purgueQueue();
	static void registerMusic(Music* music);
	static void destroyMusic(Music* music);

private:
	typedef GlobalNode super;
	MusicPlayer();
	virtual ~MusicPlayer();

	static MusicPlayer* getInstance();

	static MusicPlayer* instance;

	std::queue<Music*> songQueue;
};
