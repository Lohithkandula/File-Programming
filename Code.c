#include <stdio.h>
struct stu{
int rollno;
char name[100];
char bra[100];
int age;
}s[100];
int main()
{
FILE *file;
int n;
printf("Enter number of Students : ");
scanf("%d", &n);
for(int i = 0; i < n; i++)
{
printf("----------------------\n");
printf("Enter the Roll.no : ");
scanf("%d", &s[i].rollno);
printf("Enter the Name : ");
scanf("%s", s[i].name);
printf("Enter the Branch : ");
scanf("%s", s[i].bra);
printf("Enter the Age : ");
scanf("%d", &s[i].age);
}
for(int i = 0; i < n-1; i++)
{
for(int j = 0; j < n-i-1; j++)
{
if(s[i].rollno > s[i+1].rollno)
{
struct stu swap = s[i];
s[i] = s[i+1];
s[i+1] = swap;
}
}
}
for(int i = 0; i < n; i++)
{
file = fopen("file.txt", "a");
fprintf(file, "Name : %s\n", s[i].name);
fprintf(file, "Roll No : %d\n", s[i].rollno);
fprintf(file, "Branch : %s\n", s[i].bra);
fprintf(file, "Age : %d\n", s[i].age);
fclose(file);
}
}
