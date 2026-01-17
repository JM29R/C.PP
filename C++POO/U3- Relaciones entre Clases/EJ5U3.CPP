#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*Proponga un struct Punto con atributos para definir un punto en el plano (coordenadas 𝑥 e 𝑦). Luego, complete
la clase RectaExplicita para definir la ecuación explícita de la recta a*/
/*El método obtenerEcuacion() debe retornar una cadena de texto con la ecuación explícita de la recta, mientras que
el método pertenece(p) debe determinar si el punto p está o no sobre la recta (si satisface la ecuación).*/
struct Punto
{
    float x;
    float y;
};

class RectaExplicita
{
public:
    RectaExplicita(Punto p, Punto q)
    {
        m = (q.y - p.y) / (q.x - p.x);
        b = p.y - m * p.x;
    }
    float VerPendiente()
    {
        return m;
    }
    float VerOrdenada()
    {
        return b;
    }
    string obtenerEcuacion()
    {
        return "y = " + to_string(m) + "x + " + to_string(b);
    }
    bool pertenece(Punto p)
    {
        float y_estimada = m * p.x + b;
        return fabs(y_estimada - p.y) < 1e-6;
    }

private:
    float m;
    float b;
};

int main(int argc, char const *argv[])

{
    /* code */
    return 0;
}
