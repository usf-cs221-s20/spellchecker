// This part will prevent us from getting bad results if we #include twice
// Google the term "include guard" for context.
#ifndef trie_h_
#define trie_h_

#include <stddef.h>   // for size_t

//
// Types:
//

struct trie
{
   void *data;
   struct trie *subtries[256];
};

//
// Functions:
//

int trie_insert(struct trie **trie, const void *key, size_t keylen, void *data);

void *trie_lookup(struct trie *trie, const void *key, size_t keylen);

void trie_free(struct trie **trie);

// End of include guard:
#endif
