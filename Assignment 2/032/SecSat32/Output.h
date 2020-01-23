#pragma once

#include "Console.h"
#include "Point.h"

// Wraps the console methods within static methods, handles all output
class Output
{
   public:
      // Prints a string starting from a given position, in the colours specified
	   static void PrintString(const Point position, const char* const toPrint, const Console::COLOUR foreground = Console::WHITE, const Console::COLOUR background = Console::BLACK);

      // Prints a single character in a given position, in the colours specified
      static void PrintCharacter(const Point position, const char toPrint, const Console::COLOUR foreground = Console::WHITE, const Console::COLOUR background = Console::BLACK);

      // Prints a number in a given position, in the colours specified
      // Automatically accounts for increasing number of digits
      static void PrintNumber(const Point position, const int toPrint, const Console::COLOUR foreground = Console::WHITE, const Console::COLOUR background = Console::BLACK);

      // Draws a box of the dimensions given at a specified point, in the colours given
	   static void DrawBox(const int width, const int height, const Point topLeftCorner = m_offset, const Console::COLOUR foreground = Console::WHITE, const Console::COLOUR background = Console::BLACK);

      // Draws an area of colour, specified by a top-left and bottom-right point
      static void DrawBackground(const Console::COLOUR colour, const Point topLeft, const Point bottomRight);

      // Hides the cursor in the console window and sets the title of the console window
      static void SetConsoleInfo();

   private:
      // Gets the number to move a point left by to account for extra digits when printing a number
      static int GetPrintNumberOffset(int number);

      // Member variables
	   static Console m_console;           // The console object whose methods are being wrapped to be used like static methods
	   static Point m_offset;              // The top-left corner position of the petri dish
      static const int m_borderWidth = 1; // The border with of the petri dish to be drawn
};


