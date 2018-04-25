//-----------------------------------------------------------------------------------
// PROJECT      Special Task 2 - Parallel Merge Sort
// File		RandomArrayGenerator.c
// DESCRIPTION  C-Program for generating Ramdom Numbers to Test the MPI
//		Program. The Numbers are stored in a CSV (Comma Seperated File)
//		File 
//
//		
//		The Program is called as follows:
//		
//		./FileName Arg1 Arg2
//
//		FileName = Name of Program
//		Arg1 = Size of Array (e.g 100)
//		Arg2 = File where Numbers are stored (e.g TestData.csv)
//		
//		e.g: ./RandomArrayGenerator 100 TestData/Array_100.csv
//
// CREATED      23-Apr-2018, H.-N. Cocos - Frankfurt University of Applied Sciences
// MODIFIED     23-Apr-2018, H.-N. Cocos - Frankfurt University of Applied Sciences
//-----------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char **argv)
{

	// Read Size of Array and File Name
	int n = atoi(argv[1]);
	int *original_array = malloc(n * sizeof(int));
	
	int c;
	srand(time(NULL));

	printf("Generated Array of Size: %d\n in File: %s\n", n, argv[2]);

	// Generate Array of Random Numbers
	for(c = 0; c < n; c++) 
	{
		original_array[c] = rand() % n;
	}

	// Initialize Filepointer
	FILE *f = fopen(argv[2], "w"); 
 	if (f == NULL) return -1; 
	 
	// Write Random Numbers into File
        int count = n;
 	while (count-- > 0) 
	{ 
    		fprintf(f, "%d ", original_array[count]); 	 
	}
	
	printf("\n");
	
	// Very important free allocated memory of Array and close File!!!
	free(original_array);
	fclose(f);

	return 0;
	
}
