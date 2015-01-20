//transform

/*
USER: anakaga1
LANG: C++
TASK: transform
*/

/*PsudoCode
functions
convertToNumber - convert into 0 and 1 from @ and -
FindtheChange(compare) - how changed from the original.  return the number and smallest number if thre are more than 1 returns
main - reading file (put the all results into the main)
*/

#include <iostream>
#include<fstream>
#include <string> 
#include <vector>  

using namespace std;

vector <vector<char>> original, transformed, backup, rotationbackup;  //2dementional vector
int N;

//convert - and @ to 0 and 1
//string convertToNumber(string row){
//	for (int i = 0; i<row; i++)
//	{
//		if (row[i] == "@") return 1;
//		else return 0;
//	}
//
//}


int answer;

//find how it moved... from original...  function


//if rotate 90 degree, return 1
//   rotate 180 degree, return 2
// rotate 270 degree, return 3

//if mirrored horizontally, return 4


//if mirrored horizontally, and THEN, rotate in anyangle, return 5

// Kept it as original, return 6

//if (row[i] == newRow[j]) answer = 6;


// invaild, return 7 (it i didnt apply to any qualification above
//if (row[i] != newRow[j]) answer = 7;

//choose the smallest numbered to return!


bool compare(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (original[i][j] != transformed[i][j])   return false;
				
		}
		
	}
	return true;
}

void restore(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			 original[i][j] = backup[i][j];
		}
	}
}


void rotation(){

	for (int i = 0; i < N; i++){ //in order to avoid overwrite data later on
		for (int j = 0; j < N; j++){
			rotationbackup[i][j] = original[i][j];
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			original[i][j] = rotationbackup[N-j-1][i];
		}
	}
}

void reflection(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			original[i][j] = backup[i][N-j-1];
		}
	}
}


//reading file
int main(){
	freopen("transform.in", "r", stdin);
	//freopen("transform.out", "w', stdout);
	
	cin >> N;
	//i dont know how to reading the multiple lines
	for (int i = 0; i < N; i++){
		vector<char> row;
		for (int j = 0; j < N; j++){
			char c;
			cin >> c;
			row.push_back(c);
		}
		original.push_back(row);
		backup.push_back(row);
	}

	for (int i = 0; i < N; i++){
		vector<char> row;
		for (int j = 0; j < N; j++){
			char c;
			cin >> c;
			row.push_back(c);
		}
		transformed.push_back(row);
	}


	bool b = compare();
	reflection();
	cout << answer;
}
