#ifndef MINMAX_HPP_

#define MINMAX_HPP_

#include "board.hpp"


/* Instead of winnestatus we can use int if we wish to use some
 other evaluation function example: depth as a metric of score, less depth means more favourable for X
 */
pair<WinnerStatus, int> minmax(BoardState, bool = true);


/*
	Alpha beta puring (simply not visiting useless nodes) can optimize the minimax algorithm

	Another optimization may be to make a unordered map for all visited state and next state as key
	This will result in 19683(=3^9) enteries which is managable enough
*/
int alpha_beta_puring_minmax(BoardState, bool = true); 

// int probablity_minimax();

//probablity based search
// p(win at a node)


#endif

