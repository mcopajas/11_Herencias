#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string numeroPlaca;
    string color;
    string marca;
    float velocimetro;

public:
    Vehiculo(string placa, string col, string mar, float vel)
        : numeroPlaca(placa), color(col),
          marca(mar), velocimetro(vel) {
    }

    void mostrarDatos() {
        cout << "Numero de placa: " << numeroPlaca << endl;
        cout << "Color: " << color << endl;
        cout << "Marca: " << marca << endl;
        cout << "Velocimetro: " << velocimetro << " km/h" << endl;
    }

    void cambiarVelocidad(float nuevaVelocidad) {
        velocimetro = nuevaVelocidad;
    }
};

class Automovil : public Vehiculo {
private:
    int cantidadPuertas;
    int cantidadPasajeros;

public:
    Automovil(string placa, string col, string mar, float vel,
              int puertas, int pasajeros)
        : Vehiculo(placa, col, mar, vel),
          cantidadPuertas(puertas),
          cantidadPasajeros(pasajeros) {
    }

    void mostrarAutomovil() {
        mostrarDatos();
        cout << "Cantidad de puertas: " << cantidadPuertas << endl;
        cout << "Cantidad de pasajeros: " << cantidadPasajeros << endl;
    }

    void subirPasajeros(int cantidad) {
        cantidadPasajeros += cantidad;
    }

    void bajarPasajeros(int cantidad) {
        if (cantidad <= cantidadPasajeros && cantidad >= 0) {
            cantidadPasajeros -= cantidad;
        } else {
            cout << "Cantidad de pasajeros no valida." << endl;
        }
    }
};

class Camion : public Vehiculo {
private:
    float carga;

public:
    Camion(string placa, string col, string mar, float vel,
           float car)
        : Vehiculo(placa, col, mar, vel), carga(car) {
    }

    void mostrarCamion() {
        mostrarDatos();
        cout << "Carga: " << carga << " toneladas" << endl;
    }

    void cambiarCarga(float nuevaCarga) {
        if (nuevaCarga >= 0) {
            carga = nuevaCarga;
        } else {
            cout << "La carga no puede ser negativa." << endl;
        }
    }
};

int main() {

    cout << "========== AUTOMOVIL ==========" << endl;

    Automovil auto1("ABC-123", "Rojo", "Toyota",
                    80, 4, 5);

    auto1.mostrarAutomovil();

    cout << "\n--- Modificando automovil ---" << endl;

    auto1.cambiarVelocidad(100);
    auto1.subirPasajeros(2);

    auto1.mostrarAutomovil();

    cout << "\n========== CAMION ==========" << endl;

    Camion camion1("XYZ-456", "Blanco", "Volvo",
                   60, 8.5);

    camion1.mostrarCamion();

    cout << "\n--- Modificando camion ---" << endl;

    camion1.cambiarVelocidad(75);
    camion1.cambiarCarga(12.5);

    camion1.mostrarCamion();

    return 0;
}
