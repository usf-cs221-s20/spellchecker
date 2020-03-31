#include <stdlib.h>  // for malloc
#include "trie.h"

static int trie_alloc(struct trie **trie)
{
   if (!*trie)
   {
      // Structure not initialized.  Allocate zeroed memory.
      //
      *trie = calloc(1, sizeof(**trie));
      if (!*trie)
         return -1;
   }
   return 0;
}

int trie_insert(struct trie **trie, const void *key, size_t keylen, void *data)
{
   const unsigned char *key_bytes = key;

   // Loop until there is no more key left.
   //
   while (keylen)
   {
      // Take 1 byte prefix of the key.  That will be our index into
      // the subtries.
      //
      int idx = *(key_bytes++);
      --keylen;

      // Make sure structure is allocated
      //
      if (trie_alloc(trie))
         return -1;

      trie = &(*trie)->subtries[idx];
   }

   // Make sure structure is allocated
   //
   if (trie_alloc(trie))
      return -1;

   // trie now points at the relevant subtree for our key, and it is allocated.
   // Assign data member.
   //
   (*trie)->data = data;

   return 0;
}

void *trie_lookup(struct trie *trie, const void *key, size_t keylen)
{
   const unsigned char *key_bytes = key;

   // Same loop as above, except:
   // We don't care about memory allocation.  Unallocated trie nodes
   //    will mean "not found".
   //
   while (keylen && trie)
   {
      int idx = *key_bytes++;
      --keylen;

      trie = trie->subtries[idx];
   }
   if (trie)
      return trie->data;
   return NULL;
}

void trie_free(struct trie **trie)
{
   // Make trie_free(NULL) or trie_free(pointer_to_null) not crash.
   // This makes caller's code simpler.
   //
   if (!trie || !*trie)
      return;

   // Free the subtries
   //
   for (int i = 0; i<256; ++i)
   {
      trie_free(&(*trie)->subtries[i]);
   }

   // Return memory to the heap.
   //
   free(*trie);

   // *trie is now invalid!  Accesing it is a bug.
   // Re-assign the caller's pointer to NULL, to ensure they don't
   // access a stale pointer.
   //
   *trie = NULL;
}
