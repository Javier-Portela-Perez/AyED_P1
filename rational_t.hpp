// AUTOR:Javier Portela Pérez 
// FECHA:13-2-23
// EMAIL:alu0101569741@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: Puede utilizar la sintaxis //o /* */; sin embargo, //es mucho más común

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]:Todos los archivos de encabezado deben tener #defineprotecciones para evitar 
                      //la inclusión múltiple.
# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public:
  //elementos públicos
  //constructor
  rational_t(const int = 0, const int = 1);
  //destructor
  ~rational_t() {}
  
  // pauta de estilo [71]: indentación a 2 espacios
  // getters
  //métodos para acceder a los atributos num y den
  int get_num() const;
  int get_den() const;
  
  // setters
  //métodos para editar los atributos num y den
  void set_num(const int);
  void set_den(const int);

  double value(void) const;

  // FASE II
   bool is_equal(const rational_t& r, const double precision = EPSILON) const;
   bool is_greater(const rational_t& r, const double precision = EPSILON) const;
   bool is_less(const rational_t& r, const double precision = EPSILON) const;
  
  // FASE III
   rational_t add(const rational_t&);
   rational_t substract(const rational_t&);
   rational_t multiply(const rational_t&);
   rational_t divide(const rational_t&);
  
  //método para lectura desde teclado
  void write(ostream& = cout) const;
  //método para escritura en pantalla
  void read(istream& = cin);
  
private:
  // elementos privados
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_;
};
