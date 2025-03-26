/** @file Estacion.cc
    @brief Código de la clase Estacion
*/

#include "Estacion.hh"
#include "Bici.hh"
#include <set>

using namespace std;

Estacion::Estacion() {

}

Estacion::Estacion(const int &maxbicis) {
    this->maxbicis = maxbicis;
    nbicis = 0;
}

int Estacion::consultar_nbicis() {
    return nbicis;
}

int Estacion::consultar_maxbicis() {
    return maxbicis;
}

void Estacion::alta_bici(const string& b_id, bool& added) {
    nbicis++;
    bicis.insert(b_id);
    added = true;
}

void Estacion::baja_bici(const string& b_id) {
    bicis.erase(b_id);
    nbicis--;
}

void Estacion::escribir_bicis() {
    set<string>::iterator it = bicis.begin();
    while(it != bicis.end()) {
        cout<<(*it)<<endl;
        ++it;
    }
}

void Estacion::modificar_maxbicis(const unsigned int &capacidad, unsigned int &antigua_capacidad) {
    antigua_capacidad = maxbicis;
    maxbicis = capacidad;
}

string Estacion::obtener_primera_bici() {
    auto iter = bicis.begin();
    return *iter;
}

bool Estacion::esta_llena() {
    return (maxbicis-nbicis == 0);
}