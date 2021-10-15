#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int array[5] = {5, 1,2,3,4};
	array = {};
	cout << array[0];
	cout << array[1];
	cout << array[2];
	cout << array[3];
	cout << array[4];

	// string food = "Pizza"; 
	// string* ptr = &food;
	// cout << food << endl; 
	// cout << &food << endl; 
	// cout << ptr << endl;
	// cout << &ptr << endl;

	// double a = 30;
	// double b = 10000.0;
	// double pi = 3.1415926;
	// double pi_round = 3.14151926;

	// cout.precision (5);

	// cout << showpoint << "a1 = " << a << '\t' <<"b1 = " << b << '\t' << "pi1 = " << pi << '\t' << "pi_round1 = " << pi_round <<'\n';
	// cout << noshowpoint << "a2 = " << a << '\t' <<"b2 = " << b << '\t' << "pi2 = " << pi << '\t' << "pi_round2 = " << pi_round <<'\n';
	// cout << fixed << "a3 = " << a << '\t' <<"b3 = " << b << '\t' << "pi3 = " << pi << '\t' << "pi_round3 = " << pi_round <<'\n';
	// return 0;
}