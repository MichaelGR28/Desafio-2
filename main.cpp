#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

//Clases
class Estacion {
    private:
        string nombre;
        bool transferencia;
    public:
        Estacion(string _nombre, bool _transferencia);
        string getNombre();
        bool getTransferencia();
};

class Linea {
    private:
        char nombre;
        vector<Estacion> estaciones;
    public:
        Linea(char _nombre);
        char getNombre();
        void añadirEstacion(Estacion);
        void mostrarEstaciones();
};


//Estacion
//Constructor
Estacion::Estacion(string _nombre, bool _transferencia) {
    nombre = _nombre;
    transferencia = _transferencia;
}

//Metodos
string Estacion::getNombre(){
    return nombre;
}

bool Estacion::getTransferencia(){
    return transferencia;
}

//Linea
//Constructor
Linea::Linea(char _nombre){
    nombre = _nombre;
}

//Metodos
char Linea::getNombre(){
    return nombre;
}

void Linea::añadirEstacion(Estacion estacion){
    estaciones.push_back(estacion);
}

void Linea::mostrarEstaciones(){
    for (Estacion& i : estaciones) {
        cout << i.getNombre() << endl;
    }
}




int main() {

    Linea a('A');

    a.añadirEstacion(Estacion ("Bello", false));
    a.añadirEstacion(Estacion ("Madera", false));
    a.añadirEstacion(Estacion ("Niquia", false));
    a.añadirEstacion(Estacion ("Acevedo", false));

    a.mostrarEstaciones();
    return 0;
}