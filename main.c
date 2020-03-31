#include <stdio.h>
#include <string.h>

#include "trie.h"


int main(int argc, char **argv)
{
   struct trie *t = NULL;
   char buff[1048576] = {0};

   FILE* dictionary = fopen("/usr/share/dict/words", "r");

   if(!dictionary)
   {
      perror("failed"); //fix for more description
      return -1;
   }
   
   while (fgets(buff, sizeof buff, dictionary))
   {
      trie_insert(&t, buff, strlen(buff) - 1, (void*) 1);
      
   }

   for (int i = 1; i < argc; i++)
   {
      FILE *f = fopen(argv[i], "r");

      if (!f)
      {
         perror(argv[i]);
      }
      else
      {
         
         while (fgets (buff, sizeof(buff), f))
         {
            const char *current = buff;
            const char *p;
            const char *stop = " .,!?\t\r\n";
            
            while ((p = strpbrk(current, stop))) {
       
               //lookup letters in buff from current to the end of strpbrk()
               if (trie_lookup(t, current,  p - current) == NULL) { 

                  while (current != p) { //print out word if it is not in dictionary
                     printf("%c", *current);
                     current++;
                  }
               }
               printf("\n");
                while (strchr(stop, *current) != NULL) {
                  current++;
               }
            }
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
