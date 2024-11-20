# tbags-in-cpp

A small framework I made to make text based adventure games in CPP using the sfml library.

It works by making use of scene files => .tbags(text based adventure game scene) files. 

Each .tbags file contains information about which image should be displayed in the background, what text should be shown to the user, and what choices the user can make and which .tbags files those choices point to.

Syntax:
  In each .tbags file you can furnish the above particulars using the following syntaxes:

  -To select background images: G BG <relative-path-to-img>
  -To display a line of text: T "<text>"
  -To give a choice: C "<choice-text>" <relative-path-to-tbags-file>
