#ifndef associative_container_hpp
# define associative_container_hpp

#include <stdio.h>

#ifndef static_collection_hpp
# include "collection.cpp"
#endif

// Un contenedor es un objeto que almacena otros objetos (sus elementos), y que tiene
// operaciones para acceder a sus elementos. Un contenedor (en este conexto)
// "posee" a sus elementos, esto es el ciclo de vida de sus elementos no puede
// exceder el de su contenedor mismo.
//
// Un contenedor asociativo es un tipo de contenedor compuesto por una coleccion,
// de claves y valores. En un contenedor asociativo, la asociacion entre una
// clave y un valor se conoce como "binding", y la misma palabra "binding" suele
// utilizarse para referirse al proceso de crear una nueva asociación.
//
template< class KeyType, class ValueType >
struct AssociativeContainer
{
  Collection<KeyType> itsKeys ;
  Collection<ValueType> itsValues ;

  struct Iterator
  {
    KeyType* currentKey ;
    ValueType* currentValue ;
    AssociativeContainer<KeyType,ValueType>* associativeContainer ;
    Collection<KeyType> keys ;

    void init( AssociativeContainer<KeyType,ValueType>* istAssociativeContainer ) ;
    void release( void ) ;
    void reset( void ) ;

    Iterator& begin( void ) ;
    Iterator& next( void ) ;
    Iterator& end( void ) ;
    bool isNull( void ) ;
    KeyType* key( void ) ;
    ValueType* value( void ) ; 

  } iterator ;

  void init( void ) ;
  void release( void ) ;
  void reset( void ) ;

  ValueType& add( const KeyType& key, const ValueType& value ) ;

  ValueType& itemAtPos( const KeyType& key ) ;
  ValueType valueForKey( const KeyType& key ) ;
  bool contain( const KeyType& item ) ;
  Collection<KeyType> keys( void ) ;
  size_t count( void ) ;

  KeyType* firstItem( void ) ;
  KeyType* nextItem( void ) ;
  
};

#endif