//ride

/*
ID: anakaga1
LANG: C++
TASK: ride
*/

/* Psudocode
convert the String(alphabet) into integers
then we multiply each integer by recursion and mod the total.
 =>  check integer1 (a) and integer2 (b).  If f(a) == f (b), GO  if not, STAY
*/

/* New Usgage in C++ programming
In C++, ? is used like...  'Condition' ? 'result1' : 'result2';

<fstream> can be used for inputing and outputing...  ifstream i("nameOfFile") ofstream o("file")

ascii code; get the ascii value by substract -64.
*/


#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int convertToNumber(string s)
{
	if{
		return (s[0]-64)*convertToNumber(s.substr(1)); //-64 converts uppercase ascii A-Z to integer 1-26, by recursion, it will be like ABCDE => 1*"BCDE" and then =>1*2*"CDE" and so forth
	}
	if (s.size() == 0){ //when the string become empty, just return 1
		return 1;
	}
	
	//return (s.size() ? (s[0] - 64) * convertToNumber(s.substr(1)) : 1) % 47;
}

int main(){
     ifstream cin ("ride.in");
     ofstream cout ("ride.out");
     string first;
     string second;
     cin >> first >> second;
     cout << (convertToNumber(first)%47 == convertToNumber(second)%47 ? "GO\n" : "STAY\n"); //if first == second, then "GO", if not "STAY"
}
