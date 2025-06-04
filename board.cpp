#include <bits/stdc++.h>

#include "board.hpp"

using namespace std;
 
// The player x is computer and player o is user


void print_welcome() {
	cout << endl;
	cout << "\033[32m"; // green color

	ifstream welcome_file("welcome.txt");
	ostringstream content;

	content << welcome_file.rdbuf();
	cout << content.str() << endl;

	cout << "\033[0m"; // reset to normal color



}

char BoardState::player_char(BoardCellStatus b) {

	switch (b)
	{
	case XMARK:
		return 'X';
	case OMARK:
		return 'Y';
	}

	return -1;

}
WinnerStatus BoardState::get_winner() {
	for (unsigned short mask : BoardState::win_masks) {

		if ((occupied & mask) != mask)  continue;

		if ((grid & mask) == mask)
			return PLAYERX_WIN;
		else if ((grid & mask) == 0)
			return PLAYERO_WIN;

	}

	if (__builtin_popcount(this->grid) == 9)
		return TIE;

	return INCOMPLETE;
}



bool BoardState::is_occupied(int cell) {
	return (this->occupied >> (cell - 1)) & 1;
}


BoardCellStatus BoardState::get_atcell(int cell) {

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
	int player_bit = player == PLAYERX ? 1 : 0;

	this->occupied = (this->occupied | (1 << (cell - 1)));
	this->grid = (this->grid & ~(1 << cell - 1)) | (player_bit << (cell - 1));
}



void BoardState::print_grid(int left_space) {


	const int width = 11;


	int k = 1;
	for (size_t i = 0; i < width; i++)
	{
		for (size_t k = 0; k < left_space; k++)
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

				if (cell_mark == NOMARK)
					cout << k;
				else
					cout << player_char(cell_mark);

				k++;

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
		n += 1;
	}

	return n==0 ? -1 : n;
}