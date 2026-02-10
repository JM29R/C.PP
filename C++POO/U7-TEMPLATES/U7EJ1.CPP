/*
1. Implemente una función templatizada llamada mayor(...) que reciba dos valores y devuelva el mayor.
Compruebe el correcto funcionamiento de la rutina utilizándola desde un programa cliente con valores de tipo
int, float y string
2. Programe una sobrecarga de la función mayor(...) que reciba un std::vector y retorne la posición del mayor
elemento del mismo. Pruebe la función sobrecargada desde un programa cliente con diversos tipos de datos.
3. Responda: ¿Servirán las funciones anteriores con datos del tipo mostrado en el recuadro? Justifique su
respuesta. Si responde que no, implemente los cambios necesarios.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Persona {
string nombre;
string apellido;
int dni;
};
bool operator>(const Persona& p1, const Persona& p2) {
    return p1.dni > p2.dni;
}
template <typename T>
T mayor(T a, T b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
template <typename T>
int mayor(const vector<T>& v) {
    if (v.empty()) return -1;

    int pos = 0;
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] > v[pos]) {
            pos = i;
        }
    }
    return pos;
}



int main(int argc, char const *argv[])
{
    vector<int> vInt = {1, 2, 3, 4, 5};
    cout << "Mayor int: " << mayor(vInt) << endl;

    return 0;
}
