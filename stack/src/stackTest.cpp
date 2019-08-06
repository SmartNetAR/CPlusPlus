#include "iStack.h"
#include "Stack.cpp"
#include "testHeader.cpp"


// g++ -std=c++11 -Wall stackTest.cpp && ./stackTest --reporter compact --success

SCENARIO( "Stack puede apilar", "" ) {
    GIVEN( "Una instancia de Stack" ) {
        iStack* s = new Stack( 10 ) ;
        WHEN( "Apilo un 5") {
            s->push( 5 );
            Type item = s->pop() ;
            THEN( "debería obtener un 5" ) {
                REQUIRE( item == 5 ) ;
            }
        }
        WHEN( "Apilo un 9") {
            s->push( 9 );
            Type item = s->pop() ;
            THEN( "debería obtener un 9" ) {
                REQUIRE( item == 9 ) ;
            }
        }
        WHEN( "Apilo un 5 y un 9") {
            s->push( 5 );
            s->push( 9 );
            Type item1 = s->pop() ;
            Type item2 = s->pop() ;
            THEN( "debería obtener un 9 y un 5" ) {
                REQUIRE( item1 == 9 ) ;
                REQUIRE( item1 == 9 ) ;
            }
        }
    }
}