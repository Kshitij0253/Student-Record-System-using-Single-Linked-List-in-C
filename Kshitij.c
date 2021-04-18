/*
Project Made by :- Kshitij (2k20-BT-510) 
*/ 


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node {

	int roll;
	char Name[100];
	char Dept[100];
	int Marks;
	struct node* next;
};

struct node* head=NULL;

int check(int x)
{
	
	if (head == NULL)
		return 0;

	 struct node* t = head;

	while (t != NULL) {
		if (t->roll == x)
			return 1;
		t = t->next;
	}

	return 0;
}


void Insert_Record(int roll, char *Name,char *Dept, int Marks)
{
	
	if (check(roll)) {
		printf("Student with this  record Already Exists\n");
		return;
	}


	struct node* t = (struct node*)malloc(sizeof(struct node));
	t->roll = roll;
	printf("%s  ",Name);
	printf("%s  ",Dept);
	strcpy(t->Name,Name);
	strcpy(t->Dept,Dept);
	t->Marks = Marks;
	t->next = NULL;

	
	if (head == NULL|| (head->roll >= t->roll)) {
		t->next = head;
		head = t;
	}

	
	else {
		struct node* c = head;
		while (c->next != NULL&& c->next->roll < t->roll) {
			c = c->next;
		}
		t->next = c->next;
		c->next = t;
	}

	 printf("Record Inserted Successfully\n");
}


void Search_Record(int roll)
{
	
	if (!head) {
		printf("No such Record  Avialable\n");
		return;
	}

	
	else {
		struct node* p = head;
		while (p) {
			if (p->roll == roll) {
				 printf("Roll Nmuber %d\t\t", p->roll);
				 printf("Name %s\t\t",p->Name);
				 printf("Department %s \t",p->Dept);
			     printf("Marks %d \t\t",p->Marks);
				return;
			}
			p = p->next;
		}

		if (p == NULL)
			printf("No such Record Avialable\n");
	}
}


int Delete_Record(int roll)
{
	struct node* t = head;
	struct node* p = NULL;

	
	if (t != NULL
		&& t->roll == roll) {
		head = t->next;
		
		free(t);

		printf("Record Deleted Successfully\n");
		return 0;
	}

	
	while (t != NULL && t->roll != roll) {
		p = t;
		t = t->next;
	}
	if (t == NULL) {
		printf("Record does not Exist\n");
		return -1;
		p->next = t->next;

		
		free(t);

		 printf("Record Deleted Successfully\n");

		return 0;
	}
}



void Show_Record()
{
	struct node* p = head;
	if (p == NULL) {
		printf("No Record Available\n");
	}
	else {
		printf("Index\tName\tCourse\tMarks\n");

		while (p != NULL) {
			printf("%d\t%s\t%s\t%d\n ",p->roll , p->Name , p->Dept , p->Marks);
			p = p->next;
		}
	}
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	
    printf("\n  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  LOGIN FIRST  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  ");
    printf(" \n\n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n\n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	
	i=0;
	
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
}   

int first( )
{
	printf("\t\t\\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb       =============================           \xdb\n");
	printf("\t\t\xdb        Student Record Management System       \xdb\n");
	printf("\t\t\xdb       =============================           \xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb       Made By Kshitij and Yogesh Sathyarthi   \xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\xdb                                               \xdb\n");
	printf("\t\t\\n");
	printf(" \n\t Press Any Key To Continue:");
	
	getch();	
    system("cls");
    login();
}


int main()
{ 
    
	head = NULL;
	char Name[100];
	char Course[100];
	int Roll, Marks;
  
   first();
	
	while (1) {
		printf("\n\t\tWelcome to Student Record "
				"Management System\n\n\tPress\n\t1 to "
				"create a new Record\n\t2 to delete a "
				"student record\n\t3 to Search a Student "
				"Record\n\t4 to view all students "
				"record\n\t5 to Exit\n");
		printf("\nEnter your Choice\n");
		int Choice;

		
		scanf("%d",&Choice);
		if (Choice == 1) {
			printf("Enter Name of Student\n");
			scanf("%s",Name);
			printf("Enter Roll Number of Student\n");
			scanf("%d", &Roll);
			printf("Enter Course of Student \n");
			scanf("%s",Course);
			printf("Enter Total Marks of Student\n");
		    scanf("%d",&Marks);
			Insert_Record(Roll, Name, Course, Marks);
		}
		else if (Choice == 2) {
			printf("Enter Roll Number of Student whose record is to be deleted\n");
			scanf("%d",&Roll);
			Delete_Record(Roll);
		}
		else if (Choice == 3) {
			printf("Enter Roll Number of Student whose record you want to Search\n");
			scanf("%d",&Roll);
			Search_Record(Roll);
		}
		else if (Choice == 4) {
			Show_Record();
		}
		else if (Choice == 5) {
			exit(0);
		}
		else {
			printf("Invalid Choice Try Again\n");
		}
	}
	return 0;
}
