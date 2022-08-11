/* 


                    **************Code Written By Ahmed El Azab Group_ID : 12**************
					                        
											
											                                                             */
#include "STD_Types.h"
#include "header.h"
#include <stdio.h>
#include <stdlib.h>



u32 ListLength = 0,Size=0,ID,time,i;
u8 name[100];
u8 gender[10];
u32 patient_age,patient_id,id;



node *head=NULL;
node *current = NULL;
node *prev = NULL;



void main(void)
{
	u32 choice,input,password;
	u8   flag = 0,Exits = 1;
	printf("\t\tProject by Student Ahmed El Azab --- Student ID : 12 --- Group ID : 11126062200\n\n");
		
	while(Exits)
	{
	printf("---------------Enter 1 for Admin Mode---------------\n---------------Enter 2 for User Mode---------------\n---------------Enter 3 to Exit Program---------------\n");
	printf("Your choice: ");
	scanf("%d",&choice);
	if(choice==1)
	{
	printf("\t\t\t\tAdmin Mode\n\n");
	 printf("Please Enter Password: ");
		for (i=0; i<3; i++)
		{
			  scanf ("%d",&password);
					   if(password==1234)
					   {
						   printf("\t\t\t_________________Welcome to Admin Mode_________________\n\n");
						   flag = 1;
						   break;
					   }
					   
					   else if (i<2)
					   {
						   printf("Try again: ");
					   }
					   
	   }
	   if(flag==1)
	   {
		printf("\t\t1 - Add New Patient\n");
		printf("\t\t2 - Edit Patient Data\n");
		printf("\t\t3 - Book an Appointment\n");
		printf("\t\t4 - Cancel Appointment 4\n");
		printf("Enter Number : ");
		scanf("%d",&input);
		switch (input)
		{
			case 1 : printf("Enter Patient's Name : ");
			         scanf(" %[^\n]%*c",name);
					 printf("Enter Patient's Age : ");
			         scanf("%d",&patient_age);
					 printf("Enter Patient's Gender : ");
			         scanf(" %[^\n]%*c",gender);
					 printf("Enter Patient's ID : ");
			         scanf("%d",&patient_id);
					 Add_New_Patient(name,patient_age,gender,patient_id);
					 break;
			case 2 : printf("Enter Your ID: ");
					 scanf("%d",&id);
					Edit_Patient_Data(id); break;
			case 3 : Appointment_Reservation();
					 break;
			case 4 : printf("Enter Your ID: ");
					 scanf("%d",&id);
			         Cancel_Appointment(id);
					 break;
			default: printf("This Number is not an option!\n"); break;
		}
	   }
		else if (flag == 0)
		{
		printf("Wrong Password for 3 times, Maximum Trials has been reached,The Program shall now exit\n"); Exits=0;
		}
	}
	
	else if(choice==2)
	{
		printf("\t\t\t******** User Mode ********\n\n");
		printf("For Patient Data Press 1\n");
		printf("For Today's Appointments Press 2\n");
		printf("Enter Number : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1 : printf("Enter Your ID: ");
					 scanf("%d",&id);
					 printf("\t\t\t********** Patient Data **********\n\n");
					 Show_User_Data(id);
					 break;
			case 2 : printf("\t\t\t****** Today's Appointments ******\n\n ");
					Show_User_Res();
					break;
			default: printf("Invalid Choice please try again\n"); break;
		}
	}
	else if(choice==3)
		
		{
		Exits=0; 
		printf("\t\t\tProgram Closed");
		}
	else 
		printf("Wrong\Error\n");
	}
}