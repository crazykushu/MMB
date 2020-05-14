#include "useful.h"
#include <ctime>
#include <random>

using namespace std;

double sec()
{
  return clock() / double(CLOCKS_PER_SEC);
}

double rng()
{
  return rand() / RAND_MAX;
}