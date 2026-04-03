#pragma once
#include "Game.h"

class TicTacToe : public Game
{
public:
    TicTacToe();

    bool IsGameOver() const override;
    void TakeTurn() override;
    void Display() const override;

private:
    char m_board[9];
    int m_currentPlayer;

    bool CheckWin() const;
    bool CheckTie() const;
};