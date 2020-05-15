#include <iostream>
#include "mmb.h"
#include "mmbfast.h"
#include "mmbli.h"


using namespace std;

#define n 550
#define M 10

int main()
{
  evalloop(M, n);
  evalindex(M, n);
  evalli(M, n);
}