#include<stdio.h>
#include<string.h>
struct student{
char s[25];
int roll;
char b[3];
int age;
};
int main()
{
char ch,k[25],word[50],stu[25],branch[3];
int i,j,r,a,n1,n2,c,tmp,m,p,o,t;
FILE *f1,*f2,*f;
f1=fopen("file1.txt","w+");
f2=fopen("file2.txt","w+");
printf("Enter the number of students for sample1: ");
scanf("%d",&n1);
printf("Enter the number of students for sample2: ");
scanf("%d",&n2);
struct student stude[n1+n2];
int ar[n1+n2];
printf("Enter the data for the file1.txt file:\n");
for(i=0;i<n1;i++){
printf("\nEnter the student name: ");
scanf("%s",stu);
strcpy(stude[i].s,stu);
fprintf(f1,"Name : %s\n",stu);
printf("Enter the Roll Number: ");
scanf("%d",&r);
stude[i].roll=r;
fprintf(f1,"Roll : %d\n",r);
printf("Enter the Branch name: ");
scanf("%s",branch);
strcpy(stude[i].b,branch);
fprintf(f1,"Branch : %s\n",branch);
printf("Enter the age: ");
scanf("%d",&a);
stude[i].age=a;
fprintf(f1,"Age : %d\n\n",a);
}
printf("Enter the data for the file2.txt file:\n");
for(i=0;i<n2;i++){
printf("\nEnter the student name: ");
scanf("%s",stu);
strcpy(stude[i+n1].s,stu);
fprintf(f2,"Name : %s\n",stu);
printf("Enter the Roll Number: ");
scanf("%d",&r);
stude[i+n1].roll=r;
fprintf(f2,"Roll : %d\n",r);
printf("Enter the Branch name: ");
scanf("%s",branch);
strcpy(stude[i+n1].b,branch);
fprintf(f2,"Branch : %s\n",branch);
printf("Enter the age: ");
scanf("%d",&a);
stude[i+n1].age=a;
fprintf(f2,"Age : %d\n\n",a);
}
for(i=0;i<n1+n2;i++)
ar[i]=stude[i].roll;
t=n1+n2;
for(i=0;i<t-1;i++){
for(j=0;j<t-i-1;j++){
if(ar[j]>ar[j+1]){
tmp=ar[j];
ar[j]=ar[j+1];
ar[j+1]=tmp;
}
}
}
for(i=0;i<t;i++){
printf("%d ",ar[i]);
}
fclose(f1);
fclose(f2);
f=fopen("file3.txt","w+");
m=0;
while(m<t){
p=ar[m];
for(i=0;i<t;i++){
if(stude[i].roll==p)
o=i;
}
fprintf(f,"Name : %s\n",stude[o].s);
fprintf(f,"Roll : %d\n",stude[o].roll);
fprintf(f,"Branch : %s\n",stude[o].b);
fprintf(f,"Age : %d\n\n",stude[o].age);
m++;
}
fclose(f);
}
