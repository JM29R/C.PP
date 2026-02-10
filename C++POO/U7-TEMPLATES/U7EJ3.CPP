/*
Programe una clase templatizada llamada VectorDinamico (similar a la de la guía 2). La clase debe poseer:
1. Un constructor que reciba el tamaño inicial del vector, y reserve la memoria necesaria.
2. Un destructor que se encargue de liberar la memoria reservada.
3. Una sobrecarga del operador [] que reciba el número de elemento, devuelva su valor, y permita modificarlo.
4. Modifique o sobrecargue el constructor para que permita generar valores aleatorios con los cuales inicializar
las posiciones del arreglo que reserva.
5. Utilice la clase desde un programa cliente creando vectores aleatorios con diversos tipos de datos (int, double,
string, etc).

*/
template <typename T>
T VectorDinamico<T>::generarAleatorio() {
    return (T)(rand() % 100);
}

template<>
string VectorDinamico<string>::generarAleatorio() {
    int longitud = rand() % 5 + 3;
    string s = "";
    for (int i = 0; i < longitud; i++) {
        s += 'A' + rand() % 26;
    }
    return s;
}


template <typename T>
class VectorDinamico {
public:
    VectorDinamico(int size){
        this->size = size;
        data = new T[size];
    }

    VectorDinamico(int n, bool aleatorio) {
        tamanio = n;
        datos = new T[tamanio];

        if (aleatorio) {
            for (int i = 0; i < tamanio; i++) {
                datos[i] = generarAleatorio();
            }
        }
    }

    ~VectorDinamico() {
        delete[] data;
    }

    T& operator[](int index) {
        return data[index];
    }

private:
int size;
T* data;
T generarAleatorio();
}
#include <iostream>
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
