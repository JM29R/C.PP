// Utilizando notación de punteros, generar un arreglo dinámico y lineal de N elementos numéricos enteros, con valores
// aleatorios entre 1000 y 1500, y muestre en pantalla la dirección de memoria del mayor elemento. N es un dato
// ingresado por el usuario.
// EJ2
#include <iostream>
using namespace std;
int main()
{
    int N;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> N;
    int *v = new int[N];
    for (int i = 0; i < N; i++)
    {
        *(v + i) = rand() % 501 + 1000;
    }
    int *mayor = v;
    for (int i = 1; i < N; i++)
    {
        if (*(v + i) > *mayor)
        {
            mayor = v + i;
        }
    }
    cout << "El mayor elemento es: " << *mayor << " y su direccion de memoria es: " << mayor << endl;
    delete[] v;
    v = nullptr;
    mayor = nullptr;
    return 0;
}