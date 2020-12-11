# roshini
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char name[50];
	int metro_num;
	int num_of_seats;
}pd;




//function prototypes to be used
void reservation(void);							//main reservation function
void viewdetails(void);							//view details of all the trains
void cancel(void);
void printticket(char name[],int,int,float);	//print ticket
void specificmetro(int);						//print data related to specific train
float charge(int,int);							//charge automatically w.r.t number of seats and train
void login(void);
void refund(void);




/******************************************FUNCTION DECLARATION**********************************************************/
/*********************************************MAIN()*************************************************/


int main()

{
    menu:
		system("cls");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|       METRO TICKET RERSERVATION SYSTEM        |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|          BY JOGA ROSHINI AND ASHA             |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n Press any key to continue:");

	getch();
	system("cls");
	login();
    int menu_choice,choice_return;
    start:
	system("cls");
	printf("\n=================================\n");
	printf("    METRO RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n------------------------");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> Show all METRO stations.");
	printf("\n------------------------");
	printf("\n3>> Cancel ticket");
	printf("\n------------------------");
	printf("\n4>> REFUND");
	printf("\n------------------------");
	printf("\n5>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
	     case 1: system("cls");
              reservation();
               break;
        case 2: system("cls");
             viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
              break;
		case 3:system("cls");
			cancel();
			break;
		case 4:system("cls");
			refund();
			break;
        case 5:system("cls");
			return(0);
			break;

		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);

}
void reservation(void);							//main reservation function
void viewdetails(void);							//view details of all the trains
void cancel(void);
void printticket(char name[],int,int,float);	//print ticket
void specifictrain(int);						//print data related to specific train
float charge(int,int);

/**VIEWDETAILS()*/

//The function is yet not completed, need more details to be added!
//timings of the trains are still missing


void viewdetails(void)

{
        system("cls");
	printf("-----------------------------------------------------------------------------");
	printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\n");
	printf("-----------------------------------------------------------------------------");
    printf("\n1\tMiyapur to JNTU college: Rs.10/-");
	printf("\n2\tMiyapur to KPHB colony: Rs 15");
	printf("\n3\tMiyapur to Kukatpally: Rs 25");
	printf("\n4\tMiyapur to Kukatpally Y junction: Rs 30");
	printf("\n5\tMiyapur to Moosapet: Rs 30");
	printf("\n6\tMiyapur to Bharat Nagar: Rs 30");
	printf("\n7\tMiyapur to Erragadda: Rs 35");
	printf("\n8\tMiyapur to ESI Hospital: Rs 35");
	printf(" \n9\tMiyapur to SR Nagar: Rs 40");
	printf(" \n10\tMiyapur to Ameerpet: Rs 40");
	printf("\n11\tMiyapur to Punjagutta: Rs 40");
	printf("\n12\tMiyapur to Erramanzil: Rs 40");
	printf("\n13\tMiyapur to Khairatabad: Rs 45");
	printf("\n14\tMiyapur to Lakdi-Ka-Pool: Rs 45");
	printf("\n15\tMiyapur to Assembly: Rs 45");
	printf("\n16\tMiyapur to Nampally: Rs 45");
	printf("\n17\tMiyapur to Gandhi Bhavan: Rs 50");
	printf("\n18\tMiyapur to Osmania Medical College: Rs 50");
	printf("\n19\tMiyapur to MG Bus Station: Rs 50");
	printf("\n20\tMiyapur to Malakpet: Rs 50");
	printf("\n21\tMiyapur to New Market: Rs 50");
	printf("\n22\tMiyapur to Musarambagh: Rs 55");
	printf("\n23\tMiyapur to Dilukhnagar: Rs 55");
	printf("\n24\tMiyapur to Chaitanyapuri: Rs 55");
	printf("\n25\tMiyapur to Victoria Memorial: Rs 60");
	printf("\n26\tMiyapur to LB Nagar : Rs 60");

}

/***RESERVATION()***/

void reservation(void)

{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available metro stations<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter metro number:> ");
	start1:
	scanf("%d",&passdetails.metro_num);
	if(passdetails.metro_num>=1 && passdetails.metro_num<=26)
	{
		charges=charge(passdetails.metro_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.metro_num,charges);
	}
	else
	{
		printf("\nInvalid metro Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.metro_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

/*********************************************CHARGE()*************************************************/

float charge(int metro_num,int num_of_seats)
{
		if (metro_num==1)
	{
		return(10.0*num_of_seats);
	}
	if (metro_num==2)
	{
		return(15.0*num_of_seats);
	}
	if (metro_num==3)
	{
		return(25.0*num_of_seats);
	}
	if (metro_num==4)
	{
		return(30.0*num_of_seats);
	}
	if (metro_num==5)
	{
		return(30.0*num_of_seats);
	}
	if (metro_num==6)
	{
		return(35.0*num_of_seats);
	}
	if (metro_num==7)
	{
		return(35.0*num_of_seats);
	}
	if (metro_num==8)
	{
		return(40.0*num_of_seats);
	}
	if (metro_num==9)
	{
		return(40.0*num_of_seats);
	}
	if (metro_num==10)
	{
		return(40.0*num_of_seats);
	}
	if (metro_num==11)
    {
        return(40.0*num_of_seats);
    }

      if (metro_num==12)
	{
		return(45.0*num_of_seats);
	}
	 if (metro_num==13)
	{
		return(45.0*num_of_seats);
	}
	 if (metro_num==14)
	{
		return(45.0*num_of_seats);
	}
	if (metro_num==15)
	{
		return(45.0*num_of_seats);
	}
	if (metro_num==16)
	{
		return(45.0*num_of_seats);
	}
    if (metro_num==17)
	{
		return(50.0*num_of_seats);
	}
	if (metro_num==18)
	{
		return(50.0*num_of_seats);
	}
	if (metro_num==19)
	{
		return(50.0*num_of_seats);
	}
	if (metro_num==20)
	{
		return(55.0*num_of_seats);
	}
	if (metro_num==21)
	{
		return(55.0*num_of_seats);
	}
	if (metro_num==22)
	{
		return(55.0*num_of_seats);
	}
	if (metro_num==23)
	{
		return(55.0*num_of_seats);
	}
	if (metro_num==24)
	{
		return(60.0*num_of_seats);
	}

	if (metro_num==25)
	{
		return(60.0*num_of_seats);
	}
	if (metro_num==26)
	{
		return(65.0*num_of_seats);
	}

}


/*********************************************PRINTTICKET()*************************************************/

void printticket(char name[],int num_of_seats,int metro_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nmetro Number:\t\t%d",metro_num);
	specificmetro(metro_num);
	printf("\nCharges:\t\t%.2f",charges);
}

/*********************************************SPECIFICTRAIN()*************************************************/

void specificmetro(int metro_num)
{

	if (metro_num==1)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to JNTU college");
		printf("\nDeparture:\t\t9am ");
	}
	if (metro_num==2)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to KPHB colony");
		printf("\nDeparture:\t\t12pm");
	}
	if (metro_num==3)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Kukatpally");
		printf("\nDeparture:\t\t8am");
	}
	if (metro_num==4)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Kukatpally Y junction");
		printf("\nDeparture:\t\t11am ");
	}
	if (metro_num==5)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Moosapet");
		printf("\nDeparture:\t\t7am");
	}
	if (metro_num==6)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Bharat Nagar");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (metro_num==7)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Erragadda");
		printf("\nDeparture:\t\t1pm ");
	}
	if (metro_num==8)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\n Destination:\t\tMiyapur to ESI Hospital");
		printf("\nDeparture:\t\t4pm ");
	}
	if (metro_num==9)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to SR Nagar");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (metro_num==10)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Ameerpet");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==11)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Punjagutta");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==12)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Erramanzil");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==13)
	{printf("\nmetro:\t\t\tMetro Express");

		printf("\nDestination:\t\tMiyapur to Khairatabad");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==14)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to lakdi ka pool");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==15)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Assembly");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==16)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Nampally");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==17)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Gandhi Bhavan");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==18)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Osmania Medical College");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==19)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to MG Bus Station");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==20)
	{
        printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Malakpet");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==21)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to New Market");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==22)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Musarambagh");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==23)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Dilukhnagar");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==24)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to Chaitanyapuri");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==25)
	{
		printf("\nmetro:\t\t\tMiyapur to Victoria Memorialo Express");
		printf("\nDestination:\t\t");
		printf("\nDeparture:\t\t1.15 ");
	}
	if (metro_num==26)
	{
		printf("\nmetro:\t\t\tMetro Express");
		printf("\nDestination:\t\tMiyapur to LB Nagar");
		printf("\nDeparture:\t\t1.15 ");
	}

}
void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="rosh";
    char pass[10]="pass";
    do
{

    printf("\n  =======================REGISTER/LOGIN FORM  =======================\n  ");
    printf(" \n                       SELECT/ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       SELECT/ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"rosh")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOU ARE REGISTERED/LOGGED IN SUCCESSFULLY");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  REGISTER/LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen
		system("cls");
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



void cancel(void)
{
	/*FILE *f,*t;
	int i=0;
	int metronum;
	t=fopen("seats_reserved.txt","w");
	if ((f=fopen("seats_reserved.txt","r"))==NULL);
	{
		printf("NO RECORD ADDED.");
		main();
		* * * * *
		*
		*
		*
		*
		*
		*
		*  /  missing codes  /
	}
	else*/
	system("cls");
	int metro_num;
	printf("-----------------------\n");
		printf("Enter the station number: \n");
			printf("-----------------------\n");
		fflush(stdin);
		scanf("%i",&metro_num);
		if (metro_num==23)
        {
        printf("\n\nYour ticket has been Cancelled\tTHANK YOU.");
        }
        else
            printf("invalid");
		getch();
}
void refund(void)
{
    system("cls");
	int metro_num;
	printf("-----------------------\n");
		printf("Enter the station number: \n");
			printf("-----------------------\n");
		fflush(stdin);
		scanf("%i",&metro_num);
		if (metro_num==23)
        {
        printf("\n\nYour refund is being initiated.");
        }
        else
            printf("invalid");
		getch();
}





