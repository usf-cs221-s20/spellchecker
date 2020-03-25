# CS221 - C and Systems Programming
# Project 1: Spell checker

### Due date: 2 April 2020

## Synopsis

A typical Unix system contains a dictionary at `/usr/share/dict/words`,
which contains a word list in alphabetical order, separated by newlines.

Your goal with this project is to take a text file on the command line, and
print out each misspelled word in the text.

## Usage

We should be able to build your program on the CS Linux machines by typing
`make`.

After this, we should be able to run your program as:

        ./spell-check foo.txt

Where `foo.txt` is a path to a text file.

Your program should print each misspelled word, line-at-a-time.

## Description of suggested implementation

This repo is prepopulated with the makefile skeleton from `17-makefiles.zip` on Canvas.
You may use the trie implementation that was written for you in lecture, provided here.

You may call `fopen` on `/usr/share/dict/words`, as in the code sample `08-cat.c`
on Canvas.  You may `fgets` on this file to read the words line at a time, similar to
`01-prompt.c`, and use `trie_insert()` to store the dictionary in a trie.

Once the dictionary is loaded, you will want to use `fopen` on the file
in the command line.  (Again see `08-cat.c` for examples of using command 
line arguments.)  You may use a technique similar to `13-tokenize-lab.c`
to break the text into words, and `trie_lookup()` to determine if each
word is in the dictionary.

Please note you may need to break across not only spaces but also punctuation,
and that you may need to normalize strings for case.  You can use `isupper()`
and `tolower()` from `ctype.h` to force lower-case, similar to `03-alter-string.c`.

## Evaluation

Points may be deducted for:

* Failure to flag misspelled words
* Memory leaks
* Failure to close a file
* Possible memory bugs such as those leading to segmentation fault
* Lack of comments
* Inconsistent formatting
* Lack of a working Makefile
* Failure to compile

*5 points extra credit* If your project compiles with `-Wall -Werror`
(enables extra warnings and compiler errors).
You can set the Makefile variable `CFLAGS` for this.

