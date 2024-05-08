#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Clases
class Estacion {
    private:
        string nombre;
        bool transferencia = false;
        int numEstConet;
        vector<string> estacionesConectadas;
        vector<int> tiempoEstaciones;
    public:
        Estacion(string);
        string getNombre();
        bool getTransferencia();
        void obtenerDatos();
        vector<string> getEstacionesConectadas();
};

class Linea {
    private:
        char nombre;
        vector<Estacion> estaciones;
        vector<vector<int>> tiemposEntreEstaciones;
    public:
        Linea(char _nombre);
        char getNombre();
        void añadirEstacion(Estacion);
        void mostrarEstaciones();
        void modificarVectorEstaciones(Estacion);
        void modificarMatrizTiempos(Estacion);
};


//Estacion
//Constructor
Estacion::Estacion(string _nombre) {
    nombre = _nombre;
}

//Metodos
string Estacion::getNombre(){
    return nombre;
}

bool Estacion::getTransferencia(){
    return transferencia;
}

void Estacion::obtenerDatos() {
    int num;
    cout << "A cuantas estaciones va a estar conectada esta estación: ";
    cin >> num;
    numEstConet += num;
    cout << "Ingrese las estaciones a las que se encuentra conectada." << endl;
    for (int i = 0; i < num; i++) {
        string nombre;
        float tiempo;
        cout << "Ingrese el nombre de la estacion: ";
        cin >> nombre;
        cout << "Ingrese el tiempo estimado de viaje: ";
        cin >> tiempo;
        estacionesConectadas.push_back(nombre);
        tiempoEstaciones.push_back(tiempo);
    }
    
    cout << numEstConet << endl;
}

vector<string> Estacion::getEstacionesConectadas(){
    return estacionesConectadas;
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
    estacion.obtenerDatos();
    modificarMatrizTiempos( estacion );
    estaciones.push_back(estacion);
}

void Linea::mostrarEstaciones(){
    for (Estacion& i : estaciones) {
        cout << i.getNombre() << endl;
    }
}

void Linea::modificarMatrizTiempos(Estacion estacion){
    if (estaciones.size() != 0){

    }
}

void Linea::modificarVectorEstaciones(Estacion estacion){
    bool val = false;
    int pos;
    for (int i = 0; i < estaciones.size(); i++){
        if (estaciones[i].getNombre() == estacion.getEstacionesConectadas()[0]){
            val = true;
            pos = i;
        }
    }

    estaciones.insert(estaciones.begin() + pos, estacion.getNombre());

}

//Funciones




int main() {

    Linea a('A');
    string nombre;
    cout << "Ingresar nombre de la estacion: ";
    cin >> nombre;

    a.añadirEstacion(Estacion (nombre));
    a.añadirEstacion(Estacion (nombre));

    a.mostrarEstaciones();
    return 0;
}