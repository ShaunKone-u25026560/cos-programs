#include <iostream>
#include <string>
#include "TicTacToeHelper.h"

std::string generateEmptyBoard()
{
	return "         ";
}

char getCell(std::string board, int cellIndex)
{
	return board[cellIndex];
}

std::string makeMove(std::string board, int position, char symbol)
{
	board[position] = symbol;
	return board;
}

std::string prettyPrint(std::string board)
{
	return board.substr(0, 1) + "|" + board.substr(1, 1) + "|" + board.substr(2, 1) + "\n-+-+-\n" + board.substr(3, 1) + "|" + board.substr(4, 1) + "|" + board.substr(5, 1) +
		"\n-+-+-\n" + board.substr(6, 1) + "|" + board.substr(7, 1) + "|" + board.substr(8, 1) + "\n";
}

bool isValidMove(std::string board, int cell)
{
	return board[cell] == ' ';
}

bool isInValidMove(std::string board, int cell)
{
	return board[cell] != ' ';
}

bool isPlayerTurn(int turnCount, char symbol)
{
	int convertedSymbol = symbol - '0';
	int temp = turnCount % 2;

	return convertedSymbol == temp;
}

bool isPlayerATurn(int turnCount)
{
	return isPlayerTurn(turnCount, '0');
}

bool isPlayerBTurn(int turnCount)
{
	return isPlayerTurn(turnCount, '1');
}

bool rowCheck(std::string board, int row, char symbol)
{
	return (board[3*row] == symbol) && (board[3*row + 1] == symbol) && (board[3*row + 2] == symbol);
}

bool colCheck(std::string board, int col, char symbol)
{
	return (board[col] == symbol) && (board[col + 3] == symbol) && (board[col + 6] == symbol);
}

bool checkAllRows(std::string board, char symbol)
{
	return rowCheck(board, 0, symbol) || rowCheck(board, 1, symbol) || rowCheck(board, 2, symbol);
}

bool checkAllCols(std::string board, char symbol)
{
	return colCheck(board, 0, symbol) || colCheck(board, 1, symbol) || colCheck(board, 2, symbol);
}

bool upwardDiagonalCheck(std::string board, char symbol)
{
	return board[6] == symbol && board[4] == symbol && board[2] == symbol;
}

bool downwardDiagonalCheck(std::string board, char symbol)
{
	return board[0] == symbol && board[4] == symbol && board[8] == symbol;
}

bool isAWinner(std::string board)
{
	return checkAllRows(board, '0') || checkAllCols(board, '0') || upwardDiagonalCheck(board, '0') || downwardDiagonalCheck(board, '0');
}

bool isBWinner(std::string board)
{
	return checkAllRows(board, '1') || checkAllCols(board, '1') || upwardDiagonalCheck(board, '1') || downwardDiagonalCheck(board, '1');
}

bool boardFull(std::string board)
{
	return board[0] != ' ' &&  board[1] != ' ' && board[2] != ' ' && board[3] != ' ' && board[4] != ' ' && board[5] != ' ' &&
		board[6] != ' ' && board[7] != ' ' && board[8] != ' ';
}

bool gameOver(std::string board)
{
	return isAWinner(board) || isBWinner(board) || boardFull(board);
}
