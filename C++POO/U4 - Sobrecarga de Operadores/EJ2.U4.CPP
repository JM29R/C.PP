/*Para la clase Racional utilizada en el ejercicio anterior, implemente los operadores relacionales <, <=, >, >=, == y !=
para comparar dos números racionales. Haga uso de dichos operadores desde un programa cliente*/
#include <iostream>
#include "EJ1U4.CPP"
using namespace std;
bool operator<(const Racional &r1, const Racional &r2)
{
    if (r1.getNumerador() * r2.getDenominador() < r2.getNumerador() * r1.getDenominador())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator<=(const Racional &r1, const Racional &r2)
{
    if (r1.getNumerador() * r2.getDenominador() <= r2.getNumerador() * r1.getDenominador())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator>(const Racional &r1, const Racional &r2)
{
    if (r1.getNumerador() * r2.getDenominador() > r2.getNumerador() * r1.getDenominador())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>=(const Racional &r1, const Racional &r2)
{
    if (r1.getNumerador() * r2.getDenominador() >= r2.getNumerador() * r1.getDenominador())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator==(const Racional &r1, const Racional &r2)
{
    if (r1.getNumerador() * r2.getDenominador() == r2.getNumerador() * r1.getDenominador())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(const Racional &r1, const Racional &r2)
{
    if (r1.getNumerador() * r2.getDenominador() != r2.getNumerador() * r1.getDenominador())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
