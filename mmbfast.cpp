#include "mmbfast.h"
#include "useful.h"
#include <ctime>
#include <random>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

void evalindex(int M, int n)
{
  double c[n][n], a[n][n], b[n][n];
  double runtime [8];
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
          c[i][j] += a[i][k]*b[k][j];
        }
      }
    }
  }
  double stoptime1 = sec();
  runtime[0] = (stoptime1 - starttime1) / M;
  cout << "Current runtime for the ij=ik+kj run is: " << runtime[0] <<  " s" << endl;

  double starttime2 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        for (int i = 0; i < n; i++)
        {
          c[i][j] += a[i][k]*b[j][k];
        }
      }
    }
  }
  double stoptime2 = sec();
  runtime[1] = (stoptime2 - starttime2) / M;
  cout << "Current runtime for the ij=ik+jk run is: " << runtime[1] <<  " s" << endl;

  double starttime3 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        for (int i = 0; i < n; i++)
        {
          c[i][j] += a[k][i]*b[k][j];
        }
      }
    }
  }
  double stoptime3 = sec();
  runtime[2] = (stoptime3 - starttime3) / M;
  cout << "Current runtime for the ij=ki+kj run is: " << runtime[2] <<  " s" << endl;

  double starttime4 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        for (int i = 0; i < n; i++)
        {
          c[i][j] += a[k][i]*b[j][k];
        }
      }
    }
  }
  double stoptime4 = sec();
  runtime[3] = (stoptime4 - starttime4) / M;
  cout << "Current runtime for the ij=ki+jk run is: " << runtime[3] <<  " s" << endl;

  double starttime5 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        for (int i = 0; i < n; i++)
        {
          c[j][i] += a[i][k]*b[k][j];
        }
      }
    }
  }
  double stoptime5 = sec();
  runtime[4] = (stoptime5 - starttime5) / M;
  cout << "Current runtime for the ji=ik+kj run is: " << runtime[4] <<  " s" << endl;

  double starttime6 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        for (int i = 0; i < n; i++)
        {
          c[j][i] += a[i][k]*b[j][k];
        }
      }
    }
  }
  double stoptime6 = sec();
  runtime[5] = (stoptime6 - starttime6) / M;
  cout << "Current runtime for the ji=ik+jk run is: " << runtime[5] <<  " s" << endl;

  double starttime7 = sec();
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
  double stoptime7 = sec();
  runtime[6] = (stoptime7 - starttime7) / M;
  cout << "Current runtime for the ji=ki+kj run is: " << runtime[6] <<  " s" << endl;

  double starttime8 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        for (int i = 0; i < n; i++)
        {
          c[j][i] += a[k][i]*b[j][k];
        }
      }
    }
  }
  double stoptime8 = sec();
  runtime[7] = (stoptime8 - starttime8) / M;
  cout << "Current runtime for the ji=ki+jk run is: " << runtime[7] <<  " s" << endl;

  double ratio = *max_element(runtime, runtime + 8) / *min_element(runtime, runtime + 8);
  cout << "The ratio between worst and best case is: " << ratio << endl;
}