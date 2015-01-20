// Your Ride Is Here

/*
ID: anakaga1
LANG: JAVA
TASK: ride
*/

/*Psodocode

convert the String(alphabet) into array (number) list
then we multiply by recursion => integer1 (first) and integer2 (secound)
then, check if the mod of first line and secound line is the same.

*/
import java.io.*;

public class ride{

	static int convertToNumber(String s){
		int r = 1;

		for (int i=0; i<s.length();i++){
			char c = s.charAt(i);
			r = r*(c - 'A' +1);
		}

		return r;
	}

	public static void main(String args[]) {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String cometName = null;

		try {
			cometName = br.readLine();
			System.err.println("cometName = " +cometName);

		} catch (IOException ioe) {
			System.out.println("IO error trying to read cometName!");
			System.exit(1);
		}
		String groupName = null;

		try {
			groupName = br.readLine();
			System.err.println("groupName = " +groupName);

		} catch (IOException ioe) {
			System.out.println("IO error trying to read groupName!");
			System.exit(1);
		}


		int comet = convertToNumber(cometName); 
		int group = convertToNumber(groupName);
	// actual code
		if (comet%47 == group%47){
			System.out.println("GO");
		}

		else{
			System.out.println("STAY");
		}
	}
}


