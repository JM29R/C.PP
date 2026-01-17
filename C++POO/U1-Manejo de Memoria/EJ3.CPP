/*Escriba una función que utilice punteros para buscar y retornar la dirección de un entero dentro de un arreglo. Se
pasan como parámetros el arreglo, su tamaño y el entero a buscar. Si el dato no se encuentra, debe retornar
la dirección de memoria nula (nullptr). ¿Desde un programa cliente, cómo se obtiene el índice del elemento
encontrado cuando la función no devuelve nullptr?*/
#include <iostream>
using namespace std;
int *Buscar_Direccion(int arr[], int n, int dato)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == dato)
        {
            return &arr[i];
        }
    }
    return nullptr;
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = size(arr);
    int dato;
    cout << "Ingrese el dato a buscar: ";
    cin >> dato;
    int *direccion = Buscar_Direccion(arr, n, dato);
    if (direccion != nullptr)
    {
        int indice = direccion - arr;
        cout << "El dato " << dato << " se encuentra en la direccion: " << direccion << " y su indice es: " << indice << endl;
    }
    else
    {
        cout << "El dato " << dato << " no se encuentra en el arreglo." << endl;
    }
    delete direccion;
    direccion = nullptr;
    return 0;
}