#include<stdio.h>
    int main()
    {
       int marks;
       printf("Enter Marks:");
       scanf("%d", &marks);
    if  (marks >= 90) 
    printf("A Grade");
     else if (marks >= 75)
     printf("B Grade");
     else if (marks>=60)
     printf("C Grade");
     else if (marks >= 40)
     printf("D Grade");
     else  
     printf("Fail");
       
       return 0;

    }
  