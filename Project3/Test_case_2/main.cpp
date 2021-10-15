#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAX_SIZE = 500;

int readfile(int inputArray[], ifstream& instream);
int merge(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
void writefile(ofstream& outStream, int outputArray[], int outputArray_size);
void printArray(int array[], int size, char separator); 
bool checkFile(string filename);

int main(int argc, char const *argv[])
{
    
    ifstream inStream;
    ofstream outStream;
    int inArray1[MAX_SIZE];
    int inArray1_size;
    int inArray2[MAX_SIZE];
    int inArray2_size;
    int outArray[MAX_SIZE*2];
    int outArray_size;


    cout << "*** Welcome to Freestone's sorting program ***" << endl;
    string filename;
    cout << "Enter the first input file name: ";
    cin >> filename;
    while (cin.fail() || !checkFile(filename)){
        cout << "Input file opening failed, try again: ";
        cin >> filename;
    }

    inStream.open(filename.c_str());
    inArray1_size = readfile(inArray1, inStream);
    inStream.close();
    cout << "The list of "<< inArray1_size <<" numbers in file "  << filename << " is: " << endl;
    printArray(inArray1, inArray1_size, '\n');
    cout << endl;

    cout << "Enter the second input file name: ";
    cin >> filename;
    while (cin.fail() || !checkFile(filename)){
        cout << "Input file opening failed, try again: ";
        cin >> filename;
    }

    inStream.open(filename.c_str());
    inArray2_size = readfile(inArray2, inStream);
    inStream.close();
    cout << "The list of "<< inArray2_size <<" numbers in file "  << filename << " is: " << endl;
    printArray(inArray2, inArray2_size, '\n');
    cout << endl;

    outArray_size = merge(inArray1, inArray1_size, inArray2, inArray2_size, outArray);
    cout << "The sorted list of "<< outArray_size << " numbers is: ";
    printArray(outArray, outArray_size, ' ');

    string out_filename;
    cout << "\nEnter the output file name: ";
    cin >> out_filename;

    outStream.open(out_filename.c_str());
    writefile(outStream, outArray, outArray_size);
    outStream.close();

    cout << "*** Please check the new file - " << out_filename << " ***\n*** Goodbye. ***";
    return 0;
}

int readfile(int inputArray[], ifstream& inStream)
{
    int index = 0;
    int value; 
    while (inStream.good())
    {
        inStream >> inputArray[index++];
    }
    return index;
} 

// merge step of merge sort
int merge(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[])
{
    int i=0,j=0,k=0;
    while(i < inputArray1_size && j < inputArray2_size)
    {
        if (inputArray1[i] <= inputArray2[j]){
            outputArray[k] = inputArray1[i];
            i++;
        }
        else{
            outputArray[k] = inputArray2[j];
            j++;
        }
        k++;
    }
    while (i < inputArray1_size)
    {
        outputArray[k] = inputArray1[i];
        i++;
        k++;
    }
    while (j < inputArray2_size)
    {
        outputArray[k] = inputArray2[j];
        j++;
        k++;
    }
    return k;
}
void writefile(ofstream& outStream, int outputArray[], int outputArray_size)
{
    for (int i = 0; i < outputArray_size; i++)
    {
        outStream << outputArray[i] << endl;
    }
    
}

void printArray(int array[], int size, char separator){
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << separator;
    }
}

bool checkFile(string filename){
    ifstream inStream;
    inStream.open(filename.c_str());
    if (inStream.fail()) 
    {
        inStream.close(); //unsure if this is needed, but better safe than sorry
        return false;
    }
    inStream.close();
    return true;
}
