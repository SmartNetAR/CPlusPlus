#include "../ContarPalabras.cpp"

#ifndef collection_cpp
# include "../../../collections/src/collection.cpp"
#endif

// #ifndef set_cpp
// # include "../../../collections/src/set.cpp"
// #endif

#include "catch2/catch.hpp"
/* Dado un texto que termina en un punto. Construir una lista de palabras
    y su frecuencia ( veces que palabra aparece en el texto ).
    El texto se procesa caracter a caracter. */

SCENARIO( "Contar y construir la lista de palabras que se ingresan hasta el punto(.)", "" ) {
    GIVEN( "Una instancia de word" ) {
        Collection<Word> listOfWords; listOfWords.init() ;
        Collection<int> listOfFrecuencies ; listOfFrecuencies.init() ;
        
        Word word ; word.init() ;

        size_t wordInText = 0 ;
         WHEN( "escriba 'hola hola mundo de la programación.'") {
            // Mientras haya una palabra en el texto obtenerla y procesarla
            while( !word.assign( getWordFromText() ).isNull() ) {
                process( word ) ;
                // si la palabra no está en la listaDePalabras, la agrega ...
                if ( !listOfWords.contain( word ) ) listOfWords.add( word ) ; 
                // en este punto la palabra está en la lista de palabras
                // solo nos resta incrementar la lista de frecuencias
                listOfFrecuencies.itemAtPos( listOfWords.indexOf( word ) )++ ;

                wordInText++ ;
            }                      
            THEN( "Debería obtener la cantidad de palabras 5" ) {
                REQUIRE( wordInText == 6 ) ;
                REQUIRE( listOfWords.size() == 5 ) ;
            }
        }
        // WHEN( "escriba 'hola mundo.'") {
        //     word.assign( getWordFromText() ) ;            
        //     THEN( "Debería obtener la cantidad de palabras 2" ) {
        //         // Mientras haya una palabra en el texto obtenerla y procesarla
        //         while( !( word.isNull() )) {
        //             process( word ) ;
        //             count++ ;
        //             word.assign( getWordFromText() ) ;
        //         }
        //         REQUIRE( count == 2 ) ;
        //     }
        // }
    }
}