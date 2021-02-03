#include <iostream>
#include "../include/lexer.h"
#include "../include/automate.h"

int main(void)
{
   string chain("(1+34)*123");

   Lexer l(chain);

   // Test
   Symbol *s;
   while ((s = l.read())->getId() != END)
   {
      s->print();
      l.next();
   }

   // Resolve
   Automate automate(chain);
   automate.print();
   automate.run();
   automate.print();
   return 0;
}
