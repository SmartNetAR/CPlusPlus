#include "../set.cpp"
#include "catch2/catch.hpp"
/* Dado un texto que termina en un punto. Construir una lista de palabras
    y su frecuencia ( veces que palabra aparece en el texto ).
    El texto se procesa caracter a caracter. */

SCENARIO( "Gestión con set", "" ) {
    GIVEN( "Una instancia de Set" ) {
        char abc[3] = { 'a', 'b', 'c' } ;
        Set<char> s ; s.init( abc, sizeof( abc ) ) ;
        Set<char> t ; t.init() ;
        WHEN( "si agrego items 1 char.'") {
            s.add( 'p') ;            
            THEN( "Debería obtener la cantidad de 4" ) {
                REQUIRE( s.size() == 4 ) ;
            }
            THEN( "No debe estar vacía" ) {
                REQUIRE( s.isEmpty() == false ) ;
            }
        }
        WHEN( "lo agrego a otro set" ) {
            s.add( 'p') ;
            t.add( s ) ;
            THEN( "Debería tener los mismos items") {
                REQUIRE( s.size() == t.size() ) ;
            }            
        }
        WHEN( "inicializo con un set" ) {
            s.add( 'p' ).add( 'q' ).add( 'r' ) ;
            Set<char> u ; u.init( s ) ;
            THEN( "Debería tener los mismos items") {
                REQUIRE( s.size() == u.size() ) ;
            }            
        }
        WHEN( "agrego un array" ) {
            char arrayChar[] = { 'x', 'y', 'z' } ;
            s.add( arrayChar, sizeof( arrayChar ) ) ;
            THEN( "Debería tener los mismos items + los del array" ) {
                REQUIRE( s.size() == 6 ) ;
            }            
        }
        WHEN( "agrego una Collection" ) {
            Collection<char> c ; c.init() ;
            c.add( 'x' ).add( 'y' ).add( 'z' ) ;
            s.add( c ) ;
            THEN( "Debería tener los mismos items + los de la Collection" ) {
                REQUIRE( c.size() == 3 ) ;
                REQUIRE( s.size() == 6 ) ;
            }
        }
        WHEN( "inicializo con una Collection" ) {
            Collection<char> c ; c.init() ;
            c.add( 'x' ).add( 'y' ).add( 'z' ) ;
            s.init( c ) ;
            THEN( "Debería tener los mismos items + los de la Collection" ) {
                REQUIRE( c.size() == 3 ) ;
                REQUIRE( s.size() == 3 ) ;
            }
        }
        WHEN( "si agrego dos char") {
            s.add( 'x' ).add( 'y' ) ;
            THEN( "Deberían ser 5" ) {
                REQUIRE( s.size() == 5 ) ;
            }
        }
        WHEN( "agrego 3 repetidos, que ya estaban contenidos" ) {
            size_t beforeSize = s.size() ;
            char abc[] = { 'a', 'b', 'c' } ;
            s.add( abc, sizeof( abc ) ) ;
            THEN( "Debería ser igual al tamaño anteior (3)" ) {
                REQUIRE( s.size() == beforeSize ) ;
            }
        }
    }
}