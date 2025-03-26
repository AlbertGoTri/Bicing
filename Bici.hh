/** @file Bici.hh
    @brief Especificación de la clase Bici
*/

#ifndef _BICI_HH_
#define _BICI_HH_

#ifndef NO_DIAGRAM
#include "PRO2Excepcio.hh"
#include <iostream>
#include <list>
#endif

/** @class Bici
    @brief Representa una bici con atributos
*/
class Bici
{
public:
  // Constructoras

  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar una bici.
      \pre Cierto
      \post El resultado es una bici sin atributos específicos
      \coste Constante
  */
  Bici();

  /** @brief Creadora con valores concretos.

      \pre pes > 0
      \post El resultado es una bici con atributos específicos
      \coste Constante
  */
  Bici(const string &estacion);

  // Consultoras

  /** @brief Consulta la estación de la bici.

      \pre Cierto
      \post El resultado es la estación de la bici
      \coste Constante
  */
  string consultar_estacion();

  // Modificadoras

  /** @brief Modifica la estación de la bici.

      \pre <em>cierto</em>
      \post La estación de la bici es igual a e_id
      \coste Constante
  */
  void modificar_estacion(const string &e_id);

  /** @brief Añade un viaje a la bici.

      \pre <em>cierto</em>
      \post Se añade un viaje desde e_origen hasta e_destino
      \coste Constante
  */
  void anadir_viaje(const string &e_origen, const string &e_destino);

  // Escritura

  /** @brief Escribe la información de los viajes de la bici.

      \pre <em>cierto</em>
      \post Se escribe la información de los viajes por el canal estándar de salida
      \coste Lineal respecto al número de viajes
  */
  void escribir_viajes();

private:
  /** @brief Estación de la bici */
  string estacion;

  /** @brief Lista de viajes de la bici (pares origen-destino) */
  list<pair<string, string>> viajes;
};

#endif
