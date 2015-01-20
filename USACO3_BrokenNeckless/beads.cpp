//beads

/*
ID: anakaga1
LANG: C++
TASK: beads
*/

/*Psudocode
We have to
*/


#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int main()
{
	freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    
    string circle;
    cin >> circle;
    
    circle += circle;
    
    //when the first colour is WHITE
    if (circle[0] == "w")
    {
    	while (circle[i] == "w") //count as long as beads are white
    	{
    		i++;
    	}
    	if (circle[0+i+1] == "r") //if beads became red,...
    	{
    		while(circle !="b") // counting RED and WHITE
    		{
    			i++;
    		}
    		while(circle != "r") // count BLUE and WHITE after beads became BLUE
    		{
    			i++;
    		}
    		return i++;
    	}

    	else (circle [0+i] == "b") //if beads became BLUE,
    	{
    		while (circle[i+1] != "r") // counting BLUE and WHITE
    		{
    			i++;
    		}
    		while (circle[i+1] != "b") // counting RED and WHITE after beads became RED
    		{
    			i++;
    		}
    		return i++;
    	}
    }

    //when the first one's colour is RED,
    if (circle[0] == "r")
    {
        i=0;
        while (circle[i] != "b") //counting red and white beads
        {
            i++;
        }
        while (circle[i] != "r")   //counting blue and white beads
        {
            i++
        }
        return i;
        }
    }

    //when the first one's colour is BLUE
    else (circle [0] == "b")
    {
    	i=0;
    	while (circle[i] != "r")
    	{
    		i++;
    	}
    	while (circle[i] != "b"){
    		i++;
    	}
    	return i;
    }

}
