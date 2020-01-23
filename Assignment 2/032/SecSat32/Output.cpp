#include "Output.h"

Console Output::m_console(77, 34);
Point Output::m_offset(40, 1);

void Output::PrintString(const Point position, const char* const toPrint, const Console::COLOUR foreground, const Console::COLOUR background)
{
   // Apply offset to point
	int x = position.X + m_offset.X + m_borderWidth;
	int y = position.Y + m_offset.Y + m_borderWidth;

	m_console.setColour(foreground, background);
	m_console.gotoXY(x, y);
	cout << toPrint;
}

void Output::PrintCharacter(const Point position, const char toPrint, const Console::COLOUR foreground, const Console::COLOUR background)
{
   // Apply offset to point
   int x = position.X + m_offset.X + m_borderWidth;
   int y = position.Y + m_offset.Y + m_borderWidth;

   m_console.setColour(foreground, background);
   m_console.gotoXY(x, y);
   cout << toPrint;
}

void Output::PrintNumber(const Point position, const int toPrint, const Console::COLOUR foreground, const Console::COLOUR background)
{
   // Apply offset to point
   int x = position.X + m_offset.X + m_borderWidth;
   int y = position.Y + m_offset.Y + m_borderWidth;
   x += GetPrintNumberOffset(toPrint); // Offset the x position depending on the number of digits in the number

   m_console.setColour(foreground, background);
   m_console.gotoXY(x, y);
   cout << toPrint;
}

void Output::DrawBox(const int width, const int height, const Point topLeftCorner, const Console::COLOUR foreground, const Console::COLOUR background)
{
	m_console.setColour(foreground, background);

	// Console coordinates
	const int left = topLeftCorner.X;
	const int right = left + (width + 1);
	const int top = topLeftCorner.Y;
	const int bottom = top + (height + 1);

	// Drawing characters
	const char topLeft = char(201);
	const char topRight = char(187);
	const char bottomLeft = char(200);
	const char bottomRight = char(188);
	const char horizontal = char(205);
	const char vertical = char(186);
	const char empty = ' ';

   // Draw corner
	m_console.gotoXY(left, top);
	cout << topLeft;

   // Draw top
	for (int loop = 0; loop < width; loop++)
	{
		cout << horizontal;
	}

   // Draw corner
	cout << topRight;

   // Draw sides
	for (int loop = 0; loop < height + 1; loop++)
	{
		int height = top + 1 + loop;
		m_console.gotoXY(left, height);
		cout << vertical;
		m_console.gotoXY(right, height);
		cout << vertical;
	}

   // Draw corner
	m_console.gotoXY(left, bottom);
	cout << bottomLeft;

   // Draw bottom
	for (int loop = 0; loop < width; loop++)
	{
		cout << horizontal;
	}

   // Draw corner
	cout << bottomRight;

	// Give inside of box the correct background
	for (int loop = 0; loop < height; ++loop)
	{
		m_console.gotoXY(topLeftCorner.X + m_borderWidth, topLeftCorner.Y + loop + m_borderWidth);

		for (int innerLoop = 0; innerLoop < width; ++innerLoop)
		{
			cout << empty;
		}
	}
}

void Output::DrawBackground(const Console::COLOUR colour, const Point topLeft, const Point bottomRight)
{
	m_console.setColour(colour, colour);
	m_console.gotoXY(topLeft.X, topLeft.Y);
	const char empty = ' ';

	for (int loop = 0; loop < bottomRight.Y; ++loop)
	{
		for (int innerLoop = 0; innerLoop < bottomRight.X; ++innerLoop)
		{
			cout << empty;
		}
	}
}

void Output::SetConsoleInfo()
{
   // Set console window title
   //SetConsoleTitle(L"EvoMunch");                   

   // Hide console window cursor
   HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO cursorInfo;
   cursorInfo.bVisible = false;
   cursorInfo.dwSize = 20;
   SetConsoleCursorInfo(console, &cursorInfo);       
}

int Output::GetPrintNumberOffset(int number)
{
   int offset = 0;

   while (number >= 10)
   {
      number /= 10;
      --offset;
   }

   return offset;
}


