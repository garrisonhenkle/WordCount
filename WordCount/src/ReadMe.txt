g++ *.cpp -o Main

Commands
-----------
Compilation: g++ *.cpp -o Main

-	Compiles the program to the script Main

Running: ./Main arg1 arg2 arg3 argn

-	./ Main can be followed by n number of args containing string filenames

- 	Examples: ./Main test1.txt test2.txt test3.txt test4.txt test5.txt
-		  ./Main test1.txt
-		  ./Main test1.bi test2.uni


Notes
-------------
-	All unigrams and bigrams are output to the files text.uni and text.bi respectively

-	The processing time of all files will be output to the text.time file

-	text.uni contains all monograms paired with their counts

-	text.bi contains all bigrams paired with their counts and probabilities

-	For multiple file inputs (ex: ./Main text1.txt text2.txt), the bigram and monograms of every additional file will be appended to the end of the file, separated by two lines ('\n' characters)

