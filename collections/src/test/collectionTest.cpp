#include "../collection.cpp"
#include "catch2/catch.hpp"
/* Dado un texto que termina en un punto. Construir una lista de palabras
    y su frecuencia ( veces que palabra aparece en el texto ).
    El texto se procesa caracter a caracter. */

SCENARIO( "Gestión con collection", "" ) {
    GIVEN( "Una instancia de collection" ) {
        // unsigned count = 0 ;
        Collection<char> col ; col.init() ;
        WHEN( "si agrego 3 char.'") {
            char abc[3] = { 'a', 'b', 'c' } ;
            col.add( abc , 3 ) ;          
            THEN( "Debería obtener la cantidad de 3" ) {
                REQUIRE( col.size() == 3 ) ;
            }
        }
        WHEN( "si agrego dos char") {
            col.add( 'x' ) ; col.add( 'y' ) ;
            THEN( "Deberían ser 2" ) {
                REQUIRE( col.size() == 2 ) ;
            }
            char abc[] = { 'a', 'b', 'c' } ;
            col.add( abc, 3 ) ;
            THEN( "Debería ser 5" ) {
                REQUIRE( col.size() == 5 ) ;
            }
            THEN( "La posición x debería ser la 0, la b la pos 3") {
                REQUIRE( col.indexOf( 'x' ) == 0 ) ;
                REQUIRE( col.indexOf( 'b' ) == 3 ) ;
            }
            THEN( "En la posición 2 debería estár la 'a'") {
                REQUIRE( col.itemAtPos( 2 ) == 'a' ) ;
            }
            THEN( "En la primer posición debería estár la 'x'") {
                char* ch = col.firstItem() ;
                REQUIRE( *ch == 'x' ) ;
            }
            THEN( "No debería encontrar la 'z'") {
                REQUIRE( col.contain('z') == false ) ;
            }
            THEN( "Debería encontrar la 'y'") {
                REQUIRE( col.contain('y') == true ) ;
            }
        }
    }
}