#include <stdio.h>

#define USER_INPUT_MSG "Please insert two decimal numbers, use ENTER in between:\n"

int find_bits(unsigned long x, unsigned long y);
int get_numbers();
int print_numbers(long num);

int main() {

    int x;
    int y;

    printf(USER_INPUT_MSG);  
    
    x = get_numbers();  /* Gets the 1st number from user and prints it*/
    print_numbers(x);	
    
    y = get_numbers();  /* Gets the 2nd number from user and prints it*/
    print_numbers(y);
    
    find_bits(x,y);  /* Calculates how many bits is ON */

    return 0;
}

int get_numbers(){
    /* This function asks a number from the user and returns it */
    
    int num;

    scanf("%d",&num); 
    
    return num;
}

int print_numbers(long num){
    /* This function prints the number that was inserted by the user */
    
    printf("The number you inserted is: %ld\n",num);  
    return 0;
}

int find_bits(unsigned long x,unsigned long y){
    /* This function prints the number that was inserted by the user */
    
    int num_of_1 = 0;
    unsigned int mask = 1 << (sizeof(int)*8-1);

    /* Uses mask in order to indicate how many bits are ON */
    while (mask) {
        if (x & mask && y & mask)
            num_of_1 += 1;
        else
            num_of_1 += 0;
        mask = mask >> 1;
    }
    printf("\nThe number of the ON bits is: %d \n", num_of_1);
    return 0;
}
