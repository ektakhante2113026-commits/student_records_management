#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct student
{
    char first_name[20];
    char last_name[20];
    int roll_no;
    char branch[20];
    char address[30];
    float percentage;
};

void addStudent();
void displayStudents();

int main()
{
    int choice = 0;

    while (choice != 3)
    {
        printf("\n====================================================");
        printf("\n        STUDENT RECORD MANAGEMENT SYSTEM");
        printf("\n====================================================");

        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Exit");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            printf("\n\nPress any key to continue...");
            getch();
            break;

        case 3:
            printf("\nThank You!\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
            getch();
        }
    }

    return 0;
}

void addStudent()
{
    FILE *fp;
    struct student s;
    char choice;

    fp = fopen("information.txt", "a");

    if (fp == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    do
    {
        printf("\n------------ Add Student ------------\n");

        printf("First Name : ");
        scanf("%19s", s.first_name);

        printf("Last Name : ");
        scanf("%19s", s.last_name);

        printf("Roll Number : ");
        scanf("%d", &s.roll_no);

        printf("Branch : ");
        scanf("%19s", s.branch);

        printf("Address : ");
        scanf("%29s", s.address);

        printf("Percentage : ");
        scanf("%f", &s.percentage);

        fprintf(fp,
                "%-15s %-15s %-10d %-10s %-15s %.2f\n",
                s.first_name,
                s.last_name,
                s.roll_no,
                s.branch,
                s.address,
                s.percentage);

        printf("\nStudent record added successfully.");

        printf("\nDo you want to add another student? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    fclose(fp);
}

void displayStudents()
{
    FILE *fp;
    char ch;

    fp = fopen("information.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n==============================================================\n");
    printf("%-15s %-15s %-10s %-10s %-15s %s\n",
           "First Name",
           "Last Name",
           "Roll No",
           "Branch",
           "Address",
           "Percentage");
    printf("==============================================================\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }

    fclose(fp);
}
