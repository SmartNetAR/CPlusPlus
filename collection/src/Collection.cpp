#ifndef Collection_cpp
#define Collection_cpp

#include <iostream>

struct Word {
  enum { MAX_STRING_LENGTH = 254, CONTAINER_CAPACITY = MAX_STRING_LENGTH + 1 } ;

  char items[ CONTAINER_CAPACITY ] ;

  bool isNull( void ) {
    // si el primer caracter de la cadena es nulo
    return items[ 0 ] == '\0' ;
  }
} ;
void process ( Word thisWord ) {

}

Word getWordFromText( void ) {
  Word word ;
  return word ;
}

#endif