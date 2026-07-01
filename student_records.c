#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct student
{
    int rollNo;
    char firstName[20];
    char lastName[20];
    char branch[20];
    char address[30];
    float percentage;
};

void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();

int main()
{
    int choice;

    while (1)
    {
        printf("\n=====================================================\n");
        printf("         STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("=====================================================\n");

        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            printf("\nThank You!\n");
            exit(0);

        default:
            printf("\nInvalid Choice!\n");
        }

        printf("\nPress any key to continue...");
        getch();
    }

    return 0;
}

void addStudent()
{
    FILE *fp;
    struct student s;
    char choice;

    fp = fopen("students.dat", "ab");

    if (fp == NULL)
    {
        printf("\nUnable to open file!\n");
        return;
    }

    do
    {
        printf("\n------------ Add Student ------------\n");

        printf("Enter Roll Number : ");
        scanf("%d", &s.rollNo);

        printf("Enter First Name : ");
        scanf("%19s", s.firstName);

        printf("Enter Last Name : ");
        scanf("%19s", s.lastName);

        printf("Enter Branch : ");
        scanf("%19s", s.branch);

        printf("Enter Address : ");
        scanf("%29s", s.address);

        printf("Enter Percentage : ");
        scanf("%f", &s.percentage);

        fwrite(&s, sizeof(struct student), 1, fp);

        printf("\nStudent record added successfully.\n");

        printf("\nDo you want to add another student? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    fclose(fp);
}

void displayStudents()
{
    FILE *fp;
    struct student s;
    int found = 0;

    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n========================================================================================\n");
    printf("%-10s %-15s %-15s %-15s %-20s %-10s\n",
           "Roll No", "First Name", "Last Name", "Branch", "Address", "Percentage");
    printf("========================================================================================\n");

    while (fread(&s, sizeof(struct student), 1, fp) == 1)
    {
        printf("%-10d %-15s %-15s %-15s %-20s %-10.2f\n",
               s.rollNo,
               s.firstName,
               s.lastName,
               s.branch,
               s.address,
               s.percentage);

        found = 1;
    }

    if (!found)
    {
        printf("\nNo student records available.\n");
    }

    fclose(fp);
}

void searchStudent()
{
    FILE *fp;
    struct student s;
    int roll;
    int found = 0;

    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(struct student), 1, fp) == 1)
    {
        if (s.rollNo == roll)
        {
            printf("\n========== Student Found ==========\n");

            printf("Roll Number : %d\n", s.rollNo);
            printf("First Name : %s\n", s.firstName);
            printf("Last Name  : %s\n", s.lastName);
            printf("Branch     : %s\n", s.branch);
            printf("Address    : %s\n", s.address);
            printf("Percentage : %.2f\n", s.percentage);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent with Roll Number %d not found.\n", roll);
    }

    fclose(fp);
}

void deleteStudent()
{
    FILE *fp, *temp;
    struct student s;
    int roll;
    int found = 0;

    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo student records found!\n");
        return;
    }

    temp = fopen("temp.dat", "wb");

    if (temp == NULL)
    {
        printf("\nUnable to create temporary file!\n");
        fclose(fp);
        return;
    }

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(struct student), 1, fp) == 1)
    {
        if (s.rollNo == roll)
        {
            found = 1;
            continue;   // Skip writing the matching record
        }

        fwrite(&s, sizeof(struct student), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("\nStudent record deleted successfully.\n");
    else
        printf("\nStudent with Roll Number %d not found.\n", roll);
}
