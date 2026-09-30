#include "CPU.h"
#include "GameConfig.h"

CPU::CPU() : hand_(Hand::Rock),randomEngine_(std::random_device{}())
{
}

void CPU::SelectHand()
{
    std::uniform_int_distribution<int> distribution(GameConfig::RANDOM_MIN,GameConfig::RANDOM_MAX);

    const int randomValue = distribution(randomEngine_);

    switch (randomValue)
    {
    case GameConfig::INPUT_ROCK:

        hand_ = Hand::Rock;
        break;

    case GameConfig::INPUT_SCISSORS:

        hand_ = Hand::Scissors;
        break;

    case GameConfig::INPUT_PAPER:

        hand_ = Hand::Paper;
        break;

    default:

        hand_ = Hand::Rock;
        break;
    }
}

Hand CPU::GetHand() const
{
    return hand_;
}