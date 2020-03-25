#include <stdio.h> // for fopen, fclose, fread, fwrite, stdin, stdout

int
main(int argc, char **argv)
{
   // Loop through command line arguments.
   //
   for (int i=1; i<argc; ++i)
   {
      // Try to open the file.
      // 
      FILE *f = fopen(argv[i], "r");
      if (!f)
      {
         // There was an error.  Print the most recent error as a string.
         // argv[i] (the filename) will be used as a prefix to the error
         // message.
         //
         perror(argv[i]);
      }
      else
      {
         int r;
         char buf[4096];

         // Try to read the file, one chunk at a time.
         //
         while ((r = fread(buf, 1, sizeof(buf), f)))
         {
            // We got r bytes from fread().  Try to write.
            //
            int r2 = fwrite(buf, 1, r, stdout);
            if (r != r2)
            {
               // We seem to have written fewer bytes than we read?
               // Print an error.
               //
               perror("short write");
               break;
            }
         }

         // Flush buffered writes that may not have made it to disk.
         // Use this as an opportunity to check for errors.
         //
         if (fflush(stdout))
         {
            perror("write error");
            break;
         }

         // Close the file.
         //
         fclose(f);
      }
   }

   return 0;
}
