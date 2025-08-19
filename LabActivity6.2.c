/*
Lab Activity Number	: 6.2
Lab Activity Title	: One Dimensional Array (Assignment)

Date Performed		: July 12, 2024
Date Submitted		: July 12, 2024

Machine Problem:
Write a program for grade computation. The final grade should be computed using the formula:
	
FinalGrade= 20% Recitation + 35% Quizzes + 40% FinalExam + 5% Evaluation. 

The number of student is a variable. 
The inputs are student number, recitation grade, average of quizzes, final exam grade and teacher’s evaluation, and of course the number of students.  
The output should be tabulated as shown below if the number of student is equivalent to 3:
WARNING:  if the input grade is higher than 100 and lower than 0, it will print a message to enter correct grade. 

Sample Input
Enter number of students: 3
Enter Student Number: 101
Enter Recitation: 999
Enter Recitation: 100

Enter Quizzes: 100
Enter Final Exam: 100
Enter Evaluation: 1000
Enter Evaluation: 100

Enter Student Number: 102
Enter Recitation: 69

Enter Quizzes: 699
Enter Quizzes: 69

Enter Final Exam: 69
Enter Evaluation: 69



Enter Student Number: 103
Enter Recitation: 50

Enter Quizzes: 50

Enter Final Exam: 50
Enter Evaluation: 50
*/

#include <stdio.h>

typedef struct 
{
    int studentno;
    float recitation;
    float quizzes;
    float exam;
    float eval;
    float final;
} student;

float finalcompute(float recitation, float quizzes, float finals, float evaluation) 
{
    return (0.20 * recitation) + (0.35 * quizzes) + (0.40 * finals) + (0.05 * evaluation);
}

void invalidgrade(float *grade, const char *prompt) 
{
    do {
        printf("%s (0-100): ", prompt);
        scanf("%f", grade);
        if (*grade < 0 || *grade > 100) 
        {
            printf("Invalid grade. Please enter a grade between 0 and 100.\n");
        }
    } while (*grade < 0 || *grade > 100);
}

int main() 
{
    int i, no;
    
    printf("Enter the number of students: ");
    scanf("%d", &no);
    
    student students[no];
    int failed[no];
    int nofailed = 0;

    for (i = 0; i < no; i++) 
    {
        printf("\nEnter Student Number: ");
        scanf("%d", &students[i].studentno);
        invalidgrade(&students[i].recitation, "Enter Recitation");
        invalidgrade(&students[i].quizzes, "Enter Quizzes");
        invalidgrade(&students[i].exam, "Enter Final Exam");
        invalidgrade(&students[i].eval, "Enter Evaluation");
        
        students[i].final = finalcompute(students[i].recitation, students[i].quizzes, students[i].exam, students[i].eval);

        if (students[i].final < 60.0) 
        {
            failed[nofailed] = students[i].studentno;
            nofailed++;
        }
    }

    printf("\nFinal Grades:\n");
    for (i = 0; i < no; i++) 
    {
        printf("Student Number: %d, Final Grade: %.2f\n", students[i].studentno, students[i].final);
    }

    printf("\nNumber of failed students: %d\n", nofailed);
    if (nofailed > 0) 
    {
        printf("Student Numbers of failed students: ");
        for (i = 0; i < nofailed; i++) 
        {
            printf("%d ", failed[i], "\n");
        }
    }
    getch();
    return 0;
}