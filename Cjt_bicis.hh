/** @file Cjt_bicis.hh
    @brief Especificación de la clase Cjt_bicis
*/

#ifndef _CJT_BICIS_HH_
#define _CJT_BICIS_HH_

#include "Bici.hh"
#ifndef NO_DIAGRAM
#include "PRO2Excepcio.hh"
#include <iostream>
#include <map>
#include "BinTree.hh"

#endif

/** @class Cjt_bicis
    @brief Representa un conjunto de bicis con atributos
*/
class Cjt_bicis
{
public:
  // Constructoras

  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar un conjunto de bicis.
      \pre <em>cierto</em>
      \post El resultado es un conjunto de bicis vacío
      \coste Constante
  */
  Cjt_bicis();

  // Consultoras

  /** @brief Verifica la existencia de una bici en el conjunto.

      \pre <em>cierto</em>
      \post El resultado indica si existe una bici con identificador b_id en el conjunto
      \coste Logarítmico respecto al número de bicis
  */
  bool existe(const string &b_id);

  /** @brief Consulta la estación de una bici en el conjunto.

      \pre Existe una bici con identificador b_id en el conjunto
      \post El resultado es la estación de la bici con identificador b_id
      \coste Logarítmico respecto al número de bicis
  */
  string consultar_estacion(const string &b_id);

  /** @brief Muestra los viajes de una bici en el conjunto.

      \pre Existe una bici con identificador b_id en el conjunto
      \post Se muestra por el canal estándar de salida la información de los viajes de la bici con identificador b_id
      \coste Lineal respecto al número de viajes de la bici
  */
  void viajes_bici(const string &b_id);

  // Modificadoras

  /** @brief Añade una bici al conjunto.

      \pre No existe una bici con identificador b_id en el conjunto y la bici cabe en la estacion con id e_id
      \post Se añade una bici con identificador b_id y estación e_id al conjunto
      \coste Logarítmico respecto al número de bicis
  */
  void anadir_bici(const string &b_id, const string &e_id);

  /** @brief Da de baja una bici del conjunto.

      \pre Existe una bici con identificador b_id en el conjunto
      \post Se elimina la bici con identificador b_id del conjunto
      \coste Logarítmico respecto al número de bicis
  */
  void baja_bici(const string &b_id);

  /** @brief Modifica la estación de una bici en el conjunto.

      \pre Existe una bici con identificador b_id en el conjunto
      \post La estación de la bici con identificador b_id es igual a e_id
      \coste Logarítmico respecto al número de bicis
  */
  void modificar_estacion(const string &b_id, const string &e_id);

  /** @brief Añade un viaje a una bici en el conjunto.

      \pre Existe una bici con identificador b_id en el conjunto, tanto e_origen como e_destino existen y son diferentes entre si
      \post Se añade un viaje desde e_origen hasta e_destino a la bici con identificador b_id
      \coste Logarítmico respecto al número de bicis
  */
  void anadir_viaje(const string &b_id, const string &e_origen, const string &e_destino);

private:
  /** @brief Mapa de bicis en el conjunto (identificador de bici -> objeto Bici) */
  map<string, Bici> bicis;
};

#endif
