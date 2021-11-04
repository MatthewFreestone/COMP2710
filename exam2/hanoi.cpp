#include<iostream>
using namespace std;
void hanoi(int n, char start, char end, char aux){
    if (n == 1){
        cout << "Move disk 1 from " << start << " to " << end << endl;
        return;
    }
    hanoi(n-1, start, aux, end);
    cout << "Move disk " << n <<" from " << start << " to " << end << endl;
    hanoi(n-1, aux, end, start);
    // cout << "Move disk " << n <<" from " << aux << " to " << end << endl;

}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    hanoi(n,'A','C','B');
    return 0;
}
