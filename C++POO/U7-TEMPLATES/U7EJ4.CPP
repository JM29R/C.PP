/*
Desarrolle una clase templatizada llamada ManejadorArchivo que posea métodos y atributos para manipular un
archivo binario que contenga registros del tipo de dato especificado por el parámetro (mediante un vector en memoria,
no directamente sobre el archivo). La clase debe poseer métodos para:
1. Abrir un archivo binario y cargar los registros en memoria.
2. Obtener el registro en una posición especificada por el usuario.
3. Modificar el registro en una posición determinada.
4. Actualizar la información del archivo con los cambios.
*/
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class ManejadorArchivo {
public:
    ManejadorArchivo(const string& nombre) {
        this->nombre = nombre;
    }

    bool abrirArchivo(vector<T>& registros) {
        ifstream ar(nombre, ios::binary);
        if (!ar) {
            cerr << "No se pudo abrir el archivo." << endl;
            return false;
        }
        ar.seekg(0, ios::end);
        size_t bytes = ar.tellg();
        ar.seekg(0, ios::beg);
        size_t cantidad = bytes / sizeof(T);
        registros.resize(cantidad);
        ar.read(reinterpret_cast<char*>(registros.data()),
                cantidad * sizeof(T));

        ar.close();
        return true;
    }
    String obtenerRegistro(const vector<T>& registros, size_t posicion) {
        if (posicion >= registros.size()) {
            cerr << "Posición fuera de rango." << endl;
            return T();
        }
        return registros[posicion];
    }
    void modificarRegistro(vector<T>& registros, size_t posicion, const T& nuevoValor) {
        if (posicion >= registros.size()) {
            cerr << "Posición fuera de rango." << endl;
            return;
        }
        registros[posicion] = nuevoValor;
    }
    bool actualizarArchivo(const vector<T>& registros) {
        ofstream ar(nombre, ios::binary | ios::trunc);
        if (!ar) {
            cerr << "No se pudo abrir el archivo para escribir." << endl;
            return false;
        }
        ar.write(reinterpret_cast<const char*>(registros.data()),
                 registros.size() * sizeof(T));
        ar.close();
        return true;
    }

private:
    string nombre;

};
#include <iostream>
int main(int argc, char const *argv[])
{

    return 0;
}
