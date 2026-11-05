#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const float PI = 3.1416;

class Figura {
protected:
    string color;

public:
    Figura(string col) : color(col) {
    }
};

class Circulo : public Figura {
private:
    float radio;

public:
    Circulo(string col, float r)
        : Figura(col), radio(r) {
    }

    float calcularArea() {
        return PI * radio * radio;
    }

    float calcularPerimetro() {
        return 2 * PI * radio;
    }

    void mostrarCirculo() {
        cout << "Color: " << color << endl;
        cout << "Radio: " << radio << " cm" << endl;
        cout << "Area: " << calcularArea() << " cm2" << endl;
        cout << "Perimetro: " << calcularPerimetro() << " cm" << endl;
    }
};

class Rectangulo : public Figura {
private:
    float base;
    float altura;

public:
    Rectangulo(string col, float b, float h)
        : Figura(col), base(b), altura(h) {
    }

    float calcularArea() {
        return base * altura;
    }

    float calcularPerimetro() {
        return 2 * (base + altura);
    }

    void mostrarRectangulo() {
        cout << "Color: " << color << endl;
        cout << "Base: " << base << " cm" << endl;
        cout << "Altura: " << altura << " cm" << endl;
        cout << "Area: " << calcularArea() << " cm2" << endl;
        cout << "Perimetro: " << calcularPerimetro() << " cm" << endl;
    }
};

class Triangulo : public Figura {
private:
    float base;
    float altura;
    string tipo;

public:
    Triangulo(string col, float b, float h, string t)
        : Figura(col), base(b), altura(h), tipo(t) {
    }

    float calcularArea() {
        return (base * altura) / 2;
    }

    void mostrarTriangulo() {
        cout << "Color: " << color << endl;
        cout << "Base: " << base << " cm" << endl;
        cout << "Altura: " << altura << " cm" << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Area: " << calcularArea() << " cm2" << endl;

        if (tipo == "Rectangulo" || tipo == "rectangulo") {
            float hipotenusa = sqrt(base * base + altura * altura);
            float perimetro = base + altura + hipotenusa;

            cout << "Perimetro: " << perimetro << " cm" << endl;
        } else {
            cout << "Perimetro: No se puede determinar "
                 << "solo con base y altura." << endl;
        }
    }
};

int main() {

    cout << "========== CIRCULO ==========" << endl;

    Circulo circulo1("Rojo", 5);
    circulo1.mostrarCirculo();

    cout << "\n========== RECTANGULO ==========" << endl;

    Rectangulo rectangulo1("Azul", 8, 4);
    rectangulo1.mostrarRectangulo();

    cout << "\n========== TRIANGULO ==========" << endl;

    Triangulo triangulo1("Verde", 6, 8, "Rectangulo");
    triangulo1.mostrarTriangulo();

    return 0;
}

