#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<errno.h>
#include<windows.h>
#define FILENAME "lib_books.dat"

void login(void);
int check_password();
void mainmenu(void);
void add_books(void);
void view_books(void);
void search_books(void);
void delete_books(void);
void edit_book_credential(void);
int check_book_id(int);
FILE *fb,*ft;

struct
{
int book_id;
char auth_name[20];
char book_name[50];
char course[55];
int book_quantity;
}book;

struct
{
int student_ID;
char student_name[20];
char student_dept[3];
}student;

int main()
 {
  for(int i=0;i<=115;++i)
  {
  printf("*");
  }
   printf("\n\t\t\t\t WELCOME TO LIBRARY MANAGEMENT SYSTEM \t");
   printf("\n");
  for(int i=0;i<=115;++i)
  {
   printf("*");
  }
  printf("\n\n\t\t\t Press any key to continue... \t");
 getch();

login();
 }
int check_password()
 {
  char password[10]={"password"};
  char ch,pswrd[10];
  int i=0;
  printf("\n\n\tEnter the password:");
  while(ch!=13)
  {
   ch=getch();
    if(ch!=13 && ch!=8)
     {
       putch('*');
       pswrd[i] = ch;
       i++;
   }
  } 
   pswrd[i] = '\0';
   if(strcmp(pswrd,password)==0 )
   return 0;
   return 1;
  }
 void login(void)
 {
  char user[20]={"lib_admin"};
  char s[20];
int i=0,attempt=3;
while(attempt>0)
{
system("cls");
printf("\n\t----------------------------------- Login -----------------------------------\n");
printf("\n\n\n\tEnter the user name:");
gets(s);
if(check_password()==0 && strcmp(s,user)==0)
{
printf("\n\n\n\t\tLOGGED IN SUCCESSFULLY!");
printf("\n\n\n\t\tPress any key to continue...");
getch();
mainmenu();
}
else
{
printf("\n\n\n\t\a INCORRECT USERNAME OR PASSWORD.");
attempt--;
if(attempt>0)
{
printf("\n\n\tRemaining attempt:\t%d",attempt);
printf("\n\n\tPress any key to login again.");
getch();
}
else
{
printf("\n\n\tSorry, unknown user. Try again later.");
getch();
}
}
}
}
void mainmenu()
{
system("cls");
printf("\n\n\t--------------------------------- MAIN MENU ------------------------------------------");
printf("\n\t\t 1. Add Books");
printf("\n\t\t 2. View books");
printf("\n\t\t 3. Search Books");
printf("\n\t\t 4. Delete Books");
printf("\n\t\t 5. Edit Book list");
printf("\n\t\t 6. Exit");
printf("\n\t\t\t\t\t");
printf("\n\t\t Enter your choice:\t");
switch(getch())
{
case '1':
system("pause");
add_books();
break;
case '2':
system("pause");
view_books();
break;
case '3':
system("pause");
search_books();
break;
case '4':
system("pause");
delete_books();
break;
case '5':
system("pause");
edit_book_credential();
case '6':
{
system("cls");
for(int i=0;i<=29;++i)
{
printf(":*:*");
}
printf("\n\n\t\t\t\tTHANK YOU FOR USING THE LIBRARY!");
printf("\n\n");
for(int i=0;i<=29;++i)
{
printf(":*:*");
}
sleep(2);
exit(0);
}
default:
{
printf("\n INVALID INPUT TRY AGAIN!\n" );
sleep(2);
if(getch())
mainmenu();
}
}
}
void add_books()
{
system("cls");
int num;
fb=fopen(FILENAME,"ab+");
for(int i=0;i<115;++i)
{
printf("*");
}
printf("\n");
printf("\n\t\t\tADD BOOKS\t\t\t\n");
for(int i=0;i<115;++i)
{
printf("*");
}
printf("\n");
printf("\n\tBook ID No.:");
scanf("%d",&num);
if(check_book_id(num) == 0)
{
printf("\n\t\aThe book id already exists\a");
getch();
mainmenu();
}
book.book_id=num;
printf("\n\tBook Name:");
fflush(stdin);
fgets(book.book_name,50,stdin);
printf("\n\tAuthor Name:");
fflush(stdin);
fgets(book.auth_name,25,stdin);
printf("\n\tCOURSE:");
fflush(stdin);
fgets(book.course,55,stdin);
printf("\n\tNumber of books in the library:");
scanf("%d",&book.book_quantity);
fseek(fb,0,SEEK_END);
fwrite(&book,sizeof(book),1,fb);
fclose(fb);
printf("\n\n\tThe entered records have been saved successfully!\n");
printf("\n\n\tWANT TO ADD MORE BOOKS?(Y / N):\t" );
if(getch()=='n' || getch()=='N')
mainmenu();
else
if(getch()=='y' || getch()=='Y')
add_books();
else
mainmenu();
}
void view_books(void)
{
int i=0;
system("cls");
printf("\n\n\t\t\tLIST OF BOOKS IN OUR LIBRARY\n\n");
fb=fopen(FILENAME,"rb");
while(fread(&book,sizeof(book),1,fb)==1)
{
printf("\tCOURSE: %s\n",book.course);
printf("\tBOOK ID: %d\n",book.book_id);
printf("\tBOOK NAME:%s\n",book.book_name);
printf("\tAUTHOR NAME:%s\n",book.auth_name);
printf("\tNUMBER OF BOOKS IN OUR
LIBRARY:%d\n",book.book_quantity);
printf("\n");
i=i+book.book_quantity;
}
printf("\n\t\tTOTAL NUMBER OF BOOKS IN OUT LIBRARY is %d\n",i);
fclose(fb);
printf("\n\n\tPress Enter to go back");
if(getch())
mainmenu();
}
void search_books()
{
int d,i,f=0;
system("cls");
printf("\n\n\n\tSEARCH THE BOOKS.\n");
printf("\n\n\t 1. Search By ID");
printf("\n\n\t 2. Search By Name");
printf("\n\n\t 3. Go Back");
printf("\n\n\t Enter Your Choice\t");
fb=fopen(FILENAME,"rb+"); //open file for reading propose
switch(getch())
{
case '1':
{
system("cls");
for(int i=0;i<117;++i)
{
printf("#");
}
printf("\n\t\t\t\t\tSEARCH BOOKS BY ID.\n");
for(int i=0;i<117;++i)
{
printf("#");
}
printf("\n\tEnter the book ID:\t");
scanf("%d",&d);
printf("\n\t");
while(fread(&book,sizeof(book),1,fb)==1)
{
if(book.book_id==d)
{
sleep(1);
printf("\n\tThe entered book is available in our library\n");
printf("\n\tBOOK ID: %d\n",book.book_id);
printf("\n\tNAME OF THE BOOK:%s\n",book.book_name);
sleep(1);
f=1;
}
}
if(f==0)
{
printf("\n\n\t\aNo such record!\n");
}
printf("\n\n\tTry another search?(Y/N)\t");
if(getch()=='y'|| getch()=='Y')
search_books();
else
mainmenu();
break;
}
case '2':
{
char s[15];
char book_name[50]={0};
system("cls");
printf("\n\tSEARCH THE BOOKS BY NAME.\n");
printf("\n\tEnter the book name:");
fflush(stdin);
fgets(book_name,50,stdin);
printf("\n\t");
while(fread(&book,sizeof(book),1,fb)==1)
{
if(strcmp(book.book_name,(book_name))==0) //checks whether
book.name is equal to the book name or not
{
printf("\n\tThis book is available in our library\n");
printf("\n\tBOOK ID:%d\n",book.book_id);
printf("\n\tBOOK NAME:%s\n",book.book_name);
printf("\n\tAUTHOR NAME:%s\n",book.auth_name);
f=1;
}
}
if(f==0)
{
printf("\n\n\t\aNo such record\n");
}
printf("\n\n\tTry another search?(Y/N)\t");
if(getch()=='y' || getch()=='Y')
search_books();
else
mainmenu();
break;
}
case '3':
mainmenu();
default :
getch();
search_books();
}
fclose(fb);
}
void delete_books() //function that delete items from file fb
{
int d,f;
char another='y';
while(another=='y') //infinite loop
{
system("cls");
printf("\n\tDELETE BOOKS\n");
printf("\n\tEnter the ID of the book to be deleted:\t");
scanf("%d",&d);
fb=fopen(FILENAME,"rb+");
rewind(fb);
while(fread(&book,sizeof(book),1,fb)==1)
{
if(book.book_id==d)
{
printf("\n\tThe book record is available");
printf("\n\tThe book's name is %s",book.book_name);
sleep(1);
f=1;
}
}
if(f!=1)
{
printf("\n\tNo such record.");
sleep(1);
if(getch())
mainmenu();
}
if(f==1 )
{
printf("\n\n\tDo you want to delete it?(Y/N):\n");
if(getch()=='y'|| getch()=='Y')
{
ft=fopen("temp.dat","wb+"); //temporary file for delete
rewind(fb);
while(fread(&book,sizeof(book),1,fb)==1)
{
if(book.book_id!=d)
{
fseek(ft,0,SEEK_CUR);
fwrite(&book,sizeof(book),1,ft); //data gets written in temp file
'temp.dat'
}
}
fclose(ft);
fclose(fb);
remove(FILENAME);
rename("temp.dat",FILENAME); //copy all item from temporary file to
fb except that we are deleting it
fb=fopen(FILENAME,"rb+");
if(f==1)
{
printf("\n\tThe records have been deleted successfully!");
printf("\n\tDelete another record?(Y/N)");
}
}
else
mainmenu();
fflush(stdin);
another=getch();
}
}
mainmenu();
}
int check_book_id(int t) //check whether the book exists in the library or not for
adding or deleting
{
rewind(fb);
while(fread(&book,sizeof(book),1,fb)==1)
if(book.book_id==t)
{return 0;} //returns 0 if book exits
return 1; //return 1 if it not
}
void edit_book_credential(void) //edit information about book
{
system("cls");
int c=0,d;
printf("\n\n\tEDIT THE BOOK'S CRENDENTIALS");
char another='y';
while(another=='y')
{
printf("\n\n\tEnter the ID of the book to be edited:\t");
scanf("%d",&d);
fb=fopen(FILENAME,"rb+");
if(fb == NULL)
{
printf("File is not opened\n");
exit(1);
}
while(fread(&book,sizeof(book),1,fb)==1)
{
if(check_book_id(d)==0)
{
printf("\n\n\tThis book exists.");
printf("\n\n\tEnter the new name:");
fflush(stdin);
fgets(book.book_name,50,stdin);
printf("\n\tEnter the new author's name:");
fflush(stdin);
fgets(book.auth_name,25,stdin);
printf("\n\tThe record has been modified successfully!");
fseek(fb,ftell(fb)-sizeof(book),0);
fwrite(&book,sizeof(book),1,fb);
fclose(fb);
c=1;
}
if(c==0)
{
printf("\n\n\t\aNo such record");
}
}
printf("\n\tModify another record?(Y/N)\t");
fflush(stdin);
another=getch() ;
}
if(getch())
mainmenu();
}
