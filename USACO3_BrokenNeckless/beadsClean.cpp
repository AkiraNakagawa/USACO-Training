//beads

/*
ID: anakaga1
LANG: C++
TASK: beads
*/

/*Psudocode
First, we need to double the string so we can search for end and beginning of the string.  
Then, we use Finite State Machine!  Set the start, blue, and red states!  In the looping, find the first colour and for each colour except white,
we direct to blue or red.  Then, looping as long as the colour of beads are the same colour and when the colour changes, looping until it gets the original colour.
and we have to see if the looping the count is larger than longest, if so, we should put the int into longest.
In the case, when we have a string which has only one colour (or either red or blue with white), we should mention that length of the string is the integer longest! (by boolean)
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
	cin >> length; //reading the string from the input file
	cin >> circle;


	//cerr << "circle size" << circle.length() << endl;

	circle += circle; //double the string!

	int STATE_START = 0; //set the Finite State Machines
	int STATE_RED = 1;
	int STATE_BLUE = 2;

	int state = STATE_START;

	bool sameColours = true;

	int longest = 0; //preparing for the final answer!
	int rcount = 0;  //counting red beads
	int bcount = 0;  //counting blue beads
	for (int i = 0; i < circle.length(); i++)
	{
		char c = circle[i];
		

		//find out what bead of coulour is from.  and count 1 for any case
		if (state == STATE_START) {
			if (c == 'b')
			{
				state = STATE_BLUE;
			}
			if (c == 'r')
			{
				state = STATE_RED;
			}
			/*if (c == 'w')              //we can ignore whites because we can count by the double string!
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
		
		//when the first colour is BLUE
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
		
	}
	//boolean if there are only same colour of beads; like rrrrrr, then longest gets string's length.
	if (sameColours == true)
	{
		longest = length;
	}

	if (longest > circle.length() / 2)  //because it was dobled change back to the original length
	{
		longest = circle.length()/2;
	}

		cout << longest << endl;
    
    
}
