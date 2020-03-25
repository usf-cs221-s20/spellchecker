#include <stdio.h>   // for fgets, puts
#include <string.h>  // for strpbrk

int main()
{
   char buf[4096];

   while (fgets(buf, sizeof(buf), stdin))
   {
      char *p = buf;
      char *q;

      while ((q=strpbrk(p, " \t\r\n")))
      {
         *q++ = 0;
         if (*p)
            puts(p);
         p = q;
      }

      if (*p)
         puts(p);
   }

   return 0;
}
