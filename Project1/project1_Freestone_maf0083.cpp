//Matthew Freestone, maf0083
//project1_Freestone_maf0083.cpp 
//g++ project1_Freestone_maf0083.cpp -o runme; ./runme
//I used the "Project1_hints.pdf" to check how to align the data properly.
//I used https://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input to learn to check data type on cin 
#include <iostream>
#include <limits>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //initialize inputed variables
    double balance, rate, payment;
    cout << "Loan Amount: ";
    cin >> balance;
    //ensure that user passed in an integer
    while (!cin){
        cout << "Please enter a number: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> balance; 
    }
    //ensure user passed an amount above zero 
    if (balance <= 0){
        cout << "Loan Amount must be a positive number: ";
        cin >> balance; 
    }

    cout << "Interest Rate (% per year): ";
    cin >> rate;
    //ensure that user passed in an integer
    while (!cin){
        cout << "Please enter a number: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> rate; 
    }
    //ensure rate is non-negative
    if (rate < 0){
        cout << "Interest Rate must be a non-negative number: ";
        cin >> balance; 
    }
    //change yearly rate to monthly 
    rate /= 12;

    cout <<"Monthly Payments: ";
    cin >> payment;
    //ensure that user passed in an integer
    while (!cin){
        cout << "Please enter a number: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> payment; 
    }
    //ensure payment is above 0
    if (payment <= 0){
        cout << "Monthly Payments must be a positive number: ";
        cin >> payment; 
    }
    //ensure payment is large enough to offset the interest
    if (balance*(rate/100) >= payment){
        cout << "Payment is insufficient, pick a larger Monthly Payment: ";
        cin >> payment; 
    }

    //print table header
    cout << "*****************************************************************\n"  
         << "\tAmortization Table\n" 
         << "*****************************************************************\n"  
         << "Month\tBalance\t\tPayment\t\tRate\tInterest\tPricipal\n";

    //print initial column with "N/A" in most categories
    printf("0\t$%.2f\tN/A\t\tN/A\tN/A\t\tN/A\n", balance);
    int month = 1;
    double totalInterest = 0;
    //iterate until the balance is no longer positive 
    for (; balance > 0; month++){
        double interest = balance*(rate/100);
        totalInterest += interest;
        balance += interest;
        if (balance > payment) {
            balance -= payment;
        }
        else {
            payment = balance;
            balance = 0;
        }
        double principal = payment - interest;
        char extraBalanceTab, extraPaymentTab;
        //add an extra space if the balance is too short
        if (balance < 1000) {
            extraBalanceTab = '\t';            
        }
        //add an extra space if the payment is too short
        if (payment < 1000) {
            extraPaymentTab = '\t';
        }
        //Print with each floating point number formated with 2 digits after the decimal 
        printf("%d\t$%.2f%c\t$%.2f%c\t%.2f\t$%.2f\t\t$%.2f\n", month, balance, extraBalanceTab, payment, extraPaymentTab, rate, interest, principal);
    }
    cout << "**********************************************************\n\n";

    //Print out final information
    cout << "It takes " << --month << " " << (month > 1 ? "months" : "month") << " to pay off the loan.\n";
    printf("Total interest paid is: $%.2f\n\n", totalInterest);
    return 0;
}
