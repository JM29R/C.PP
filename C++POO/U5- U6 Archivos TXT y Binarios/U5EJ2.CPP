#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Alumno
{
    string nombre;
    string apellido;
    int nota1;
    int nota2;
};

int main(int argc, char const *argv[])
{
    vector<Alumno> listaAlumnos;
    ifstream file("lista.txt");
    if (!file.is_open())
    {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }
    while (!file.eof())
    {
        Alumno alumno;
        file >> alumno.nombre >> alumno.apellido >> alumno.nota1 >> alumno.nota2;
        if (file) // Verifica que la lectura fue exitosa
            listaAlumnos.push_back(alumno);
    }
    file.close();
    for (size_t i = 0; i < listaAlumnos.size(); i++)
    {
        const Alumno &a = listaAlumnos[i];
        cout << a.nombre << " " << a.apellido << " - notas: " << a.nota1 << ", " << a.nota2 << endl;
    }

    return 0;
}
