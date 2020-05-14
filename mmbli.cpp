#include "mmbli.h"
#include "useful.h"
#include <ctime>
#include <random>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

void evalli(int M, int n)
{
  double c[n][n], a[n][n], b[n][n];
  double runtime [2];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      c[i][j] = 0.0;
      a[i][j] = rng();
      b[i][j] = rng();
    }
  }

  double starttime1 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int k = 0; k < n; k++)
    {
      for (int j = 0; j < n; j++)
      {
        for (int i = 0; i < n; i++)
        {
          c[j][i] += a[k][i]*b[j][k];
        }
      }
    }
  }
  double stoptime1 = sec();
  runtime[0] = (stoptime1 - starttime1) / M;
  cout << "Current runtime for the ji=ki+jk run without accumulator is: " << runtime[0] <<  " s" << endl;

  double acc = 0.0;
  double starttime2 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int k = 0; k < n; k++)
    {
      for (int j = 0; j < n; j++)
      {
        for (int i = 0; i < n; i++)
        {
          acc = a[k][i]*b[j][k];
        }
        c[k][j] = acc;
      }
    }
  }
  double stoptime2 = sec();
  runtime[1] = (stoptime2 - starttime2) / M;
  cout << "Current runtime for the ji=ki+jk run with accumulator is: " << runtime[1] <<  " s" << endl;  

  double ratio = *max_element(runtime, runtime + 8) / *min_element(runtime, runtime + 2);
  cout << "The ratio between worst and best case is: " << ratio << endl;
}