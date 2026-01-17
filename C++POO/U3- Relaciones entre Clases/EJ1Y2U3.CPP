#include <iostream>
#include <vector>
using namespace std;
/*a) Diseñe una clase Persona que contenga los siguientes atributos: apellido y nombre, y fecha de nacimiento. La
clase debe poseer, además, un método CalcularEdad(...) que permita obtener la edad actual de la persona en
base a la fecha de nacimiento y la fecha actual.
b) Implemente una clase Alumno para contener la siguiente información de un alumno: apellido y nombre, año de
nacimiento, promedio y cantidad de materias aprobadas. La clase debe poseer, además dos métodos adicionales:
AgregarMateria(...) para actualizar el promedio y la cantidad de materias cada vez que el alumno rinde una nueva
materia; y CalcularMeritoAcademico(...) que retorne el mérito académico del alumno, el cual se calcula como el
producto entre el promedio y la cantidad de materias aprobadas.
c) Cree, también, una clase Docente para modelar un docente a partir de la siguiente información: apellido y nombre,
año de nacimiento y fecha de ingreso. La clase debe poseer, además, un método CalcularAntiguedad(...) que
calcule la antigüedad del docente en base a su fecha de ingreso y la fecha actual.
Notas: Para b) y c) proponga una jerarquía de clases adecuada para evitar repetir atributos. Implemente todos los
constructores y los métodos adicionales que considere adecuados.*/
struct Materias
{
    string nombre;
    float nota;
};

class Persona
{
public:
    Persona(string a, string b, int c) : nombre(a), apellido(b), FC(c) {}
    float CalcularEdad(int anioActual)
    {
        return anioActual - FC;
    }

private:
    string nombre;
    string apellido;
    int FC;
};
class Alumno : public Persona
{
public:
    Alumno(string a, string b, int c, int d) : Persona(a, b, c), legajo(d) {}
    void AgregarMateria(string materia, float nota)
    {
        Materias m;
        m.nombre = materia;
        m.nota = nota;
        M.push_back(m);
    }
    float CalcularPromedio()
    {
        float suma = 0;
        for (size_t i = 0; i < M.size(); i++)
        {
            suma += M[i].nota;
        }
        promedio = suma / M.size();
        return promedio;
    }
    float CalcularMeritoAcademico()
    {
        if (promedio >= 7.5)
        {
            return promedio * 1.1;
        }
        else
        {
            return promedio;
        }
    }

private:
    int legajo;
    vector<Materias> M;
    float promedio;
};
class Docente : public Persona
{
public:
    Docente(string a, string b, int c, float d) : Persona(a, b, c), FIngreso(d) {}
    float CalcularAntiguedad(int anioActual)
    {
        return anioActual - FIngreso;
    }

private:
    float FIngreso;
};
/*Utilice las clases Alumno y Docente del ejercicio anterior para crear una clase Curso que modele el cursado de
una materia. Cada curso tiene un nombre, un profesor a cargo y un número máximo de alumnos. Implemente un
método AgregarAlumno(...) que permita agregar un alumno al curso (si es que no se llegó al cupo), y otro método
MejorPromedio(...) que devuelva el alumno con mejor promedio. Proponga los constructores y métodos extra que
considere necesarios.
*/
class Curso
{
public:
    Curso(string a, Docente d, int c) : nombre(a), profesor(d), maxAlumnos(c) {}
    bool AgregarAlumno(Alumno a)
    {
        if (alumnos.size() < maxAlumnos)
        {
            alumnos.push_back(a);
            return true;
        }
        return false;
    }
    Alumno MejorPromedio()
    {
        float mejor = 0;
        int pos = -1;
        for (size_t i = 0; i < alumnos.size(); i++)
        {
            float prom = alumnos[i].CalcularPromedio();
            if (prom > mejor)
            {
                mejor = prom;
                pos = i;
            }
        }
        if (pos != -1)
            return alumnos[pos];
        // Retornar un alumno por defecto si no hay alumnos
        return Alumno("", "", 0, 0);
    }

private:
    string nombre;
    Docente profesor;
    int maxAlumnos;
    vector<Alumno> alumnos;
};
int main(int argc, char const *argv[])
{

    return 0;
}
