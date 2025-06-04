#ifndef MINMAX_HPP_

#define MINMAX_HPP_

#include "board.hpp"



pair<int, int> minmax(const BoardState&, Player, int&);
int alpha_beta_puring_minmax(BoardState, Player, int&);




#endif

