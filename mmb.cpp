#include "mmb.h"
#include "useful.h"
#include <ctime>
#include <random>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;


void evalloop(int M, int n)
{
  double c[n][n], a[n][n], b[n][n];
  double runtime [6];
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
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        for (int k = 0; k < n; k++)
        {
          c[i][j] += a[i][k]*b[k][j];
          c[i][j] += a[i][k]*b[j][k];
          c[i][j] += a[k][i]*b[k][j];
          c[i][j] += a[k][i]*b[j][k];
          c[j][i] += a[i][k]*b[k][j];
          c[j][i] += a[i][k]*b[j][k];
          c[j][i] += a[k][i]*b[k][j];
          c[j][i] += a[k][i]*b[j][k];
        }
      }
    }
  }
  double stoptime1 = sec();
  runtime[0] = (stoptime1 - starttime1) / M;
  cout << "Current runtime for the ijk run is: " << runtime[0] <<  " s" << endl;

  double starttime2 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int k = 0; k < n; k++)
      {
        for (int j = 0; j < n; j++)
        {
          c[i][j] += a[i][k]*b[k][j];
          c[i][j] += a[i][k]*b[j][k];
          c[i][j] += a[k][i]*b[k][j];
          c[i][j] += a[k][i]*b[j][k];
          c[j][i] += a[i][k]*b[k][j];
          c[j][i] += a[i][k]*b[j][k];
          c[j][i] += a[k][i]*b[k][j];
          c[j][i] += a[k][i]*b[j][k];
        }
      }
    }
  }
  double stoptime2 = sec();
  runtime[1] = (stoptime2 - starttime2) / M;
  cout << "Current runtime for the ikj run is: " << runtime[1] <<  " s" << endl;

double starttime3 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int k = 0; k < n; k++)
        {
          c[i][j] += a[i][k]*b[k][j];
          c[i][j] += a[i][k]*b[j][k];
          c[i][j] += a[k][i]*b[k][j];
          c[i][j] += a[k][i]*b[j][k];
          c[j][i] += a[i][k]*b[k][j];
          c[j][i] += a[i][k]*b[j][k];
          c[j][i] += a[k][i]*b[k][j];
          c[j][i] += a[k][i]*b[j][k];
        }
      }
    }
  }
  double stoptime3 = sec();
  runtime[2] = (stoptime3 - starttime3) / M;
  cout << "Current runtime for the jik run is: " << runtime[2] <<  " s" << endl;

double starttime4 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        for (int i = 0; i < n; i++)
        {
          c[i][j] += a[i][k]*b[k][j];
          c[i][j] += a[i][k]*b[j][k];
          c[i][j] += a[k][i]*b[k][j];
          c[i][j] += a[k][i]*b[j][k];
          c[j][i] += a[i][k]*b[k][j];
          c[j][i] += a[i][k]*b[j][k];
          c[j][i] += a[k][i]*b[k][j];
          c[j][i] += a[k][i]*b[j][k];
        }
      }
    }
  }
  double stoptime4 = sec();
  runtime[3] = (stoptime4 - starttime4) / M;
  cout << "Current runtime for the jki run is: " << runtime[3] <<  " s" << endl;

  double starttime5 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          c[i][j] += a[i][k]*b[k][j];
          c[i][j] += a[i][k]*b[j][k];
          c[i][j] += a[k][i]*b[k][j];
          c[i][j] += a[k][i]*b[j][k];
          c[j][i] += a[i][k]*b[k][j];
          c[j][i] += a[i][k]*b[j][k];
          c[j][i] += a[k][i]*b[k][j];
          c[j][i] += a[k][i]*b[j][k];
        }
      }
    }
  }
  double stoptime5 = sec();
  runtime[4] = (stoptime5 - starttime5) / M;
  cout << "Current runtime for the kij run is: " << runtime[4] <<  " s" << endl;

  double starttime6 = sec();
  for (int m = 0; m < M; m++)
  {
    for (int k = 0; k < n; k++)
    {
      for (int j = 0; j < n; j++)
      {
        for (int i = 0; i < n; i++)
        {
          c[i][j] += a[i][k]*b[k][j];
          c[i][j] += a[i][k]*b[j][k];
          c[i][j] += a[k][i]*b[k][j];
          c[i][j] += a[k][i]*b[j][k];
          c[j][i] += a[i][k]*b[k][j];
          c[j][i] += a[i][k]*b[j][k];
          c[j][i] += a[k][i]*b[k][j];
          c[j][i] += a[k][i]*b[j][k];
        }
      }
    }
  }
  double stoptime6 = sec();
  runtime[5] = (stoptime6 - starttime6) / M;
  cout << "Current runtime for the kji run is: " << runtime[5] <<  " s" << endl;
  cout << "The minimum runtime is: " << *min_element(runtime, runtime + 6) << endl;
}