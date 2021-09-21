#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int p1 = 8;
	int *ptr1 = &p1;
	int p2 = 9;
	cout << "P1: " << p1 << "; " << &p1 << endl;
	cout << "Ptr1: " << ptr1 << "; " << *ptr1 << endl;

	// p1 = p2;
	// cout << "P1: " << &p1 << "; P2: " << &p2 << endl;
	
	
	// ptr1 = &p2;
	// &p1 = ptr1;
	// cout << "P1: " << &p1 << "; P2: " << &p2 << endl;
	return 0;
}