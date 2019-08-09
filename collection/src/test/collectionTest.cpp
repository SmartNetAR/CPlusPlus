#include "../Collection.cpp"
#include "catch2/catch.hpp"
/* Dado un texto que termina en un punto. Construir una lista de palabras
    y su frecuencia ( veces que palabra aparece en el texto ).
    El texto se procesa caracter a caracter. */

SCENARIO( "Collection puede agregar palabras", "" ) {
    GIVEN( "Mientras haya una palabra en el texto obtenerla y procesarla" ) {
        unsigned count = 0 ;
        Word word ; word.init() ;
        WHEN( "haya una palabra en el texto obtenerla y procesarla") {
            // word = getWordFromText() ;
            word.assign( getWordFromText() ) ;            
            THEN( "si escribo 5 palabras y termino con ., debería obterner un 5" ) {
                while( !( word.isNull() )) {
                    process( word ) ;
                    count++ ;
                    // word = getWordFromText() ;
                    word.assign( getWordFromText() ) ;
                }
                REQUIRE( count == 5 ) ;
            }
        }
    }
}