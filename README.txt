Description:
This program was designed to run on ORNLs Kraken, and did so successfully.
MPI is leveraged to allow program to scale over multiple processors.
A number of different texts are all compared to one another.
a number between 0 and 1 is assigned to each set to denote similarity.

Note:
This project was created in haste and as such is missing appropriate comments and contains some obvious flaws in efficiency.

Process:
One processor is reserved to managed others.
Program begins by having each processor convert one to many texts to a hash table.
After each hash table is complete it is written to disk then freed from memory, conserving memory.
After all processors have completed, next task begins.
Each processor reads in one to many hash tables from disk and compares to each other hash table.
Load of each processor depends on number of processors and number of books.

Running:
Enter command "make install" to download texts and prepare application to run
Executable and necessary files are placed in /bin
Texts to be compared are downloaded according to /src/bookList.dat
Alternative texts may be used given bookNames.dat is updated accordingly

To run enter command:
./compareTexts bookList.dat