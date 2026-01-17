// Declare una variable entera común y otra variable entera utilizando memoria dinámica (almacenando su dirección
// de memoria en un puntero). Asigne a la primera variable el valor 10 y a la segunda variable un valor ingresado por
// el usuario. Muestre luego los valores y las direcciones de memoria de ambas variables. IMPORTANTE: No olvide
// liberar la memoria de la segunda variable antes de salir.// EJ1
#include <iostream>
using namespace std;

int main()
{
    int var1 = 10;
    int *var2 = new int;
    cout << "Ingrese un valor entero: ";
    cin >> *var2;
    cout << "Valor de var1: " << var1 << ", Direccion de var1: " << &var1 << endl;
    cout << "Valor de var2: " << *var2 << ", Direccion de var2: " << var2 << endl;
    delete var2;
    var2 = nullptr; // Evitar puntero colgante
    return 0;
}