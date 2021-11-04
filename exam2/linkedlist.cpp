#include<bits.h>
#include<iostream>
struct Node{
    int val;
    struct Node* prev;
    struct Node* next;
    Node(int v){
        this->val = v;
        this->prev = NULL;
        this->next = NULL;
    }
};
using namespace std;
int main(int argc, char const *argv[])
{
    Node head(0);
    Node* n = &head;
    for (int i = 1; i < 10; i++)
    {
        Node* nn = new Node(i);
        n->next = nn;
        nn->prev = n;
        n = nn;
    }


    n = &head;
    cout << head.val << " ";
    while (n->next){
        n = n->next;
        cout << n->val << " ";
    }
    n = n->prev;
    while(n){
        cout << n->val << " ";
        n = n->prev;
    }
    

    return 0;
}
