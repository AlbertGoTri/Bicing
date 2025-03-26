/** @file Cjt_estaciones.hh
    @brief Especificación de la clase Cjt_estaciones
*/

#ifndef _CJT_ESTACIONES_HH_
#define _CJT_ESTACIONES_HH_


#include "Estacion.hh"
#include "Cjt_bicis.hh"
#ifndef NO_DIAGRAM
#include "PRO2Excepcio.hh"
#include <iostream>
#include <map>
#include "BinTree.hh"

#endif

using namespace std;

/** @class Cjt_estaciones
    @brief Representa un conjunto de estaciones con atributos
*/
class Cjt_estaciones
{
public:
  // Constructoras

  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un conjunto de estaciones.
      \pre <em>cierto</em>
      \post El resultado es un conjunto de estaciones vacío
      \coste Constante
  */
  Cjt_estaciones();

  // Modificadoras

  /** @brief Inicializa el conjunto de estaciones.

      \pre <em>cierto</em>
      \post El conjunto de estaciones se inicializa con valores proporcionados por la entrada estándar
      \coste Variable, dependiente de la entrada
  */
  void inicializar();

  /** @brief Da de alta una bici en una estación.

      \pre La bici con identificador b_id no eiste en la estacion con identificador e_id, y cabe en ella
      \post Se añade una bici con identificador b_id a la estación con identificador e_id
      \coste Logarítmico respecto al número de estaciones
  */
  void alta_bici(const string &b_id, const string &e_id);

  /** @brief Da de baja una bici de una estación.

      \pre La bici con  identificador b_id existe en la estación con identificador e_id
      \post Se elimina la bici con identificador b_id de la estación con identificador e_id
      \coste Logarítmico respecto al número de estaciones
  */
  void baja_bici(const string &b_id, const string &e_id);

  /** @brief Mueve una bici de una estación a otra.

      \pre La bici con identificador b_id está en la estación con identificador e_id, la estación con identificador e_destino_id existe y es diferente de e_id
      \post Se mueve la bici con identificador b_id desde la estación con identificador e_id a la estación con identificador e_destino_id
      \coste Logarítmico respecto al número de estaciones
  */
  void mover_bici(const string &b_id, const string &e_id, const string &e_destino_id);

  /** @brief Verifica si una estación tiene poca capacidad.

      \pre La estacion con identificador e_id existe
      \post El resultado indica si la estación con identificador e_id tiene capacidad insuficiente
      \coste Constante
  */
  bool poca_capacidad(const string &e_id, const int &capacidad);

  /** @brief Modifica la capacidad de una estación.

      \pre La estacion con identificador e_id existe y capacidad > nbicis en la estacion
      \post La capacidad de la estación con identificador e_id es igual a capacidad
      \coste Logarítmico respecto al número de estaciones
  */
  void modificar_capacidad(const string &e_id, const int &capacidad);

  /** @brief Consulta el número de plazas libres en todas las estaciones.

      \pre <em>cierto</em>
      \post El resultado es el número de plazas libres en todas las estaciones
      \coste Constante
  */
  unsigned int plazas_libres();

  /** @brief Sube bicis a las estaciones correspondiendes.

      \pre <em>cierto</em>
      \post Se redistribuyen bicis entre las estaciones para maximizar la proporción de plazas libres
      \coste Variable, dependiente de la estructura de las estaciones y el número de bicis
  */
  void subir_bicis(Cjt_bicis &bicis);

  /** @brief Asigna una estación a una bici.

      \pre <em>cierto</em>
      \post Se asigna una estación a la bici con identificador b_id y se actualiza estacion_id
      \coste Variable, dependiente de la estructura de las estaciones y el número de bicis
  */
  void asignar_estacion(const string &b_id, string &estacion_id);

  // Consultoras

  /** @brief Verifica si una estación existe.

      \pre <em>cierto</em>
      \post El resultado indica si existe una estación con identificador e_id
      \coste Logarítmico respecto al número de estaciones
  */
  bool existe_estacion(const string &e_id);

  /** @brief Verifica si una estación está llena.

      \pre La estacion con identificador e_id existe
      \post El resultado indica si la estación con identificador e_id está llena
      \coste Constante
  */
  bool esta_llena(const string &e_id);

  /** @brief Verifica si todas las estaciones están llenas.

      \pre <em>cierto</em>
      \post El resultado indica si todas las estaciones están llenas
      \coste Constante
  */
  bool todas_llenas();

  // Escritura

  /** @brief Escribe la información de las bicis en una estación.

      \pre <em>cierto</em>
      \post Se escribe la información de las bicis en la estación con identificador e_id por el canal estándar de salida
      \coste Variable, dependiente del número de bicis en la estación
  */
  void bicis_estacion(const string &e_id);

private:
  /** @brief Árbol de estaciones */
  BinTree<string> arbol_estaciones;

  /** @brief Mapa de estaciones en el conjunto (identificador de estación -> objeto Estacion) */
  map<string, Estacion> mapa_estaciones;

  /** @brief Número total de plazas en todas las estaciones */
  int plazas_totales;

  /** @brief Número de plazas usadas en todas las estaciones */
  int plazas_usadas;

  /** @brief Inicializa el árbol de estaciones y el mapa de estaciones con valores proporcionados por la entrada estándar.
      \param arbol_estaciones Árbol de estaciones a inicializar
  */
  void setTree(BinTree<string> &arbol_estaciones);

  /** @brief Recorre el árbol de estaciones para redistribuir bicis entre ellas y maximizar la proporción de plazas libres.
      \param t Árbol de estaciones
      \param bicis Conjunto de bicis para redistribuir
  */
  void subir_bicis_rec(const BinTree<string> &t, Cjt_bicis &bicis);

  /** @brief Recorre el árbol de estaciones para asignar una estación a una bici y maximizar la proporción de plazas libres.
      \param t Árbol de estaciones
      \param estaciones Número total de estaciones
      \param plazas_libres Número total de plazas libres en todas las estaciones
      \param coef_max Coeficiente máximo actual
      \param e_id Identificador de la estación con el coeficiente máximo
  */
  void asignar_estacion_rec(const BinTree<string> &t, unsigned int &estaciones, unsigned int &plazas_libres, double &coef_max, string &e_id);
};

#endif
