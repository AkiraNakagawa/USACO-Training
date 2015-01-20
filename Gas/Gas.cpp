// gas

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;
vector <string> prices;

int main(){
	//freopen("gas.in", "r", stdin);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++){
		int lowerBound = 199;

		prices.clear();
		for (int j = 0; j < 3; j++){
			string c;
			cin >> c;
			prices.push_back(c);
		}
		cout << "Gas Station #" << i + 1 << ":" << endl;
		cout << "   Input:  " << prices[0] << " " << prices[1] << " " << prices[2] << endl;
		//processing 
		for (int k = 0; k < 3; k++){ //searching from regular to super
			//cout << lowerBound << endl;
			//printf("k = %d lowerBound=%d\n", k, lowerBound); 
			int found = prices[k].find('-');
			if (found >= 0){
				for (char m = '0'; m <= '9'; m++){ //can use for loop for characters as well!
					prices[k][found] = m;
					int currentPrice = atoi(prices[k].c_str()); //atoi(str.c_str() ) str becomes integer!  Remember!!!
					if (currentPrice > lowerBound){
						lowerBound = currentPrice;
						break; //stop looping if its bigger than bound
					}
				}
			}

			else{ //if there is no '-', just set the lowerbound = that price
				int currentPrice = atoi(prices[k].c_str());
				if (currentPrice > lowerBound){
					lowerBound = currentPrice;
					
				}
			}

		}
		//output
		cout << "   Output: " << prices[0] << " " << prices[1] << " " << prices[2] << endl;
		cout << endl;

	}

}