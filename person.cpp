#include "person.h"

Person::Person()
{

}

Person::~Person()
{
    delete children;
    delete spouse;
}
