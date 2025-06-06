#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <bits/stdc++.h>
using namespace std;

/*Function for user interface*/
void print_welcome();
#define MASK_WIN 0b000101011;

/* Tic tac toe board relaated bad structures and functions*/

// The player X is computer and player O is computer 

enum Player { PLAYERX = 1, PLAYERO = -1 };	// player
enum WinnerStatus { PLAYERX_WIN = 1, INCOMPLETE = 2, TIE = 0, PLAYERO_WIN = -1 }; // winner points
enum BoardCellStatus { XMARK = 1, NOMARK = 0, OMARK = -1 }; // cell of a board

struct BoardState {
	/* The grid of tic tac toe is represented by bits in row major form starting from LSB */
	uint16_t grid = 0, occupied = 0;    // 18 bits required




	//constructors
	BoardState(int = 0, int = 0);
	BoardState(const BoardState&);	// copy constructor

	//operator assignment
	BoardState operator=(const BoardState&);




	// no move constructor

	WinnerStatus get_winner(); // To find winner

	// cell related functions
	bool is_occupied(int);
	int get_emptycell();	// gets the first empty cell
	vector<int> get_all_emptycells();	// get a list of empty cell (useful for minimax)

	BoardCellStatus get_atcell(int);	// get mark at a given cell 

	void set_atcell(int, Player);	// set a cell with a particular player
	void print_grid();	// print the tic tac toe grid

	static char player_char(BoardCellStatus);	// get player character

private:

	/*
		this is a mask that will help us to check state of board in get_winner function
	*/
	static inline const unsigned short win_masks[8] = {
		0b000000111,
		0b000111000,
		0b111000000,
		0b001001001,
		0b010010010,
		0b100100100,
		0b100010001,
		0b001010100
	};
};

#endif
