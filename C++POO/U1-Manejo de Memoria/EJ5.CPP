/*Escriba un programa que genere un arreglo aleatoriamente, luego permita al usuario ingresar un valor M y una
posición P, y finalmente inserte el valor M en la posición P del arreglo. Muestre el arreglo modificado. Nota: Para la
inserción, implemente una función insertar(...).*/
#include <iostream>
using namespace std;
void insertar(int *&arreglo, float M, int P)
{
    arreglo[P] = M;
}
main(int argc, char const *argv[])
{
    float M;
    int P;
    int *Arreglo = new int[10];
    for (int i = 0; i < 10; i++)
    {
        Arreglo[i] = rand() % 100;
    }
    cout << "Arreglo original: ";
    for (int i = 0; i < 10; i++)
    {
        cout << Arreglo[i] << " ";
    }
    cout << endl;
    cout << "Ingrese el valor a insertar: ";
    cin >> M;
    cout << "Ingrese la posicion donde insertar el valor: ";
    cin >> P;
    int *arreglo = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arreglo[i] = rand() % 100;
    }
    insertar(arreglo, M, P);
    cout << "Arreglo modificado: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
    delete[] arreglo;
    return 0;
}