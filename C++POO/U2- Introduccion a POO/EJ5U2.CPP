
#include <iostream>
#include <cmath>
using namespace std;
struct Alumno
{
    string nombre;
    float nota;
};
class Curso
{
public:
    Curso(string nombre, int capacidad) : nombre(nombre), capacidad(capacidad)
    {
        alumnos = new Alumno[capacidad];
        numAlumnos = 0;
    }
    bool AgregarAlumno(string nombre)
    {
        if (numAlumnos < capacidad)
        {
            alumnos[numAlumnos].nombre = nombre;
            alumnos[numAlumnos].nota = 0;
            numAlumnos++;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool AsignarNota(string nombre, float nota)
    {
        for (int i = 0; i < numAlumnos; i++)
        {
            if (alumnos[i].nombre == nombre)
            {
                alumnos[i].nota = nota;
                return true;
            }
        }
        return false;
    }
    void MostrarAlumnos()
    {
        for (int i = 0; i < numAlumnos; i++)
        {
            cout << "Nombre: " << alumnos[i].nombre << ", Nota: " << alumnos[i].nota << endl;
        }
    }
    float PromedioCurso()
    {
        if (numAlumnos == 0)
        {
            return 0;
        }
        else
        {
            float suma = 0;
            for (int i = 0; i < numAlumnos; i++)
            {
                suma += alumnos[i].nota;
            }
            return suma / numAlumnos;
        }
    }
    void MejorAlumno()
    {
        if (numAlumnos == 0)
        {
            cout << "No hay alumnos en el curso." << endl;
        }
        else
        {
            float mejorNota = alumnos[0].nota;
            string mejorAlumno = alumnos[0].nombre;
            for (int i = 1; i < numAlumnos; i++)
            {
                if (alumnos[i].nota > mejorNota)
                {
                    mejorNota = alumnos[i].nota;
                    mejorAlumno = alumnos[i].nombre;
                }
            }
            cout << "Mejor alumno: " << mejorAlumno << " con nota: " << mejorNota << endl;
        }
    }
    ~Curso()
    {
        delete[] alumnos;
    }

private:
    string nombre;
    int capacidad;
    Alumno *alumnos;
    int numAlumnos;
};
int main(int argc, char const *argv[])
{
    string nombreCurso;
    int capacidad;
    cout << "Ingrese el nombre del curso: ";
    getline(cin, nombreCurso);
    cout << "Ingrese la capacidad del curso: ";
    cin >> capacidad;
    Curso curso(nombreCurso, capacidad);
    int opcion;
    cout << "Menu:\n1. Agregar Alumno\n2. Asignar Nota\n3. Mostrar Alumnos\n4. Promedio del Curso\n5. Mejor Alumno\n6. Salir" << endl;
    cin >> opcion;
    while (opcion != 6)
    {
        if (opcion == 1)
        {
            string nombreAlumno;
            cout << "Ingrese el nombre del alumno: ";
            cin >> ws; // Limpiar el buffer
            getline(cin, nombreAlumno);
            if (curso.AgregarAlumno(nombreAlumno))
            {
                cout << "Alumno agregado exitosamente." << endl;
            }
            else
            {
                cout << "No se pudo agregar el alumno. Capacidad llena." << endl;
            }
        }
        else if (opcion == 2)
        {
            string nombreAlumno;
            float nota;
            cout << "Ingrese el nombre del alumno: ";
            cin >> ws; // Limpiar el buffer
            getline(cin, nombreAlumno);
            cout << "Ingrese la nota del alumno: ";
            cin >> nota;
            if (curso.AsignarNota(nombreAlumno, nota))
            {
                cout << "Nota asignada exitosamente." << endl;
            }
            else
            {
                cout << "No se pudo asignar la nota. Alumno no encontrado." << endl;
            }
        }
        else if (opcion == 3)
        {
            curso.MostrarAlumnos();
        }
        else if (opcion == 4)
        {
            cout << "Promedio del curso: " << curso.PromedioCurso() << endl;
        }
        else if (opcion == 5)
        {
            curso.MejorAlumno();
        }
        else
        {
            cout << "Opcion no valida." << endl;
        }
        cout << "Menu:\n1. Agregar Alumno\n2. Asignar Nota\n3. Mostrar Alumnos\n4. Promedio del Curso\n5. Mejor Alumno\n6. Salir" << endl;
        cin >> opcion;
    }

    return 0;
}
