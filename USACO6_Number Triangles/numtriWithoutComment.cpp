//numtri

/*
TASK: numtri
USER: anakaga1
LANG: C++
*/

/*Psudocode
In order to find the maximum sum of the root, we are going to check each number's children (
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector <vector<int> > triangle;




int main(){
	freopen("numtri.in", "r", stdin);
	//freopen("numtri.out", "w", stdout);

	int NumRow;
	cin >> NumRow;

	for (int i = 0; i < NumRow; i++){
		vector<int> tri;
		for (int j = 0; j <= i; j++){
			int c;
			cin >> c;
			tri.push_back(c);
		}
		triangle.push_back(tri);
	}

	for (int k = NumRow -2; k >= 0; k--){
		for (int l = 0; l <= k; l++){
			if (triangle[k + 1][l] >= triangle[k + 1][l + 1]) {
				triangle[k][l] += triangle[k + 1][l];
			}
			else{
				triangle[k][l] += triangle[k + 1][l + 1];
			}
			
		}
	}

	cout << triangle[0][0] << '\n';

}