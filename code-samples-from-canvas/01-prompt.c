#include <stdio.h>   // for fgets, stdin, printf
#include <string.h>  // for strlen

int main()
{
   char buf[4096];

   while (fgets(buf, sizeof(buf), stdin) != NULL)
   {
      size_t len = strlen(buf);
      if (len > 0 && buf[len-1] == '\n')
      {
         buf[len-1] = 0;
         --len;
      }

      printf("%s\n", buf);
   }

   return 0;
}
