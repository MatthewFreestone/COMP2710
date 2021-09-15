# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>
using namespace std;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive){
	/* Input: A_alive indicates whether Aaron is alive */
	/* B_alive indicates whether Bob is alive */
	/* C_alive indicates whether Charlie is alive */
	/* Return: true if at least two are alive */ 
	/* otherwise return false */
	int t = 0;
	if (A_alive){
		t++;
	}
	if (B_alive){
		t++;
	}
	if (C_alive){
		t++;
	}

	if (t >= 2){
		return true;
	}
	return false;
}

void Aaron_shoots1(bool& B_alive, bool& C_alive){
	/* Strategy 1: Use call by reference
	* Input: B_alive indicates whether Bob alive or dead 
	* C_alive indicates whether Charlie is alive or dead
	* Return: Change B_alive into false if Bob is killed. 
	* Change C_alive into false if Charlie is killed. 
	*/
	int shoot_target_result = rand()%3; //can  be 0, 1, 2
	// 1/3 chance of a hit
	if (shoot_target_result == 0) { 
		//shoot at C if hes alive
		if (C_alive){ 
			C_alive = false;
			// cout << "A killed C; ";
		}

		//otherwise shoot at B
		else { 
			B_alive = false;
			// cout << "A killed B; ";
		}
	}
	else{
		// cout << "A missed; ";
	}
}

void Bob_shoots(bool& A_alive, bool& C_alive){
	/* Call by reference
	* Input: A_alive indicates if Aaron is alive or dead 
	* C_alive indicates whether Charlie is alive or dead
	* Return: Change A_alive into false if Aaron is killed. 
	* Change C_alive into false if Charlie is killed. 
	*/
	int shoot_target_result = rand()%3; //can  be 0, 1,2
	// 2/3 chance of a hit
	if (shoot_target_result >= 1) { 
		//shoot at C if hes alive
		if (C_alive){ 
			C_alive = false;
			// cout << "B killed C; ";
		}

		//otherwise shoot at A
		else { 
			A_alive = false;
			// cout << "B killed A; ";
		}
	}
	else{
		// cout << "B missed; ";
	}
}

void Charlie_shoots(bool& A_alive, bool& B_alive){
	/* Call by reference
	* Input: A_alive indicates if Aaron is alive or dead 
	* B_alive indicates whether Bob is alive or dead 
	* Return: Change A_alive into false if Aaron is killed. 
	* Change B_alive into false if Bob is killed. 
	*/

	//Guaranteed hit
	//shoot at B if hes alive
	if (B_alive){ 
		B_alive = false;
		// cout << "C killed B; ";
	}

	//otherwise shoot at A
	else { 
		A_alive = false;
		// cout << "C killed A; ";
	}
}

void Aaron_shoots2(bool& B_alive, bool& C_alive){
	//aaron does nothing
	/* Strategy 2: Use call by reference
	* Input: B_alive indicates whether Bob alive or dead 
	* C_alive indicates whether Charlie is alive or dead 
	* Return: Change B_alive into false if Bob is killed. 
	* Change C_alive into false if Charlie is killed. 
	*/

   if (B_alive && C_alive){
	   return;
   }
   else {
	   int shoot_target_result = rand()%3; //can  be 0, 1, 2
	   // 1/3 chance of a hit
	   if (shoot_target_result == 0) { 
		   //shoot at C if hes alive
			if (C_alive){ 
				C_alive = false;
			}

			//otherwise shoot at B
			else { 
				B_alive = false;
			}
		}
	}
}

void test_at_least_two_alive(void) {
	cout << "Unit Testing 1: Function - at_least_two_alive()\n";
	cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "\tCase passed ...\n";

	cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "\tCase passed ...\n";

	cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "\tCase passed ...\n";

	cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "\tCase passed ...\n";

	cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "\tCase passed ...\n";
}

int play_tournament(bool& A_alive, bool& B_alive, bool& C_alive){
	while (at_least_two_alive(A_alive,B_alive,C_alive)){
		if (A_alive){
			Aaron_shoots1(B_alive, C_alive);
		}
		if (B_alive){
			Bob_shoots(A_alive, C_alive);
		}
		if (C_alive){
			Charlie_shoots(A_alive, B_alive);
		}
	}
	if (A_alive){
		// cout << "a won" << endl;
		return 1;
	}
	if (B_alive){
		// cout << "b won" << endl;
		return 2;
	}
	if (C_alive){
		// cout << "c won" << endl;
		return 3;
	}

	//error
	return -1;
}
int play_tournament_strat2(bool& A_alive, bool& B_alive, bool& C_alive){
	while (at_least_two_alive(A_alive,B_alive,C_alive)){
		if (A_alive){
			Aaron_shoots2(B_alive, C_alive);
		}
		if (B_alive){
			Bob_shoots(A_alive, C_alive);
		}
		if (C_alive){
			Charlie_shoots(A_alive, B_alive);
		}
	}
	if (A_alive){
		// cout << "a won" << endl;
		return 1;
	}
	if (B_alive){
		// cout << "b won" << endl;
		return 2;
	}
	if (C_alive){
		// cout << "c won" << endl;
		return 3;
	}

	//error
	return -1;
}

int main(int argc, char const *argv[])
{
	const int NUMBER_OF_RUNS = 10000;
	const bool RUN_UNIT_TESTS = true;
	const bool PERSON_DEFAULT = true;

	srand(time(0));
	bool A_alive = PERSON_DEFAULT;
	bool B_alive = PERSON_DEFAULT;
	bool C_alive = PERSON_DEFAULT;


	cout << "*** Welcome to Freestone's Duel Simulator ***\n";
	if (RUN_UNIT_TESTS){
		test_at_least_two_alive();
		cout << "Press Enter to continue...";
		cin.ignore().get(); //Pause Command for Linux Terminal
	}
	cout << "Ready to test strategy 1 (run " << NUMBER_OF_RUNS << " times):\n";
	cout << "Press Enter to continue...";
	cin.ignore().get(); //Pause Command for Linux Terminal
	int wins[] = {0,0,0};
	for (int i = 0; i < NUMBER_OF_RUNS; i++){
		A_alive = PERSON_DEFAULT;
		B_alive = PERSON_DEFAULT;
		C_alive = PERSON_DEFAULT;
		int winner = play_tournament(A_alive,B_alive,C_alive);
		wins[--winner]++;

	}
	cout << wins[0] << " " << wins[1] << " " << wins[2] << endl;

	cout << "Ready to test strategy 2 (run " << NUMBER_OF_RUNS << " times):\n";
	cout << "Press Enter to continue...";
	cin.ignore().get(); //Pause Command for Linux Terminal
	for (int i = 0; i < 3; i++){
		wins[i]=0;
	}
	for (int i = 0; i < NUMBER_OF_RUNS; i++){
		A_alive = PERSON_DEFAULT;
		B_alive = PERSON_DEFAULT;
		C_alive = PERSON_DEFAULT;
		int winner = play_tournament_strat2(A_alive,B_alive,C_alive);
		wins[--winner]++;

	}
	cout << wins[0] << " " << wins[1] << " " << wins[2];
	
	return 0;
}