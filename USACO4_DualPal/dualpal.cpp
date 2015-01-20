
/*
TASK: dualpal
LANG: C++
USER: anakaga1
*/
//Dual Palindromes

/* Psdocode
	there are 5 functions to solve this problem...
	1. convert the integer into string...  
			- using <sstream>

	2. Generate a reversed string
			- for loop, from size of the string through 0, i--;   

	3. check if the number is palindrome...????
			- comparing the (original string ==  reversed string) if so true if not false

	4. convert the string (base10) into any base
			- using looping remainder = number%base and number/base => then put into the empty string
	
	5. check if the number has at least 2 palindrome
			- boolean .  for (when base 2 to 10) if the number is palindrome in a base, count++; then return true if there is palindrome twice

*/

#include <string>
#include <iostream>
#include <fstream>
#include <sstream> 

using namespace std;

const string BASES = "0123456789ABCDEF";

//string converter
string convertToString(int number){
	ostringstream ss;
	ss << number;
	return ss.str(); //its like string builder in java.  streaming the number and put in the string
}

//prepare the string which is reversed 
string reverseString(string str){
	string rString = "";
	for (int i = str.size() -1; i >= 0; i--){
		rString += str[i];
	}
	return rString;
}

//if the string is palindrome  (
bool isPalindrome(string s){
	if (s == reverseString(s)){
		return true;
	}
	else return false;
}

//convert the base 10 nubmer into any base of number
string convertToBase(int number, int base){
	string outNumber = "";
	do { //runs once before checking condition
		int remainder = number % base;
		number = number / base;
		outNumber = BASES[remainder] + outNumber;
	} while (number > 0);

	return outNumber;
}

//if the palindrome counts more than twice
bool isPalindromicInMultipleBases(int number){
	int palindromeCount=0;

	for (int B=2;B<=10;B++){
		string convertedNumber = convertToBase(number, B);
		if(isPalindrome(convertedNumber))
		{
			palindromeCount++;
		}
	}
	if(palindromeCount>=2)
		{
			return true; //if it counts mroe than twice, return true
		}
	else return false;  //if its less than twice(discluding twice), return false
	
}

//solve whole question
int main()
{
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);

	//string temp;
	//cin >> temp;
	//cout << convertToBase(13, 16);

	int N;
	int S;
	cin >> N;
	cin >> S;

    int count=0;
	S += 1;
    for (S; count < N; S++)  { //starts from the starting number, and until count counts N times.  
        if (isPalindromicInMultipleBases(S))  {
            cout << S << endl;
            count++;
        }
    }

}


