/****************************************************************************
 * Program Name: readFile.cpp
 * Author: Alexandra Carper
 * Date: 03/02/2018
 * Description: Reads values from input file into an array and returns
 *              a pointer to the array from the function.
 ***************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "readFile.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int *readFile(string file, int &size)
{
    ifstream inFile;
    int *array = new int[size];

    //Open file
    inFile.open(file.c_str());

    //If file does not open
    if(!inFile)
    {
        cout << file << " does not exist." << endl;
    }
        //If file opens
    else
    {
        //For each element of the array
        for(int i = 0; i < size; i++)
        {
            //Read in an integer
            inFile >> array[i];
        }
    }
    inFile.close();
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return array;
}