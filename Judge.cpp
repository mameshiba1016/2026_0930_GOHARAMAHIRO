#include "Judge.h"
#include <iostream>
#include <stdexcept>
#include "Player.h"
#include "CPU.h"

Judge::Judge() : result_(Result::Draw)
{
}

Result Judge::CompareHands(Hand playerHand,Hand cpuHand) const
{
    // 同じ手なら引き分け
    if (playerHand == cpuHand)
    {
        return Result::Draw;
    }
    // Playerがグーの場合
    if (playerHand == Hand::Rock)
    {
        if (cpuHand == Hand::Scissors)
        {
            return Result::Win;
        }

        return Result::Lose;
    }
    // Playerがチョキの場合
    if (playerHand == Hand::Scissors)
    {
        if (cpuHand == Hand::Paper)
        {
            return Result::Win;
        }

        return Result::Lose;
    }
    // Playerがパーの場合
    if (playerHand == Hand::Paper)
    {
        if (cpuHand == Hand::Rock)
        {
            return Result::Win;
        }

        return Result::Lose;
    }

    throw std::logic_error("不正な手が指定されました。");
}

void Judge::Check(const Player* player,const CPU* cpu)
{
    if (player == nullptr || cpu == nullptr)
    {
        throw std::invalid_argument("判定対象が存在しません。");
    }

    const Hand playerHand = player->GetHand();
    const Hand cpuHand = cpu->GetHand();

    result_ = CompareHands(playerHand,cpuHand);
}

const char* Judge::GetHandName(Hand hand) const
{
    switch (hand)
    {
    case Hand::Rock:
        return "グー";

    case Hand::Scissors:
        return "チョキ";

    case Hand::Paper:
        return "パー";

    default:
        return "不明";
    }
}

void Judge::ShowResult(const Player* player,const CPU* cpu) const
{
    if (player == nullptr || cpu == nullptr)
    {
        throw std::invalid_argument("表示対象が存在しません。");
    }

    std::cout << "\n========== RESULT ==========\n";

    std::cout<< "Player："<< GetHandName(player->GetHand())<< '\n';

    std::cout<< "CPU   ："<< GetHandName(cpu->GetHand())<< '\n';

    switch (result_)
    {
    case Result::Win:

        std::cout << "Playerの勝ち！\n";
        break;

    case Result::Lose:

        std::cout << "CPUの勝ち！\n";
        break;

    case Result::Draw:

        std::cout << "引き分け！\n";
        break;
    }

}

Result Judge::GetResult() const
{
    return result_;
}