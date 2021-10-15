#include<iostream>
using namespace std;

enum Colors {
    BLACK, 
    WHITE,
    RED,
    BLUE,
};

void printColor(Colors color){
    switch (color)
    {
    case BLACK:
        cout << "Black"; 
        break;

    case WHITE:
        cout << "WHITE";
        break;

    case RED:
        cout << "RED";
        break;

    default:
        cout << "Unknown";
        break;
    }
}

int main(int argc, char const *argv[])
{
    Colors r = BLUE;
    printColor(r);
    return 0;
}
