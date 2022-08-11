/* 


                    **************Code Written By Ahmed El Azab Group_ID : 12**************
					                        
											
											                                                             */
#include "STD_Types.h"
#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


extern u32 ListLength,Size,ID,time,i;


u32 res[5]={-1,-1,-1,-1,-1};

extern node *head  ;
extern node *current  ;
extern node *prev  ;

node* new_node()
{
	node* temp=(node*)malloc(sizeof(node));
	return temp;
}

void Add_New_Patient(u8 name[],u32 age,u8 gender[], u32 id)
{
   node *link = (node*)malloc(sizeof(node));
   u32 pos=0;
     current = head;
   while(current != NULL)
   {
      if(current->id == id)
      {
         printf("The ID is already exist, please try again\n\n");
         return;
      }
      current = current->next;
      pos++;
   }
   strcpy(link->name,name);
   link->age = age;
   strcpy(link->gender,gender);
   link->id = id;
   link->next = NULL;
   printf("Patient is added successfully \n\n\n");
    current = head;
   if(head==NULL)
   {
      head = link;
      return;
   }
   while(current->next != NULL)
   {
	   current = current->next;
	  
   }
   current->next = link;
    Size++;

}

void Edit_Patient_Data(u32 id)
{
	u8 flag1=0;
   current=head;
   while(current != NULL && flag1==0)
   {
      if(current->id == id)
      {
		printf("Enter New Name: ");
		scanf(" %[^\n]%*c",current->name);
		printf("Enter New Age: ");
		scanf("%d",&current->age);
		printf("Enter New Gender: ");
		scanf(" %[^\n]%*c",current->gender);
		printf("Enter New ID: ");
		scanf("%d",&current->id);
		flag1=1;
		return;
      }
	  current=current->next;
   }
   	  if(flag1==0)
		printf("The ID Doesn't Exist, Please Enter Your Data and Get an ID First, Thank you\n"); 	
	
   return;
}

void Appointment_Reservation() 
{	u8 flag2=0;
    printf("\t\tChoose Appointment Time\n\n");
	for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0 : if(res[0]!=-1) break;
						else printf("\t\t2pm to 2:30pm is Available, To Book Press 1\n"); break;
			case 1 : if(res[1]!=-1) break;
						else printf("\t\t2:30pm to 3pm is Available, To Book Press 2\n"); break;		
			case 2 : if(res[2]!=-1) break;
						else printf("\t\t3:30pm to 4pm is Available, To Book Press 3\n"); break;
			case 3 : if(res[3]!=-1) break;
						else printf("\t\t4pm to 4:30pm is Available, To Book Press 4\n"); break;
			case 4 : if(res[4]!=-1) break;
						else printf("\t\t4:30pm to 5pm is Available, To Book Press 5\n"); break;						
		}
	}
	printf("Enter The Number of the Available Appointment You Would like to Book : ");
	scanf("%d",&time);
	printf("Please Enter your ID: ");
	scanf("%d",&ID);
	current = head;
   while(current != NULL)
   {
      if(current->id == ID)
      {
        res[time-1]=ID;
		flag2=1;
        return;
      }
      current = current->next;
   }
   if (flag2==0)
	   printf("This ID doesn't Exist, Please Enter Your Data and Get an ID First, Thank you\n");
		return;
}
void Cancel_Appointment(u32 ID)
{	
	u8 flag3=0;
	for(i=0;i<5;i++)
	{
			if(res[i]==ID)
			{
				res[i]=-1;
				flag3=1;
			}
    }
	if(flag3==0)
	{
		printf("Wrong ID\n");
	}
	return;
}
void Show_User_Data(u32 id)
{	u8 flag4=0;
    current=head;
   while(current != NULL)
   {
      if(current->id == id)
      {
		  printf("Name: ");
      printf(current->name);
	  printf("\n");
	  printf("Age: %d\n",current->age);
	  printf("Gender: ");
	  printf(current->gender);
	  printf("\n");
	  printf("ID: %d\n",current->id);
	  flag4=1;
	  }
      current = current->next;
   }
   if(flag4==0)
   printf("This ID doesnt't Exist\n");
   return;
}
void Show_User_Res()
{
	for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0 : if(res[0]==-1) break;
						else printf("\t\t2pm to 2:30pm is Booked by  ID Num: %d\n",res[0]); break;
			case 1 : if(res[1]==-1) break;
						else printf("\t\t2:30pm to 3pm is Booked by the ID Num: %d\n",res[1]); break;		
			case 2 : if(res[2]==-1) break;
						else printf("\t\t3:30pm to 4pm is Booked by the ID Num: %d\n",res[2]); break;
			case 3 : if(res[3]==-1) break;
						else printf("\t\t4pm to 4:30pm is Booked by the ID Num: %d\n",res[3]); break;
			case 4 : if(res[4]==-1) break;
						else printf("\t\t4:30pm to 5pm is Booked by the ID Num: %d\n",res[4]); break;						
		}
	}
}
