#include "Player.h"
#include <iostream>
#include <limits>
#include "GameConfig.h"

Player::Player() : hand_(Hand::Rock)
{
}

void Player::SelectHand()
{
    while (true)
    {
        std::cout << "\n===== 手を選択 =====\n";

        std::cout<< GameConfig::INPUT_ROCK<< "：グー\n";

        std::cout<< GameConfig::INPUT_SCISSORS<< "：チョキ\n";

        std::cout<< GameConfig::INPUT_PAPER<< "：パー\n";

        std::cout << "入力 > ";

        int input{};

        if (!(std::cin >> input))
        {
            if (std::cin.eof())
            {
                throw std::runtime_error("入力が終了しました。");
            }

            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            std::cout << "入力が正しくありません。\n";

            continue;
        }

        switch (input)
        {
        case GameConfig::INPUT_ROCK:

            hand_ = Hand::Rock;
            return;

        case GameConfig::INPUT_SCISSORS:

            hand_ = Hand::Scissors;
            return;

        case GameConfig::INPUT_PAPER:

            hand_ = Hand::Paper;
            return;

        default:

            std::cout<< "指定された番号を入力してください。\n";

            break;
        }
    }
}

Hand Player::GetHand() const
{
    return hand_;
}