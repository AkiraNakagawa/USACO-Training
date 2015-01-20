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

string circle;
bool sameColours;
int STATE_START = 0; //set the Finite State Machines
int STATE_RED = 1;
int STATE_BLUE = 2;
int longest = 0; //preparing for the final answer!

void countColourDifference(int i, int state)
{
	char colourOne, colourTwo;
	if (state == STATE_RED)
	{
		colourOne = 'r';
		colourTwo = 'b';
	}

	else if (state == STATE_BLUE)
	{
		colourOne = 'b';
		colourTwo = 'r';
	}
	

	if (circle[i] == colourTwo) 
	{
		sameColours = false;
		if (state == STATE_RED)
		{
			state = STATE_BLUE;
		}
		else
		{
			state = STATE_RED;
		}
			

		int count1 = 0;  //counting red beads
		int count2 = 0;  //counting blue beads

		// counting blue forward now ;(
		for (int j = i; j < circle.length(); j++)
		{
			if (circle[j] == colourOne)
			{
				break;
			}
			count2++;
		}

		//counting red backwards
		for (int j = i - 1; j >= 0; j--)
		{
			if (circle[j] == colourTwo)
			{
				break;
			}
			count1++;
		}

		if (count1 + count2 > longest)
		{
			longest = count1 + count2;
		}
	}
}


int main()
{
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);

	int length = 0;
	
	cin >> length; //reading the string from the input file
	cin >> circle;


	//cerr << "circle size" << circle.length() << endl;

	circle += circle; //double the string!

	

	int state = STATE_START;

	sameColours = true;

	
	
	for (int i = 0; i < circle.length(); i++)
	{
		char c = circle[i];


		//find out what bead of colour is from.  skip whites
		if (state == STATE_START) {
			if (c == 'b')
			{
				state = STATE_BLUE;
			}
			if (c == 'r')
			{
				state = STATE_RED;
			}
			//we can ignore whites because we check the point where the colour changes (white can count as red or blue)!
		}

		//when the first one's colour is red, 
		else // find the first blue bead count the string forward and backward
		{
			countColourDifference(i, state);
		}

	}
	//boolean if there are only same colour of beads; like rrrrrr, then longest gets string's length.
	if (sameColours == true)
	{
		longest = length;
	}

	if (longest > length)  //because it was dobled change back to the original length
	{
		longest = length;
	}

	cout << longest << endl;
}