#include <stdio.h>
#include <string.h>

#include "trie.h"

int main(int argc, char **argv)
{
   struct trie *t = NULL;
   char buff[256] = {0};

   FILE* dictionary = fopen("/usr/share/dict/words", "r");
   
   while (fgets(buff, sizeof buff, dictionary))
   {
      trie_insert(&t, buff, strlen(buff) - 1, (void*) 1);
      
   }

   for (int i = 0; i < argc; i++)
   {
      FILE *f = fopen(argv[i], "r");

      if (!f)
      {
         perror(argv[i]);
      }
      else
      {
         int r;
         while((r = fread(buff, 1, sizeof(buff), f)))

            trie_lookup(t, buff,  strlen(buff) - 1);
         }
      }
   }





   // TODO: place your project code here.
   // example of usage of trie data structure follows

   // if (trie_insert(&t, "hello", 5, "hi guys"))
   //    fprintf(stderr, "insert failed\n"); 

   // if (trie_lookup(t, "hello", 5))
   //    printf("hello is in trie\n");

   trie_free(&t);
   return 0;
}
