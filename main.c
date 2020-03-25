#include <stdio.h>

#include "trie.h"

int main(int argc, char **argv)
{
   struct trie *t = NULL;

   // TODO: place your project code here.
   // example of usage of trie data structure follows

   if (trie_insert(&t, "hello", 5, "hi guys"))
      fprintf(stderr, "insert failed\n"); 

   if (trie_lookup(t, "hello", 5))
      printf("hello is in trie\n");

   trie_free(&t);
   return 0;
}
