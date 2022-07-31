#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct details
{
  char name[20];
  char password[20];
  int metro_num;
  int num_of_seats;
  float charge;
  char date[20];
};



//function prototypes to be used
void registration();
void reservation(void);							//main reservation function
void viewdetails(void);							//view details of all the trains
void cancel(void);
void printticket(char name[],int,int,float,char date[]);	//print ticket
void specificmetro(int);						//print data related to specific train
float charge(int,int);							//charge automatically w.r.t number of seats and train
void view_ticket();
void display_all();
void change_reservation();

int main()

{
    menu:
		system("cls");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|              BY JOGA ROSHINI AND ASHA         |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n Press any key to continue:");

	getch();
	system("cls");

    int menu_choice,choice_return;
    start:
	system("cls");
	printf("\n\t\t\t\t=================================\n");
	printf("\t\t\t\t    METRO RESERVATION SYSTEM");
	printf("\n\t\t\t\t=================================");
  printf("\n\n--------------------------------------");
	printf("\n1>> registration");
  printf("\n\n--------------------------------------");
	printf("\n2>> Reserve A Ticket");
	printf("\n\n--------------------------------------");
  printf("\n3>> display the Ticket");
	printf("\n\n---------------------------------------");
	printf("\n4>> View All Available METRO'S");
	printf("\n\n---------------------------------------");
	printf("\n5>> Cancel ticket");
	printf("\n\n---------------------------------------");
  printf("\n6>> display all registered users ");
	printf("\n\n---------------------------------------");
  printf("\n7>> Change your date of boarding ");
	printf("\n\n---------------------------------------");
	printf("\n8>> Exit");
	printf("\n\n===================================================");
  printf("\n\n please enter your choice : ");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
    case 1: system("cls");
            registration();
            break;
    case 2: system("cls");
              reservation();
               break;
    case 3: system("cls");
             view_ticket();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
              break;
    case 4: system("cls");
             viewdetails();
          			printf("\n\nPress any key to go to Main Menu..");
          			getch();
                        break;
		case 5:system("cls");
			cancel();
		  printf("\n\nPress any key to go to Main Menu..");
      getch();
      break;

      case 6:system("cls");
        display_all();
        printf("\n\nPress any key to go to Main Menu..");
        getch();
        break;

        case 7: system("cls");
            change_reservation();
            printf("\n\n\npress any key to go back to the main menu ");
            getch();
            break;

      	case 8:system("cls");
    			return(0);
    			break;

		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);

}


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



void registration()
{
    FILE *fp;
    struct details d;

    char user[10];


    fp=fopen("roshini.txt","a+");

    printf(" please enter the details below: ");
    first:
    printf("\n\n\n enter username: ");
    scanf("%s",user);

    while(1)
    {
        fread(&d,sizeof(d),1,fp);

        if(feof(fp))
        {
            break;
        }
        if(strcmp(d.name,user)==0)
        {

                printf("\n\n\n this username already exists . please try again!!");
                goto first;
        }
    }

    strcpy(d.name,user);

    printf("\n enter password  :");
    scanf("%s",d.password);



    fwrite(&d,sizeof(d),1,fp);

    fclose(fp);

    printf("\n\n\t\t\t  registration succesful  ");
    printf("\nPress any key to go back to  Main menu!\n\n");

    getch();
}



void reservation(void)

{

  printf(" **** ONLY A REGISTERED USER CAN MAKE RESERVATION. IF YOU HAVE'NT REGISTERED YET, PLEASE COMPLETE THE REGISTRATION FIRST ****");

  char confirm;
  int i=0;

      char name[20],pass[20],date[20];
      FILE *fp,*fp1;
      struct details d,d1;

      int found=0,count=0;

      fp=fopen("roshini.txt","r+");
      fp1=fopen("copy.txt","w+");


      printf("\n\n\n enter username: ");
      scanf("%s",name);

      printf("\n enter password  :");
      scanf("%s",pass);

      while(1)
      {
          fread(&d,sizeof(d),1,fp);

          if(feof(fp))
          {
              break;
          }
          if((strcmp(d.name,name)==0)&&(strcmp(d.password,pass)==0))
          {
              found=1;
              fflush(stdin);


              printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");

              printf("\n\n\n Enter the DATE of travelling in dd-mm-yyyy format :");
              scanf("%s",date);
              strcpy(d.date,date);
              printf("\n\n\nEnter Number of seats:> ");
            	scanf("%d",&d.num_of_seats);
            	printf("\n\n>>Press Enter To View Available metro stations<< ");
            	getch();
            	system("cls");
            	viewdetails();
            	printf("\n\nEnter metro number:> ");

              stard1:
            	scanf("%d",&d.metro_num);
            	if(d.metro_num>=1 && d.metro_num<=26)
            	{
            		d.charge=charge(d.metro_num,d.num_of_seats);
            		printticket(d.name,d.num_of_seats,d.metro_num,d.charge,d.date);
            	}
            	else
            	{
            		printf("\nInvalid metro Number! Enter again--> ");
            		goto stard1;
            	}
              printf("\n\nConfirm Ticket (y/n):>");
            	start:
            	scanf(" %c",&confirm);
            	if(confirm == 'y')
            	{

                fwrite(&d,sizeof(d),1,fp1);
            		printf("==================================");
            		printf("\n Reservation Done\n");
            		printf("==================================");
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




          }
          else
          {
              fwrite(&d,sizeof(d),1,fp1);
          }
      }
      fclose(fp);
      fclose(fp1);

      if(found==0)
      {
          printf(" YOU ARE NOT A REGISTERED USER\n\n");
          printf("\n\n press any key to go to main menu \n");
      }
      else
      {
          fp=fopen("roshini.txt","w+");
          fp1=fopen("copy.txt","r+");

          while(1)
          {
              fread(&d,sizeof(d),1,fp1);

              if(feof(fp1))
              {
                  break;
              }
              fwrite(&d,sizeof(d),1,fp);
          }

      }
      fclose(fp);
      fclose(fp1);
      getch();
}


void printticket(char name[],int num_of_seats,int metro_num,float charges,char date[])
{
	//system("cls");
	printf("---------------------------------------------\n");
	printf("\tTICKET\n");
	printf("--------------------------------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nmetro Number:\t\t%d",metro_num);
	specificmetro(metro_num);
	printf("\nCharges:\t\t%.2f",charges);
  printf("\n DATE OF TRAVELLING : %s",date);
}


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



//cancelling a ticket
void cancel()
{
  char name[20],pass[20];
 FILE *fp,*fp1;
 struct details d,d1;

 int found=0,count=0;

 fp=fopen("roshini.txt","r");
 fp1=fopen("copy.txt","w");

 printf("\n\n\nenter username and password of the user whose ticket you want to cancel : ");

 printf("\nENTER USERNAME: ");
 scanf("%s",name);

 printf("\nENTER PASSWORD  :");
 scanf("%s",pass);


 while(1)
 {
     fread(&d,sizeof(d),1,fp);

     if(feof(fp))
     {
         break;
     }
     if((strcmp(d.name,name)==0)&&(strcmp(d.password,pass)==0))
     {
         found=1;
         printf("\n\nYOUR TICKET WAS : \n\n\n");
         printticket(d.name,d.num_of_seats,d.metro_num,d.charge,d.date);

         d.num_of_seats=0;
         d.metro_num=0;
         printf("\n\n The ticket has been cancelled !! \n\n");
         printf("\n amount refunded = %f ",d.charge);
         d.charge=0;

         printf("\n\n\ndetails after cancelling the ticket : ");
         printf("\nName:\t\t\t%s",d.name);
       	printf("\nNumber Of Seats:\t%d",d.num_of_seats);
       	printf("\nmetro Number:\t\t%d",d.metro_num);

     }
     else
     {
         fwrite(&d,sizeof(d),1,fp1);
     }
 }
 fclose(fp);
 fclose(fp1);

 if(found==0)
 {
     printf("\n  user not found ");
     printf("\n\n enter any key to go to main menu");
 }
 else
 {
     fp=fopen("roshini.txt","w");
     fp1=fopen("copy.txt","r");

     while(1)
     {
         fread(&d,sizeof(d),1,fp1);

         if(feof(fp1))
         {
             break;
         }
         fwrite(&d,sizeof(d),1,fp);
     }
 }
 fclose(fp);
 fclose(fp1);
 getch();
}




void view_ticket()
{

 int ctr=0;

 char name[20],pass[20];
 FILE *fp;
 struct details d;


 fp=fopen("roshini.txt","r");



 printf("\n\nENTER USERNAME: ");
 scanf("%s",name);

 printf("\nENTER PASSWORD  :");
 scanf("%s",pass);



 while(1)
 {
     fread(&d,sizeof(d),1,fp);

     if(feof(fp))
     {
         break;
     }
     if((strcmp(d.name,name)==0)&&(strcmp(d.password,pass)==0))
     {

         ctr=1;
         printticket(d.name,d.num_of_seats,d.metro_num,d.charge,d.date);

     }
 }
 fclose(fp);


 if(ctr==0)
 {
     printf("\n\n\t\t\t\t you are not a registered  user\n\n\n\n");
 }

}




void display_all()
{
    FILE *fp;
    struct details d;

    fp=fopen("roshini.txt","r+");

    printf("\t\t\t ALL REGISTERED USERS :\n\n\n");
      printf("--------------------------------------------\n\n");
    while(1)
    {
        fread(&d,sizeof(d),1,fp);

        if(feof(fp))
        {
            break;
        }

      	printf("\nName:\t\t%s",d.name);


    }
  printf("\n***********************************************************************\n\n");

  fclose(fp);
}






void change_reservation()
{

    char new_date[20];
    int ctr=0;              //counter
    char ch;

    char name[20],pw[20];
    FILE *fp,*fp1;
    struct details d;
  fp=fopen("roshini.txt","r");
  fp1=fopen("copy.txt","w");

   printf("**********************CHANGING THE DATE OF BOARDING***************************\n\n");
    printf("\n\n\nPlease enter the username and password of the user whose date you want to change :  ");
    printf("\n\nENTER USERNAME: ");
    scanf("%s",name);

    printf("\nENTER PASSWORD  :");
    scanf("%s",pw);

    while(1)
    {
        fread(&d,sizeof(d),1,fp);

        if(feof(fp))
        {
            break;
        }
        if((strcmp(d.name,name)==0)&&(strcmp(d.password,pw)==0))
        {

            ctr=1;
            printf("\n\n previous date of boarding was :  %s",d.date);
            printf("\n\n\n please enter the new date of boarding in dd-mm-yyyy format :");
            scanf("%s",new_date);

            strcpy(d.date,new_date);
            fwrite(&d,sizeof(d),1,fp1);

            printf("\n\n new date of boarding is : %s",d.date);

            printf("\n\n\nyour ticket after changing the date  is : \n\n\n");
            printticket(d.name,d.num_of_seats,d.metro_num,d.charge,d.date);





        }
        else
        {

            fwrite(&d,sizeof(d),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if(ctr==0)
    {
        printf("\n\nuser not found !!\n\n");
    }
    else
    {
        fp=fopen("roshini.txt","w");
        fp1=fopen("copy.txt","r");

        while(1)
        {
            fread(&d,sizeof(d),1,fp1);

            if(feof(fp1))
            {
                break;
            }
            fwrite(&d,sizeof(d),1,fp);
        }

    }
    fclose(fp);
    fclose(fp1);

}
