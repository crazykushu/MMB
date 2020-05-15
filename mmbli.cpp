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
  double runtime [3];
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
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        for (int i = 0; i < n; i++)
        {
          c[j][i] += a[k][i]*b[k][j];
        }
      }
    }
  }
  double stoptime1 = sec();
  runtime[0] = (stoptime1 - starttime1) / M;
  cout << "Current runtime for the ji=ki+kj run without accumulator is: " << runtime[0] <<  " s" << endl;

  double acc = 0.0;
  double starttime2 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        for (int i = 0; i < n; i++)
        {
          acc = a[j][i]*b[i][k];
        }
        c[j][k] = acc;
      }
    }
  }
  double stoptime2 = sec();
  runtime[1] = (stoptime2 - starttime2) / M;
  cout << "Current runtime for the ji=ki+kj run with accumulator is: " << runtime[1] <<  " s" << endl;  

  double* d = new double[n*n];
  double* e = new double[n*n];
  double* f = new double[n*n];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      f[i * n + j] = 0.0;
      d[i * n + j] = a[i][j];
      e[i * n + j] = b[i][j];
    }
  }
  double starttime3 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        for (int i = 0; i < n; i++)
        {
          *(f+j*n+k) += *(d+j*n+i) * *(e+i*n+k);
        }
      }
    }
  }
  double stoptime3 = sec();
  runtime[2] = (stoptime3 - starttime3) / M;
  cout << "Current runtime with pointer is: " << runtime[2] <<  " s" << endl;


  double ratio = *max_element(runtime, runtime + 3) / *min_element(runtime, runtime + 3);
  cout << "The ratio between worst and best case is: " << ratio << endl;
}