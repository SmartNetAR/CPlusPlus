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

  void init ( const char* plainString = "" ) {
    strcpy( items, plainString ) ;
  }

  const char* c_string( void ) {
    // cout necesita la dirección del primer caracter del arreglo. 
    return &( items[ 0 ] ) ; // items
  }

  Word& concat( char ch ) {
    size_t len = strlen( items ) ;
    items[ len ] = ch ;
    items[ len + 1 ] = '\0' ;
    return *this ;
  }

  Word& assign( const Word& word ) {
    strcpy( items, word.items ) ;
    return *this ;
  }

} ;

void process ( Word thisWord ) {
  std::cout << thisWord.c_string() << std::endl ;
}

typedef const char* SetOfChar ;

SetOfChar alphabet = "abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ" ;
SetOfChar delimiter =  " ,;:" ;
SetOfChar endOfText = "." ;

bool contain( SetOfChar set, char ch ) {
  size_t cardinal = strlen( set ) ;
  size_t idx = 0 ;
  for( ; idx < cardinal && set[ idx ] != ch; idx++ ) ;
  return ( idx < cardinal ) ;
}

Word getWordFromText( void ) {
  enum States { idle, working, ending } ;
  static States state = idle ;
 
  // Word word = "" ;
  Word word ; word.init() ;
  bool done = false ;
  while ( !done ) {
    if ( state == idle ) {
      char ch = std::cin.get() ;
      if ( contain( endOfText, ch ) ) {
        state = ending ;
      } else if ( contain( alphabet, ch ) ) {
        // word = word + ch ;
        word = word.concat( ch ) ;
        state = working ;
      } else if ( contain( delimiter, ch ) ) {
        ;
      }
    } else if ( state == working ) {
      char ch = std::cin.get() ;
      if ( contain( endOfText, ch ) ) {
        done = true ;
        state = ending ;
      } else if ( contain( alphabet, ch ) ) {
        // word = word + ch ;
        word = word.concat( ch ) ;
        state = working ;
      } else if ( contain( delimiter, ch ) ) {
        done = true ;
        state = idle ;
      }
    } else if( state == ending ) {
      done = true ;
      state = idle ;
    }
  }
  return word ;
}

#endif