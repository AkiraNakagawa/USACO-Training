/*
TASK: gift1
LANG: C++
*/

#include <fstream>
#include  <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

/*Psudocode
we need to know...
	1. number of people in the group ----- cin >> NP (as int)
	2. individual names ---- cin >> PersonalName (as string) and add individual names into vector
	3. balance --- balance = balance + recieve + leftOver - togive
*/

/* New things to reminder

*/

/*  Sidenote
method of vector is used under the commented 
*/


vector <string> names;
//vector <int> balance;

map <string, int> money;

//int position(string name)
//{
//	for (int i = 0; i < names.size(); i++){
//		if (name == names.at(i)){
//			return i;
//		}
//	}
//	return -1;//in case it doesnt have names...
//}

int main()
{
	freopen("gift1.in", "r", stdin); //read
	freopen("gift1.out", "w", stdout); //write

	int NP;
	cin >> NP;
	
	for (int i = 0; i < NP; i++) {
		string PersonName;  //one of the name (willbe) in vector
		cin >> PersonName;
		names.push_back(PersonName);
		money[PersonName] = 0;

		//balance.push_back(0);
	}

	//calculations
	for (int i = 0; i < NP; i++){
		string giver;
		cin >> giver;

		int amtToGive, numFriends;
		cin >> amtToGive >> numFriends;

		if (numFriends == 0){ // to avoid 0 / 0!!!!!!
			//int giverPosition = position(giver);
			//balance.at(giverPosition) += amtToGive;
			money[giver] += amtToGive;
		}
		else {
			int amtRecieve = amtToGive / numFriends;
			int leftOver = amtToGive % numFriends;

			//int giverPosition = position(giver);
			//balance.at(giverPosition) -= amtToGive;
			//balance.at(giverPosition) += leftOver;
			money[giver] -= amtToGive;
			money[giver] += leftOver;

			for (int j = 0; j < numFriends; j++){
				string reciever;
				cin >> reciever;

				//int recieverPosition = position(reciever);
				//balance.at(recieverPosition) += amtRecieve;
				money[reciever] += amtRecieve;
			}
		}
	}

	for (int i = 0; i < NP; i++) {
		cout << names.at(i) << " " << money[names.at(i)] << '\n';
		//balance.at(i) 
	}
}