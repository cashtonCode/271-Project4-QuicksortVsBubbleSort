#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

template<class A>
void quicksort(A* array, int I, int j)
{
  int pivotIndex = findPivot(array, I, j);
  swap(array[pivotIndex], array[j]);
  int k = partition(array, I-1, j, key(array[j]));
  swap(array[k], array[j]);
  if((k-1)>1) quicksort(array, I, k-1);
  if((j-k)>1) quicksort(array, k+1, j);
}

template<class A>
int findPivot(A* array, int I, int j)
{
  return (I + j) / 2;
}

template<class A>
int partition(A* array, int l, int r, KEY pivot)//FIGURE OUT KEY pivot AND GET IT WORKING RIGHT
{
  do{
    while(key(array[++l] < pivot));
    while(r && (key(array[--r]) > pivot));
    swap(array[l], array[r]);
  }while(l<r)
  swap(array[l], array[r]);
  return 1;
}


int main()
{
  int count;
  cin >> count;
  char array[count];
  char line[31];
  ifstream inFile;
  ostream outfile;

  inFile.open("/home/win.thackerw/271/sort.dat");
  for(int i; i < count; i++)
  {
    infile >> line;
    array[i] = line;
  }
  inFile.close();

  quicksort(&array, count);//PROBABLY INCORRECT, FIX

  outfile.open("sorted.dat");
  for(int j; j < count; j++)
  {
    outfile >> array[j] >> endl;
  }
  outfile.close();

}

//BIG CHANGES
/*
  DON'T FORGET TO WRITE A LINUX TERMINAL PROGRAM THAT INSERTS COUNT FOR YOU && HOLDS THE FOLLOWING TEXT::


  for i in 2000 4000 10000 20000 50000 100000 1000000 10000000
    do
  time p4 $i > out$i
    done


*/
