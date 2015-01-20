//castle

/*
USER: anakaga1
LANG: C++
TASK: castle
*/


/*Psudocode 
Functions - OutOfBound and Existance of wall for all direction and DFS
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

First Question - Number of Rooms in the castle
	If (never visited before [in the location]) call a recursion and count the number of the room++

Second Question - The size of largest room
	First, we use 1D vecotor and pushback the data of moves of square withn the room (numSquare). 
	And compare with the global var largestRoom... if (the largestRoom is smaller than the data) largestRoom =  numSquare;

Third Question and Fourth Question - The size of the largest room creatable by removing one wall and its position
	Since we have two possibility of having North or East wall, we have to set differently for each case. 
	For North, set temporary two of room size is roomSizes[current position] + roomSizes[currentPosition above].  
	If(temporary size > largestRoomWOWall) largestRoomWOWall = temporary size; and cout largestRoomWOWall
		
	For the ForthQuestion, because by input and largestRoomWOWall we know that i (technically i+1) is the row. 
	And j (actually j+1) is the column.  
*/



#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int> > castle, castleID;
vector < vector <bool> > castleBool;
vector <int> roomSizes; //able to refer the room number and each size by vector


int countGroup = 0; //number of room
int largestRoom = 0; //largest room size in the castle withOUT removing wall
int largestWOWall = 0; //largest room size with removing wall
int largeRowPoint = 0; //where to remove the wall for Row
int largeColumnPoint = 0; // for Column
char direction; // N or E
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

//Wall Existance boolean
//includes 1
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
	if (temp > 7) temp -= 8;
	if (temp > 3 && temp < 8) return true;
	else return false;
}
//includes 8
bool walltoSouth(int currentX, int currentY){
	if (castle[currentY][currentX] > 7) return true;
	else return false;
}


int recursion(int currentColumn, int currentRow){
	if (OutOfBounds(currentColumn, currentRow)) return 0;
	if (castleBool[currentRow][currentColumn]) return 0;
	castleBool[currentRow][currentColumn] = true;
	castleID[currentRow][currentColumn] = countGroup;

	int sum = 1;
	int NewC;
	int NewR;
	//North  column is the same but goes up (-1) in the row.
	if (!walltoNorth(currentColumn, currentRow)){
		NewC = currentColumn;
		NewR = currentRow - 1;
		sum += recursion(NewC, NewR);
	}

	//South
	if (!walltoSouth(currentColumn, currentRow)){
		NewC = currentColumn;
		NewR = currentRow + 1;
		sum += recursion(NewC, NewR);
	}

	//West
	if (!walltoWest(currentColumn, currentRow)){
		NewC = currentColumn - 1;
		NewR = currentRow;
		sum += recursion(NewC, NewR);
	}

	//East
	if (!walltoEast(currentColumn, currentRow)){
		NewC = currentColumn + 1;
		NewR = currentRow;
		sum += recursion(NewC, NewR);
	}

	return sum;
}


int main(){
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
	cin >> M >> N;

	for (int i = 0; i < N; i++){
		vector <int> castle2, castleID2;
		vector <bool> castlebool2;
		for (int j = 0; j < M; j++){
			int c;
			cin >> c;
			castle2.push_back(c);
			castleID2.push_back(-1); //default ID value
			castlebool2.push_back(false);
		}
		castle.push_back(castle2);
		castleID.push_back(castleID2); 
		castleBool.push_back(castlebool2);
	}

	//output...
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (!castleBool[i][j]){
				int NumSquares = recursion(j, i); //number of squre by used recursion times
				roomSizes.push_back(NumSquares);
				countGroup++; //change the position with code under this
				if (largestRoom < NumSquares) largestRoom = NumSquares;
			}
		}

	}


	for (int j = 0; j< M ; j++){
		for (int i = N -1; i>=0; i--){
			if (i > 0) { //if the wall point is withn the row
				// if north is the one has the biggest one of the wall
				int currentID = castleID[i][j];
				int nextID = castleID[i - 1][j];
				if (currentID != nextID){ //if the room number(orID) is different between current square and next square above...
					int tempSize;
					tempSize = roomSizes[currentID] + roomSizes[nextID]; //sum of the current room size and size of room above
					if (tempSize > largestWOWall){  //if bigger than previous result of room size...
						largestWOWall = tempSize;
						largeRowPoint = i + 1;  //for both one... because we count from 0, not 1...
						largeColumnPoint = j + 1;
						direction = 'N';
					}
				}
			}
			if (j < M - 1){ //
				// if east
				int currentID = castleID[i][j];
				int nextID = castleID[i][j +1];
				if (currentID != nextID){
					int tempSize;

					tempSize = roomSizes[currentID] + roomSizes[nextID];
					if (tempSize > largestWOWall){ //if the north has the same point, bc cannot be > so north has priority
						largestWOWall = tempSize; 
						largeRowPoint = i + 1;
						largeColumnPoint = j + 1;
						direction = 'E';
					}
				}
			}
		}
	}


	cout << countGroup << endl;
	cout << largestRoom << endl;
	cout << largestWOWall << endl;
	cout << largeRowPoint << " " << largeColumnPoint << " "<< direction<< endl;  

}
