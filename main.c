#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
      for(int i = 0; buff[i]; i++){
         if (isupper(buff[i]) > 0){
          buff[i] = tolower(buff[i]);
         }
      }
   

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
            size_t len = strlen(buff);
            buff[len] = '\n';
            buff[len + 1] = 0; //always adds null char to end of file in order to include all
            for(int i = 0; buff[i]; i++){
               if (isupper(buff[i]) > 0){
               buff[i] = tolower(buff[i]);
               }
            }
            char *current = buff;
            char *p;
            const char *stop = " .,!?\t\r\n";
            
            
            while ((p = strpbrk(current, stop))) {

               //lookup letters in buff from current to the end of strpbrk()
               if (trie_lookup(t, current,  p - current) == NULL) { 

                  while (current != p) { //print out word if it is not in dictionary
                     printf("%c", *current);
                     current++;
                  }
                  printf("\n");
               }

               current = p;

               while (strchr(stop, *current) != NULL) {
                  current++;
               }
            }
         }
      }
   }
  
   trie_free(&t);
   return 0;
}
