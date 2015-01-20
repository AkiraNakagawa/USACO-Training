//oil

/*
USER: anakaga1
LANG: C++
TASK: oil
*/


/*Psudocode

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector <vector <char> > grid;
vector < vector <bool> > gridBool;

int m, n;
bool OutOfBounds (int currentColumn, int currentRow){
	//if the current column is smaller than 0 for Left
	if (currentColumn < 0) return true;
	//if the current column is greater than n -1 for right
	if (currentColumn > n - 1) return true;
	//if the current row is smaller than 0, for up
	if (currentRow < 0) return true;
	//if the current row greater than m-1, for DOWN
	if (currentRow > m - 1) return true;
	return false;
}


void recursion(int currentColumn, int currentRow){
	if (OutOfBounds(currentColumn, currentRow)) return ; 
	if (grid[currentRow][currentColumn] != '@') return;
	if (gridBool[currentRow] [currentColumn]) return;
	else gridBool[currentRow][currentColumn] = true;
	
	int NewC;
	int NewR;
	//up 
	NewC = currentColumn;
	NewR = currentRow - 1;
	recursion(NewC, NewR);

	//down 
	NewC = currentColumn;
	NewR = currentRow + 1;
	recursion(NewC, NewR);

	//left
	NewC = currentColumn -1;
	NewR = currentRow;
	recursion(NewC, NewR);
	//right
	NewC = currentColumn +1;
	NewR = currentRow;
	recursion(NewC, NewR);

	//up right
	NewC = currentColumn +1;
	NewR = currentRow - 1;
	recursion(NewC, NewR);

	//up left
	NewC = currentColumn -1;
	NewR = currentRow - 1;
	recursion(NewC, NewR);

	//down right
	NewC = currentColumn +1;
	NewR = currentRow + 1;
	recursion(NewC, NewR);

	//down left
	NewC = currentColumn -1;
	NewR = currentRow + 1;
	recursion(NewC, NewR);

}
int main(){
	freopen("oil.in", "r", stdin);
	//freopen("oil.out", "w", stdout);

	cin >> m >> n;

	while (m > 0){
		grid.clear();
		gridBool.clear();
		for (int i = 0; i < m; i++){
			vector <char> grid2;
			vector <bool> gridB2;
			for (int j = 0; j < n; j++){
				char c;
				cin >> c;
				grid2.push_back(c);
				gridB2.push_back(false);
			}
			grid.push_back(grid2);
			gridBool.push_back(gridB2);
		}
		
		int countGroup =0;
		for (int i = 0; i < m; i++){
			
			for (int j = 0; j < n; j++){
				if (grid[i][j] == '@' && !gridBool[i][j]){
					recursion(j, i);
					countGroup++;
				}
			}
			
		}

		cout << countGroup << endl;

		//to read the next test cases!
		cin >> m >> n;
	}


}