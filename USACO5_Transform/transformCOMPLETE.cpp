//transform

/*
USER: anakaga1
LANG: C++
TASK: transform
*/

/*PsudoCode
functions
compare - for looping for row and column
rotation - this method is to rotate once for 90 degree.  rotationbackup[i][j] = original[i][j] and original[i][j] = rotationbackup[N-j-1][i]
reflection - this method is to mirror.  original[i][j] = backup[i][N-j-1]
main - reading file (put the all results into the main).  In order to avoid the overwrite for answer, we should print out immediately after the each condition hits the right condition, and return 0.
*/


//and again, I am sorry that I could not put the normal folder into Nova, so I put the zip folder for this assingment again.
#include <iostream>
#include<fstream>
#include <string> 
#include <vector>  

using namespace std;

vector <vector<char> > original, transformed, backup, rotationbackup;  //2dementional vector
int N;
int answer;

bool compare(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (original[i][j] != transformed[i][j])   return false;
				
		}
		
	}
	return true;
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
	freopen("transform.out", "w", stdout);
	
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
		rotationbackup.push_back(row);
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

	//find how it moved... from original...  function


	//if rotate 90 degree, return 1
	rotation();
	if (compare()){
		answer = 1;
		cout << answer << endl;
		return 0;
	}
	//   rotate 180 degree, return 2
	rotation();
	if (compare()){
		answer = 2;
		cout << answer << endl;
		return 0;
	}
	// rotate 270 degree, return 3
	rotation();
	if (compare()){
		answer = 3;
		cout << answer << endl;
		return 0;
	}
	//if mirrored horizontally, return 4
	rotation();
	reflection();
	if (compare()){
		answer = 4;
		cout << answer << endl;
		return 0;
	}

	//if mirrored horizontally, and THEN, rotate in anyangle, return 5
	rotation();
	if (compare()){
		answer = 5;
		cout << answer << endl;
		return 0;
	}
	//   rotate 180 degree, return 2
	rotation();
	if (compare()){
		answer = 5;
		cout << answer << endl;
		return 0;
	}
	// rotate 270 degree, return 3
	rotation();
	if (compare()){
		answer = 5;
		cout << answer << endl;
		return 0;
	}
	// Kept it as original, return 6
	rotation();
	reflection();
	if (compare()){
		answer = 6;
		cout << answer << endl;
		return 0;
	}


	// invaild, return 7 (it i didnt apply to any qualification above
	answer = 7;
	cout << answer << endl;
	return 0;

	//choose the smallest numbered to return!
	/*bool b = compare();
	reflection();*/
	
}
