#include "../associative_container.cpp"
#include "catch2/catch.hpp"

SCENARIO( "Gestión con AssociativeContainer", "" ) {
    GIVEN( "Una instancia de AssociativeContainer" ) {
        AssociativeContainer<char,char> as ; as.init() ;
        WHEN( "si agrego la clave a y valor 1 char.'") {
            as.add( 'a', '1') ;
            as.add( 'b', '2') ;
            THEN( "Debería obtener los valores para las clave ingresadas" ) {
                REQUIRE( as.valueForKey( 'a' ) == '1' ) ;
                REQUIRE( as.valueForKey( 'b' ) == '2' ) ;
            }
            THEN( "No debe estar vacía" ) {
                REQUIRE( as.count() == 2 ) ;
            }
        }
    }
}