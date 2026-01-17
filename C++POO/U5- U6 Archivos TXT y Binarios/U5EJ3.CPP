#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Configuracion
{
    string materia;
    string carrera;
    string facultad;
    string universidad;
    int nroUnidad;
    string nombre_unidad;
    string otro_campo;
    string campo_adicional;
};

class ConfigFile
{
public:
    ConfigFile(string f) { filename = f; }

private:
    string filename;
    vector<Configuracion> configuraciones;
};

int main(int argc, char const *argv[])
{
    return 0;
}
