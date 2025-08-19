/*
Lab Activity Number	: 5.2
Lab Activity Title	: Looping Statements (Assignment)

Date Performed		: June 06, 2024
Date Submitted		: June 06, 2024

Machine Problem:
Collatz Sequence
The Collatz conjecture is a conjecture in mathematics named after Lothar Collatz, who first proposed it in 1937. The conjecture is also known as the 3n + 1 conjecture,
the Ulam conjecture (after Stanisław Ulam), Kakutani’s problem (after Shizuo Kakutani), the Thwaites conjecture (after Bryan Thwaites), Hasse’s algorithm (after Helmut Hasse), 
or the Syracuse problem; the sequence of numbers involved is referred to as the hailstone sequence or hailstone numbers (because the values are usually subject 
to multiple descents and ascents like hailstones in a cloud), or as wondrous numbers.

Mathematics
The Collatz function is defined for a positive integer n as follows.
 
f(n) = 3n+1 if n is odd
        n/2    if n is even
 
We consider the repeated application of the Collatz function starting with a given integer n, as follows:
f(n), f(f(n)), f(f(f(n))), …
 
It is conjectured that no matter which positive integer n you start from, this sequence eventually will have 1 in it. It has been verified to hold for numbers up to 5 × 260 [Wikipedia: Collatz Conjecture]. 
If n=7, the sequence is
1.	f(7) = 22
2.	f(f(7)) = f(22) = 11
3.	f(11) = 34
4.	f(34) = 17
5.	f(17) = 52
6.	f(52) = 26
7.	f(26) = 13
8.	f(13) = 40
9.	f(40) = 20
10.	f(20) = 10
11.	f(10) = 5
12.	f(5) = 16
13.	f(16) = 8
14.	f(8) = 4
15.	f(4) = 2
16.	f(2) = 1
Thus if you start from n=7, you need to apply f 16 times in order to first get 1.
In this question, you will be given a positive number <= 32,000.
You have to output how many times f has to be applied repeatedly in order to first reach 
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int no;

    printf("Enter a number:\n");
    scanf("%d", &no);

    while(no > 1)
    {
        if (no % 2 == 0)
        {
            no = no / 2;
            printf("%d\n", no);
        }

        else
        {
            no = no * 3 + 1;
            printf("%d\n", no);
        }
    }
    getch();
    return 0;
}