//numtri

/*
TASK: numtri
USER: anakaga1
LANG: C++
*/

/*Psudocode
First, we use vector so that we can read input data of Number Triangle.  In this case, because we have to know every integer by row and column, specifically we use 2 dementional vector
In order to find the maximum sum of the root, we are going to check each number's children.
and if the child directly below (or child directly below +1) is bigger, sum up with the parent with the larger one. 
if (child directly below is larger)  parent += child directly below (or child directly below +1)
and then, we output the integer at [0][0] (top), which became the largerst integer.
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