/*Diseñe una clase Cilindro que modele un cilindro con el objetivo de calcular el volumen del cuerpo conociendo el
radio de su base y la altura del mismo.
1. La interfaz pública de la clase debe estar compuesta por los métodos AsignarDatos(...) y ObtenerVolumen(...)
para asignar los datos del problema y obtener el volumen del cuerpo.
2. Escriba un programa cliente que utilice dicha clase. Defina 2 instancias de Cilindro llamadas c1 y c2. El objeto
c1 debe utilizar datos ingresados por el usuario, mientras que para c2 utilice 5.3cm y 10.2cm para el radio y la
altura respectivamente.
3. Agregue un constructor a la clase Cilindro que reciba 2 parámetros para inicializar el radio y la altura. Luego
intente compilar nuevamente el programa. ¿Puede explicar por qué se produce un error? Proponga una
solución*/
#include <iostream>
using namespace std;
class Cilindro
{
public:
    void AsignarDatos(float r, float h)
    {
        radio = r;
        altura = h;
    }
    float ObtenerVolumen()
    {
        return 3.14 * radio * radio * altura;
    }

private:
    float radio;
    float altura;
};

int main(int argc, char const *argv[])
{
    Cilindro c1, c2;
    float r, h;
    cout << "Ingrese el radio y la altura del cilindro c1: ";
    cin >> r >> h;
    c1.AsignarDatos(r, h);
    c2.AsignarDatos(5.3, 10.2);
    cout << "El volumen del cilindro c1 es: " << c1.ObtenerVolumen() << endl;
    cout << "El volumen del cilindro c2 es: " << c2.ObtenerVolumen() << endl;
    return 0;
}
