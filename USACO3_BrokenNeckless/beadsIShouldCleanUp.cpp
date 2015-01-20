//beads

/*
ID: anakaga1
LANG: C++
TASK: beads
*/

/*Psudocode
First, we need to double the string so we can search for end and beginning of the string.  
Then, 
*/


#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);

	int length = 0;
	string circle;
	cin >> length;
	cin >> circle;


	//cerr << "circle size" << circle.length() << endl;

	//circle +=  "|" + circle; //double the string
	circle += circle;

	int STATE_START = 0; //set the Finite State Machines
	int STATE_RED = 1;
	int STATE_BLUE = 2;

	int state = STATE_START;

	bool sameColours = true;

	int longest = 0;
	int rcount = 0;
	int bcount = 0;
	for (int i = 0; i < circle.length(); i++)
	{
		char c = circle[i];
		//cerr << "i=" << i << " begin state=" << state << " character=" << c << " count=" << count << " longest=" << longest;

		//find out what bead of coulour is from.  and count 1 for any case
		if (state == STATE_START) {
			if (c == 'b')
			{
				//bcount++;
				state = STATE_BLUE;
			}
			if (c == 'r')
			{
				//rcount++;
				state = STATE_RED;
			}
			/*if (c == 'w') //we can ignore whites because we can count by the double string!
			{
			state = STATE_START;
			}
			count++;*/
		}

		//when the first one's colour is red, 
		if (state == STATE_RED) // find the first blue bead count the string forward and backward
		{

			if (c == 'b') //if it gets colour blue, count 1
			{
				sameColours = false;
				state = STATE_BLUE;
				bcount = 0;
				rcount = 0;

				// counting blue forward now ;(
				for (int j = i; j < circle.length(); j++)
				{
					if (circle[j] == 'r')
					{
						break;
					}
					bcount++;
				}

				//counting red backwards
				for (int j = i - 1; j >= 0; j--)
				{
					if (circle[j] == 'b')
					{
						break;
					}
					rcount++;
				}

				if (rcount + bcount > longest)
				{
					longest = rcount + bcount;
				}
			}
		}




		if (state == STATE_BLUE)
		{
			if (c == 'r') //if it gets colour blue, count 1
			{
				sameColours = false;
				state = STATE_RED;
				bcount = 0;
				rcount = 0;

				//counting red forward now ;(
				for (int j = i; j < circle.length(); j++)
				{
					if (circle[j] == 'b')
					{
						break;
					}
					rcount++;
				}

				//counting blue beads backwards
				for (int j = i - 1; j >= 0; j--)
				{
					if (circle[j] == 'r')
					{
						break;
					}
					bcount++;
				}

				if (rcount + bcount > longest)
				{
					longest = rcount + bcount;
				}
			}
		}
		//cerr << " new state=" << state << "    new count=" << count << " new longest=" << longest << endl;
	}

	if (sameColours == true)
	{
		longest = length;
	}

	if (longest > circle.length() / 2)  //because it was dobled change back to the original length
	{
		longest = circle.length()/2;
	}

		cout << longest << endl;
    
    // //when the first colour is WHITE
    // if (circle[0] == "w")
    // {
    // 	while (circle[i] == "w") //count as long as beads are white
    // 	{
    // 		i++;
    // 	}
    // 	if (circle[0+i+1] == "r") //if beads became red,...
    // 	{
    // 		while(circle !="b") // counting RED and WHITE
    // 		{
    // 			i++;
    // 		}
    // 		while(circle != "r") // count BLUE and WHITE after beads became BLUE
    // 		{
    // 			i++;
    // 		}
    // 		return i++;
    // 	}

    // 	else (circle [0+i] == "b") //if beads became BLUE,
    // 	{
    // 		while (circle[i+1] != "r") // counting BLUE and WHITE
    // 		{
    // 			i++;
    // 		}
    // 		while (circle[i+1] != "b") // counting RED and WHITE after beads became RED
    // 		{
    // 			i++;
    // 		}
    // 		return i++;
    // 	}
    // }

    // //when the first one's colour is RED,
    // if (circle[0] == "r")
    // {
    //     i=0;
    //     while (circle[i] != "b") //counting red and white beads
    //     {
    //         i++;
    //     }
    //     while (circle[i] != "r")   //counting blue and white beads
    //     {
    //         i++
    //     }
    //     return i;
    //     }
    // }

    // //when the first one's colour is BLUE
    // else (circle [0] == "b")
    // {
    // 	i=0;
    // 	while (circle[i] != "r")
    // 	{
    // 		i++;
    // 	}
    // 	while (circle[i] != "b"){
    // 		i++;
    // 	}
    // 	return i;
    // }

}
