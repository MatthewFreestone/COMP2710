#include<iostream>
#include<fstream>
using namespace std;

const int MAX_SIZE = 100;

int readfile(int inputArray[], ifstream& instream);
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
void writefile(int outputArray[], int outputArray_size);

int main(int argc, char const *argv[])
{
    char filename[260];
    int inArray1[MAX_SIZE];
    cout << "file name: ";
    cin >> filename;
    // cout << "entered filename is: " << filename << endl;
    ifstream inStream;
    int iArray1[MAX_SIZE];
    int iArray1_size;
    int iArray2[MAX_SIZE];
    int iArray2_size;
    inStream.open(filename);
    if (inStream.fail()) 
    {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    iArray1_size = readfile(inArray1, inStream);
    inStream.close();

    for (int i = 0; i < iArray1_size; i++)
    {
        cout << inArray1[i] << endl;
    }
    
    return 0;
}

int readfile(int inputArray[], ifstream& inStream){
    int index = 0;
    inStream >> inputArray[index];
    while (! inStream.eof()) 
    {
        // cout << inputArray[index] << endl;
        index++;
        inStream >> inputArray[index];
    }
    return index;
} 

// ifstream inStream;
//  int data;
//  cout << "file name:";
//  cin >> filename;
//  cout << "entered filename is:" << filename << endl;
//  // Pass the file name as an array of chars to open()
//  // inStream.open(filename); 
//  inStream.open((char*)filename.c_str());
//  if (inStream.fail()) {
//  cout << "Input file opening failed." << endl;
//  exit(1);
//  }
//  inStream >> data; 
//  while (!inStream.eof()) {
//  cout << data << endl;
//  inStream >> data;
//  }
//  inStream.close();