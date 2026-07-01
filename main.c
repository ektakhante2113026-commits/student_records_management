#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct student
{
    char first_name[20];
    char last_name[20];
    int roll_no;
    char Class[10];
    char vill[20];
    float per;
};

void addstudent();
void studentrecord();

int main()
{
    int choice = 0;

    while (choice != 3)
    {
        printf("\n\n");
        printf("\t\t=============================================\n");
        printf("\t\t Government Polytechnic, Nagpur\n");
        printf("\t\t STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("\t\t=============================================\n");

        printf("\n1. Add Student");
        printf("\n2. Display Records");
        printf("\n3. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 1:
            addstudent();
            break;

        case 2:
            studentrecord();
            printf("\n\nPress any key to continue...");
            getch();
            break;

        case 3:
            printf("\nThank You!\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
            printf("Press any key to continue...");
            getch();
        }
    }

    return 0;
}

void addstudent()
{
    FILE *fp;
    struct student info;
    char another;
    int i, n;

    do
    {
        fp = fopen("information.txt", "a");

        if (fp == NULL)
        {
            printf("Unable to open file.\n");
            return;
        }

        fprintf(fp, "\n");

        printf("\n========== Add Student ==========\n");

        printf("Enter First Name : ");
        gets(info.first_name);

        for (i = 0; info.first_name[i] != '\0'; i++)
        {
            n = info.first_name[i];
            fprintf(fp, "%c", n);
        }

        fprintf(fp, "\t");

        printf("Enter Last Name : ");
        gets(info.last_name);

        for (i = 0; info.last_name[i] != '\0'; i++)
        {
            n = info.last_name[i];
            fprintf(fp, "%c", n);
        }

        fprintf(fp, "\t");

        printf("Enter Roll Number : ");
        scanf("%d", &info.roll_no);
        fprintf(fp, "%d\t", info.roll_no);

        printf("Enter Branch : ");
        scanf("%s", info.Class);

        for (i = 0; info.Class[i] != '\0'; i++)
        {
            n = info.Class[i];
            fprintf(fp, "%c", n);
        }

        fprintf(fp, "\t");

        printf("Enter Address : ");
        scanf("%s", info.vill);

        for (i = 0; info.vill[i] != '\0'; i++)
        {
            n = info.vill[i];
            fprintf(fp, "%c", n);
        }

        fprintf(fp, "\t");

        printf("Enter Percentage : ");
        scanf("%f", &info.per);
        fprintf(fp, "%.2f", info.per);

        fclose(fp);

        printf("\nRecord Stored Successfully!\n");

        printf("\nDo you want to add another record? (Y/N): ");
        scanf(" %c", &another);
        fflush(stdin);

    } while (another == 'Y' || another == 'y');
}

void studentrecord()
{
    FILE *fp;
    int ch;

    fp = fopen("information.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n========== STUDENT RECORDS ==========\n\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }

    fclose(fp);
}
