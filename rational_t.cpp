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

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d) // método que verifica que el denominador es 
                                                 //distinto de cero, y si lo es llama al numerador n 
                                                 //y a denominador d
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
// método para obtener de la clase el numerador 
int rational_t::get_num() const 
{
  return num_;
}

// método para obtener de la clase el denominador
int rational_t::get_den() const 
{
  return den_;
}

// método para poder llamar al numerador como n
void rational_t::set_num(const int n) 
{
  num_ = n;
}

// método que verifica que el denominador es distinto de cero,y si lo es llama al denominador d
void rational_t::set_den(const int d) 
{
  assert(d != 0);
  den_ = d;
}

// método para dividir
double rational_t::value() const 
{
  return double(get_num()) / get_den();
}
// comprueba si dos numeros racionales son iguales
bool rational_t::is_equal(const rational_t &r, const double precision) const 
{
  bool result = fabs(value() - r.value()) < precision; 
  return result;
}

// comprueba si un numero racional es mayor que otro

bool rational_t::is_greater(const rational_t &r, const double precision) const 
{
  bool result = (value() - r.value()) > precision;
  return result;
}

// comprueba si un numero racional es menor que otro
bool rational_t::is_less(const rational_t &r, const double precision) const
{
  bool result = (value() - r.value()) < precision;
  return result;
}

// operaciones

// suma dos numeros racionales
rational_t rational_t::add(const rational_t &r)
{
  rational_t result;
  int new_num = (get_num() * r.get_den()) + (r.get_num() * get_den());
  int new_den = get_den() * r.get_den();
  result.set_num(new_num);
  result.set_den(new_den);
  return result;
}

// resta dos numeros racionales
rational_t rational_t::substract(const rational_t& r) {
  rational_t result;
  int new_num = (get_num() * r.get_den()) - (r.get_num() * get_den());
  int new_den = get_den() * r.get_den();
  result.set_num(new_num);
  result.set_den(new_den);
  return result;
}

// multiplica dos numeros racionales
rational_t rational_t::multiply(const rational_t& r) {
  rational_t result;
  int new_num = get_num() * r.get_num();
  int new_den = get_den() * r.get_den();
  result.set_num(new_num);
  result.set_den(new_den);
  return result;
}

// divide dos numeros racionales
rational_t rational_t::divide(const rational_t& r) {
  rational_t result;
  int new_num = get_num() * r.get_den();
  int new_den = get_den() * r.get_num();
  result.set_num(new_num);
  result.set_den(new_den);
  return result;
}


// método para leer los datos del teclado
void rational_t::write(ostream &os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

// método para imprimir los datos en la pantalla
void rational_t::read(istream &is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
