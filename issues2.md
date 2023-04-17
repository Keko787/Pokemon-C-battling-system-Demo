For this project iteration, mainly the system's source code was reoriented for better understanding of the code, readability, and security, the file paths were hidden, 
and a bug with the oppenent ai when the tackle move is done which was discovered to be an exploit.

1. Consoladated all files into folders and updated the file paths of all files affected. This increases security because each folder can be compressed and encrypted if needed. 
2. Improved readability, added comments for each function, and made comments documenting certain sections of code. This change makes it easier to understand code and implementations, it also made code blocks and sections easier to read. It improve bug fixing and error removal.
3. Hiden file paths in the source code with definitions of file paths. This prevents the path of files being seen in the source code so threat actor won't know the location of the file or other files.
4. Fixed the tackle move so that the opponent ai performs their move as well. This was discovered to be an game exploit that gave the user an advantage which fulfulls the 14th criterion
