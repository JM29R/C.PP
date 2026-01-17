#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*a) Defina una clase Tecla para representar una tecla de un piano. Cada tecla puede estar o no apretada, y tiene
además una nota asociada (cuyo nombre se representará con un string). Su interfaz debe tener tener entonces:
• un constructor que reciba el nombre de la nota
• un método VerNota que retorne el nombre de la nota
• un método Apretar que cambie el estado de la tecla a apretada.
• un método Soltar que cambie el estado de la tecla a no apretada.
• un método EstaApretada que retorne true si la tecla está apretada, false en caso contrario
b) Defina una clase Pedal para representar el pedal de un piano. El pedal debe almacenar un valor (float) que
indique la presión que el músico ejerce sobre el pedal. El constructor debe inicializar la presión en 0, y la clase debe
tener métodos para modificarla y consultarla.
c) Reutilizando las clases Tecla, Pedal e Instrumento:
defina una clase Piano que modele un instrumento de tipo ”piano” con solo 7 teclas (“do”, “re”, “mi”, “fa”, “sol”, “la” y
“si”) y 1 pedal. La clase piano debe tener métodos para:
• apretar una tecla, indicando el número de tecla, y que retorne la nota que debería sonar.
• soltar una tecla, indicando el número de tecla
• presionar el pedal, indicando la presión que se aplica
Nota: el método Sonido de Instrumento debe retornar el sonido que haría el instrumento en su estado actual. En el
piano, será la suma de las teclas que estén apretadas.*/
class Instrumento
{
public:
    Instrumento(string a) : Nombre(a) {}
    string VerNombre()
    {
        return Nombre;
    }
    virtual string Sonido() const = 0;
    virtual ~Instrumento() {}

private:
    string Nombre;
};

class Tecla
{
public:
    Tecla(string a) : Nombre(a) {}
    string VerNombre() const
    {
        return Nombre;
    }
    void Presionar()
    {
        Estado = true;
    }
    void Soltar()
    {
        Estado = false;
    }
    bool EstaPresionada() const
    {
        return Estado;
    }

private:
    string Nombre;
    bool Estado = false;
};
class Pedal
{
public:
    Pedal(float a) : Presion(a) {}
    float VerPresion() const
    {
        return Presion;
    }
    void AumentarPresion(float a)
    {
        if (Presion + a <= 100)
            Presion += a;
    }
    void DisminuirPresion(float a)
    {
        if (Presion - a >= 0)
            Presion -= a;
    }

private:
    float Presion = 0;
};

class Piano : public Instrumento
{
public:
    Piano(string a, const vector<Tecla> &t, Pedal p) : Instrumento(a), teclas(t), pedal(p) {}
    string Tocar(int indiceTecla)
    {
        if (indiceTecla < 0 || indiceTecla >= teclas.size())
        {
            return "Indice de tecla invalido";
        }
        teclas[indiceTecla].Presionar();
        return Sonido();
    }
    bool SoltarTecla(int indiceTecla)
    {
        if (indiceTecla < 0 || indiceTecla >= teclas.size())
            return false;
        else
        {
            teclas[indiceTecla].Soltar();
            return true;
        }
    }
    bool PresionarPedal(float presion)
    {
        if (presion < 0 || presion > 100)
            return false;
        else
        {
            pedal.AumentarPresion(presion);
            return true;
        }
    }
    string Sonido() const override
    {
        string sonido = "Piano sonando con presion de pedal: " + to_string(pedal.VerPresion()) + "%. Teclas presionadas: ";
        for (size_t i = 0; i < teclas.size(); i++)
        {
            if (teclas[i].EstaPresionada())
            {
                sonido += teclas[i].VerNombre() + " ";
            }
        }
        return sonido;
    }

private:
    vector<Tecla> teclas;
    Pedal pedal;
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
