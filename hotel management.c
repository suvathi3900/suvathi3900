#include<stdio.h>
#include<string.h>
#include<conio.h>

struct Customer
{
char name[100];
char address[100];
char phone[12];
char from_date[20];
char to_date[20];
float payment_advance;
int booking_id;
};

typedef struct Room
{
char type;
int roomNumber;
int rent;
int status;
char food;
struct Customer cust;
};
struct Room addRoom(int);
void searchRoom(int);
void displayRoom(Room);

//Global Declarations
struct Room rooms[100];
int count=0;


struct Room addRoom(int rno)
{
struct Room room;
room.roomNumber=rno;
printf("\nType Comfort (Standard-S/Deluxe-D/Presidential Suite-P) : ");
scanf("%s",&room.type);
printf("\nDo you want to add Food :");
scanf("%s",&room.food);
switch(room.type)
{
    case 'S': if(room.food=='Y'||room.food=='y')
                room.rent=6000;
              else
                room.rent=5000;
              printf("\nDaily Rent : %d", room.rent);
              break;
    case 'D': if(room.food=='Y'||room.food=='y')
                room.rent=8000;
              else
                room.rent=7000;
              printf("\nDaily Rent : %d", room.rent);
              break;
    case 'P': if(room.food=='Y'||room.food=='y')
                room.rent=11000;
              else
                room.rent=10000;
              printf("\nDaily Rent : %d", room.rent);
              break;
}
room.status=0;

printf("\n Room Added Successfully!");
getch();
return room;
}


void searchRoom(int rno)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
printf("Room Details\n");
if(rooms[i].status==1)
{
printf("\nRoom is Reserved");
}
else
{
printf("\nRoom is available");
}
displayRoom(rooms[i]);
getch();
}
else
{
printf("\nRoom not found");
getch();
}
}

void displayRoom(struct Room tempRoom)
{
printf("\nRoom Number: %d\t",tempRoom.roomNumber);
printf("\nType Comfort (Standard-S/Deluxe-D/Presidential Suite-P) : %s",tempRoom.type);
printf("\nRent: %d ",tempRoom.rent);
}

void checkIn();
void getAvailRoom();
void searchCustomer(char *);
void checkOut(int);
void guestSummaryReport();

void guestSummaryReport(){

if(count==0){
	printf("\n No Guest in Hotel !!");
}
for(int i=0;i<count;i++)
{
if(rooms[i].status==1)
{
printf("\n Customer First Name : %s ",rooms[i].cust.name);
printf("\n Room Number : %d ",rooms[i].roomNumber);
printf("\n Address (only city) : %s ",rooms[i].cust.address);
printf("\n Phone : %s ",rooms[i].cust.phone);
printf("\n---------------------------------------");
}

}
getch();
}

//hotel management reservation of room
void checkIn()
{
int i,found=0,rno;

struct Room room;
printf("\nEnter Room number : ");
scanf("%d",&rno);
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
if(rooms[i].status==1)
{
printf("\nRoom is already Booked");
getch();
return;
}

printf("\nEnter booking id: ");
scanf("%d",&rooms[i].cust.booking_id);

printf("\nEnter Customer Name (First Name): ");
scanf("%s",&rooms[i].cust.name);

printf("\nEnter Address (only city): ");
scanf("%s",&rooms[i].cust.address);

printf("\nEnter Phone: ");
scanf("%s",&rooms[i].cust.phone);

printf("\nEnter From Date: ");
scanf("%s",&rooms[i].cust.from_date);

printf("\nEnter to  Date: ");
scanf("%s",&rooms[i].cust.to_date);

printf("\nEnter Advance Payment: ");
scanf("%f",&rooms[i].cust.payment_advance);

rooms[i].status=1;

printf("\n Customer Checked-in Successfully..");
getch();
}
}


//hotel management shows available rooms
void getAvailRoom()
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==0)
{
displayRoom(rooms[i]);
printf("\n\nPress enter for next room");
found=1;
getch();
}
}
if(found==0)
{
printf("\nAll rooms are reserved");
getch();
}
}

//hotel management shows all persons that have booked room
void searchCustomer(char *pname)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && stricmp(rooms[i].cust.name,pname)==0)
{
printf("\nCustomer Name: %s ",rooms[i].cust.name);
printf("\nRoom Number: %d ",rooms[i].roomNumber);

printf("\n\nPress enter for next record");
found=1;
getch();
}
}
if(found==0)
{
printf("\nPerson not found.");
getch();
}
}

//hotel managemt generates the bill of the expenses
void checkOut(int roomNum)
{
int i,found=0,days,rno;
float billAmount=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && rooms[i].roomNumber==roomNum)
{
//rno = rooms[i].roomNumber;
found=1;
//getch();
break;
}
}
if(found==1)
{
printf("\nEnter Number of Days: ");
scanf("%d",&days);
billAmount=days * rooms[i].rent;

printf("\n\t######## CheckOut Details ########\n");
printf("\nCustomer Name : %s ",rooms[i].cust.name);
printf("\nRoom Number : %d ",rooms[i].roomNumber);
printf("\nAddress : %s ",rooms[i].cust.address);
printf("\nPhone : %s ",rooms[i].cust.phone);
printf("\nTotal Amount Due : %f ",billAmount);
printf("\nAdvance Paid: %f ",rooms[i].cust.payment_advance);
printf("\n*** Total Payable: %f ",billAmount-rooms[i].cust.payment_advance,"/ only");

rooms[i].status=0;
count--;
}
getch();
}

//managing rooms (adding and searching available rooms)
void manageRooms()
{
struct Room room;
int opt,rno,i,flag=0;
char ch;
do
{
system("cls");
printf("\n### Manage Rooms ###");
printf("\n1. Add Room");
printf("\n2. Search Room");
printf("\n3. Back to Main Menu");
printf("\n\nEnter Option: ");
scanf("%d",&opt);

//switch statement
switch(opt)
{
case 1:
printf("\nEnter Room Number: ");
scanf("%d",&rno);
i=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
flag=1;
}
}
if(flag==1)
{
printf("\nRoom Number is Present.\nPlease enter unique Number");
flag=0;
getch();
}
else
{
rooms[count]=addRoom(rno);
count++;
}
break;
case 2:
printf("\nEnter room number: ");
scanf("%d",&rno);
searchRoom(rno);
break;
case 3:
//nothing to do
break;
default:
printf("\nPlease Enter correct option");
break;
}
}while(opt!=3);
}

int main()
{
int i,j,opt,rno;
char ch;
char pname[100];

system("cls");
printf("\n                               *************** WILD ORCHID RESORT ****************                                         ");
printf("\n        Nestled amidst the mesmerising wonder-hills of Kodaikanal, we promise you beautiful memorises for a lifetime       ");
printf("\n                                                  BOOK NOW!!!!!!                                                           ");
getch();
do
{
system("cls");
printf("########  WILD ORCHID RESORT  #########\n");
printf("\n1. Manage Rooms");
printf("\n2. Check-In Room");
printf("\n3. Available Rooms");
printf("\n4. Search Customer");
printf("\n5. Check-Out Room");
printf("\n6. Guest Summary Report");
printf("\n7. Exit");
printf("\n\nEnter Option: ");
scanf("%d",&opt);
switch(opt)
{
case 1:
manageRooms();
break;
case 2:
if(count==0)
{
printf("\nRooms data is not available.\nPlease add the rooms first.");
getch();
}
else
checkIn();
break;
case 3:
if(count==0)
{
printf("\nRooms data is not available.\nPlease add the rooms first.");
getch();
}
else
getAvailRoom();
break;
case 4:
if(count==0)
{
printf("\nRooms are not available.\nPlease add the rooms first.");
getch();
}
else
{
printf("Enter Customer Name: ");
scanf("%s",&pname);
searchCustomer(pname);
}
break;
case 5:
if(count==0)
{
printf("\nRooms are not available.\nPlease add the rooms first.");
getch();
}
else
{
printf("Enter Room Number : ");
scanf("%d",&rno);
checkOut(rno);
}
break;
case 6:
guestSummaryReport();
break;
case 7:
printf("\n!!!THANK YOU!!!");
break;
default:
printf("\nPlease Enter correct option");
break;
}
}while(opt!=7);

getch();
}
