# Speller.C

In speller.c, we have created a program designed to check the spelling of a file after loading a dictionary of words from disk into memory. 
This dictionary, however, is implemented in a file called dictionary.c.
The prototypes for the functions in it, however, are defined not in dictionary.c itself, but in dictionary.h instead. 
That way, both speller.c and dictionary.c can include the file.
