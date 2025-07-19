//tictactoe with a bot

//play tic tac toe with a bot :)

#include <iostream>
#include <limits>

char board[9] = { '1','2','3','4','5','6','7','8','9' };

void printBoard() {
    std::cout << "\n";
    for (int i = 0; i < 9; i++) {
        std::cout << board[i];
        if (i % 3 != 2) std::cout << " | ";
        else if (i != 8) std::cout << "\n---------\n";
    }
    std::cout << "\n\n";
}

bool checkWin(char player) {
    int wins[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };
    for (auto& w : wins) {
        if (board[w[0]] == player && board[w[1]] == player && board[w[2]] == player)
            return true;
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < 9; i++)
        if (board[i] != 'X' && board[i] != 'O') return false;
    return true;
}

int minimax(bool isAI) {
    if (checkWin('O')) return +10;   // Bot is 'O'
    if (checkWin('X')) return -10;   // Human is 'X'
    if (isDraw()) return 0;

    int bestScore = isAI ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();

    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            char backup = board[i];
            board[i] = isAI ? 'O' : 'X';
            int score = minimax(!isAI);
            board[i] = backup;

            if (isAI)
                bestScore = std::max(bestScore, score);
            else
                bestScore = std::min(bestScore, score);
        }
    }

    return bestScore;
}

void BotsMove() {
    int bestMove = -1;
    int bestScore = std::numeric_limits<int>::min();

    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            char backup = board[i];
            board[i] = 'O';
            int score = minimax(false);
            board[i] = backup;

            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }

    board[bestMove] = 'O';
}

int main() {
    std::cout << "You are X. Bot is O.\n";
    char human = 'X', bot = 'O';

    while (true) {
        printBoard();

        int move;
        std::cout << "Enter your move (1-9): ";
        std::cin >> move;

        if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        board[move - 1] = human;

        if (checkWin(human)) {
            printBoard();
            std::cout << "You win!\n";
            break;
        }

        if (isDraw()) {
            printBoard();
            std::cout << "It's a draw!\n";
            break;
        }

        BotsMove();

        if (checkWin(bot)) {
            printBoard();
            std::cout << "Bot wins!\n";
            break;
        }

        if (isDraw()) {
            printBoard();
            std::cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
