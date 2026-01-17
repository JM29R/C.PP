/*Diseñe una clase Polinomio que contenga:
1. un constructor que reciba el grado el polinomio e inicialice sus coeficientes en 0.
2. un método que permita cambiar un coeficiente.
3. un método evaluar que permita evaluar el polinomio para un valor dado de la variable x.
4. el/los métodos que considere necesarios para poder mostrar un polinomio desde un programa cliente.
5. una función que permita sumar dos polinomios retornando un tercer polinomio con el resultado (ej. p_res =
Sumar(p1, p2);). ¿Cómo variaría si en lugar de ser una función libre fuera un método de la clase?
Verifique el funcionamiento de la función Sumar(...) mediante un programa cliente.*/

#include <iostream>
#include <cmath>
using namespace std;
class Polinomio
{
public:
    Polinomio(int grado)
    {
        grado = grado;
        coeficientes = new float[grado + 1];
        for (int i = 0; i <= grado; i++)
        {
            coeficientes[i] = 0;
        }
    }
    void cambiarCoeficiente(int grado, float valor)
    {
        if (grado >= 0 && grado <= this->grado)
        {
            coeficientes[grado] = valor;
        }
    }
    float evaluar(float x)
    {
        float resultado = 0;
        for (int i = 0; i <= grado; i++)
        {
            resultado += coeficientes[i] * pow(x, i);
        }
        return resultado;
    }
    void mostrar()
    {
        for (int i = grado; i >= 0; i--)
        {
            cout << coeficientes[i] << "x^" << i;
            if (i != 0)
            {
                cout << " + ";
            }
        }
        cout << endl;
    }
    Polinomio sumar(const Polinomio &otro)
    {
        int gradoMax = max(grado, otro.grado);
        Polinomio resultado(gradoMax);
        for (int i = 0; i <= gradoMax; i++)
        {
            float coef1 = (i <= grado) ? coeficientes[i] : 0;
            float coef2 = (i <= otro.grado) ? otro.coeficientes[i] : 0;
            resultado.cambiarCoeficiente(i, coef1 + coef2);
        }
        return resultado;
    }
    ~Polinomio()
    {
        delete[] coeficientes;
    }

private:
    float grado;
    float *coeficientes;
};
int main(int argc, char const *argv[])
{
    Polinomio p1(2);
    p1.cambiarCoeficiente(2, 1);
    p1.cambiarCoeficiente(1, -3);
    p1.cambiarCoeficiente(0, 2);
    cout << "Polinomio p1: ";
    p1.mostrar();
    Polinomio p2(2);
    p2.cambiarCoeficiente(2, 2);
    p2.cambiarCoeficiente(1, 0);
    p2.cambiarCoeficiente(0, -5);
    cout << "Polinomio p2: ";
    p2.mostrar();
    Polinomio p3 = p1.sumar(p2);
    cout << "Polinomio p3 (suma de p1 y p2): ";
    p3.mostrar();
    cout << "Evaluacion de p1 en x=2: " << p1.evaluar(2) << endl;
    cout << "Evaluacion de p2 en x=2: " << p2.evaluar(2) << endl;
    cout << "Evaluacion de p3 en x=2: " << p3.evaluar(2) << endl;
    return 0;
}