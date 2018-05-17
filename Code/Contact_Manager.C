#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct contact
{
	char name[50];
	char num[50];
	struct contact *ptr;
};

typedef struct contact node;

node *head=NULL,*start,*cur,*prev,*new1;

int check_dublicate_num(char n[50])
{
	int found=0;
	start=head;
	while(start!=NULL)
	{
		if(strcmp(n,start->num)==0)
			found=1;
		start=start->ptr;
	}
	if(found==1)
		return(1);
	return(0);
}
void insert()
{
	int check=0;

	system("cls");
	printf("***************************************************************");
	printf("\n\t\t\tADD CONTACT\n");
	printf("***************************************************************");

	new1=(node*)malloc(sizeof(node));
	
	printf("\n\nEnter Name :");
	scanf("%s",&new1->name);
	printf("Enter Pno :");
	scanf("%s",&new1->num);
	new1->ptr=NULL;
	
	strupr(new1->name);
	
	if(head==NULL)
	{
		head=new1;
	}
	else
	{
		if(check_dublicate_num(new1->num))
			printf("\n\nSame Pno already saved\n");
		else
		{
			if(strcmp(head->name,new1->name)>0)
			{
				start=head;
				new1->ptr=start;
				head=new1;
			}
			else
			{
				start=head;
				while(start->ptr!=NULL)
				{
					prev=start;
					start=start->ptr;
					if((strcmp(prev->name,new1->name)<0) && (strcmp(start->name,new1->name)>=0))
					{
						check=1;
						break;
					}
				}
				if(start->ptr==NULL && check==0)
				{
					start->ptr=new1;
				}
				else
				{
					new1->ptr=prev->ptr;
					prev->ptr=new1;
				}
			}
		}
	}
}

void del()
{
	char key[50];
	int found=0;
	char key2[50];
	
	system("cls");
	printf("***************************************************************");
	printf("\n\t\t\tDELETE CONTACT\n");
	printf("***************************************************************");
		
	if(head==NULL)
		printf("\n\nEmpty\n");
	else
	{
		printf("\n\nEnter name to del a Contact : ");
		scanf("%s",&key);
		strupr(key);
		
		start=head;
		while(start!=NULL)
		{
			if(strcmp(key,start->name)==0)
				found++;
			start=start->ptr;
		}
		
		if(found<2)
		{
			start=head;
			while(strcmp(start->name,key)!=0 && start->ptr!=NULL)
			{
				prev=start;
				start=start->ptr;
			}
			if(strcmp(start->name,key)!=0 && start->ptr==NULL)
				printf("\n\nNo Contact with name %s\n\n",key);
			else if(head==start)
			{
				head=start->ptr;
				free(start);
			}
			else
			{
				prev->ptr=start->ptr;
				free(start);			
			}
		}
		else
		{
			printf("\n\n%d contact found with name %s which one you want to delete\n\n",found,key);
			start=head;
			while(start!=NULL)
			{
				if(strcmp(key,start->name)==0)
				printf("%s\t%s\n",start->name,start->num);
				start=start->ptr;
			}
			
			start=head;
			printf("\nEnter Pno to delete : ");
			scanf("%s",key2);
			while(strcmp(start->num,key2)!=0 && start->ptr!=NULL)
			{
				prev=start;
				start=start->ptr;
			}
			if(strcmp(start->num,key2)!=0 && start->ptr==NULL)
			printf("\nContact not found");
			
			else
			{
				if(head==start)
					head=start->ptr;
				else
					prev->ptr=start->ptr;
				free(start);
			}
		}
	}
}

void find()
{
	char key[50];
	int found=0;
	
	system("cls");
	printf("***************************************************************");
	printf("\n\t\t\tSEARCH CONTACT\n");
	printf("***************************************************************");
		
	if(head==NULL)
		printf("\n\nEmpty\n");
	
	else
	{
		start=head;
		printf("\n\nEnter name to Search : ");
		scanf("%s",&key);
		strupr(key);
		while(start!=NULL)
		{
			if(strcmp(start->name,key)==0)
			printf("%s\t%s\n",start->name,start->num);	
			start=start->ptr;
			found=1;
		}
		if(found==0)
			printf("\nContact not found");
	}
}

void modify()
{
	char key[50];
	int found=0,ch;
	char key2[50];
	
	system("cls");
	printf("*************************************************************************");
	printf("\n\t\t\tMODIFY CONTACT\n");
	printf("*************************************************************************");

	if(head==NULL)
		printf("\n\nEmpty\n");
	else
	{
		printf("\n\nEnter name to modify element : ");
		scanf("%s",&key);
		strupr(key);
		
		start=head;
		while(start!=NULL)
		{
			if(strcmp(key,start->name)==0)
				found++;
			start=start->ptr;
		}
		
		if(found<2)
		{
			start=head;
			while(strcmp(start->name,key)!=0 && start->ptr!=NULL)
			{
				prev=start;
				start=start->ptr;
			}
			if(strcmp(start->name,key)!=0 && start->ptr==NULL)
				printf("\n\nNo Cantact with name %s\n\n",key);
			else
			{
				printf("\n\nWhat do you want to change :\n1:Name\n2:Pno\n3:Both\n\nEnter you choice : ");
				scanf("%d",&ch);
				
				if(ch==1)
				{
					printf("\n\nEnter name :");
					scanf("%s",&start->name);
					strupr(start->name);
				}
				else if(ch==2)
				{
					printf("\n\nEnter num :");
					scanf("%s",&start->num);
				}
				else if(ch==3)
				{
					printf("\n\nEnter name :");
					scanf("%s",&start->name);
					strupr(start->name);
					printf("Enter num :");
					scanf("%s",&start->num);
				}
				else
				printf("\n\nInvallid Input\n\n");
			}
		}
	
		else
		{
			printf("\n\n%d contact found with name %s which one you want to modify\n\n",found,key);
			start=head;
			while(start!=NULL)
			{
				if(strcmp(key,start->name)==0)
				printf("%s\t%s\n",start->name,start->num);
				start=start->ptr;
			}
			
			start=head;
			printf("\nEnter Pno to modify : ");
			scanf("%s",&key2);
			while(strcmp(start->num,key2)!=0 && start->ptr!=NULL)
			{
				prev=start;
				start=start->ptr;
			}
			
			if(strcmp(start->num,key2)!=0 && start->ptr==NULL)
			printf("\nContact not found");
			else
			{
				printf("\n\nWhat do you want to change :\n1:Name\n2:Pno\n3:Both\n\nEnter you choice : ");
				scanf("%d",&ch);
				
				if(ch==1)
				{
					printf("\n\nEnter name :");
					scanf("%s",&start->name);
					strupr(start->name);
				}
				else if(ch==2)
				{
					printf("\n\nEnter num :");
					scanf("%s",&start->num);
				}
				else if(ch==3)
				{
					printf("\n\nEnter name :");
					scanf("%s",&start->name);
					strupr(start->name);
					printf("Enter num :");
					scanf("%s",&start->num);
				}
				else
				printf("\n\nInvallid Input\n\n");
			}
		}
	}	
}

void display()
{
	system("cls");
	printf("***************************************************************");
	printf("\n\t\t\t CONTACTS\n");
	printf("***************************************************************");

	if(head==NULL)
		printf("\n\nEmpty");
	else
	{
		start=head;
		printf("\n\nNAME\t  Pno\n\n");
		while(start!=NULL)
		{
			printf("%s\t%s\n",start->name,start->num);
			start=start->ptr;
		}
	}
}

void load_data()
{
	FILE *p;
	char nam[50];
	char pno[50];
	p=fopen("database.txt","r");
	
	while(fscanf(p,"%s",nam),fscanf(p,"%s",&pno)==1)
	{
		new1=(node*)malloc(sizeof(node));
		strcpy(new1->name,nam);
		strcpy(new1->num,pno);
		new1->ptr=NULL;
		
		strupr(new1->name);

		if(head==NULL)
		{
			head=new1;
		}
		else
		{
			prev->ptr=new1;
		}
		prev=new1;
	}
	fclose(p);
}

void write_data()
{
	FILE *p;
	p=fopen("database.txt","w");
	start=head;
	if(head!=NULL)
	while(start!=NULL)
	{
		fprintf(p,"%s\t",start->name);
		fprintf(p,"%s\n",start->num);
		start=start->ptr;
	}
	fclose(p);
}

int main()
{
	int ch=1;
	load_data();
	while(ch!=6)
	{
		system("cls");
		printf("***************************************************************");
		printf("\n\t\t\tCONTACT MANAGEMENT\n");
		printf("***************************************************************");
		printf("\n\n1:Add Contact\n2:Delete Contact\n3:Display all Contacts");
		printf("\n4:Search a Contact\n5:Modify Pno\n6:Exit\n\nEnter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
			case 4:
				find();
				break;
			case 5:
				modify();
				break;
			case 6:
				printf("\n\nBye");
				break;
			default:
				printf("\n\nInvalid Input\n");
		}
		printf("\n\n");
		system("pause");
	}
	write_data();
	return(0);
}
