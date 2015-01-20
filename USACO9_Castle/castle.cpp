//castle

/*
USER: anakaga1
LANG: C++
TASK: castle
*/


/*Psudocode for first question  //The number of rooms the castle has.
It is similar to oil problem
First, we check if it's out of bounds error.
bool function...
	if (currecnt column is less than 0) return true;
	if (currenct column is more than M-1) return true:
	so the same as row...
	
bool functions for walls...
	for the boolean West .. (1)
		if (currect loction's integer is odd)  return true;
	for the boolean North... (2)
		if (current location's integer/2 is odd) return true;
	for the boolean East
		if (current location's integer is more than 7) -=8
		and then (the integer is between 4 to 7) return true;
	for the boolean South...(8)
		if (current location's integer is more than 7) return true;
		
void function for DFS
	if (current position is outofbounds) or (have visited) just return;
	else(boolVisited[inCurrentRowandCloumn]) return true;
	set the integers for NewColumn and NewRow and ,for example, for north, the column integer doesn't change but row is -1 row.
	and recurse north.  and so on for other direction.
*/

/*For Second question  //The size of the largest room
	using the first question's info (about how many room),  int countRoomSize, for (int i=0;i < countGroup; i++) 
*/

/*For Third qestion  //The size of the largest room creatable by removing one wall

*/

/*For Forth qeustion //The single wall to remove to make the largest room possible

*/


#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int>> castle;
vector < vector <bool> > castleBool;

// M is Column an N is Row
int M, N;

bool OutOfBounds(int currentColumn, int currentRow){
	//if the current column is smaller than 0 for Left
	if (currentColumn < 0) return true;
	//if the current column is greater than M -1 for right
	if (currentColumn > M - 1) return true;
	//if the current row is smaller than 0, for up
	if (currentRow < 0) return true;
	//if the current row greater than N-1, for DOWN
	if (currentRow > N - 1) return true;
	return false;
}

//1
bool walltoWest(int currentX, int currentY){
	if (castle[currentY][currentX] % 2 == 1) return true;
	else return false;
}
//includes 2
bool walltoNorth(int currentX, int currentY){
	int temp = castle[currentY][currentX];
	temp = temp / 2;
	if (temp % 2 == 1) return true;
	else return false;
}
//includes 4
bool walltoEast(int currentX, int currentY){
	int temp = castle[currentY][currentX];
	if (temp> 7) temp -= 8; 
	if (temp > 3 && temp < 8) return true;
	else return false;
}
//includes 8
bool walltoSouth(int currentX, int currentY){
	if (castle[currentY][currentX] > 7) return true;
	else return false;
}


void recursion(int currentColumn, int currentRow){
	if (OutOfBounds(currentColumn, currentRow)) return;
	if (castleBool[currentRow][currentColumn]) return;
	else castleBool[currentRow][currentColumn] = true;

	int NewC;
	int NewR;
	//North
	if (!walltoNorth(currentColumn,currentRow)){
		NewC = currentColumn;
		NewR = currentRow - 1;
		recursion(NewC, NewR);
	}

	//SOuth
	if (!walltoSouth(currentColumn, currentRow)){
		NewC = currentColumn;
		NewR = currentRow + 1;
		recursion(NewC, NewR);
	}
	
	//West
	if (!walltoWest(currentColumn, currentRow)){
		NewC = currentColumn - 1;
		NewR = currentRow;
		recursion(NewC, NewR);
	}
	
	//East
	if (!walltoEast(currentColumn, currentRow)){
		NewC = currentColumn + 1;
		NewR = currentRow;
		recursion(NewC, NewR);
	}
	

}


int main(){
	freopen("castle.in", "r", stdin);

	cin >> M >> N;

	for (int i = 0; i < N; i++){
		vector <int> castle2;
		vector <bool> castlebool2;
		for (int j = 0; j < M; j++){
			int c;
			cin >> c;
			castle2.push_back(c);
			castlebool2.push_back(false);
		}
		castle.push_back(castle2);
		castleBool.push_back(castlebool2);
	}
	//Line 1 output
	int countGroup = 0;
	for (int i = 0; i < N; i++){

		for (int j = 0; j < M; j++){
			if (!castleBool[i][j]){
				recursion(j, i);
				countGroup++;
			}
		}

	}

	cout << countGroup << endl;
	
	//Line 2 output
	int roomSize = 0;
	for (int i = 0; i <  N; i++){
		for (int j= 0; j< M; j++){
			if (!castleBool[i][j] && ){
				recursion(j,i);
				roomSize++;
			}
		}
	}
	
	cout << roomSize << endl;
}