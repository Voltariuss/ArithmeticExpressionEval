#include <iostream>
#include "../include/lexer.h"
#include "../include/automate.h"

int main(int argc, char *argv[])
{
   if (argc > 2)
   {
      cout << "Error: invalid number of args (max 2 allowed)" << endl;
      return EXIT_FAILURE;
   }
   string chain;
   if (argc == 1)
   {
      chain = "(1+34)*123";
   }
   else if (argc == 2)
   {
      chain = argv[1];
   }
   Automate automate(chain);
   automate.run();
   return EXIT_SUCCESS;
}
