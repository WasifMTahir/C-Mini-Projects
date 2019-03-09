//Tested for n=1000 because it crashes for larger values of n
//Original code took 0.07255s
//This code took 0.01196

#include <iostream>
#include <string>
using namespace std;

//Function not needed anymore
/*
int compute(int *array, int i, int j)
{
  int k;
  int out = 1;
  for (k=i; k<=j; k++)
  {
    out *= array[k];
  }
  return out;
}*/

int main()
{
  int n = 1000;
  int m = n/2;
  int k = 0;
  int out = 1;
  int A[n];
  int B[n][m];
  for (int q=0; q<n; q++)
  {
      A[q] = q+1;
      for (int w = q; w<m; w++)
          B[q][w] = 1;
  }
  for (int i=0;i<n;i++)
  {
      for (int j=0;j<m;j++)
      {
      	if (j>i)
      		out *= j+1;
      	else
      		out = 1;	
        B[i][j] = out;
      }
  }
  return 0;
}
