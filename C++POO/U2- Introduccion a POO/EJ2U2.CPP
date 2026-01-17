/*Proponga una clase EcuacionCuadratica para modelar ecuaciones cuadráticas de la forma 𝑎𝑥2 + 𝑏𝑥 + 𝑐 = 0 .
La clase debe incluir:
1. Un constructor que reciba los valores de los coeficientes a, b y c.
2. Un método TieneRaicesReales(...) que retorne verdadero si las raíces de la ecuación son reales.
3. Dos métodos VerRaiz1(...) y VerRaiz2(...) que permitan obtener las raíces reales (en caso de que lo
sean).
4. Dos métodos VerParteReal(...) y VerParteImag(...) que permitan obtener las partes real e imaginaria de
las raíces complejas (en caso de que lo sean).
5. Cree un programa cliente que utilice un objeto de la clase EcuaciónCuadratica para determinar las raíces de
una ecuación cuadrática cuyos coeficientes sean ingresados por el usuario, y las muestre en el formato que
corresponda (según sean reales o complejas).
*/

#include <iostream>
#include <cmath>
using namespace std;
class EcuacionCuadratica
{
public:
    EcuacionCuadratica(float a, float b, float c)
    {
        a = a;
        b = b;
        c = c;
    }
    bool TieneRaicesReales() { return (b * b - 4 * a * c) >= 0; }
    float Raiz1() { return (-b + sqrt(b * b - 4 * a * c)) / (2 * a); }
    float Raiz2() { return (-b - sqrt(b * b - 4 * a * c)) / (2 * a); }
    float VerParteReal() { return -b / (2 * a); }
    float VerParteImaginaria() { return sqrt(-(b * b - 4 * a * c)) / (2 * a); }

private:
    float a, b, c;
};

int main(int argc, char const *argv[])
{
    float a, b, c;
    cout << "Ingrese los coeficientes a, b y c de la ecuacion cuadratica (ax^2 + bx + c = 0): ";
    cin >> a >> b >> c;
    EcuacionCuadratica ecuacion(a, b, c);
    if (ecuacion.TieneRaicesReales())
    {
        cout << "Las raices reales son: " << endl;
        cout << "Raiz 1: " << ecuacion.Raiz1() << endl;
        cout << "Raiz 2: " << ecuacion.Raiz2() << endl;
    }
    else
    {
        cout << "Las raices son complejas." << endl;
        cout << "Parte real: " << ecuacion.VerParteReal() << endl;
        cout << "Parte imaginaria: " << ecuacion.VerParteImaginaria() << endl;
    }

    return 0;
}
