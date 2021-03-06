// Matthew Freestone, maf0083
// project4_Freestone_maf0083.cpp 
// g++ project4_Freestone_maf0083.cpp -o runme; ./runme
// I used the hints file for definition of 2 versions
#include<string>
#include<iostream>
#define UNIT_TESTING
using namespace std;
struct TriviaNode
{
    string question;
    string answer; 
    int worth; 
    TriviaNode* next;
    TriviaNode(string,string,int);
};
TriviaNode* initQuestionList();
void getNewQuestion(TriviaNode*);
int askQuestions(TriviaNode*, int);
int questionsInLL = 0;
#ifdef UNIT_TESTING
int main(int argc, char const *argv[])
{
    TriviaNode* head;
    head = initQuestionList();
    cout << "*** This is a debugging version ***" << endl;
    cout << "Unit Test Case 1: Ask no question. The program should give a warning message. " << endl;
    askQuestions(head, 0);
    cout << "Case 1 Passed\n\n";

    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
    askQuestions(head,1);
    cout << "Case 2.1 Passed\n\n";
    
    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
    askQuestions(head,1);
    cout << "Case 2.2 Passed\n\n";
    
    cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
    askQuestions(head,questionsInLL);
    cout << "Case 3 Passed\n\n";

    cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
    askQuestions(head,5);
    cout << "Case 4 Passed\n\n";

    cout << "** End of the Debugging Version ***" << endl;
}
#else
int main(int argc, char const *argv[])
{
    TriviaNode* head;
    head = initQuestionList();

    cout << "*** Welcome to Freestone's trivia quiz game ***" << endl;

    string cont = "Yes";
    do{
        if (cont != "Yes"){
            cout << "Invalid response, enter Yes or No: ";
            cin >> cont; 
            cin.ignore(100, '\n');
        }
        getNewQuestion(head);

        cout << "Continue? (Yes/No): ";
        cin >> cont;
        cin.ignore(100, '\n');
    }
    while(cont != "No");
    cout << endl;
    
    int totalpts = 0;
    TriviaNode* n = head;
    askQuestions(n, questionsInLL);
    cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
    return 0;
}
#endif

TriviaNode* initQuestionList(){
    TriviaNode* head = new TriviaNode("How long was the shortest war on record? (Hint: how many minutes)", "38", 100);
    head->next = new TriviaNode("What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)", "Bank of Italy", 50);
    head->next->next = new TriviaNode("What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)", "Wii Sports", 20);
    return head;
}

int askQuestions(TriviaNode* n, int numQ){
    if (!n){
        cout << "No question list!" << endl;
        return 1;
    }
    if (numQ < 1){
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
        return 1; 
    } 
    if (numQ > questionsInLL){
        cout << "Warning - There is only "<< questionsInLL << " trivia in the list." << endl;
        return 1;
    }


    int totalpts = 0;
    for (int i = 0; i<numQ && n; i++) {
        cout << "Question: " << n->question << endl;
        string ans;
        cout << "Answer: ";
        getline(cin, ans);
        if (ans == n->answer){
            cout << "Your answer is correct! You receive " << n->worth <<" points." << endl;
            totalpts += n->worth;
        }
        else{
            cout << "Your answer is wrong. The correct answer is " << n->answer << endl;
        }
        cout << "Your total points: " << totalpts << "\n\n";

        n = n->next;
    }
    return 0;
}

void getNewQuestion(TriviaNode* head){
    string q, a;
    int p;
    cout << "Enter a question: ";
    getline(cin, q);
    cout << "Enter an answer: ";
    getline(cin, a);
    cout << "Enter award points: ";
    cin >> p;
    while (cin.fail()){
        cout << "Please enter a number: ";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> p; 
    }
    TriviaNode* n = head;
    while (n->next){
        n = n->next;
    }
    n->next = new TriviaNode(q,a,p);
}

TriviaNode::TriviaNode(string question, string answer, int worth){
    this->question = question;
    this->answer = answer;
    this->worth = worth;
    this->next = NULL;
    questionsInLL++;
}