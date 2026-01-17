/*Se tiene un arreglo dinámico de n enteros, y se quiere aumentar su tamaño a un nuevo tamaño c. Implemente una
función redimensionar() que reserve dinámicamente memoria para un nuevo arreglo que contenga lugar suficiente
para guardar c datos (los n datos anteriores y los c-n nuevos). Copie en la nueva memoria los datos del vector viejo
e inicialice con ceros los nuevos elementos. La memoria del primer arreglo debe ser liberada y el struct actualizado
para que el programa cliente pueda seguir operando con el nuevo arreglo. La función debería poder invocarse de la
siguiente manera:
arreglo a;
...incializar a con n elementos...
redimensionar(a, c);
El struct arreglo contendría el puntero a los datos y el entero con el tamaño, equivalente al struct vector_int_dinamico
presentado en el apunte de teoría (pág. 10).
Finalmente, implemente un programa cliente que muestre el arreglo resultante.*/

#include <iostream>
using namespace std;
void redimensionar(int *&arreglo, int N, int C)
{
    int *ArregloC = new int[C];
    for (int i = 0; i < N; i++)
    {
        ArregloC[i] = arreglo[i];
    }
    for (int i = N; i < C; i++)
    {
        ArregloC[i] = rand() % 1000;
        }
    delete[] arreglo;
    arreglo = ArregloC;
}
int main(int argc, char const *argv[])
{
    int N;
    cout << "Ingrese el tamanio del arreglo: ";
    cin >> N;
    int C;
    cout << "Ingrese el nuevo tamanio del arreglo: ";
    cin >> C;
    int *arreglo = new int[N];
    for (int i = 0; i < N; i++)
    {
        arreglo[i] = rand() % 100;
    }
    cout << "Arreglo original: ";
    for (int i = 0; i < N; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
    redimensionar(arreglo, N, C);
    cout << "Arreglo redimensionado: ";
    for (int i = 0; i < C; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
    delete[] arreglo;

    return 0;
}
