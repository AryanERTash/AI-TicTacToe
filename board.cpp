#include <bits/stdc++.h>

#include "board.hpp"

using namespace std;



void print_welcome() {
	/*
		Print welcome message which is in welcome.txt
	*/
	cout << endl;
	cout << "\033[32m"; // green color

	ifstream welcome_file("welcome.txt");
	ostringstream content;

	content << welcome_file.rdbuf();
	cout << content.str() << endl;

	cout << "\033[0m"; // reset to normal color



}

// basic constructor and copy constructor
BoardState::BoardState(int grid, int occupied) : grid(grid), occupied(occupied) {}

BoardState::BoardState(const BoardState& b) : BoardState(b.grid, b.occupied) {}

BoardState BoardState::operator=(const BoardState& stt) {
	// copy at assignment
	grid = stt.grid;
	occupied = stt.occupied;
	return *this;
}

char BoardState::player_char(BoardCellStatus b) {

	/*
		Give char corresponding to the cell
	*/

	switch (b)
	{
	case XMARK:
		return 'X';
	case OMARK:
		return 'O';
	}

	return -1;

}
WinnerStatus BoardState::get_winner() {
	/*
		Returns WinnerStatus 
	*/
	for (unsigned short mask : BoardState::win_masks) {

		if ((occupied & mask) != mask)  continue;

		if ((grid & mask) == mask)
			return PLAYERX_WIN;
		else if ((grid & mask) == 0)
			return PLAYERO_WIN;

	}

	if (__builtin_popcount(occupied) == 9) // count number of 1s in occupied bits
		return TIE;

	return INCOMPLETE;	// game is still going on
}



bool BoardState::is_occupied(int cell) {
	return (this->occupied >> (cell - 1)) & 1; 	// the cell is occupied or not
}


BoardCellStatus BoardState::get_atcell(int cell) {

	// get mark at cell

	int val = ((grid >> (cell - 1)) & 1);


	if (is_occupied(cell)) {

		switch (val) {
		case 1:
			return XMARK;
		case 0:
			return OMARK;
		}

	}


	return NOMARK;
}

void BoardState::set_atcell(int cell, Player player) {

	/*
		Set a cell in the board
	*/

	int player_bit = player == PLAYERX ? 1 : 0;

	occupied = (occupied | (1 << (cell - 1)));
	grid = (grid & ~(1 << cell - 1)) | (player_bit << (cell - 1));
}



void BoardState::print_grid() {

	// print the whole grid


	const int width = 11;


	int k = 1;
	for (size_t i = 0; i < width; i++)
	{
		for (size_t k = 0; k < width; k++)
		{
			cout << " ";
		}

		for (size_t j = 0; j < width; j++)
		{


			if (i % 4 == 3 || j % 4 == 3) {
				std::cout << " . ";
			}
			else if (i % 4 == 1 && j % 4 == 1)
			{
				cout << " ";

				BoardCellStatus cell_mark = get_atcell(k);

				if (cell_mark == NOMARK) {
					cout << k;	// if cell not yet occipied simply put the number of cell
				}
				else {
					cout << "\033[32m";	// green text for occupied cells
					cout << player_char(cell_mark);
					cout << "\033[0m";		// revert to normal color
				}

				k++;	// next cell

				cout << " ";

			}
			else {
				cout << "   ";
			}
		}
		cout << std::endl;

	}


}


int BoardState::get_emptycell() {

	// -1 if no position left 


	int vbits = this->occupied;

	int n = 0;
	while (n < 9 && (vbits & 1) == 1) {
		vbits >>= 1;
		n++;
	}

	return n == 0 ? -1 : n + 1;
}


vector<int> BoardState::get_all_emptycells() {

	// return a vector of empty cells from a given board state

	vector<int> empty_cells;

	for (int i = 1; i <= 9; i++)
	{
		if (!is_occupied(i)) {
			empty_cells.emplace_back(i);
		}
	}

	return empty_cells;

}