#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*Implemente una clase Fraccion para representar una fracción a partir de un numerador y un denominador, con un
método ConvertirADouble() para obtener el real que representa, y los demás métodos que considere necesarios.
Implemente una clase NumeroMixto para representar un número formado por una parte entera y una fracción impropia
(fracción menor a 1). Reutilice la clase Fraccion al implementar la clase NumeroMixto. La clase NumeroMixto debe
también poseer un método ConvertirADouble(). ¿Qué relación entre clases puede utilizar en este caso?*/
class Fraccion
{
public:
    Fraccion(int n, int d) : numerador(n), denominador(d) {}
    float ConvertirADouble()
    {
        return (float)numerador / denominador;
    }

private:
    int numerador;
    int denominador;
};
class NumeroMixto
{
public:
    NumeroMixto(int e, int n, int d) : entero(e), fraccion(n, d) {}
    float ConvertirADouble()
    {
        return entero + fraccion.ConvertirADouble();
    }

private:
    int entero;
    Fraccion fraccion;
};
int main(int argc, char const *argv[])
{

    return 0;
}
