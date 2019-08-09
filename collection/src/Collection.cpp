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

  const char* c_string( void ) {
    // cout necesita la dirección del primer caracter del arreglo. 
    return &( items[ 0 ] ) ; // items
  }
} ;

void process ( Word thisWord ) {
  std::cout << thisWord.c_string() << std::endl ;
}

typedef const char* SetOfChar ;

SetOfChar alphabet = "abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ" ;
SetOfChar delimiter =  " ,;:" ;
SetOfChar endOfText = "." ;

Word getWordFromText( void ) {
  enum { idle, working } ;
  static States state = idle ;
 
  Word word ;
  bool done = false ;
  while ( !done ) {
    if ( state == idle ) {
      char ch = std::cin.get() ;
      if ( contain( endOfText, ch ) ) {
        done = true ;
        state = idle ;
      } else if ( contain( alphabet, ch ) ) {
        word = word + ch ;
        state = working ;
      } else if ( contain( delimiter, ch ) ) {
        ;
      }
    } else if ( state == working ) {
      char ch = std::cin.get() ;
      if ( contain( endOfText, ch ) ) {
        done = true ;
        state = idle ;
      } else if ( contain( alphabet, chr ) ) {
        word = word + ch ;
        state = working ;
      } else if ( contain( delimiter, ch ) ) {
        done = true ;
        state = idle ;
      }
    }
  }
  

  return word ;
}

#endif