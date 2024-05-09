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
        vector<char> lineas;
    public:
        Estacion(string);
        string getNombre();
        bool getTransferencia();
        void agregarLinea(char);
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
        void modificarVectorEstaciones(Estacion, int);
        void modificarMatrizTiempos(Estacion, int, int, int);
        void mostrarTiempos();
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

void Estacion::agregarLinea(char linea) {
    lineas.push_back(linea);
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
    estacion.agregarLinea(nombre);
    int num;
    cout << "En esta linea hay " << estaciones.size() << " estaciones, indicar en que posicion se ingresara esta estacion: ";
    cin >> num;
    cout << estaciones.size() << endl;

    modificarVectorEstaciones(estacion, num);

    if (estaciones.size()-1 != 0){
        int tiempoIzquierda;
        int tiempoDerecha;
        if (num > estaciones.size()-1) {
            cout << "Cuanto tiempo hay entre la estacion " << estacion.getNombre() << " y la estacion " << estaciones[num-2].getNombre() << endl;
            cin >> tiempoIzquierda;
            tiempoDerecha = 0;
        }
        else if (num < 2){
            cout << "Cuanto tiempo hay entre la estacion " << estacion.getNombre() << " y la estacion " << estaciones[num].getNombre() << endl;
            cin >> tiempoDerecha;
            tiempoIzquierda = 0;
        }
        else{
            cout << "Cuanto tiempo hay entre la estacion " << estacion.getNombre() << " y la estacion " << estaciones[num-2].getNombre() << endl;
            cin >> tiempoIzquierda;
            cout << "Cuanto tiempo hay entre la estacion " << estacion.getNombre() << " y la estacion " << estaciones[num].getNombre() << endl;
            cin >> tiempoDerecha;
        }
        modificarMatrizTiempos(estacion, num, tiempoIzquierda, tiempoDerecha);
    }
    mostrarEstaciones();
}

void Linea::mostrarEstaciones(){
    for (Estacion& i : estaciones) {
        cout << i.getNombre() << endl;
    }
}

void Linea::modificarMatrizTiempos(Estacion estacion, int pos, int izq, int der){
    vector<vector<int>> aux;
    for (int i = 0; i <= (estaciones.size()); i++)
    {
        vector<int> fila;
        for (int j = 0; j < estaciones.size(); j++)
        {
            if ((i == pos-2 && j == pos-1) || (i == pos-1 && j == pos-2)){
                fila.push_back(izq);
            }
            else if ((i == pos-1 && j == pos) || (i == pos && j == pos-1)){
                fila.push_back(der);
            }
            else{
                fila.push_back(0);
            }
        }
        aux.push_back(fila);
    }
    tiemposEntreEstaciones = aux;
    mostrarTiempos();
    
}

void Linea::modificarVectorEstaciones(Estacion estacion, int posicion){
    estaciones.insert(estaciones.begin() + (posicion-1), estacion);

}

void Linea::mostrarTiempos(){
    for (vector<int> i : tiemposEntreEstaciones) {
        for (int j : i) {
            cout << j << "  ";
        }
        cout << endl;
    }
}

//Funciones




int main() {

    Linea a('A');
    string nombre;
    cout << "Ingresar nombre de la estacion: ";
    cin >> nombre;

    a.añadirEstacion(Estacion ("Bello"));
    a.añadirEstacion(Estacion (nombre));
    cout << "Ingresar nombre de la estacion: ";
    cin >> nombre;
    a.añadirEstacion(Estacion (nombre));
    return 0;
}