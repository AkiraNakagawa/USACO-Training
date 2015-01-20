//Dual Palindromes

/* Psdocode
	there are 5 functions to solve this problem...
	1. convert the integer into string...
	2. check if the number is palindrome
	3. check if the 
	4. check if the number has at least 2 palindrome
	5. Main streaming files and make output
*/

#include <string>
#include <iostream>
#include <fstream>
#include <algorith>

using namespace std;
//string converter
string converToString(int number, int base){
//later
}

//if the string is palindrome
bool isPalindrome(string s){
	//later
}


//find palindromic number
bool isPalindromicInBase(int number, int base){
	string s = converToString(number,base);
	if (isPalindrome(s)){
		return true;
	}
	else return false;
}


//if the palindrome counts more than twice
bool isPalindromicInMultipleBases(int number){
	int palindromeCount=0;

	for (int B=2;B<=10;i++){
		if(isPalindromicInMultipleBases(number, B))
		{
			palindromeCount++;
		}
	}
	if(palindromeCount>=2)
		{
			return true;
		}
	else return false;
	
}

//solve whole question
int main()
{
	freopen("dualpal,in", "r", stdin);
	freopen("dualpal.out", "w", stdout);

	int N;
	int S;
	cin >> N;
	cin >> S;
	
	int S = StartNumber;
	int count=0;

	int i;
    int count=0;
    
    for (i=S; ; i++)  {
        if (isPalindromicInMultipleBases(S))  {
            cout << S << endl;
            count++;
        }

        if (count == N) break;
    }

}


