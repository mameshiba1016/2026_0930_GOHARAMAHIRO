#pragma once
#include "Hand.h"

class Player;
class CPU;

class Judge
{
private:
    Result result_;

private:
    Result CompareHands(Hand playerHand,Hand cpuHand) const;

    const char* GetHandName(Hand hand) const;

public:
    Judge();

    void Check(const Player* player,const CPU* cpu);

    void ShowResult(const Player* player,const CPU* cpu) const;

    Result GetResult() const;
};