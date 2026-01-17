#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Punto
{
    float x;
    float y;
};

class Recta
{
public:
    virtual string ObtenerEcuacion() const = 0;
    virtual bool Pertenece(Punto p) const = 0;
    virtual ~Recta() {}
};
class RectaExplicita : public Recta
{
    RectaExplicita(Punto p, Punto q)
    {
        m = (p.y - q.y) / (p.x - q.x);
        b = p.y - m * p.x;
    }
    float VerM() const { return m; }
    float VerB() const { return b; }
    string ObtenerEcuacion() const override
    {
        return "y = " + to_string(m) + "x + " + to_string(b);
    }
    bool Pertenece(Punto p) const override
    {
        return fabs(p.y - (m * p.x + b)) < 1e-6;
    }

private:
    float m;
    float b;
};
class RectaGeneral : public Recta
{
    RectaGeneral(Punto p, Punto q)
    {
        A = q.y - p.y;
        B = p.x - q.x;
        C = A * p.x + B * p.y;
    }
    float VerA() const { return A; }
    float VerB() const { return B; }
    float VerC() const { return C; }
    string ObtenerEcuacion() const override
    {
        return to_string(A) + "x + " + to_string(B) + "y = " + to_string(C);
    }
    bool Pertenece(Punto p) const override
    {
        return fabs(A * p.x + B * p.y - C) < 1e-6;
    }

private:
    float A;
    float B;
    float C;
};