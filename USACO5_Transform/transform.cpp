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

vector <vector<int>> numbers;  //2dementional vector


//convert - and @ to 0 and 1
int convertToNumber(string row){
    for (int i=0;i<row;i++)
    {
        if (row[i] == "@") return 1;
        else return 0;
    }
    
}


int answer;

//find how it moved... from original...  function


//if rotate 90 degree, return 1
//   rotate 180 degree, return 2
// rotate 270 degree, return 3

//if mirrored horizontally, return 4


//if mirrored horizontally, and THEN, rotate in anyangle, return 5

// Kept it as original, return 6

if (row[i] == newRow[j]) answer = 6;


// invaild, return 7 (it i didnt apply to any qualification above
if (row[i] != newRow[j]) answer = 7;

//choose the smallest numbered to return!






//reading file
int main(){
	int N;
	cin >> N;
	
    
    cout << answer;
}
