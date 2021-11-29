/**
Author: Andrew Darby

**/

#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<fstream>

using namespace std;

int xMoves[] = { -1, 1,-2, 2, 1, -1, -2, 2 };
int yMoves[] = { -2,-2,-1,-1, 2,  2,  1, 1 };
int visited[15][15];
int traveled[15][15];
int x2 = 0;
int y2 = 0;
const int BSIZE = 8;

int computeMoves(int, int);
bool validMove(int, int);
int convertToInt(char);

int main()
{
	ifstream inFile;		            //create input stream object
	string readFile = "input.txt";		// name of input txt file
	char a = 'a';
	char b = 'b' ;
	char c = 'c';
	char d = 'd';
	int x1 = 0;
	int y1 = 0;



	inFile.open(readFile);	            // open input file for X and O matrix
	if (inFile)				            // test success of file open
		cout << "file opened." << endl << endl;


	while (inFile >> a >> b >> c >> d) 			// while there is input from txt file
	{
	
		for (int i = 0; i < 15; i++)
		{
			for(int j = 0; j < 15; j++)
			visited[i][j] = 0;
		}

		x1= convertToInt(a);	//converts char to int
		y1 = b - 48;		//converts char to int

		x2 = convertToInt(c);	//converts char to int
		y2 = d - 48;		//converts char to int


		
		cout << "The number of moves required to move from: (" << x1 << ", " << y1 << ") to (" << x2 << "," << y2 << ") ";
			cout << "is " << computeMoves(x1, y1) << ".";
			cout << endl;
	
	}


	return 0;
}

//method tests validity of move
bool validMove(int x, int y)
{
	if (x < 1 || x > 8 || y < 1 || y > 8)
		return false;

	if (visited[x][y] == 1) 
		return false;

	return true;
}

//method converts char input to int 
int convertToInt(char a)
{
	int c = a - 'a' + 1;
	return c;

}// end method convertToInt

//method computes # of moves from start to finish point
int computeMoves(int x, int y)
{
	queue<pair<int, int>> moves;
	traveled[x][y] = 0;
	visited[x][y] = 1; 
	moves.push({ x, y });

	if (x == x2 && y == y2)
		return traveled[x][y];

	while (!moves.empty())
	{
		int currentX = moves.front().first;
		int currentY = moves.front().second;
		moves.pop();

		for (int i = 0; i < 8; i++)
			if (validMove(currentX + xMoves[i], currentY + yMoves[i]))
			{
				x = currentX + xMoves[i];
				y = currentY + yMoves[i];

				traveled[x][y] = traveled[currentX][currentY] + 1;
				visited[x][y] = 1;
				moves.push({ x , y });

				if (x == x2 && y == y2) return traveled[x][y];
			}
	}

}
