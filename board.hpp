#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <bits/stdc++.h>


using namespace std;



/*Function for user interface*/
void print_welcome();



/* Tic tac toe board relaated structures and functions*/
enum Player { PLAYERX = 1, PLAYERO = -1 };
enum WinnerStatus { PLAYERX_WIN = 1, INCOMPLETE = 2, TIE = 0, PLAYERO_WIN = -1 };
enum BoardCellStatus { XMARK = 1, NOMARK = 0, OMARK = -1 };


struct BoardState {
	/* The grid of tic tac toe is represented by bits in row major form starting from LSB */

	uint16_t grid, occupied = 0;	// 18 bits required

	BoardState(int grid, int occupied) : grid(grid), occupied(occupied) {}

	BoardState(const BoardState& b) : BoardState(b.grid, b.occupied) {}


	BoardState operator=(const BoardState& stt) {
		// copy at assignment
		this->grid = stt.grid;
		this->occupied = stt.occupied;
	}


	// no move constructor



	WinnerStatus get_winner();

	bool is_occupied(int);
	int get_emptycell();
	BoardCellStatus get_atcell(int);


	void set_atcell(int, Player);

	static char player_char(BoardCellStatus);

	void print_grid(int);


private:
	static inline const unsigned short win_masks[8] = {
		0b000000111,
		0b000111000,
		0b111000000,
		0b001001001,
		0b010010010,
		0b100100100,
		0b100010001,
		0b001010100
	};;
};



#endif
