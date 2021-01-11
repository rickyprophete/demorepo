#pragma once
class TTT
{
public:
	TTT();
	~TTT();
	void menu(); 

private:
	
	//Variables used throughout program

	static const int N = 9;            ////constant size of Board
	char *board        = new char [N]; ////Used to keep track of final moves & to display
	char *boardCopy    = new char [N]; ////Used to check for winning conditions

	static const char BLANK = '.'; ////Blank space for board
	static const char  X    = 'X'; ////'X' character for board
	static const char OH    = 'O'; ////'O' character for board

	char currentPlayer		=  X ; ////Tracking current player, default is set to char X
	int xWins               =  0 ; ////track wins for X used in showScore()
	int ohWins              =  0 ; ////track wins for OH used in showScore()
	int ties                =  0 ; ////track ties in showScore()

	static const char QUIT     = 'Q';
	static const char PLAY     = 'P';
	static const char PLAYCOMP = 'C';
	static const char RULES    = 'R';

	////Funtion stubs

	void resetBoard();
	void resetBoardCopy();

	char getCurrentPlayer()     const;

	void makeMove(int move);
	void switchCurrentPlayer();

	bool isBoardFull()          const;
	bool isSquareFree(int move) const;
	bool isWinner(char)         const;
	bool isMoveValid(int move)  const;

	int displayBoard()          const;

	void displayBoard_VOID()    const;
	void playGame();
	void playCompGame();
	void welcome()              const;
	void wait()                 const;
	void showScore();
	void showRules()            const;

	int possWin(char);
	int cpuMove();
	int randMove();

};


