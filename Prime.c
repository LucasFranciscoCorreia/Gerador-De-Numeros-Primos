#include <stdio.h>
#include <math.h>

#define QNT 100000000
#define MAX pow(2, 32) - 1
int array[QNT];

/**
 * Checks if a given number is prime.
 *
 * @param n The number to check for primality.
 * @param count The number of elements in the array of known primes.
 * @return 1 if the number is prime, 0 otherwise.
 */
int isPrime(int n, int count){
    int square = sqrt(n);
    int prime = 1;
    for(int i = 1; i < count && array[i] <= square; i++){
        if(!(n % array[i])){
            prime = 0;
            break;
        }
    }
    return prime;
}

/**
 * @brief Adds a prime number to the array at the specified index.
 *
 * This function takes a prime number and an index, and stores the prime number
 * in the array at the given index.
 *
 * @param n The prime number to be added to the array.
 * @param count The index at which the prime number should be stored in the array.
 */
void addPrime(int n, int count){
    array[count] = n;
}

/**
 * @file Primo.c
 * @brief This file contains the implementation of a prime number generator.
 *
 * The program initializes an array with the first four prime numbers (2, 3, 5, 7)
 * and then continues to find and add prime numbers to the array using a specific pattern.
 * The pattern checks numbers of the form i, i+2, i+6, and i+8, where i starts at 11 and increments by 10.
 * 
 * The program uses the functions isPrime() to check if a number is prime and addPrime() to add a prime number to the array.
 * 
 * @return Returns 1 upon successful completion.
 */
int main(){
    array[0] = 2;
    //printf("1 - 2\n");
    array[1] = 3;
    //printf("2 - 3\n");
    array[2] = 5;
    //printf("3 - 5\n");
    array[3] = 7;
    //printf("4 - 7\n");
    
    int count = 4;

    for(int i = 11; count <= QNT && i <= MAX-10; i = i + 10){
        if(isPrime(i, count)){
            //printf("%d - %d\n", count+1, i);
            addPrime(i, count);
            count++;
        }
        if(isPrime(i + 2, count)){
            //printf("%d - %d\n", count+1, i+2);
            addPrime(i + 2, count);
            count++;
        }
        if(isPrime(i + 6, count)){
            //printf("%d - %d\n", count+1, i+6);
            addPrime(i + 6, count);
            count++;
        }
        if(isPrime(i + 8, count)){
            //printf("%d - %d\n", count+1, i+8);
            addPrime(i + 8, count);
            count++;
        }        
    }
    return 1;
}
