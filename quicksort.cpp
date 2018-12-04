/*
Author:   Cashton Christensen
Date:     3/27/2018
Purpose:  To sort a file of character arrays ( strings ) using the quicksort sorting method
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

template<class TYPENAME>
int partition (TYPENAME Ar[], int start ,int end)
{
  int i = start + 1;
  TYPENAME piv = Ar[start] ;     //make the first element as pivot element.
  for(int j = start + 1; j <= end; j++)
  {
  /*rearrange the array by putting elements which are less than pivot
  on one side and which are greater that on other. */
    if (Ar[j] < piv)
    {
      swap(Ar[i], Ar[j]);
      i += 1;
    }
  }
  swap(Ar[start], Ar[i - 1]);  //put the pivot element in its proper place.
  return i - 1;              //return the position of the pivot
}

template<class TYPENAME>
int rand_partition (TYPENAME Ar[ ], int start, int end)
{
  //chooses position of pivot randomly by using rand() function .
  int random = start + rand( )%(end - start + 1);

  swap(Ar[random], Ar[start]);        //swap pivot with 1st element.
  return partition(Ar, start, end);  //call the above partition func.
}

template<class TYPENAME>
void quick_sort (TYPENAME Ar[ ], int start, int end)
{
  if(start < end)
  {
    //stores the position of pivot element
    int piv_pos = rand_partition (Ar, start, end);
    quick_sort(Ar, start, piv_pos - 1);    //sorts the left side of pivot.
    quick_sort(Ar, piv_pos + 1, end);      //sorts the right side of pivot.
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

  quick_sort(array, 0, size - 1);

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
