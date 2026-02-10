/*
1. Implemente una función clamp(...) que reciba como parámetros una variable (por referencia) y dos valores
indicando los lí mites superior e inferior para el valor de dicha variable. Si el valor de la variable supera su
máximo, este debe ajustarse al máximo valor permitido. De la misma forma si el valor es inferior al mínimo.
2. Pruebe la función templatizada desde un programa cliente. Explique el error que ocurre al invocar la función
con float f=0.5; clamp(f, 0, 1); ¿Cómo lo solucionaría?
*/
template <typename T>
void clamp(T& valor, T min, T max) {
    if (valor < min) {
        valor = min;
    } else if (valor > max) {
        valor = max;
    }
}



#include <iostream>
int main(int argc, char const *argv[])
{
    float f = 0.5;
    clamp(f, (float)0, (float)1);
    std::cout << "Valor clamped: " << f << std::endl;
    return 0;
}
