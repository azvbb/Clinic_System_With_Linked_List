/* 


                    **************Code Written By Ahmed El Azab Group_ID : 12**************
					                        
											
											                                                             */
typedef struct Node_type node;

struct Node_type{
    u8 name[100];
	u32 age;
	u8 gender[10];
	u32 id;
    node *next;
};

void Add_New_Patient(u8 name[],u32 age,u8 gender[], u32 id);
void Edit_Patient_Data(u32 id);
void DeleteNode(u32 data);
void Appointment_Reservation() ;
void Cancel_Appointment(u32 ID);
void Show_User_List(u32 id);
void Show_User_Res();