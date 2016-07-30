#include "catch.hpp"
#include "../ConsoleProgress.h"

TEST_CASE("Foo")
{
	ConsoleProgress consoleProgress;
	REQUIRE(2 * 2 == 4);
}
