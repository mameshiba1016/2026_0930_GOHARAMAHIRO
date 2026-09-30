#pragma once

namespace GameConfig
{
    // 入力番号
    constexpr int INPUT_ROCK = 0;
    constexpr int INPUT_SCISSORS = 1;
    constexpr int INPUT_PAPER = 2;
    // CPUの乱数範囲
    constexpr int RANDOM_MIN = INPUT_ROCK;
    constexpr int RANDOM_MAX = INPUT_PAPER;
}