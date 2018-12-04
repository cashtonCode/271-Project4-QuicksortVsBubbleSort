/*
Author:   Cashton Christensen
Date:     3/27/2018
Purpose:  To sort a file of character arrays ( strings ) using the bubble sort sorting method
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

template<class TYPENAME>
void bubble_sort(TYPENAME array[ ], int n) {
  for (int I = 0; I < n - 1; I++)
  {
    for (int j = n - 1; j > I; j--)
    {
      if(array[j] < array[j-1])
        swap(array[j], array[j-1]);
    }
  }
}

int main(int argc, char* argv[])
{
  int size = atoi(argv[1]);
  string *array = new string[size];
  string line = "";
  ifstream inFile;

  inFile.open("/home/win.thackerw/271/sort.dat");
  for(int i = 0; i < size; i++)
  {
    inFile >> line;
    array[i] = line;
  }
  inFile.close();

  bubble_sort(array, size);

  ofstream outFile;

  outFile.open("sorted.dat");
  for(int i = 0; i < size; i++)
  {
    outFile << array[i] << endl;
  }
  outFile.close();

  delete [] array;

  return 0;
}
