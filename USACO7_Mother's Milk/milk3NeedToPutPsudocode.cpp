//milk3

/*
USER: anakga1
LANG: C++
TASK: milk3
*/


#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


struct ABC
{
	int a, b, c;
	ABC(int Na, int Nb, int Nc){
		a = Na;
		b = Nb;
		c = Nc;
	}
	//i figure out this from the online...
	//http://stackoverflow.com/questions/6973406/c-stl-map-container-with-class-key-and-class-value
	bool operator<(const ABC& abc) const {
		if (a == abc.a) {
			if (b == abc.b) {
				return (c < abc.c);
			}
			return (b < abc.b);
		}
		return (a < abc.a);
	}
};

map <ABC, bool> milks2;

vector <int> milks; //sorry as English, its incorrect... but its a vector called milk"s"

	int A;
	int B;
	int C; //this is meant (using as) to be CONSTANT

void recursion(int a, int b, int c){
	//stop when we revisit the same values
	ABC index = ABC(a, b, c);
	if (milks2[index] == true){
		return; //exit the function
	}

	if (milks2[index] == false){
		milks2[index] = true;
	}
	
	if (a == 0){
		milks.push_back(c);
	}

	int pour;
	//A->B
	//if the empty part of B (B-b) is greater than a (amount of milk in A), then pour a into B
	if (B - b > a){
		pour = a;
	}
	//because empty part of B is smaller so we can pour only B - b amount into B
	else{
		pour = B - b;
	}
	//those two lines are pouring milk from A to B bucket
	a -= pour;
	b += pour;
	//call the recursion of new integers a b c
	recursion(a, b, c);
	//those two are undo pouring.
	a += pour;
	b -= pour;

	//A->C
	if (C - c > a){
		pour = a;
	}
	else{
		pour = C - c;
	}
	a -= pour;
	c += pour;
	recursion(a, b, c);
	a += pour;
	c -= pour;

	//B->A
	if (A - a > b){
		pour = b;
	}
	else{
		pour = A - a;
	}
	b -= pour;
	a += pour;
	recursion(a, b, c);
	b += pour;
	a -= pour;


	//B->C
	if (C - c > b){
		pour = b;
	}
	else{
		pour = C - c;
	}
	b -= pour;
	c += pour;
	recursion(a, b, c);
	b += pour;
	c -= pour;

	//C->A
	if (A - a > c){
		pour = c;
	}
	else{
		pour = A - a;
	}
	c -= pour;
	a += pour;
	recursion(a, b, c);
	c += pour;
	a -= pour;

	//C->B
	if (B - b > c){
		pour = c;
	}
	else{
		pour = B - b;
	}
	c -= pour;
	b += pour;
	recursion(a, b, c);
	c += pour;
	b -= pour;


}


int main(){
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);

	

	cin >> A >> B >> C;

	recursion(0, 0, C);

	//soring by algorithm!
	sort(milks.begin(), milks.end());

	cout << milks[0];
	for (int i = 1; i < milks.size(); i++){
		cout << " " << milks[i];
	}
	cout << endl;

	return 0;
	
}