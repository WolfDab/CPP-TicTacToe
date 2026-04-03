#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe() : m_currentPlayer(0)
{
    char startChar = '1';
    for (int i = 0; i < 9; ++i)
    {
        m_board[i] = startChar + i;
    }
}

bool TicTacToe::IsGameOver() const
{
    if (CheckWin())
    {
        char winner = (m_currentPlayer == 1) ? 'X' : 'O';
        std::cout << "\n*** Player " << winner << " wins! ***\n\n";
        return true;
    }

    if (CheckTie())
    {
        std::cout << "\n*** It's a tie! ***\n\n";
        return true;
    }

    return false;
}

void TicTacToe::Display() const
{
    std::cout << "\n";
    std::cout << " " << m_board[0] << " | " << m_board[1] << " | " << m_board[2] << "\n";
    std::cout << "---|---|---\n";
    std::cout << " " << m_board[3] << " | " << m_board[4] << " | " << m_board[5] << "\n";
    std::cout << "---|---|---\n";
    std::cout << " " << m_board[6] << " | " << m_board[7] << " | " << m_board[8] << "\n";
    std::cout << "\n";
}

void TicTacToe::TakeTurn()
{
    bool validTurn = false;
    int choice = 0;
    char mark = (m_currentPlayer == 0) ? 'X' : 'O';

    while (!validTurn)
    {
        std::cout << "Player " << mark << "'s turn.\n";
        std::cout << "Enter a position (1-9): ";
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a number.\n\n";
            continue;
        }

        if (choice >= 1 && choice <= 9)
        {
            int index = choice - 1;

            if (m_board[index] != 'X' && m_board[index] != 'O')
            {
                m_board[index] = mark;
                validTurn = true;
            }
            else
            {
                std::cout << "That position is already taken! Try again.\n\n";
            }
        }
        else
        {
            std::cout << "Invalid position! Must be between 1 and 9.\n\n";
        }
    }

    m_currentPlayer = 1 - m_currentPlayer;
}

bool TicTacToe::CheckWin() const
{
    const int winCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // horizontal rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // vertical columns
        {0, 4, 8}, {2, 4, 6}             // diagonals
    };

    for (int i = 0; i < 8; ++i)
    {
        if (m_board[winCombos[i][0]] == m_board[winCombos[i][1]] &&
            m_board[winCombos[i][1]] == m_board[winCombos[i][2]])
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::CheckTie() const
{
    for (int i = 0; i < 9; ++i)
    {
        if (m_board[i] != 'X' && m_board[i] != 'O')
        {
            return false;
        }
    }
    return true;
}