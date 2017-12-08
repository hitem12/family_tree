#include "person.h"

Person::Person()
{
    parents[0] = 0;
    parents[1] = 0;
}

Person::~Person()
{
    delete[] children;
    delete[] spouse;
}
