/*********************************************************************
** Program name: main.cpp
** Author: Alexandra Carper
** Date: 03/02/2018
** Description: This file includes a main function and four other
 *              functions. The readFile() reads integers from a file
 *              into a dynamically allocated array and then returns
 *              the array from the function. The linearSearch()
 *              function performs a search for the target value the
 *              user input and returns whether or not it was found.
 *              The sortArray() function sorts the array and writes
 *              the numbers to an output file that is named by the
 *              user. Finally, the binarySearch() function reads the
 *              array from the output file in written to in the
 *              sortArray() function and performs a binary search
 *              for the target on the array.
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "readFile.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

bool linearSearch(int array[], int size, int target);
void sortArray(string oFileName, int array[], int size);
bool binarySearch(string oFileName, int size, int target);

int main()
{
    string file1 = "num.txt";
    int file1Size = 9;
    int *file1Array;

    string file2 = "early.txt";
    int file234Size = 10;
    int *file2Array;

    string file3 = "middle.txt";
    int *file3Array;

    string file4 = "end.txt";
    int *file4Array;

    file1Array = readFile(file1, file1Size);
    file2Array = readFile(file2, file234Size);
    file3Array = readFile(file3, file234Size);
    file4Array = readFile(file4, file234Size);

    int target;
    bool validTarget = false;

    cout << "What is target value: " << endl;
    while(!validTarget)
    {
        cin >> target;
        if(cin.fail())
        {
            cout << "Error! Please enter a valid target." << endl;
            cin.clear();
            cin.ignore();
        }
        else if(target < 0)
        {
            cout << "Error! Please enter a positive integer!" << endl;
            cin.clear();
            cin.ignore();
        }
        else
        {
            validTarget = true;
        }
    }

    //Search file 1's array for target
    if(linearSearch(file1Array, file1Size, target))
    {
        cout << file1 << ": target value found" << endl;
        cout << endl;
    }
    else
    {
        cout << file1 << ": target value not found" << endl;
        cout << endl;
    }

    //Search file 2's array for target
    if(linearSearch(file2Array, file234Size, target))
    {
        cout << file2 << ": target value found." << endl;
        cout << endl;
    }
    else
    {
        cout << file2 << ": target value not found." << endl;
        cout << endl;
    }

    //Search file 3's array for target
    if(linearSearch(file3Array, file234Size, target))
    {
        cout << file3 << " target value found." << endl;
        cout << endl;
    }
    else
    {
        cout << file3 << " target value not found." << endl;
        cout << endl;
    }

    //Search file 4's array for target
    if(linearSearch(file4Array, file234Size, target))
    {
        cout << file4 << " target value found." << endl;
        cout << endl;
    }
    else
    {
        cout << file4 << " target value not found." << endl;
        cout << endl;
    }
    cout << endl;

    string file1out;
    string file2out;
    string file3out;
    string file4out;

    cout << "Enter name for output file 1: ";
    cin >> file1out;
    cout << endl;


    cout << "Enter name for output file 2: ";
    cin >> file2out;
    cout << endl;

    cout << "Enter name for output file 3: ";
    cin >> file3out;
    cout << endl;

    cout << "Enter name for output file 4: ";
    cin >> file4out;
    cout << endl;
    cout << endl;

    //Sort arrays (SOURCE FROM BOOK PG. 616)
    sortArray(file1out, file1Array, file1Size);
    sortArray(file2out, file2Array, file234Size);
    sortArray(file3out, file3Array, file234Size);
    sortArray(file4out, file4Array, file234Size);

    cout << "Array 1: ";
    for(int h = 0; h < file1Size; h++)
    {
        cout << file1Array[h];
    }
    cout << endl;

    cout << "Array 2: ";
    for(int i = 0; i < file234Size; i++)
    {
        cout << file2Array[i];
    }
    cout << endl;

    cout << "Array 3: ";
    for(int j = 0; j < file234Size; j++)
    {
        cout << file3Array[j];
    }
    cout << endl;

    cout << "Array 4: ";
    for(int k = 0; k < file234Size; k++)
    {
        cout << file4Array[k];
    }
    cout << endl;
    cout << endl;

    //Binary search each array
    if(binarySearch(file1out, file1Size, target))
    {
        cout << file1 << " target value found." << endl;
        cout << endl;
    }
    else
    {
        cout << file1 << " target value not found." << endl;
        cout << endl;
    }

    if(binarySearch(file2out, file234Size, target))
    {
        cout << file2 << " target value found." << endl;
        cout << endl;
    }
    else
    {
        cout << file2 << " target value not found." << endl;
        cout << endl;
    }

    if(binarySearch(file3out, file234Size, target))
    {
        cout << file3 << " target value found." << endl;
        cout << endl;
    }
    else
    {
        cout << file3 << " target value not found." << endl;
        cout << endl;
    }

    if(binarySearch(file4out, file234Size, target))
    {
        cout << file4 << " target value found." << endl;
        cout << endl;
    }
    else
    {
        cout << file4 << " target value not found." << endl;
        cout << endl;
    }

    return 0;
}


/****************************************************************************
 * Description: Performs a linear search for the target value
 ***************************************************************************/
bool linearSearch(int array[], int size, int target)
{
    int index = 0;
    bool found = false;
    int position = -1;

    //Keep searching while target not found
    while(index < size && !found)
    {
        //If target found
        if(array[index] == target)
        {
            //Set flag
            found = true;
            position = index;
        }
        //Go to next element
        index++;
    }
    //cout << "Position: " << position << endl;
    return found;
}

/****************************************************************************
 * Description: Sorts the array and writes to output file
 ***************************************************************************/
void sortArray(string oFileName, int array[], int size)
{
    int temp;
    bool madeAswap;
    ofstream outputFile;

    do
    {
        madeAswap = false;
        for(int count = 0; count < (size - 1); count++)
        {
            if(array[count] > array[count + 1])
            {
                temp = array[count];
                array[count] = array[count + 1];
                array[count + 1] = temp;
                madeAswap = true;
            }
        }
    } while(madeAswap);

    outputFile.open(oFileName.c_str());

    if(outputFile.is_open())
    {
        for(int count = 0; count < size; count++)
        {
            outputFile << array[count] << " ";
        }
        outputFile.close();
    }
    else
    {
        cout << "Unable to open file.";
    }
}

/****************************************************************************
 * Description: Performs a binary search of array and returns if
 *              target is found or not.
 ***************************************************************************/
bool binarySearch(string oFileName, int size, int target)
{
    int value;
    int first = 0;                              //First element
    int middle;                                 //Middle element
    int last = size - 1;                        //Last element
    bool found = false;
    ifstream inputFile;                         //Input file stream object
    int *array = new int[size];                 //Dynamically allocated array to write to

    //Open output file from previous task
    inputFile.open(oFileName.c_str());

    //If input file does not open successfully
    if(!inputFile)
    {
        cout << "Unable to open file." << endl;
    }
    else
    {
        //READ VALUES INTO ARRAY
        //For each element of the array
        for(int i = 0; i < size; i++)
        {
            //Read in an integer
            inputFile >> array[i];
        }

        //CONDUCT BINARY SEARCH
        //While target is not found and the first element is less than or equal to the last
        while(!found && first <= last)
        {
            //Set middle element to element halfway in between integers
            middle = (first + last) / 2;
            //If the middle value is equal to the target
            if(array[middle] == target)
            {
                //Set found to true
                found = true;
            }
                //If middle value is greater than the target
            else if(array[middle] > target)
            {
                //Look for target in the first half of the elements
                last = middle - 1;
            }
            else
            {
                //Look for target in the last half of the elements
                first = middle - 1;
            }
        }

        inputFile.close();
    }
    delete[] array;
    return found;
}

