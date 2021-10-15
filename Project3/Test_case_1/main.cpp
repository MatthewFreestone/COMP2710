#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAX_SIZE = 100;

int readfile(int inputArray[], ifstream& instream);
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
void writefile(ofstream& outStream, int outputArray[], int outputArray_size);

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

    string filename;
    cout << "file name: ";
    cin >> filename;

    inStream.open(filename.c_str());
    if (inStream.fail()) 
    {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    inArray1_size = readfile(inArray1, inStream);
    inStream.close();
    
    cout << "file name 2: ";
    cin >> filename;

    inStream.open(filename.c_str());
    if (inStream.fail()) 
    {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    inArray2_size = readfile(inArray2, inStream);
    inStream.close();

    cout << endl;
    outArray_size = sort(inArray1, inArray1_size, inArray2, inArray2_size, outArray);
    for (int i = 0; i < outArray_size; i++)
    {
        cout << outArray[i] << " ";
    }

    string out_filename;
    cout << "output file name: ";
    cin >> out_filename;

    outStream.open(out_filename.c_str());
    writefile(outStream, outArray, outArray_size);
    outStream.close();
    return 0;
}

int readfile(int inputArray[], ifstream& inStream)
{
    int index = 0;
    inStream >> inputArray[index];
    while (! inStream.eof()) 
    {
        cout << inputArray[index] << endl;
        index++;
        inStream >> inputArray[index];
    }
    return index;
} 

// assumes both arrays come in sorted
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[])
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
