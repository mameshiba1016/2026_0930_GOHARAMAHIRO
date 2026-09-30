#pragma once
#include <random>
#include "Hand.h"

class CPU
{
private:
    Hand hand_;

    std::mt19937 randomEngine_;

public:
    CPU();

    void SelectHand();

    Hand GetHand() const;
};