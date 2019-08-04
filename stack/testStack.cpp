#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_FAST_COMPILE
#include "catch2/catch.hpp"
#include "iStack.h"
#include "Stack.cpp"

// g++ -std=c++11 -Wall testStack.cpp && ./testStack --reporter compact --success

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
    }
}