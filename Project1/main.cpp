#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int amnt, interest, payment;
    cout << "Loan Amount: ";
    cin >> amnt;
    cout << "Interested Rate (% per year): ";
    cin >> interest;
    cout <<"Monthly Payments: ";
    cin >> payment;
    cout << amnt << interest << payment; 
    // cout << "**********************************************************";
    // cout << "\n\t\tAmortization Table\n";
    // cout << "**********************************************************";
    return 0;
}
