#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*Una fábrica de tanques los hace de forma de cilindro y de esfera. En ambos envases debemos rotular el volumen
en 𝑚3
y el peso en 𝑘𝑔. Modele una clase base Tanque con un constructor que reciba el peso, un método para
consultarlo, y un método virtual para calcular su volumen. Modele la clase hija Cilindro que se construirá a partir
de los argumentos adicionales radio y altura, cuya fórmula de volumen es: área de la base * altura, donde el área de
la base se calcula como 𝜋 * radio2
; y otra clase hija Esfera con el radio como argumento adicional, cuya fórmula de
volumen es: 4
3
* 𝜋 * radio3
. En el programa principal debe usar un único puntero de tipo*/
class Tanque
{
public:
    Tanque(float p) : peso(p) {}
    float ConsultarPeso()
    {
        return peso;
    }
    virtual float CalcularVolumen() = 0;

private:
    float peso;
};
class Cilindro : Tanque
{
public:
    Cilindro(float p, float r, float h) : Tanque(p), radio(r), altura(h) {}
    float CalcularVolumen() override
    {
        return M_PI * pow(radio, 2) * altura;
    }

private:
    float radio;
    float altura;
};
class Esfera : Tanque
{
public:
    Esfera(float p, float r) : Tanque(p), radio(r) {}
    float CalcularVolumen() override
    {
        return (4.0 / 3.0) * M_PI * pow(radio, 3);
    }

private:
    float radio;
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
