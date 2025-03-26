/** @file Bici.cc
    @brief Código de la clase Bici
*/

#include "Bici.hh"

using namespace std;

Bici::Bici() {

}

Bici::Bici(const string& estacion) {
    this->estacion = estacion;
}

string Bici::consultar_estacion() {
    return estacion;
}

void Bici::escribir_viajes() {
    list<pair<string,string>>::iterator it = viajes.begin();
    while (it != viajes.end()){
        cout << (*it).first << ' ' << (*it).second << endl;
        ++it;
    }
}

void Bici::modificar_estacion(const string& e_id) {
    estacion = e_id;
}

void Bici::anadir_viaje(const string& e_origen, const string& e_destino) {
    viajes.insert(viajes.end(), make_pair(e_origen, e_destino));
    estacion = e_destino;
}