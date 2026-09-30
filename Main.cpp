#include <iostream>
#include <exception>
#include "Player.h"
#include "CPU.h"
#include "Judge.h"

int main()
{
    try
    {
        // インスタンス生成
        Player player;
        CPU cpu;
        Judge judge;

        std::cout << "JANKEN GAME\n";
        // Playerの手を選択
        player.SelectHand();
        // CPUの手を選択
        cpu.SelectHand();
        // ポインタを渡して勝敗判定
        judge.Check(&player,&cpu);
        // 結果表示
        judge.ShowResult(&player,&cpu);
    }
    catch (const std::exception& error)
    {
        std::cerr<< "エラー："<< error.what()<< '\n';

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}