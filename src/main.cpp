#include <iostream>
#include "../include/lexer.h"
#include "../include/automate.h"

int main(void)
{
   string chain("(1+34)*123");

   Lexer lexer(chain);

   Symbol *symbol;
   while ((symbol = lexer.read())->getId() != END)
   {
      symbol->print();
      cout << endl;
      lexer.next();
   }

   Automate automate(chain);
   automate.print();
   automate.run();
   automate.print();
   return 0;
}
