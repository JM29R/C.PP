/*Escriba un programa que cargue en un vector de strings una lista de palabras desde un archivo de texto (que
contendrá una palabra por línea), muestre en pantalla la cantidad de palabras leídas, las ordene en el vector
alfabéticamente, y reescriba el archivo original con la lista ordenada. Ayuda: para ordenar un vector v de principio a
fin puede utilizar la sentencia sort(v.begin(), v.end());*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> S = {"anana", "banana", "cebolla", "durazno", "elefante", "fresa", "guitarra", "helado", "iglesia", "jirafa"};
    sort(S.begin(), S.end());
    fstream F("U5EJ1.TXT", ios::trunc);
    F.open("U5EJ1.TXT");
    for (size_t i = 0; i < S.size(); i++)
    {
        F << S[i] << endl;
    }
    F.close();
    ifstream R("U5EJ1.TXT");
    string P;
    for (int i = 0; i < 10; i++)
    {
        R >> P;
        cout << P << endl;
    }
    R.close();
    return 0;
}
