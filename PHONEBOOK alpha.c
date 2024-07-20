#include<stdio.h>
#include<string.h>
typedef struct contact
{
	char name[20];
	long long int no;
	char group[20];
	char city[20];
	char state[20];
}CONTACT;
CONTACT c;
void search();
void create();
void main()
{
	short int a;
	system("cls");
	printf("\nWhat's on your mind?\nSelect one of the options :\n\n");
	printf("\t1)Create new contact\n");
	printf("\t2)Search contacts\n");
	printf("\t3)Exit\n");
    scanf("%d",&a);
    switch(a)
    {
    	case 1:
			system("cls");
    		create();
    	case 2:
    		system("cls");
    		search();
    	case 3:
    		printf("\n\n\n\t\t\t\tTHANK YOU");
    		break;
		}
}
 void create()
 {
 	FILE *fp;
 	fp=fopen("phbk.txt","a");
 	//name
 	printf("\n\nPLEASE ENTER FOLLOWING DETAILS\n\n");
	printf("Name : \n");
 	scanf("%s",&c.name);
 	fprintf(fp,"\n %s",c.name);
 	//number
 	printf("Phone Number :\n");
 	scanf("%lld",&c.no);
 	fprintf(fp," %lld",c.no);
 	//group
 	printf("Group :\n");
 	scanf("%s",&c.group);
 	fprintf(fp," %s",c.group);
	//city
 	printf("City :\n");
 	scanf("%s",&c.city);
 	fprintf(fp," %s",c.city);
 	//state
 	printf("State :\n");
 	scanf("%s",&c.state);
 	fprintf(fp," %s",c.state);
 	//end
 	printf("\n\nContact Successfully Created\n\nPRESS ENTER FOR MAIN MENU");
 	fclose(fp);
 	getch();
	main();
 	}
  void search()
  {
  	FILE *fp;
  	char find[15];
  	int i,j=1;
  	fp=fopen("phbk.txt","r");
  	printf("\nEnter the contact to search :\n");
  	scanf("%s",&find);
  	//matching
  	//no of contacts found
  	//dispaly of found contacts
  	//printf("Sr.No. Name\t\t\tNumber\tGroup\tCity\tState");
	j=1;
	outerloop:
  	while(!feof(fp))
	  {
	    fscanf(fp,"%s %lld %s %s %s",&c.name,&c.no,&c.group,&c.city,&c.state);
		for(i=0;i<strlen(find);i++)
		 {
		   if(c.name[i]==find[i]||c.group[i]==find[i]||c.city[i]==find[i]||c.state[i]==find[i])
		    continue;//printf("%c\t",c.name[i]);
		   else
		    goto outerloop;
	    }
	    printf("\n%d %s\t%lld\t%s\n  %s\n  %s\n\n",j,c.name,c.no,c.group,c.city,c.state);
	    j++;
	  }
     if (j==1)
      printf("\n\nSORRY,NO CONTACTS FOUND"); 
    fclose(fp);
    printf("\n\nPRESS ENTER FOR MAIN MENU");
	getch();
	main();	
	  }  
	  
	  
  
  	
	    
