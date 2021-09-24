// Matthew Freestone, maf0083
// project2_Freestone_maf0083.cpp 
// g++ project2_Freestone_maf0083.cpp -o runme; ./runme
// I used the function outlines given in the project2 description to structure my code.
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
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

void Bob_shoots(bool& A_alive, bool& C_alive){
	/* Call by reference
	* Input: A_alive indicates if Aaron is alive or dead 
	* C_alive indicates whether Charlie is alive or dead
	* Return: Change A_alive into false if Aaron is killed. 
	* Change C_alive into false if Charlie is killed. 
	*/
	if (C_alive){ 
		C_alive = false;
		// cout << "B killed C; ";
	}
	else { 
		A_alive = false;
		// cout << "B killed A; ";
	}
}

void Charlie_shoots(bool& A_alive, bool& B_alive){
	/* Call by reference
	* Input: A_alive indicates if Aaron is alive or dead 
	* B_alive indicates whether Bob is alive or dead 
	* Return: Change A_alive into false if Aaron is killed. 
	* Change B_alive into false if Bob is killed. 
	*/

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

	if (B_alive && C_alive) {
		return;
	}
	else {
		if (C_alive){ 
			C_alive = false;
		}
		//otherwise shoot at B
		else { 
			B_alive = false;
		}
	}
}

//Unit test for at_least_two_alive
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

//Unit test for Aaron_shoots1
void test_aaron_shoots1(){
	bool b_alive = true;
	bool c_alive = true;
	cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
	cout << "\tCase 1: Bob alive, Charlie alive\n";
	Aaron_shoots1(b_alive, c_alive);
	assert(b_alive == true);
	assert(c_alive == false);
	cout << "\t\tAaron is shooting at Charlie\n";

	b_alive = false;
	c_alive = true;
	cout << "\tCase 2: Bob dead, Charlie alive\n";
	Aaron_shoots1(b_alive, c_alive);
	assert(b_alive == false);
	assert(c_alive == false);
	cout << "\t\tAaron is shooting at Charlie\n";

	b_alive = true;
	c_alive = false;
	cout << "\tCase 3: Bob alive, Charlie dead\n";
	Aaron_shoots1(b_alive, c_alive);
	assert(b_alive == false);
	assert(c_alive == false);
	cout << "\t\tAaron is shooting at Bob\n";
}


//Unit test for Bob_shoots
void test_bob_shoots(){
	bool a_alive = true;
	bool c_alive = true;
	cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
	cout << "\tCase 1: Aaron alive, Charlie alive\n";
	Bob_shoots(a_alive, c_alive);
	assert(c_alive == false);
	assert(a_alive == true);
	cout << "\t\tBob is shooting at Charlie\n";

	a_alive = false;
	c_alive = true;
	cout << "\tCase 2: Aaron dead, Charlie alive\n";
	Bob_shoots(a_alive, c_alive);
	assert(c_alive == false);
	assert(a_alive == false);
	cout << "\t\tBob is shooting at Charlie\n";

	a_alive = true;
	c_alive = false;
	cout << "\tCase 3: Aaron alive, Charlie dead\n";
	Bob_shoots(a_alive, c_alive);
	assert(a_alive == false);
	assert(c_alive == false);
	cout << "\t\tBob is shooting at Aaron\n";
}

//Unit test for Charlie_shoots
void test_charlie_shoots(){
	bool a_alive = true;
	bool b_alive = true;
	cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
	cout << "\tCase 1: Aaron alive, Bob alive\n";
	Charlie_shoots(a_alive, b_alive);
	assert(b_alive == false);
	assert(a_alive == true);
	cout << "\t\tCharlie is shooting at Bob\n";

	a_alive = false;
	b_alive = true;
	cout << "\tCase 2: Aaron dead, Bob alive\n";
	Charlie_shoots(a_alive, b_alive);
	assert(a_alive == false);
	assert(b_alive == false);
	cout << "\t\tCharlie is shooting at Bob\n";

	a_alive = true;
	b_alive = false;
	cout << "\tCase 3: Aaron alive, Bob dead\n";
	Charlie_shoots(a_alive, b_alive);
	assert(a_alive == false);
	assert(b_alive == false);
	cout << "\t\tCharlie is shooting at Aaron\n";
}

//Unit test for Aaron_shoots2
void test_aaron_shoots2(){
	bool b_alive = true;
	bool c_alive = true;
	cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
	cout << "\tCase 1: Bob alive, Charlie alive\n";
	Aaron_shoots2(b_alive, c_alive);
	assert(c_alive && b_alive == true);
	cout << "\t\tAaron intentionally misses his first shot\n";
	cout << "\t\tBoth Bob and Charlie are alive.\n";

	b_alive = false;
	c_alive = true;
	cout << "\tCase 2: Bob dead, Charlie alive\n";
	Aaron_shoots2(b_alive, c_alive);
	assert(c_alive == false);
	assert(b_alive == false);
	cout << "\t\tAaron is shooting at Charlie\n";

	b_alive = true;
	c_alive = false;
	cout << "\tCase 3: Bob alive, Charlie dead\n";
	Aaron_shoots2(b_alive, c_alive);
	assert(b_alive == false);
		assert(c_alive == false);
	cout << "\t\tAaron is shooting at Bob\n";
}

// Tournament using Aaron_shoots1
int play_tournament(bool& A_alive, bool& B_alive, bool& C_alive){
	int shoot_target_result = 0;
	while (at_least_two_alive(A_alive,B_alive,C_alive)){
		if (A_alive){
			int shoot_target_result = rand()%3; //can  be 0, 1, 2
			// 1/3 chance of a hit
			if (shoot_target_result == 0){
				Aaron_shoots1(B_alive, C_alive);
			}
		}
		if (B_alive){
			int shoot_target_result = rand()%3; //can  be 0, 1, 2
			// 2/3 chance of a hit
			if (shoot_target_result > 0){
				Bob_shoots(A_alive, C_alive);
			}
		}
		if (C_alive){
			Charlie_shoots(A_alive, B_alive);
		}
	}
	if (A_alive){
		return 0;
	}
	if (B_alive){
		return 1;
	}
	if (C_alive){
		return 2;
	}

	//error
	return -1;
}

// Tournament using Aaron_shoots2
int play_tournament_strat2(bool& A_alive, bool& B_alive, bool& C_alive){
	while (at_least_two_alive(A_alive,B_alive,C_alive)){
		if (A_alive){
			int shoot_target_result = rand()%3; //can  be 0, 1, 2
			// 1/3 chance of a hit
			if (shoot_target_result == 0){
				Aaron_shoots2(B_alive, C_alive);
			}
		}
		if (B_alive){
			int shoot_target_result = rand()%3; //can  be 0, 1, 2
			// 2/3 chance of a hit
			if (shoot_target_result > 0){
				Bob_shoots(A_alive, C_alive);
			}
		}
		if (C_alive){
			Charlie_shoots(A_alive, B_alive);
		}
	}
	if (A_alive){
		return 0;
	}
	if (B_alive){
		return 1;
	}
	if (C_alive){
		return 2;
	}

	//Error, this should never return 
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
		cout << "Press any key to continue...";
		cin.ignore().get(); //Pause Command for Linux Terminal

		test_aaron_shoots1();
		cout << "Press any key to continue...";
		cin.ignore().get(); //Pause Command for Linux Terminal

		test_bob_shoots();
		cout << "Press any key to continue...";
		cin.ignore().get(); //Pause Command for Linux Terminal

		test_charlie_shoots();
		cout << "Press any key to continue...";
		cin.ignore().get(); //Pause Command for Linux Terminal

		test_aaron_shoots2();
		cout << "Press any key to continue...";
		cin.ignore().get(); //Pause Command for Linux Terminal
	}
	cout << "Ready to test strategy 1 (run " << NUMBER_OF_RUNS << " times):\n";
	cout << "Press any key to continue...";
	cin.ignore().get(); //Pause Command for Linux Terminal
	int wins[] = {0,0,0};
	for (int i = 0; i < NUMBER_OF_RUNS; i++){
		A_alive = PERSON_DEFAULT;
		B_alive = PERSON_DEFAULT;
		C_alive = PERSON_DEFAULT;
		int winner = play_tournament(A_alive,B_alive,C_alive);
		wins[winner]++;

	}
	//Calculuate win percentages for each player
	double a_wins_percent_1 = ((double)wins[0]/NUMBER_OF_RUNS) * 100;
	double b_wins_percent = ((double)wins[1]/NUMBER_OF_RUNS) * 100;
	double c_wins_percent = ((double)wins[2]/NUMBER_OF_RUNS) * 100;

	cout << setprecision(2) << fixed;
	cout << "Aaron won " << wins[0] << "/" << NUMBER_OF_RUNS << " duels or " << a_wins_percent_1 << "%\n";
	cout << "Bob won " << wins[1] << "/" << NUMBER_OF_RUNS << " duels or " << b_wins_percent << "%\n";
	cout << "Charlie won " << wins[2] << "/" << NUMBER_OF_RUNS << " duels or " << c_wins_percent << "%\n\n";

	cout << "Ready to test strategy 2 (run " << NUMBER_OF_RUNS << " times):\n";
	cout << "Press any key to continue...";
	cin.ignore().get(); //Pause Command for Linux Terminal
	for (int i = 0; i < 3; i++){
		wins[i]=0;
	}
	for (int i = 0; i < NUMBER_OF_RUNS; i++){
		A_alive = PERSON_DEFAULT;
		B_alive = PERSON_DEFAULT;
		C_alive = PERSON_DEFAULT;
		int winner = play_tournament_strat2(A_alive,B_alive,C_alive);
		wins[winner]++;

	}

	//Calculuate win percentages for each player
	double a_wins_percent_2 = ((double)wins[0]/NUMBER_OF_RUNS) * 100;
	b_wins_percent = ((double)wins[1]/NUMBER_OF_RUNS) * 100;
	c_wins_percent = ((double)wins[2]/NUMBER_OF_RUNS) * 100;
	cout << setprecision(2) << fixed;

	cout << "Aaron won " << wins[0] << "/" << NUMBER_OF_RUNS << " duels or " << a_wins_percent_2 << "%\n";
	cout << "Bob won " << wins[1] << "/" << NUMBER_OF_RUNS << " duels or " << b_wins_percent << "%\n";
	cout << "Charlie won " << wins[2] << "/" << NUMBER_OF_RUNS << " duels or " << c_wins_percent << "%\n\n";
	
	//compare aaron's win percentage from each strategy 
	if (a_wins_percent_2 > a_wins_percent_1){
		cout << "Strategy 2 is better than strategy 1.";
	}
	else{
		cout << "Strategy 1 is better than strategy 2.";
	}

	return 0;
}