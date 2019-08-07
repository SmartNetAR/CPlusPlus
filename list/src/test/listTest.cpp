#include "../List.cpp"
#include "catch2/catch.hpp"

// g++ -std=c++11 -Wall stackTest.cpp && ./stackTest --reporter compact --success

SCENARIO( "List puede encolar", "" ) {
    GIVEN( "Una instancia de List" ) {
        iList* q = new List( 10 ) ;
        WHEN( "Encolo solo un 5, la propia función devuelve el item") {
            Type item = q->append( 5 );
            // Type item = q->pop() ;
            THEN( "debería obtener un 5" ) {
                REQUIRE( item == 5 ) ;
            }
        }
        WHEN( "Encolo solo un 9") {
            q->append( 9 );
            Type item = q->pop() ;
            THEN( "debería obtener un 9" ) {
                REQUIRE( item == 9 ) ;
            }
        }
        WHEN( "Encolo un 5, un 9 y un 13") {
            q->append( 5 );
            q->append( 9 );
            q->append( 13 );
            Type item1 = q->pop() ;
            Type item2 = q->pop() ;
            Type item3 = q->pop() ;
            THEN( "debería obtener un 5, un 9 y un 13" ) {
                REQUIRE( item1 == 5 ) ;
                REQUIRE( item2 == 9 ) ;
                REQUIRE( item3 == 13 ) ;
            }
        }
        WHEN( "Encolo un 6 y un 7 y consulto el último dos veces") {
            q->append( 6 ) ;
            q->append( 7 ) ;
            auto item1 = q->peekBack() ;
            auto item2 = q->peekBack() ;
            THEN( "debería obtener un 7 ambas veces" ) {
                REQUIRE( item1 == 7 ) ;
                REQUIRE( item2 == 7 ) ;
            }
        }
        WHEN( "Encolo un 6 y un 7 y consulto el primero dos veces") {
            q->append( 6 ) ;
            q->append( 7 ) ;
            auto item1 = q->peekFront() ;
            auto item2 = q->peekFront() ;
            THEN( "debería obtener un 6 ambas veces" ) {
                REQUIRE( item1 == 6 ) ;
                REQUIRE( item2 == 6 ) ;
            }
        }
        WHEN ( "Está vacía y quiero desencolar" ) {
            auto item = q->pop() ;
            THEN( "qué debería obtener un error o un nullptr" ) {
                // REQUIRE( item == ? ) ;
            }
        }
    }
}