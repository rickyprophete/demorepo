#pragma once
class TTT
{
public:
	TTT();
	~TTT();
	void menu(); 

private:
	
	////Variables used throughout program

	static const int N = 9; ////constant size of Board
	char board[N];

	static const char BLANK = '.'; ////Blank space for board
	static const char  X = 'X'; ////'X' character for board
	static const char OH = 'O'; ////'O' character for board

	char currentPlayer; ////Tracking current player, default is set to char X
	int xWins = 0; ////track wins for X used in showScore()
	int ohWins = 0; ////track wins for OH used in showScore()

	static const char QUIT = 'Q';
	static const char PLAY = 'P';

	////Funtion stubs

	void resetBoard();
	char getCurrentPlayer() const;
	void makeMove(int move);
	void switchCurrentPlayer();
	bool isBoardFull() const;
	bool isSquareFree(int move) const;
	bool hasWinner() const;
	bool isMoveValid(int move) const;
	int displayBoard() const;
	void displayBoard_VOID() const;
	void playGame();
	void welcome() const;
	void wait() const;
	void showScore();
};


