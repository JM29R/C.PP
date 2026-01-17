/*
Dada la clase Racional mostrada en el recuadro:
Implemente sobrecargas para los siguiente operadores:
• El operador + para sumar dos objetos de la clase Racional.
• El operador * para multiplicar un objeto de tipo Racional por un entero.
Finalmente, compruebe el funcionamiento de los operadores con el siguiente programa cliente:
*/

#include <iostream>
using namespace std;

class Racional
{
public:
    Racional(int num, int den) : numerador(num), denominador(den) {}
    int getNumerador() const { return numerador; }
    int getDenominador() const { return denominador; }
    Racional operator+(const Racional &other) const
    {
        int num = numerador * other.denominador + other.numerador * denominador;
        int den = denominador * other.denominador;
        return Racional(num, den);
    }
    Racional operator*(const Racional &other) const
    {
        int num = numerador * other.numerador;
        int den = denominador * other.denominador;
        return Racional(num, den);
    }

private:
    int numerador;
    int denominador;
};

int main(int argc, char const *argv[])
{
    Racional a(3, 5), b(2, 3);
    Racional c = a + b;
    cout << "Suma: " << c.getNumerador() << "/" << c.getDenominador() << endl;
    Racional d = a * b;
    cout << "Producto: " << d.getNumerador() << "/" << d.getDenominador() << endl;

    return 0;
}
