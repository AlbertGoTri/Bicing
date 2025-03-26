/** @file Cjt_bicis.cc
    @brief Código de la clase Cjt_bicis
*/

#include "Cjt_bicis.hh"
#include "Bici.hh"
using namespace std;

Cjt_bicis::Cjt_bicis() {
    
}

bool Cjt_bicis::existe(const string& b_id) {
    map<string, Bici>::iterator it = bicis.find(b_id);
    if(it != bicis.end()) {
        return true;
    }else{
        return false;
    }
}

void Cjt_bicis::anadir_bici(const string& b_id, const string& e_id) {
    Bici b(e_id);
    bicis[b_id] = b;
}

void Cjt_bicis::baja_bici(const string& b_id) {
    bicis.erase(b_id);
}

string Cjt_bicis::consultar_estacion(const string& b_id) {
    return bicis[b_id].consultar_estacion();
}

void Cjt_bicis::viajes_bici(const string& b_id) {
    bicis[b_id].escribir_viajes();
}

void Cjt_bicis::anadir_viaje(const string& b_id, const string& e_origen, const string& e_destino) {
    bicis[b_id].anadir_viaje(e_origen, e_destino);
}

void Cjt_bicis::modificar_estacion(const string& b_id, const string& e_id) {
    bicis[b_id].modificar_estacion(e_id);
}