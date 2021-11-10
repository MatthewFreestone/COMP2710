#include<string>
#include<iostream>
// #define UNIT_TESTING
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
bool askQuestion(TriviaNode*);
#ifdef UNIT_TESTING
int main(int argc, char const *argv[])
{}
#else
int main(int argc, char const *argv[])
{
    TriviaNode* head;
    head = initQuestionList();

    cout << "*** Welcome to Freestone's trivia quiz game ***" << endl;
    while(true){
        getNewQuestion(head);
        string cont;
        cout << "Continue? (Yes/No): ";
        cin >> cont;
        if (cont == "Yes"){
            continue;
        }
        else{
            break;
        }
    }
    cout << endl;
    
    int totalpts = 0;
    TriviaNode* n = head;
    while (n){
        if (askQuestion(n)){
            totalpts += n->worth;
        }
        n = n->next;
        cout << "Your Total points: " << totalpts << endl << endl;
    }
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

bool askQuestion(TriviaNode* n){
    cout << "Question: " << n->question << endl;
    string ans;
    cout << "Answer: ";
    getline(cin, ans);
    if (ans == n->answer){
        cout << "Your answer is correct! You receive " << n->worth <<" points." << endl;
        return true;
    }
    cout << "Your answer is wrong. The correct answer is " << n->answer << endl;
    return false; 
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
        this->next = nullptr;
    }