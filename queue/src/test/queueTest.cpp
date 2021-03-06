#include "../Queue.cpp"
#include "catch2/catch.hpp"

// g++ -std=c++11 -Wall stackTest.cpp && ./stackTest --reporter compact --success

SCENARIO( "Queue puede encolar", "" ) {
    GIVEN( "Una instancia de Queue" ) {
        iQueue* q = new Queue( 10 ) ;
        WHEN( "Encolo solo un 5, la propia función devuelve el item") {
            Type item = q->enqueue( 5 );
            // Type item = q->dequeue() ;
            THEN( "debería obtener un 5" ) {
                REQUIRE( item == 5 ) ;
            }
        }
        WHEN( "Encolo solo un 9") {
            q->enqueue( 9 );
            Type item = q->dequeue() ;
            THEN( "debería obtener un 9" ) {
                REQUIRE( item == 9 ) ;
            }
        }
        WHEN( "Encolo un 5, un 9 y un 13") {
            q->enqueue( 5 );
            q->enqueue( 9 );
            q->enqueue( 13 );
            Type item1 = q->dequeue() ;
            Type item2 = q->dequeue() ;
            Type item3 = q->dequeue() ;
            THEN( "debería obtener un 5, un 9 y un 13" ) {
                REQUIRE( item1 == 5 ) ;
                REQUIRE( item2 == 9 ) ;
                REQUIRE( item3 == 13 ) ;
            }
        }
        WHEN( "Encolo un 6 y un 7 y consulto el último dos veces") {
            q->enqueue( 6 ) ;
            q->enqueue( 7 ) ;
            auto item1 = q->peekBack() ;
            auto item2 = q->peekBack() ;
            THEN( "debería obtener un 7 ambas veces" ) {
                REQUIRE( item1 == 7 ) ;
                REQUIRE( item2 == 7 ) ;
            }
        }
        WHEN( "Encolo un 6 y un 7 y consulto el primero dos veces") {
            q->enqueue( 6 ) ;
            q->enqueue( 7 ) ;
            auto item1 = q->peekFront() ;
            auto item2 = q->peekFront() ;
            THEN( "debería obtener un 6 ambas veces" ) {
                REQUIRE( item1 == 6 ) ;
                REQUIRE( item2 == 6 ) ;
            }
        }
        WHEN ( "Está vacía y quiero desencolar" ) {
            auto item = q->dequeue() ;
            THEN( "qué debería obtener un error o un nullptr" ) {
                // REQUIRE( item == ? ) ;
            }
        }
    }
}