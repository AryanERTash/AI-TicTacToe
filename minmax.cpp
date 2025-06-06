#include <bits/stdc++.h>

#include "board.hpp"
#include "minmax.hpp"

using namespace std;

pair<WinnerStatus, int> minmax(BoardState board, bool maxplayer ) {

	WinnerStatus win = board.get_winner();	// status 
	// cout << win << " nigger\n";
	if (win != INCOMPLETE) return { win, -1 };	// return if leaf node

	int optimal_win = maxplayer ? INT16_MIN : INT16_MAX;	// optimal
	int move = -1;

	vector<int> vec = board.get_all_emptycells();

	for (int cell : vec) {
		// iterate through all possible bit flips
		
		BoardState next_board = board;
		next_board.set_atcell(cell, maxplayer ? PLAYERX : PLAYERO);

		pair<WinnerStatus, int> next_pair = minmax(next_board, !maxplayer);
		int win_stat = next_pair.first;
		
		// cout << (WinnerStatus)win_stat << " " << depth << endl;
		
		

		if (maxplayer && win_stat > optimal_win) {
			optimal_win = win_stat;
			move = cell;
		}
		else if (!maxplayer && win_stat < optimal_win) {
			optimal_win = win_stat;
			move = cell;
		}
	}
	

	return { (WinnerStatus)optimal_win, move };
}
