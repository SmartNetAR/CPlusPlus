#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_FAST_COMPILE
// "BDD-style" convenience wrappers
// #define SCENARIO( ... ) TEST_CASE( "Scenario: " __VA_ARGS__ )
// #define SCENARIO_METHOD( className, ... ) INTERNAL_CATCH_TEST_CASE_METHOD( className, "Scenario: " __VA_ARGS__ )

// #define GIVEN( desc )    SECTION( std::string("   Given: ") + desc )
// #define WHEN( desc )     SECTION( std::string("    When: ") + desc )
// #define AND_WHEN( desc ) SECTION( std::string("And when: ") + desc )
// #define THEN( desc )     SECTION( std::string("    Then: ") + desc )
// #define AND_THEN( desc ) SECTION( std::string("     And: ") + desc )

#include "catch2/catch.hpp"