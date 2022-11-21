#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>     //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>
#include<windows.h>

struct Library // to call in program
{
    int books_id; // declare the integer data type
    int ISBN_Number;// declare the integer data type
    char bookName[20];// declare the character data type
    char authorName[20];// declare the character data type
    int edition[15];
};
struct Library r_book;

void addbooks(); // to display the add books screen
void deletebooks(); // to display the delete function
void searchbooks(); // to display search book function
void modifybooks(/*struct Library r_book,FILE *ptr*/); // to display the modify function
void displaybooks();  // to show display book function
void issuebooks(); //  to display issue book function
void exit_application(); // to exit

void returnfunc(void);
void menu();


void gotoxy(short x, short y)// declare the gotoxy function
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int wrong=1, count;//global variable for login function of int type
int i=0, valid=0;
char choice=0 ;

char answer;
int target=0,found=0;






void menu()
{
    system("cls");
    int choice = 0;
    do
    {

        printf("\n------------------------------------------------------------------------------------------------");
        gotoxy(20,2);
        printf("MAIN MENU");
        gotoxy(20,4);
        printf("\n------------------------------------------------------------------------------------------------");
        gotoxy(20,6);
        printf("\n\t\t\t1.Add Books");
        gotoxy(20,8);
        printf("\n\t\t\t2.Delete Books");
        gotoxy(20,10);
        printf("\n\t\t\t3.Search Books");
        gotoxy(20,12);
        printf("\n\t\t\t4.Modify Book");
        gotoxy(20,14);
        printf("\n\t\t\t5.Display Books");
        gotoxy(20,16);
        printf("\n\t\t\t6.Issue Book");
        gotoxy(20,18);
        printf("\n\t\t\t7.Exit");
        gotoxy(20,20);
        printf("\n\n\n\t\t\tEnter choice [1-7] => ");
        scanf("%d",&choice);
        switch(choice)
            {
                case 1:
                    addbooks();
                    break;
                case 2:
                    deletebooks();
                    break;
                case 3:
                    searchbooks(); //Lptr,ptr
                    break;
               // case 4:
                //    modifybooks();
                    break;
                case 5:
                    displaybooks();
                    break;
               // case 6:
               //     issuebooks();
                    break;
                case 7:
                    printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
                    exit(2);
                    break;
                default:
                    printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
            }                                         //Switch Ended
    }
    while(choice!=0);  //Loop Ended
}


int main() // declare main function
{
    //int i;


    menu();


    return 0;
}

void addbooks()
{
	FILE *ptr;
	ptr = fopen("SP.txt","a");
	system("cls");

	printf("\n\t\t****************************************************");
	printf("\n\t*********************ADD NEW BOOKS*********************");
	printf("\n\t\t******************************************************");
	printf("\n\n\t\t  ENTER YOUR DETAILS BELOW:");
	printf("\n\t\t------------------------------");

    answer = 'Y' ;


    while (answer == 'Y')
    {
        gotoxy(19,8);
        printf("Enter book serial no: ");
        fflush(stdin);
        scanf("%d",&r_book.books_id);
        fprintf(ptr,"%d",r_book.books_id);
        //fwrite (&r_book, sizeof ( r_book ), 1, ptr ) ;
        gotoxy(19,9);
        printf("Enter Book ISBN number: ");
        fflush(stdin);
        scanf("%d",&r_book.ISBN_Number);
        fprintf(ptr,"%d",r_book.ISBN_Number);
        //fwrite (&r_book, sizeof ( r_book ), 1, ptr ) ;
        gotoxy(19,10);
        printf("Enter Book Name: ");
        fflush(stdin);
        scanf("%s", r_book.bookName);
        fprintf(ptr,"%s", r_book.bookName);
        //fwrite (&r_book, sizeof ( r_book ), 1, ptr ) ;
        gotoxy(19,11);
        printf("Enter Book Author: ");
        fflush(stdin);
        scanf("%s", r_book.authorName);
        fprintf(ptr,"%s", r_book.authorName);
        //fwrite (&r_book, sizeof ( r_book ), 1, ptr ) ;
        gotoxy(19,12);
        printf("Enter Book Edition: ");
        fflush(stdin);
        scanf("%d",&r_book.edition);
        fprintf(ptr,"%d",r_book.edition);
        //fwrite (&r_book, sizeof ( r_book ), 1, ptr ) ;



        //fwrite(&r_book, sizeof(r_book),1,ptr);

        //fprintf(ptr,"%d %d %s %s %s \n\n",r_book.books_id, r_book.ISBN_Number, r_book.bookName, r_book.authorName, r_book.edition);
        //fclose(ptr);
        printf("\n\t SUCCESFULLY RECORDED.\n");

        printf("\n\t\t Do you want to add another book?[Y/N]:");
        scanf("%s",&answer);
        getch();
        while(toupper(answer)!='Y'&& toupper(answer)!='N')
        {
            printf("Invalid!\n\tDo you want to add book?[Y/N]:");
            scanf("%s",&answer);
        }

        if(toupper(answer)=='Y')
        {
            addbooks();
        }
        else
        {
            printf("\n\t\tPress any key to go to main menu.....");
            menu();
        }
     }


}

void deletebooks()
{

	int target;
	system("cls");
	printf("\n\t\t*************************************************");
	printf("\n\t***************Delete Books Details****************");
	printf("\n\t\t*************************************************");
	FILE *ptr,*dptr;
	ptr=fopen("SP.txt","r");
	printf("\n\nEnter Book ID NO. for delete:");
	scanf("%d",&target);
	dptr=fopen("SP2.txt","w+");
	if(ptr==NULL)
	{
		printf("\n\tNo Record in File!");
		printf("\n\t\t\tPress any key to Main Menu..");
		getch();
		menu();
	}
	else
	{
		while(fscanf(ptr,"%d %d %s %s %d \n\n",&r_book.books_id, &r_book.ISBN_Number, r_book.bookName, r_book.authorName, &r_book.edition)!=EOF)
		{
			if(target!=r_book.books_id)
			{
				fprintf(dptr,"%d %d %s %s %d \n\n",r_book.books_id, r_book.ISBN_Number, r_book.bookName, r_book.authorName, r_book.edition);
			}
			else
			{
				found=1;
			}
		}
		if(!found)
		{
			printf("\nRecord not found");
		}
		else
		{
			printf("\n\tRecord deleted successfully.....");
		}
		fclose(ptr);
		fclose(dptr);
		remove("SP.txt");
		rename("SP2.txt","SP.txt");
	}
	getch();
	menu();
}

void searchbooks()
{
    system("cls");
    int found=0, Choose, n;
    char id[40], a[40];
    FILE *ptr;
    system("cls");
    ptr=fopen("SP.txt","r");
    printf("\n\t\t******************************************************");
    printf("\n\t\t***************** SEARCH BOOKS LIST*******************");
    printf("\n\t\t******************************************************\n\n");

    while (Choose == 'y')
    {
        printf("How do you want to search book? \n1. By Book ISBN Number \n2. By Book name \n3. By Author name ");
        scanf("%d", &Choose);
        switch(Choose)
        {
            //int ISBN_No;
            //char book_name[20];
            //char author_name[20];
        case 1:
        printf("\nEnter Book ISBN Number to search:");
        fflush(stdin);
        scanf("%d",&n);

        printf("                                                                                     \n");
        printf(" Book ID NO. Book ISBN NO.  Book Name.   AUTHOR.    EDITION.  ");

        printf("\n=====================================================================================\n");
        while(fscanf(ptr,"%d %d %s %s %d \n\n",&r_book.books_id, &r_book.ISBN_Number, r_book.bookName, r_book.authorName, &r_book.edition)!=EOF)
        {
            if(strcmp(n,r_book.ISBN_Number)==0)
            {
                found=1;
                gotoxy(1,10);
                printf("%d",r_book.books_id);
                gotoxy(12,10);
                printf("%d",r_book.ISBN_Number);
                gotoxy(24,10);
                printf("%s",r_book.bookName);
                gotoxy(40,10);
                printf(" %s",r_book.authorName);
                gotoxy(56,10);
                printf(" %d",r_book.edition);
                break;
            }
        }
            break;
        case 2:
        printf("\nEnter Book Name to search:");
        fflush(stdin);
        scanf("%s",id);
        id[0]=toupper(id[0]);

        printf("                                                                                     \n");
        printf(" Book ID NO. Book ISBN NO.  Book Name.   AUTHOR.    EDITION.  ");

        printf("\n=====================================================================================\n");
        while(fscanf(ptr,"%d %d %s %s %d \n\n",&r_book.books_id, &r_book.ISBN_Number, r_book.bookName, r_book.authorName, &r_book.edition)!=EOF)
        {
            if(strcmp(id,r_book.bookName)==0)
            {
                found=1;
                gotoxy(1,10);
                printf("%d",r_book.books_id);
                gotoxy(12,10);
                printf("%d",r_book.ISBN_Number);
                gotoxy(24,10);
                printf("%s",r_book.bookName);
                gotoxy(40,10);
                printf(" %s",r_book.authorName);
                gotoxy(56,10);
                printf(" %d",r_book.edition);
                break;
            }
        }
        break;
        case 3:
            printf("\nEnter Author Name to search:");
            fflush(stdin);
        scanf("%s",a);
        a[0]=toupper(a[0]);

        printf("                                                                                     \n");
        printf(" Book ID NO. Book ISBN NO.  Book Name.   AUTHOR.    EDITION.  ");

        printf("\n=====================================================================================\n");
        while(fscanf(ptr,"%d %d %s %s %d \n\n",&r_book.books_id, &r_book.ISBN_Number, r_book.bookName, r_book.authorName, &r_book.edition)!=EOF)
        {
            if(strcmp(a,r_book.authorName)==0)
            {
                found=1;
                gotoxy(1,10);
                printf("%d",r_book.books_id);
                gotoxy(12,10);
                printf("%d",r_book.ISBN_Number);
                gotoxy(24,10);
                printf("%s",r_book.bookName);
                gotoxy(40,10);
                printf(" %s",r_book.authorName);
                gotoxy(56,10);
                printf(" %d",r_book.edition);
                break;
            }
        }
            break;
        default:


            if(!found) printf("\n\n\tNo Record");
            fclose(ptr);
            printf("\t\t\n\n\nPress any key to go to main menu.....");
            getch();
            menu();
        }

    }
}




/*void modifybooks()
{

    int i, found,target;
    char ch;
    int books_id;
    FILE *ptr, *modify;
    system("cls");
    printf("\n\t\t********************************************");
    printf("\n\t\t*******Edit Books Details*******************");
    printf("\n\t\t********************************************");

   ptr=fopen("Lib.exe","rb+");
   if(sfile==NULL)
   {

		printf("\n\t Can not open file!! ");
		getch();
		mainmenu();
   }
    gotoxy(15,6);
   printf("\tEnter Book ID NO. for edit:");
   scanf("%i",&target);
   gotoxy(15,8);
   modify=fopen("TempBook.txt","a+");
   if (modify==NULL)
   {
   	printf("\n File cannot be open...!");
   	getch();
   	printf("\n\nPress any key to go to main menu.......");
   	mainmenu();
   }
   else
   {
   	while(fscanf(sfile,"%i %s %s %s %s %i\n",&m.books_id,m.b_name,m.a_name,m.s_name,m.add,&m.days)!=EOF)
   	{
   		if(m.books_id==target)
   		{
   			found=1;
   			printf("\n\tBook ID NO.\t:%i\n\tBook Name\t:%s\n\tPublication\t:%s\n\tStudent Name\t:%s\n\tStudent Address\t:%s\n\tDue Days\t:%i\n",m.books_id,
			   															m.b_name,m.a_name,m.s_name,m.add,m.days);
			printf("\n\tEdit With New Records!");

   		}
   	}
   }
}*/

void displaybooks()
{
	system("cls");
	int i,e;
	FILE *ptr;
	system("cls");
	ptr=fopen("SP.txt","r");
	printf("\n\t\t\t*********************************************************");
	printf("\n\t\t\t**************** VIEW ALL BOOK RECORDS *****************");
	printf("\n\t\t\t*********************************************************");
	if(ptr==NULL)
	{
		printf("\n\n\t\t RECORD EMPTY");
		getch();
	}
	else
	{
		gotoxy(1,6);
		printf("Book Id NO.");
		gotoxy(13,6);
		printf("Book ISBN NO.");
		gotoxy(30,6);
		printf("Book Name");
		gotoxy(45,6);
		printf("Author Name");
		gotoxy(63,6);
		printf("Edition");
		gotoxy(83,6);

		for(i=0;i<95;i++)
		{
			printf("-");
		}
		e=8;
		//while(fscanf(ptr,"%d %d %s %s %d \n\n",&r_book.books_id, &r_book.ISBN_Number, r_book.bookName, r_book.authorName, &r_book.edition)!=EOF)
		//{
			gotoxy(1,e);
			printf("%d",r_book.books_id);
			gotoxy(13,e);
			printf("%d",r_book.ISBN_Number);
			gotoxy(30,e);
			printf("%s",r_book.bookName);
			gotoxy(45,e);
			printf("%s",r_book.authorName);
			gotoxy(63,e);
			printf("%d",r_book.edition);
			e++;
		//}
		printf("\n");
		for(i=0;i<95;i++)
		printf("-");
	}
	printf("\n\n\t Press any key for main menu........");
	fclose(ptr);
	getch();
	menu();
}

