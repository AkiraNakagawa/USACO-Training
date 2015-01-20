//speed

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include<fstream>
#include <sstream>
#include<cstdio>

using namespace std;


int munite;
int hour;

int main(){
	//int allows up to go through any number
	//we converted the ints into strings so it would return as a number.
	//d is the miles s1 is the first speed s2 is the second speed
	freopen("speed.in", "r", stdin);
	float d;
	float s1;
	float s2;

	/*for (int i = 0; i< 3; i++){
	times;
	string c;
	cin >> c;
	times.push_back(c);
	}*/

	while (true){
		cin >> d >> s1 >> s2;

		//printf("%f %f %f\n", d, s1, s2);// print out the input
		if (d == 0) break;

		float diffR = d / s1 - d / s2; // gives you the difference between the two in hours
		diffR = diffR * 60; //2.25
		/*int munite;
		int hour;*/
		if (diffR < 60){
			munite = diffR; //2? yes
			hour = 0;
		}
		else{ //131 dattara....  hour ha 2 de munite ha 11, munite ha diffR - hour*60
			hour = munite / 60;
			munite = diffR - hour * 60;
		}



		diffR = diffR - munite; //2.25.... - 2
		diffR = diffR * 60; // convert into time 
		int fen = diffR; //15
		printf("%d:%02d:%02d\n", hour, munite, fen); //both munite and fen should have 2 

		//cout << munite << ":" << fen << endl;

	}

}