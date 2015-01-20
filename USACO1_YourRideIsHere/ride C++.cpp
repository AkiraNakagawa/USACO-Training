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
	return (s.size() ? (s[0] - 64) * convertToNumber(s.substr(1)) : 1) % 47;
}

int main(){
     ifstream cin ("ride.in");
     ofstream cout ("ride.out");
     string first;
     string second;
     cin >> first >> second;
     cout << (convertToNumber(first) == convertToNumber(second) ? "GO\n" : "STAY\n"); //if first == second, then "GO", if not "STAY"
}
