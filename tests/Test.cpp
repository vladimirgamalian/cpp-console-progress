#include "catch.hpp"
#include "../ConsoleProgress.h"

TEST_CASE("Foo")
{
	ConsoleProgress consoleProgress(100);
	
	REQUIRE(progress.bar(0).length() == 0);
	REQUIRE(progress.bar(40).length() == 40);
	REQUIRE(progress.bar(80).length() == 80);
}
