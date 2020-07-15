#include <stdio.h>
#include <string.h>

struct Employee  // We use that to define array of structure.
{
	int id;
	char surname[20];
	int projects;
	char jobtype[20];
}p[60],t;

void CodersInfo(struct Employee p[]) // This function receives array of structure parameters that user inputs and creates a file to write coders working more than 10 projects into .txt file.
{
	int i,name = 0;
	
	FILE *f; // It is used to indicate file operation.
	
	f=fopen("coders.txt","w"); // This creates a file and runs as wished(I mean we use "w" because we want to write some informations into .txt file.)
	
	for(i=0;i<5;i++)
	{
		if(strcmp(p[i].jobtype, "coder") == 0 || strcmp(p[i].jobtype, "Coder") == 0) // This determines whether an employee is coder or not.
      {
		if(p[i].projects > 10)  // It selects coders working more than 10 projects.
	{
		fprintf(f,"%s\t%d %s\n",p[i].surname,p[i].projects,p[i].jobtype); // This prints the information wanted into .txt file.
		name++; // This saves the number of coders working more than 10 projects.
	}
      }
    }
    
    fclose(f); // It is used to end file operation.
    
    printf("%d Coders info work more than 10 projects recorded into file! \n",name);
	
	printf("\n");
}

void SortEmployees(struct Employee p[]) // This function sorts the employees from highest to lowest according to their project number.
{
	int i,j;
	for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            if(p[j+1].projects > p[j].projects) // This if statement makes sort operation.
            {
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
    
    for(i=0;i<5;i++) // The sort operation maden by the if statement is printed by using loop operation.
    {
        printf("%s \t \t \t %d\n",p[i].surname,p[i].projects);
    }
}

int main ()
{
	int i,j;
	
	printf("Enter ID, Surname, Number of Projects and Job of 5 Employees: \n"); // User inputs the data wanted.
	
	for(i=0;i<5;i++) // As we indicated above, user must enter 5 different employee inputs. With this loop statement, the program receives the inputs.
	{
		scanf("%d %s %d %s",&p[i].id,p[i].surname,&p[i].projects,p[i].jobtype);
	}
	
	printf("\n");
	
	CodersInfo(p); // We call this function in order to obtain coders.txt file.
	
	printf("Sorted list of employees according to the number of projects: \n");
	
	printf("Surname                  Number of Projects: \n");
	printf("****************************************************** \n");
	
	SortEmployees(p); // This function prints the sort operation into the screen.
	
	return 0;
}
