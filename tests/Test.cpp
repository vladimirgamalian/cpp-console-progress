#include "catch.hpp"
#include "../ConsoleProgress.h"

TEST_CASE("Foo")
{
	ConsoleProgress p(100);
	
	REQUIRE(p.bar(0).length() == 0);
	REQUIRE(p.bar(40).length() == 40);
	REQUIRE(p.bar(80).length() == 80);
	
	REQUIRE(p.bar(10).bar() == "----------");
	p.set(50);
	REQUIRE(p.bar(10).bar() == "=====-----");
	p.set(100);
	REQUIRE(p.bar(10).bar() == "==========");
}
