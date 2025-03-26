/** @file Estacion.hh
    @brief Especificación de la clase Estacion
*/

#ifndef _ESTACION_HH_
#define _ESTACION_HH_

#include "Bici.hh"
#ifndef NO_DIAGRAM
#include "PRO2Excepcio.hh"
#include <iostream>
#include <set>

#endif

/** @class Estacion
    @brief Representa una estación con atributos
*/
class Estacion
{
public:
  // Constructoras

  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar una estación.
      \pre <em>cierto</em>
      \post El resultado es una estación con atributos por defecto
      \coste Constante
  */
  Estacion();

  /** @brief Creadora con capacidad máxima.

      \pre maxbicis > 0
      \post El resultado es una estación con capacidad máxima maxbicis
      \coste Constante
  */
  Estacion(const int &maxbicis);

  // Consultoras

  /** @brief Consulta el número de bicis en la estación.

      \pre <em>cierto</em>
      \post El resultado es el número de bicis en la estación
      \coste Constante
  */
  int consultar_nbicis();

  /** @brief Consulta la capacidad máxima de bicis en la estación.

      \pre <em>cierto</em>
      \post El resultado es la capacidad máxima de bicis en la estación
      \coste Constante
  */
  int consultar_maxbicis();

  /** @brief Obtiene el identificador de la primera bici en la estación.

      \pre La estación no está vacía
      \post El resultado es el identificador de la primera bici en la estación
      \coste Constante
  */
  string obtener_primera_bici();

  /** @brief Verifica si la estación está llena.

      \pre <em>cierto</em>
      \post El resultado indica si la estación está llena
      \coste Constante
  */
  bool esta_llena();

  // Modificadoras

  /** @brief Da de alta una bici en la estación.

      \pre No existe una bici con identificador b_id en la estacion
      \post Se añade una bici con identificador b_id a la estación
      \coste Logarítmico respecto al número de bicis en la estación
  */
  void alta_bici(const string &b_id, bool &added);

  /** @brief Da de baja una bici de la estación.

      \pre La bici con identificador b_id está en la estación
      \post Se elimina la bici con identificador b_id de la estación
      \coste Logarítmico respecto al número de bicis en la estación
  */
  void baja_bici(const string &b_id);

  /** @brief Modifica la capacidad máxima de bicis en la estación.

      \pre capacidad > nbicis
      \post La capacidad máxima de bicis en la estación es igual a capacidad
      \coste Constante
  */
  void modificar_maxbicis(const unsigned int &capacidad, unsigned int &antigua_capacidad);

  // Escritura

  /** @brief Escribe la id de las bicis en la estación.

      \pre <em>cierto</em>
      \post Se escribe la id de las bicis en la estación por el canal estándar de salida
      \coste Lineal respecto al número de bicis en la estación
  */
  void escribir_bicis();

private:
  /** @brief Número de bicis en la estación */
  int nbicis;

  /** @brief Capacidad máxima de bicis en la estación */
  int maxbicis;

  /** @brief Conjunto de identificadores de bicis en la estación */
  set<string> bicis;
};

#endif
