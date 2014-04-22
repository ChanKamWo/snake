#ifndef BLACK_BOARD_H
#define BLACK_BOARD_H

template <int XSize, int YSize>
class BlackBoard{
private:
	char board[XSize][YSize];
public:
	BlackBoard(){}
	void setGrid(int x, int y, char c){ board[x][y] = c; }
	char getGrid(int x, int y){ return board[x][y]; }
};

#endif