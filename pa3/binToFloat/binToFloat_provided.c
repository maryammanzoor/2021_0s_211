#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int power(int base, int exponent){
	int result=1;
	for(exponent; exponent>0; exponent--){
		result = result * base;
	}
	return result;
}

typedef union { 

        float f; 
        struct
        { 


                unsigned int m : 23; 
                unsigned int e : 8; 
                unsigned int sign : 1; 

        } stu; 
} myfloat; 


unsigned int convertToInt(int* arr, int low, int high) 
{ 
        unsigned f = 0, i; 
        for (i = high; i >= low; i--) { 
                f = f + arr[i] * power(2, high - i); 
        } 
        return f; 
} 


int main(int argc, char *argv[]) 
{ 

	    FILE* fp = fopen(argv[1], "r");
    	if (!fp) {
        	perror("fopen failed");
        	return EXIT_FAILURE;
    	}
        // Get the 32-bit floating point number 
        unsigned int input[32] ;
        int i ;
        
        for(i = 0 ; i<32 ;i++){
        	input[i]=((char)fgetc(fp)-'0');
                // scanf("%d",&input[i]);
        }

        myfloat var; 


        unsigned f = convertToInt(input, 9, 31); 

        var.stu.m = f; 


        f = convertToInt(input, 1, 8); 

 
        var.stu.e = f; 


        var.stu.sign = input[0]; 

        printf("The float value of the given"
                " IEEE-754 representation is : \n"); 
        printf("%f", var.f); 
} 
