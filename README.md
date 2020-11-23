# Recover 
Implementing a program that recovers JPEGs from a forensic image

## Specification
Implement a program called recover that recovers JPEGs from a forensic image.

Implement your program in a file called recover.c in a directory called recover.
* Program should accept exactly one command-line argument, the name of a forensic image from which to recover JPEGs
* Program is not executed with exactly one command-line argument, it should remind the user of correct usage, and main should return 1.
* If the forensic image cannot be opened for reading, program should inform the user as much, and main should return 1.
* If it uses malloc, program must not leak any memory.

##
Pseudocode
* Open Memory card
* Repeat until end of card:
Read 512 bytes into a buffer
If start of new JPEG
  ...
 Else
  ...
Else
  If already found JPEG
 ...

# Filter
Implementing a program that applies filters to BMPs

## Specification 
Implement the functions in helpers.c such that a user can apply grayscale, sepia, reflection, or blur filters to their images.

* The function grayscale should take an image and turn it into a black-and-white version of the same image.
* The function sepia should take an image and turn it into a sepia version of the same image.
* The reflect function should take an image and reflect it horizontally.
* Finally, the blur function should take an image and turn it into a box-blurred version of the same image.
