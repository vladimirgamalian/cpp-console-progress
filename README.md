[![Build Status](https://travis-ci.org/vladimirgamalian/cpp-console-progress.svg?branch=master)](https://travis-ci.org/vladimirgamalian/cpp-console-progress)

# cpp-console-progress

```c++
#include <iostream>
#include <thread>
#include "ConsoleProgress.h"

int main()
{
	ConsoleProgress prgs(100);

	for (int i = 0; i < 100; ++i)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		prgs.step();
		std::cout << "Download [" 
			<< prgs.bar(40) << "] " 
			<< prgs.percent() << "% " 
			<< prgs.eta() << "s  \r";
	}
	std::cout << std::endl;
}
```

will produce:

```
Download [==============--------------------------] 34% 2.6s
```
