/*
- Programmer: Kai Schenkel
- Class: SD-247 Computer Architecture
- Data: 2/4/2024
- Project 2: Assembly Programming 
- Sources: KS_GuessingGame.java, Book from class: Computer Systems, Low Level Learning on Youtube and Geeks for Geeks
- Objective: Try and understand the basics of Assembly Programming and how it works with C or try to understand how it works in general
    Thing i find the hardest is understanding how the registers work and how to use them in the code
*/
#include <stdio.h>
int main()
{
    int a = 5;
    int b = 35;
    printf("Runinng the number through the four functions\n\n");
    int sumOfNums = addNums(a, b);
    printf("The addition function has been run\n");
    printf("The sum of the numbers is %d\n\n", sumOfNums);
    int diffOfNums = subNums(a, b);
    printf("The subtraction function has been run\n");
    printf("The difference of the numbers is %d\n\n", diffOfNums);
    int quotientOfNums = divNums(a, b);
    printf("The division function has been run\n");
    printf("The quotient of the numbers is %d\n\n", quotientOfNums);
    int productOfNums = multiNums(a, b);
    printf("The multiplication function has been run\n");
    printf("The product of the numbers is %d\n\n", productOfNums);
    printf("The numbers have been run though all the functions\n\n");
    return 0;
}

int addNums(int a, int b)
{
    printf("Numbers going though the Addition Function\n");
    return a + b;
}

int subNums(int a, int b)
{
    printf("Numbers going though the Subtraction Function\n");
    return a - b;
}

int multiNums(int a, int b)
{
    printf("Numbers going though the Multiplication Function\n");
    return a * b;
}

int divNums(int a, int b)
{
    printf("Numbers going though the Division Function\n");
    if (b == 0)
    {
        printf("Cannot divide by zero\n");
        return 0;
    }
    return a / b;
}

