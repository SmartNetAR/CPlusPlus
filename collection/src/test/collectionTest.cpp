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
            // int item = l.append( 5 );
            // Type item = l->pop() ;
            THEN( "debería obtener un 5" ) {
                while( !( word.isNull() )) {
                    process( word ) ;
                    count++ ;
                    word = getWordFromText() ;
                }
                // REQUIRE( item == 5 ) ;
            }
        }
        /*
        WHEN( "Encolo solo un 9") {
            l->append( 9 );
            Type item = l->pop() ;
            THEN( "debería obtener un 9" ) {
                REQUIRE( item == 9 ) ;
            }
        } */
        /* WHEN( "Encolo un 5, un 9 y un 13") {
            l->append( 5 );
            l->append( 9 );
            l->append( 13 );
            Type item1 = l->pop() ;
            Type item2 = l->pop() ;
            Type item3 = l->pop() ;
            THEN( "debería obtener un 5, un 9 y un 13" ) {
                REQUIRE( item1 == 5 ) ;
                REQUIRE( item2 == 9 ) ;
                REQUIRE( item3 == 13 ) ;
            }
        }
        WHEN( "Encolo un 6 y un 7 y consulto el último dos veces") {
            l->append( 6 ) ;
            l->append( 7 ) ;
            auto item1 = l->peekBack() ;
            auto item2 = l->peekBack() ;
            THEN( "debería obtener un 7 ambas veces" ) {
                REQUIRE( item1 == 7 ) ;
                REQUIRE( item2 == 7 ) ;
            }
        }
        WHEN( "Encolo un 6 y un 7 y consulto el primero dos veces") {
            l->append( 6 ) ;
            l->append( 7 ) ;
            auto item1 = l->peekFront() ;
            auto item2 = l->peekFront() ;
            THEN( "debería obtener un 6 ambas veces" ) {
                REQUIRE( item1 == 6 ) ;
                REQUIRE( item2 == 6 ) ;
            }
        }
        WHEN ( "Está vacía y quiero desencolar" ) {
            // auto item = l->pop() ;
            THEN( "qué debería obtener un error o un nullptr" ) {
                // REQUIRE( item == ? ) ;
            }
        } */
    }
}