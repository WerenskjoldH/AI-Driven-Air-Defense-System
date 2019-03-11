#ifndef CONSOLE_COLORIZER_H
#define CONSOLE_COLORIZER_H

#include <Windows.h>
#include <iostream>

/*
	This is a singleton class that exists to colorize the text of window's consoles.
	TODO: 
		- Perhaps extend functionality to encapsulate all output?
		- Rename?
*/

class Colorizer
{
public:
	static Colorizer& getInstance()
	{
		// This will instantiate on the first call and then always return the same instance ( also able to be destroyed! )
		static Colorizer instance;
		return instance;
	}

	// This is a C++11 feature that prohibits the copying of a method
	// We are able to ensure the method is inaccessible in all cases as the compiler will not even bother to generate the function
	// P.S. this is only allowed for this case, if you want a purely virual method set "= 0"
	Colorizer(Colorizer  const&)	 = delete;
	void operator=(Colorizer const&) = delete;

	// c is a value from 0 to 15:
	/*
		0	-	BLACK
		1	-	BLUE
		2	-	GREEN
		3	-	CYAN
		4	-	RED
		5	-	MAGENTA
		6	-	BROWN
		7	-	LIGHT GRAY
		8	-	DARK GRAY
		9	-	LIGHT BLUE
		10	-	LIGHT GREEN
		11	-	LIGHT CYAN
		12	-	LIGHT RED
		13	-	LIGHT MAGENTA
		14	-	YELLOW
		15	-	WHITE
	*/
	void setTextColor(int c)
	{
		if (c < 0 || c > 15)
		{
			printf("ERROR::COLORIZER::Please keep text color in the integer set [0, 15]");
		}

		SetConsoleTextAttribute(consoleHandler, c);
	}

private:
	HANDLE consoleHandler;
	Colorizer()
	{
		consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	}


};

#endif // !CONSOLE_COLORIZER_H