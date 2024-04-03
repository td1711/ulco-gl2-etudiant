#pragma once

#include <array>

enum class Cell { Free, Wall, Goal };

using row_t = std::array<Cell, 10>;
using board_t = std::array<row_t, 10>;

class Board {
    private:
        int _i;
        int _j;
        board_t _board;

    protected:
        Board(int i, int j);

    public:
        Board();

        int getI() const;
        int getJ() const;
        Cell operator()(int i, int j) const;

        void tryGoLeft();

        void tryGoRight();

        void tryGoUp();

        void tryGoDown();

};
