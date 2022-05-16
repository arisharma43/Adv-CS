 

# **AVL Insertion Lab**

The AVL insertion lab provides an opportunity to implement; 1) a node insertion method, 2) a node deletion method, and 3) a single right rotation.

Important points in main.cpp:

- A brief menu is provided that can direct input to the program from 1) stdin or 2) a file.  
    - Input is terminated by an empty line, or the word "END".
    - If you choose to use a file you may provide the name of a different file or simply hit <enter> to accept the default.   The default file includes a small array is provided in "data.txt" that can create a tree for debugging.  
    -    You may create other files for testing.
    -    The format for the data is <operation>:<data>  
        -    The <operation> may be;  
            - A|a - Add the integer value (ex. A: 10)
            - D|d - Delete the value from the tree (ex. d: 10)
