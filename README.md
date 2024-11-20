# tbags-in-cpp

A small framework I made to make text based adventure games in CPP using the sfml library.

It works by making use of scene files => .tbags(text based adventure game scene) files. 

Each .tbags file contains information about which image should be displayed in the background, what text should be shown to the user, and what choices the user can make and which .tbags files those choices point to.

You can press N to show/hide the text

An example scene is setup; it should run on running main.exe provided sfml is also there

* Will require you to download sfml on your own and save it to the same folder as the main.exe
  

Syntax:
  In each .tbags file you can furnish the above particulars using the following syntaxes:

  -To select background images: G BG <relative-path-to-img>
  -To display a line of text: T "<text>"
  -To give a choice: C "<choice-text>" <relative-path-to-tbags-file>


Limiations:
-Does not have support for variables for keeping track of prior choices.
-Requires sfml be installed seperately.
