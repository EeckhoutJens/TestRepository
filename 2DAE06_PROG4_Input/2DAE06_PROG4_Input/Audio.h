#pragma once
#include <iostream>
class Audio
{
public:
	virtual ~Audio() = default;
	virtual void PlaySound(int SoundID) = 0;
	virtual void StopSound(int SoundID) = 0;
	virtual void StopAllSounds() = 0;
};

class ConsoleAudio final : public Audio
{
public:
	void PlaySound(int SoundID) override { std::cout << "Currently playing SoundID: " << SoundID << '\n'; }
	void StopSound(int SoundID) override { std::cout << "Stopped playing SoundID:" << SoundID << '\n'; }
	void StopAllSounds() override { std::cout << "Stopped playing all audio\n"; }
};

class NullAudio final : public Audio
{
public:
	void PlaySound(int SoundID) override{}
	void StopSound(int SoundID) override{}
	void StopAllSounds() override{}
};