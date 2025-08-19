/*
Lab Activity Number	: 7
Lab Activity Title	: Strings

Date Performed		: July 18, 2024
Date Submitted		: July 18, 2024

Machine Problem:
Enhanced security and anti-fraud protection 

Use of string functions
System is encrypted with username and password
Password characters will change into asterisk per input
If the username and password are correct, display “VALID” otherwise “INVALID”


Example:

Username: ilovebokskie
Password: ******

VALID!
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>

void hidepassword(char* pass) 
{
    int i = 0;
    char c;
    while (1) 
    {
        c = getch(); 

        if (c == 13) 
        {
            pass[i] = '\0';
            break;
        } 
        else if (c == 8) 
        { 
            if (i > 0) 
            {
                i--;
                printf("\b \b"); 
            }
        } 
        else 
        {
            pass[i++] = c;
            printf("*");
        }
    }
}

int main(int argc, char *argv)
{
    char user[10];
    char pass[10];
    int u, p;

    printf("Enter username: ");
    gets(user);

    printf("Enter password: ");
    hidepassword(pass);

    u = strcmp(user,"DLSU");
    p = strcmp(pass,"Id123");

    if (u == 0 && p == 0)
    puts("\n\nVALID");
    
    else
    puts("\n\nINVALID");
  
    getch();
    return 0;
}