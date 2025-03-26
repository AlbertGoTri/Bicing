/** @file program.cc
    @brief Código del fichero principal del programa
*/

#include "Cjt_estaciones.hh"
#include "Bici.hh"
#include "Estacion.hh"
#include <iostream>
#include <string>

using namespace std;

int main() {
    const string ERROR_BICI_EXISTE = "error: la bici ya existe\n";
    const string ERROR_BICI_NO_EXISTE = "error: la bici no existe\n";
    const string ERROR_ESTACION_NO_EXISTE = "error: la estacion no existe\n";
    const string ERROR_MISMA_ESTACION = "error: la bici ya esta en el sitio\n";
    const string ERROR_BICI_NO_CABE = "error: la bici no cabe\n";
    const string ERROR_POCA_CAPACIDAD = "error: capacidad insuficiente\n";
    const string ERROR_NO_PLAZAS = "error: no hay plazas libres\n";
    Cjt_estaciones estaciones;
    Cjt_bicis bicis;
    string comando, b_id, e_id, e_destino_id;
    int capacidad;

    estaciones.inicializar();

    while(cin>>comando && comando != "fin") {
        if(comando == "alta_bici" || comando == "ab") {
            
            cin>>b_id>>e_id;
            cout<<"#ab "<<b_id<<" "<<e_id<<endl;
            if(bicis.existe(b_id)) {
                cout<<ERROR_BICI_EXISTE;
            }else{
                if(!estaciones.existe_estacion(e_id)) {
                    cout<<ERROR_ESTACION_NO_EXISTE;
                }else if(estaciones.esta_llena(e_id)) {
                    cout<<ERROR_BICI_NO_CABE;
                }else{
                    estaciones.alta_bici(b_id, e_id);
                    bicis.anadir_bici(b_id, e_id);
                }
            }
        }else if(comando == "baja_bici" || comando == "bb") {
            
            cin>>b_id;
            cout<<"#bb "<<b_id<<endl;
            if(!bicis.existe(b_id)) {
                cout<<ERROR_BICI_NO_EXISTE;
            }else{
                e_id = bicis.consultar_estacion(b_id);
                bicis.baja_bici(b_id);
                estaciones.baja_bici(b_id, e_id);
            }
        }else if(comando == "estacion_bici" || comando == "eb") {
            
            cin>>b_id;
            cout<<"#eb "<<b_id<<endl;
            if(!bicis.existe(b_id)) {
                cout<<ERROR_BICI_NO_EXISTE;
            }else {
                cout<<bicis.consultar_estacion(b_id)<<endl;
            }
        }else if(comando == "viajes_bici" || comando == "vb") {
            
            cin>>b_id;
            cout<<"#vb "<<b_id<<endl;
            if(!bicis.existe(b_id)) {
                cout<<ERROR_BICI_NO_EXISTE;
            }else{
                bicis.viajes_bici(b_id);
            }
        }else if(comando == "mover_bici" || comando == "mb") {
            
            cin>>b_id>>e_destino_id;
            cout<<"#mb "<<b_id<<" "<<e_destino_id<<endl;
            if(!bicis.existe(b_id)) {
                cout<<ERROR_BICI_NO_EXISTE;
            }else {
                e_id = bicis.consultar_estacion(b_id);

                if(e_id == e_destino_id) {
                    cout<<ERROR_MISMA_ESTACION;
                }else {
                    if(!estaciones.existe_estacion(e_destino_id)) {
                        cout<<ERROR_ESTACION_NO_EXISTE;
                    }else if(estaciones.esta_llena(e_destino_id)) {
                        cout<<ERROR_BICI_NO_CABE;
                    }else {
                        estaciones.mover_bici(b_id, e_id, e_destino_id);
                        bicis.anadir_viaje(b_id, e_id, e_destino_id);
                    }
                }
            }
        }else if(comando == "bicis_estacion" || comando == "be") {
            
            cin>>e_id;
            cout<<"#be "<<e_id<<endl;
            if(!estaciones.existe_estacion(e_id)) {
                cout<<ERROR_ESTACION_NO_EXISTE;
            }else{
                estaciones.bicis_estacion(e_id);
            }
        }else if(comando == "modificar_capacidad" || comando == "mc") {
            cin>>e_id>>capacidad;
            cout<<"#mc "<<e_id<<" "<<capacidad<<endl;
            if(!estaciones.existe_estacion(e_id)) {
                cout<<ERROR_ESTACION_NO_EXISTE;
            } else if(estaciones.poca_capacidad(e_id, capacidad)) {
                cout<<ERROR_POCA_CAPACIDAD;
            } else {
                estaciones.modificar_capacidad(e_id, capacidad);
            }
        }else if(comando == "plazas_libres" || comando == "pl") {
            cout<<"#pl"<<endl;
            cout<<estaciones.plazas_libres()<<endl;
        }else if(comando == "subir_bicis" || comando == "sb") {
            cout<<"#sb"<<endl;
            estaciones.subir_bicis(bicis);
        }else if(comando == "asignar_estacion" || comando == "ae") {
            cin>>b_id;
            cout<<"#ae "<<b_id<<endl;
            if(bicis.existe(b_id)) {
                cout<<ERROR_BICI_EXISTE;
            }else {
                if(estaciones.todas_llenas()) {
                    cout<<ERROR_NO_PLAZAS;
                }else {
                    estaciones.asignar_estacion(b_id, e_id);
                    bicis.anadir_bici(b_id, e_id);
                    cout<<bicis.consultar_estacion(b_id)<<endl;
                }                
            }
        }
    }
    return 0;
}