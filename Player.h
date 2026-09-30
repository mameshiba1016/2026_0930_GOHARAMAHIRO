#pragma once
#include "Hand.h"

class Player
{
private:
    Hand hand_;

public:
    Player();

    void SelectHand();

    Hand GetHand() const;
};