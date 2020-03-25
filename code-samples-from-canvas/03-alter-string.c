#include <stdio.h>   // for fgets, stdin, printf
#include <string.h>  // for strlen
#include <ctype.h>   // for toupper/to/lower

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

      for (int i = 0; i<len; ++i)
      {
         // Convert lowercase vowels to uppercase.
         // Convert uppercase vowels to lowercase.
         // Perform "ROT-13" on others.
         // 
         if (strchr("aeiou", buf[i]))
            buf[i] = toupper(buf[i]);
         else if (strchr("AEIOU", buf[i]))
            buf[i] = tolower(buf[i]);
         else
            buf[i] += 13;
      }

      printf("%s\n", buf);
   }

   return 0;
}
