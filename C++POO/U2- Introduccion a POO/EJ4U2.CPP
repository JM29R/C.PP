/*Implemente una clase VectorDinamico que posea como atributo un puntero a entero que apunte a la memoria donde
se almacenan los datos. Dicha clase debe poseer:
1. Un constructor que reciba el tamaño inicial del vector, reserve la memoria necesaria e inicialice los valores del
vector de manera aleatoria.
2. Un destructor que se encargue de liberar la memoria reservada.
3. Un método Duplicar(...) que duplique la cantidad de memoria reservada manteniendo los datos que ya
estaban en el vector e inicializando al azar los nuevos valores.
4. Un método VerTamanio() para cosultar el tamaño del vector, y un método VerElemento(...) que reciba el
número de elemento (índice) y devuelva su valor.
5. Cree un programa cliente que muestre la utilización de todas las funciones implementadas.
6. Explique: ¿Es necesario implementar un constructor de copia? ¿Por qué?*/
#include <iostream>
#include <cmath>
using namespace std;
class VectorDinamico
{
public:
    VectorDinamico(int t)
    {
        this->t = t;
        arreglo = new int[t];
        for (int i = 0; i < t; i++)
        {
            arreglo[i] = rand() % 100;
        }
    }
    void duplicar()
    {
        int *nuevoArreglo = new int[t * 2];
        for (int i = 0; i < t; i++)
        {
            nuevoArreglo[i] = arreglo[i];
        }
        for (int i = t; i < t * 2; i++)
        {
            nuevoArreglo[i] = rand() % 100;
        }
        delete[] arreglo;
        arreglo = nuevoArreglo;
        t *= 2;
    }
    int verTamanio()
    {
        return t;
    }
    int verElemento(int indice)
    {
        if (indice >= 0 && indice < t)
        {
            return arreglo[indice];
        }
        else
        {
            return -1;
        }
    }
    ~VectorDinamico()
    {
        delete[] arreglo;
    }

private:
    int *arreglo;
    int t;
};
int main(int argc, char const *argv[])
{
    int t;
    cout << "Ingrese el tamanio inicial del vector: ";
    cin >> t;
    VectorDinamico vec(t);
    cout << "Tamanio del vector: " << vec.verTamanio() << endl;
    for (int i = 0; i < vec.verTamanio(); i++)
    {
        cout << "Elemento " << i + 1 << ": " << vec.verElemento(i) << endl;
    }
    vec.duplicar();
    cout << "Tamanio del vector después de duplicar: " << vec.verTamanio() << endl;
    for (int i = 0; i < vec.verTamanio(); i++)
    {
        cout << "Elemento " << i + 1 << ": " << vec.verElemento(i) << endl;
    }

    return 0;
}
