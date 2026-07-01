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
void updateStudent();
void deleteStudent();

int checkDuplicateRoll(int);

int main()
{
    int choice;

    while (1)
    {
        system("cls");

        printf("\n");
        printf("=====================================================\n");
        printf("          STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("=====================================================\n");

        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
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
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nThank You!\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }

        printf("\n\nPress any key...");
        getch();
    }

    return 0;
}

int checkDuplicateRoll(int roll)
{
    FILE *fp;
    struct student s;

    fp=fopen("students.dat","rb");

    if(fp==NULL)
        return 0;

    while(fread(&s,sizeof(struct student),1,fp))
    {
        if(s.rollNo==roll)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}

void addStudent()
{
    FILE *fp;
    struct student s;
    char ch;

    fp=fopen("students.dat","ab");

    if(fp==NULL)
    {
        printf("Unable to open file.");
        return;
    }

    do
    {
        printf("\n----------- Add Student -----------\n");

        printf("Roll Number : ");
        scanf("%d",&s.rollNo);

        if(checkDuplicateRoll(s.rollNo))
        {
            printf("\nRoll Number already exists!\n");

            printf("\nContinue? (Y/N): ");
            scanf(" %c",&ch);

            continue;
        }

        printf("First Name : ");
        scanf("%19s",s.firstName);

        printf("Last Name : ");
        scanf("%19s",s.lastName);

        printf("Branch : ");
        scanf("%19s",s.branch);

        printf("Address : ");
        scanf("%29s",s.address);

        printf("Percentage : ");
        scanf("%f",&s.percentage);

        fwrite(&s,sizeof(struct student),1,fp);

        printf("\nStudent Added Successfully.\n");

        printf("\nAdd Another Student (Y/N): ");
        scanf(" %c",&ch);

    }while(ch=='Y'||ch=='y');

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

    printf("\n=============================================================================================\n");
    printf("%-8s %-15s %-15s %-15s %-20s %-10s\n",
           "Roll",
           "First Name",
           "Last Name",
           "Branch",
           "Address",
           "Percentage");
    printf("=============================================================================================\n");

    while (fread(&s, sizeof(struct student), 1, fp))
    {
        printf("%-8d %-15s %-15s %-15s %-20s %-10.2f\n",
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
        printf("\nNo Records Available.\n");
    }

    printf("=============================================================================================\n");

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

    printf("\nEnter Roll Number : ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(struct student), 1, fp))
    {
        if (s.rollNo == roll)
        {
            printf("\n====================================\n");
            printf("        STUDENT FOUND\n");
            printf("====================================\n");

            printf("Roll Number : %d\n", s.rollNo);
            printf("First Name  : %s\n", s.firstName);
            printf("Last Name   : %s\n", s.lastName);
            printf("Branch      : %s\n", s.branch);
            printf("Address     : %s\n", s.address);
            printf("Percentage  : %.2f\n", s.percentage);

            printf("====================================\n");

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

void updateStudent()
{
    FILE *fp;
    struct student s;
    int roll;
    int found = 0;

    fp = fopen("students.dat", "rb+");

    if (fp == NULL)
    {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(struct student), 1, fp))
    {
        if (s.rollNo == roll)
        {
            found = 1;

            printf("\n========== Current Details ==========\n");
            printf("Roll Number : %d\n", s.rollNo);
            printf("First Name  : %s\n", s.firstName);
            printf("Last Name   : %s\n", s.lastName);
            printf("Branch      : %s\n", s.branch);
            printf("Address     : %s\n", s.address);
            printf("Percentage  : %.2f\n", s.percentage);

            printf("\n========== Enter New Details ==========\n");

            printf("First Name : ");
            scanf("%19s", s.firstName);

            printf("Last Name : ");
            scanf("%19s", s.lastName);

            printf("Branch : ");
            scanf("%19s", s.branch);

            printf("Address : ");
            scanf("%29s", s.address);

            printf("Percentage : ");
            scanf("%f", &s.percentage);

            /* Move file pointer back to overwrite current record */
            fseek(fp, -sizeof(struct student), SEEK_CUR);

            fwrite(&s, sizeof(struct student), 1, fp);

            printf("\nStudent record updated successfully!\n");

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
    char choice;

    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo student records found!\n");
        return;
    }

    temp = fopen("temp.dat", "wb");

    if (temp == NULL)
    {
        printf("\nUnable to create temporary file.\n");
        fclose(fp);
        return;
    }

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(struct student), 1, fp))
    {
        if (s.rollNo == roll)
        {
            found = 1;

            printf("\nStudent Found\n");
            printf("-----------------------------\n");
            printf("Roll Number : %d\n", s.rollNo);
            printf("Name        : %s %s\n", s.firstName, s.lastName);
            printf("Branch      : %s\n", s.branch);
            printf("Percentage  : %.2f\n", s.percentage);

            printf("\nAre you sure you want to delete this record? (Y/N): ");
            scanf(" %c", &choice);

            if (choice == 'Y' || choice == 'y')
            {
                printf("\nRecord Deleted Successfully.\n");
                continue;       // Skip writing this record
            }
        }

        fwrite(&s, sizeof(struct student), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (!found)
    {
        printf("\nStudent with Roll Number %d not found.\n", roll);
    }
}

