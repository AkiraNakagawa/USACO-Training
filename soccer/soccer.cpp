//soccer

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


int games;
int points;

int win;
int tie;
int lost;
int main(){
	//freopen("soccer.in", "r", stdin);

	int NumTeams;
	cin >> NumTeams; //the first input

	for (int i = 0; i< NumTeams; i++){
		cin >> games >> points;
		cout << "Team #" << i + 1 << endl;
		cout << "Games: " << games << endl;
		cout << "Points: " << points << endl;
		cout << "Possible records:" << endl;

		//win is for 3 points and tei is for 1 point lost is 0 point
		//if points < 3, all points are in tie
		//if points

		//i need to calculate how many possibilities i have........... i have to loop them?? I think

		//win + tie + lost = games
		//win(3) + tie(1) + lost = points

		//the number of win (so as tie) for the possible record cannot be the same.

		win = points / 3;
		tie = points % 3;
		lost = games - win - tie;
		cout << win << "-" << tie << "-" << lost << endl;


		while (win >= 1 && lost >= 2){
			win -= 1;
			lost -= 2;

			//and the add to... tie
			tie += 3;
			cout << win << "-" << tie << "-" << lost << endl;
		}
		

		cout << endl;
	}

}