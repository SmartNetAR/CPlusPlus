#include "../ContarPalabras.cpp"
#include "catch2/catch.hpp"
/* Dado un texto que termina en un punto. Construir una lista de palabras
    y su frecuencia ( veces que palabra aparece en el texto ).
    El texto se procesa caracter a caracter. */

SCENARIO( "Contar y construir la lista de palabras que se ingresan hasta el punto(.)", "" ) {
    GIVEN( "Una instancia de word" ) {
        unsigned count = 0 ;
        Word word ; word.init() ;
        WHEN( "escriba 'hola mundo de la programación.'") {
            // word = getWordFromText() ;
            word.assign( getWordFromText() ) ;            
            THEN( "Debería obtener la cantidad de palabras 5" ) {
                // Mientras haya una palabra en el texto obtenerla y procesarla
                while( !( word.isNull() )) {
                    process( word ) ;
                    count++ ;
                    // word = getWordFromText() ;
                    word.assign( getWordFromText() ) ;
                }
                REQUIRE( count == 5 ) ;
            }
        }
        WHEN( "escriba 'hola mundo.'") {
            word.assign( getWordFromText() ) ;            
            THEN( "Debería obtener la cantidad de palabras 2" ) {
                // Mientras haya una palabra en el texto obtenerla y procesarla
                while( !( word.isNull() )) {
                    process( word ) ;
                    count++ ;
                    word.assign( getWordFromText() ) ;
                }
                REQUIRE( count == 2 ) ;
            }
        }
    }
}