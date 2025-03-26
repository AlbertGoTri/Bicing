/** @file Cjt_Estaciones.cc
    @brief Código de la clase Cjt_estaciones
*/

#include "BinTree.hh"
#include "Estacion.hh"
#include "Bici.hh"
#include "Cjt_bicis.hh"
#include "Cjt_estaciones.hh"

using namespace std;

Cjt_estaciones::Cjt_estaciones() {

}

void Cjt_estaciones::setTree(BinTree<string> &arbol_estaciones) {
    string id;
    cin>>id;
    if(id != "#") {
        int c;
        cin>>c;
        plazas_totales += c;
        Estacion est (c);
        mapa_estaciones[id] = est;

        BinTree<string> ai;
        setTree(ai);
        BinTree<string> ad;
        setTree(ad);

        arbol_estaciones = BinTree<string> (id, ai, ad);
    }
}

void Cjt_estaciones::inicializar() {
    plazas_totales = 0;
    plazas_usadas = 0;
    setTree(arbol_estaciones);
}

void Cjt_estaciones::alta_bici(const string& b_id, const string& e_id) {
    map<string, Estacion>::iterator iterador = mapa_estaciones.find(e_id);
    if(iterador != mapa_estaciones.end()) {
        bool added = false;
        iterador->second.alta_bici(b_id, added);
        if(added) {
            plazas_usadas++;
        }
    }
}

void Cjt_estaciones::baja_bici(const string& b_id, const string& e_id) {
    mapa_estaciones[e_id].baja_bici(b_id);
    plazas_usadas--;
}

//Coste: O(log n)
void Cjt_estaciones::mover_bici(const string& b_id, const string& e_id, const string& e_destino_id) {
    bool added=false;
    mapa_estaciones[e_destino_id].alta_bici(b_id, added);
    if(added) {
        mapa_estaciones[e_id].baja_bici(b_id);
    }
}

bool Cjt_estaciones::poca_capacidad(const string& e_id, const int &capacidad) {
    return (capacidad < mapa_estaciones[e_id].consultar_nbicis());
}

void Cjt_estaciones::modificar_capacidad(const string& e_id, const int &capacidad) {
    unsigned int antigua_capacidad;
    mapa_estaciones[e_id].modificar_maxbicis(capacidad, antigua_capacidad);
    plazas_totales += (capacidad - antigua_capacidad);
}

unsigned int Cjt_estaciones::plazas_libres() {
    return plazas_totales - plazas_usadas;
}

void Cjt_estaciones::bicis_estacion(const string& e_id) {
    mapa_estaciones[e_id].escribir_bicis();
}

void Cjt_estaciones::subir_bicis_rec(const BinTree<string> &t, Cjt_bicis &bicis) {
    if(!t.empty()) {
        BinTree<string> left = t.left();
        BinTree<string> right = t.right();
        if(mapa_estaciones[t.value()].consultar_maxbicis() - mapa_estaciones[t.value()].consultar_nbicis() > 0) { //Si caben mas bicis en la estacion actual    
            int nbicis_left = 0, nbicis_right = 0;
            if(!left.empty()) nbicis_left = mapa_estaciones[left.value()].consultar_nbicis();
            if(!right.empty()) nbicis_right = mapa_estaciones[right.value()].consultar_nbicis();
            string b_id;
            bool added; //Variables per poder reaprofitar la funció
            if(nbicis_left > 0 || nbicis_right > 0) { //Si ambos hijos tienen bicis
                while(mapa_estaciones[t.value()].consultar_maxbicis() - mapa_estaciones[t.value()].consultar_nbicis() > 0 && (nbicis_left > 0 || nbicis_right > 0)) { //Mentre hi càpiguin bicis i hi hagi bicis en algun dels fills
                    if(nbicis_left > nbicis_right) {
                        b_id = mapa_estaciones[left.value()].obtener_primera_bici();
                        mapa_estaciones[t.value()].alta_bici(b_id, added);
                        mapa_estaciones[left.value()].baja_bici(b_id);
                        bicis.modificar_estacion(b_id, t.value());
                        nbicis_left--;
                    }else if(nbicis_left == nbicis_right) {
                        string b_id1 = mapa_estaciones[left.value()].obtener_primera_bici();
                        string b_id2 = mapa_estaciones[right.value()].obtener_primera_bici();
                        if(b_id1 > b_id2) {
                            mapa_estaciones[t.value()].alta_bici(b_id2, added);
                            mapa_estaciones[right.value()].baja_bici(b_id2);
                            bicis.modificar_estacion(b_id2, t.value());
                            nbicis_right--;
                        }else {
                            mapa_estaciones[t.value()].alta_bici(b_id1, added);
                            mapa_estaciones[left.value()].baja_bici(b_id1);
                            bicis.modificar_estacion(b_id1, t.value());
                            nbicis_left--;
                        }
                    }else if(nbicis_left < nbicis_right) {
                        b_id = mapa_estaciones[right.value()].obtener_primera_bici();
                        mapa_estaciones[t.value()].alta_bici(b_id, added);
                        mapa_estaciones[right.value()].baja_bici(b_id);
                        bicis.modificar_estacion(b_id, t.value());
                        nbicis_right--;
                    }
                }
            }
        } 
        subir_bicis_rec(left, bicis);
        subir_bicis_rec(right, bicis);
    }
}

void Cjt_estaciones::subir_bicis(Cjt_bicis &bicis) {
    subir_bicis_rec(arbol_estaciones, bicis);
}

void Cjt_estaciones::asignar_estacion_rec(const BinTree<string> &t, unsigned int& estaciones, unsigned int &plazas_libres, double &coef_max, string &e_id) {
    if(t.empty()) {
        estaciones = 0;
        plazas_libres = 0;
    } else {
        unsigned int e_derecha, e_izquierda, plazas_libres_derecha, plazas_libres_izquierda;
        asignar_estacion_rec(t.left(), e_izquierda, plazas_libres_izquierda, coef_max, e_id);
        asignar_estacion_rec(t.right(), e_derecha, plazas_libres_derecha, coef_max, e_id);

        estaciones = 1 + e_izquierda + e_derecha;
        plazas_libres = mapa_estaciones[t.value()].consultar_maxbicis() - mapa_estaciones[t.value()].consultar_nbicis() + plazas_libres_izquierda + plazas_libres_derecha;

        double coef = double(plazas_libres/double(estaciones));

        if(coef > coef_max) {
            e_id = t.value();
            coef_max = coef;
        } else if(coef == coef_max) {
            if(e_id == "" || t.value() < e_id) e_id = t.value();
        }
    }
}

void Cjt_estaciones::asignar_estacion(const string& b_id, string& estacion_id) {
    double coef_max = 0;
    string e_id = "";
    unsigned int estaciones, plazas_libres;
    asignar_estacion_rec(arbol_estaciones, estaciones, plazas_libres, coef_max, e_id); //queda en e_id la id con el valor de coeficiente máximo
    bool added = false;
    mapa_estaciones[e_id].alta_bici(b_id, added);
    if(added) {
        plazas_usadas++;
        estacion_id = e_id;
    }
}

bool Cjt_estaciones::existe_estacion(const string& e_id) {
    return (mapa_estaciones.find(e_id) != mapa_estaciones.end());
}

bool Cjt_estaciones::esta_llena(const string& e_id) {
    return mapa_estaciones[e_id].esta_llena();
}

bool Cjt_estaciones::todas_llenas() {
    return (plazas_totales-plazas_usadas == 0);
}