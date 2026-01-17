#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*Implemente una clase Monomio para representar un monomio de la forma 𝑎𝑥𝑛 a partir de un coeficiente (a) y un
exponente (n), con un método Evaluar(...) que reciba un real y retorne el valor del monomio evaluado con ese
real, y los demás métodos que considere necesarios. Implemente, luego, una clase Polinomio que reutilice la clase
Monomio para modelar un polinomio, y añada un método Evaluar(...) para evaluar un polinomio en un valor x real
dado. ¿Qué relación debe haber entre las clases Monomio y Polinomio?*/
class monomio
{
public:
    monomio(int g, int c) : grado(g), coeficiente(c) {}
    float Evaluar(int x)
    {
        return coeficiente * pow(x, grado);
    }

private:
    int grado;
    int coeficiente;
};
class polinomio
{
    void AgregarMonomio(monomio m)
    {
        monomios.push_back(m);
    }
    float Evaluar(int x)
    {
        float resultado = 0;
        for (auto m : monomios)
        {
            resultado += m.Evaluar(x);
        }
        return resultado;
    }

private:
    vector<monomio> monomios;
};
int main(int argc, char const *argv[])
{

    return 0;
}
