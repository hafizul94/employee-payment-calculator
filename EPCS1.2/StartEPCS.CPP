/****************************************************************************
*	UNIVERSITI TUN HUSSEIN ONN MALAYSIA									    *
*	LECTURER'S NAME:	AZIZUL AZHAR BIN RAMLI							    *
*	SUBJECT: ALGORITHM AND PROGRAMMING (BIC 10204 SECTION 3)			    *
*																            *
*	PROJECT QUESTION 8:	EMPLOYEE PAYMENT CALCULATOR SYSTEM  (V1.2)          *
*	GROUP MEMBERS:		1. MOHD HAFIZUL AFIFI BIN ABDULLAH	(AI130061)      *
*						2. NURSHAFIZA BINTI W.MINI  (AI130117)              *
*						3. NURUL FARHANA BINTI MOHAMED TAHIR    (AI130178)  *
*						4. SITI NA'AISHAH BINTI AZMI    (AI130103)          *
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
struct data{int piece_amount;float hourly_total;float hourly_overtime;
			float man_salary;float hourly_wage;
			float comm_sales;float piece_wages;float pay;
			};
struct data p;
int paycode=0;
float comm_fixed=250,total_pay=0;
/*GLOBAL VARIABLES*/
char projectname[]="EMPLOYEE PAYMENT CALCULATOR SYSTEM";
char user[100];
int counter[5]={0,0,0,0,0};   //looping counter declaration

/*FUNCTION PROTOTYPES*/
void header(int);
void pause();
void dateandtime();
void uthmlogo();
void helpwiz(int);

int main()
{


    system("COLOR 70");
    header(paycode);
    printf("\n\tWelcome to %s",projectname);
    printf("\n\n\tPlease enter your name: ");
    gets(user);

    while(paycode!=-1)                              //if paycode entered is -1, program terminates
    {
	paycode=0;
	header(paycode);
	printf("\n\tSelect worker to be paid by entering the Paycode.");
	printf("\n\t1. Manager (Paycode: 1)");
	printf("\n\t2. Hourly Worker (Paycode: 2)");
	printf("\n\t3. Commission Worker (Paycode: 3)");
	printf("\n\t4. Pieceworker (Paycode: 4)");
	printf("\n\n\t-1 to terminate program");
	printf("\n\t-2 to view the Help Wizard");
	printf("\n\n");
	printf("\n\tPlease enter the Paycode: ");
	scanf("%d",&paycode);

	switch(paycode)
	{
	    case 1:			//if MANAGER selected, run this code
	    {
		header(paycode);
		++counter[1];
		printf("\n\tManager Selected.");
		printf("\n\tEnter weekly salary: ");
		scanf("%f",&p.man_salary);
		if (p.man_salary>0)
		{
		    p.pay=p.man_salary;
		    printf("\n\tThe manager's pay is $%.2f",p.pay);
		    total_pay+=p.pay;
		}
		else
		{
		    printf("\n\tManager's salary cannot be negative value.");
		    printf("\n\tNo payment made.");
		    --counter[1];
		}
		pause();
	    }
	    break;
	    case 2:			//if HOURLY WORKER selected, run this code
	    {
		header(paycode);
		++counter[2];
		printf("\n\tHourly Worker Selected.");
		printf("\n\tEnter hourly salary: ");
		scanf("%f",&p.hourly_wage);
		printf("\n\tEnter total hours worked: ");
		scanf("%f",&p.hourly_total);
		if (p.hourly_wage>0&&p.hourly_total>0)
		{
		    if (p.hourly_total>40)
		    {
			p.hourly_overtime=p.hourly_total-40;
			p.pay=(40*p.hourly_wage)+(p.hourly_overtime*1.5*p.hourly_wage);
			printf("\n\tWorker worked %.2f overtime hours",p.hourly_overtime);
			printf("\n\tWorker's pay is $%.2f",p.pay);
			total_pay+=p.pay;
		    }
		    else
		    {
			p.pay=(p.hourly_total*p.hourly_wage);
			printf("\n\tWorker has not worked for overtime hours");
			printf("\n\tWorker's pay is $%.2f",p.pay);
			total_pay+=p.pay;
		    }
		}
		else
		{
		    printf("\n\tBoth worker's hourly salary and total working "
			   "\n\thours cannot be negative value.");
		    printf("\n\tNo payment made.");
		    --counter[2];
		}
		pause();
	    }
	    break;
	    case 3:			//if COMMISSION WORKER selected, run this code
	    {
		header(paycode);
		++counter[3];
		printf("\n\tCommission Worker Selected.");
		printf("\n\tEnter gross weekly sales: ");
		scanf("%f",&p.comm_sales);
		if (p.comm_sales>0)
		{
		    p.pay=((5.7/100)*p.comm_sales)+comm_fixed;
		    printf("\n\tCommission worker's pay is $%.2f",p.pay);
		    total_pay+=p.pay;
		}

		else
		{
		    printf("\n\tCommission Worker's gross weekly sales cannot "
			   "\n\tbe negative value.");
		    printf("\n\tNo payment made.");
		    --counter[3];
		}
		pause();
	    }
	    break;
	    case 4:			//if PIECEWORKER selected, run this code
	    {
		header(paycode);
		++counter[4];
		printf("\n\tPieceworker Selected.");
		printf("\n\tEnter number of pieces: ");
		scanf("%d",&p.piece_amount);
		printf("\n\tEnter wage per piece: ");
		scanf("%f",&p.piece_wages);
		if (p.piece_amount>0&&p.piece_wages>0)
		{
		    p.pay=p.piece_wages*p.piece_amount;
		    printf("\n\tPieceworker's pay is $%.2f",p.pay);
		    total_pay+=p.pay;
		}
		else
		{
		    printf("\n\tBoth number of piece and wage per piece cannot "
			   "\n\tbe negative value.");
		    printf("\n\tNo payment made.");
		    --counter[4];
		}
		pause();
	    }
	    break;
	    case -1: 		//if TERMINATE selected, run this code
	    {
		header(paycode);
		printf("\n\tComputation completed!");

		FILE *receipt;
		receipt=fopen("receipt.txt","w");
		fprintf(receipt,"\n\tPayment issued by: %s",user);
		fprintf(receipt,"\n\tReceipt generated on: ");
		time_t mytime;
		mytime=time(NULL);
		fprintf(receipt,(ctime(&mytime)));
		fprintf(receipt,"\n\t1. %d Manager(s) have been paid.",counter[1]);
		fprintf(receipt,"\n\t2. %d Hourly worker(s) have been paid.",counter[2]);
		fprintf(receipt,"\n\t3. %d Commission worker(s) have been paid.",counter[3]);
		fprintf(receipt,"\n\t4. %d Pieceworker(s) have been paid.",counter[4]);
		fprintf(receipt,"\n\n\tTOTAL PAYMENT made is $%.2f",total_pay);
		fclose(receipt);
		printf("\a\a\a\a\a\a\a\a\a");
		printf("\n\n\tYour text receipt is ready."
		       "\n\tCheck for receipt.txt in folder.");
		pause();
	    }
	    break;
	    case -2: 		//if HELP selected, run this code
	    {
		helpwiz(paycode);
	    }
	    break;
	    default: 		//if INVALID paycode entered, run paycode input cycle
	    {
		header(paycode);
		printf("\n\tPaycode INVALID.");
		printf("\n\tPress any key to back to menu.");
		pause();
	    }
	}
    }
    header(paycode);
    printf("\n\tHere is summary for your actions:");
    printf("\n\t1. %d Manager(s) have been paid.",counter[1]);
    printf("\n\t2. %d Hourly worker(s) have been paid.",counter[2]);
    printf("\n\t3. %d Commission worker(s) have been paid.",counter[3]);
    printf("\n\t4. %d Pieceworker(s) have been paid.",counter[4]);
    printf("\n\n\tTOTAL PAYMENT made is $%.2f",total_pay);
    pause();
    header(paycode);
    printf("\n\t-------------------------------------------------"
	   "\n\tThank you for using this program."
	   "\n\tDrop us a line at ai130061@siswa.uthm.edu.my"
	   "\n\t-------------------------------------------------");
    pause();
    system("cls");
    printf("\n\n\n\t");
    uthmlogo();
    printf("\n\t-------------------------------------------------"
	   "\n\t\tThis program will now QUIT. Bye!"
	   "\n\t-------------------------------------------------");
    return 0;
}

void header(int paycode)
{
    system("cls");
    printf("\n");
    printf("\t+-----------------------------------------------+\n");
    printf("\t|\t%s\t|\n",projectname);
    printf("\t+-----------------------------------------------+\n");
    dateandtime();
    printf("\n\t");
    if (paycode==-2)
    {
	printf("\n\t\t===Welcome to the Help Wizard.===\n");
    }
}

void pause()
{
    printf("\n\n");
    system("PAUSE");
}

void dateandtime()
{
	time_t mytime;
	mytime=time(NULL);
	printf("\tVersion 1.2\t");
	printf(ctime(&mytime));
}

void uthmlogo()
{
    printf("************   *UU*   *UU* .TTTTTTTT *HH* *HH*   *MM        MM*"
    "\n\t*          *    UU     UU      TT     HH   HH    MM MM    MM MM"
    "\n\t*    oo    *    UU     UU      TT     HH...HH   .MM  MM   MM MM."
    "\n\t*  oooooo  *    UU     UU      TT     HH***HH   MM   .MM MM.  MM"
    "\n\t*   oooo   *    UU.   uUU      TT     HH   HH  .MM    MM MM   MM."
    "\n\t*   ,  ,   *     UUUUU*UU.    .TT.   .HH   HH. MM.     .M.    .MM"
    "\n\t *   **    *     ------------------------------------------------"
    "\n\t  * ^  ^  *      Universiti    Tun     Hussein    Onn    Malaysia"
    "\n\t     **"
    "\n\n\tDengan Hikmah Kita Meneroka.\tWWWE: With Wisdom We Explore.\n\n\t");
}

void helpwiz(int paycode)
{
     header(paycode);
     printf("\n\tABOUT:"
	    "\n\tThis program is used to calculate payment for"
	    "\n\tworkers based on 4 roles:"
	    "\n\t\t1. Manager"
	    "\n\t\t2. Hourly Worker"
	    "\n\t\t3. Commission Worker"
	    "\n\t\t4. Pieceworker"
	    "\n\tUser is required to enter Paycode as input to"
	    "\n\tinstruct the program to do computations.");
    printf("\n\n\t-------------------------------------------------");
    printf("\n\tPage: 1/4\tPress any key to navigate next.");
    pause();
    header(paycode);
    printf("\n\tINCLUDED IN THE PACKAGE:");
    printf("\n\t1. Arithmetic Operation"
	   "\n\t2. Conditional Statement"
	   "\n\t3. Repitition/ Looping"
	   "\n\t4. Functions"
	   "\n\t5. File Input/ Output"
	   "\n\t6. Array"
	   "\n\t7. Pointer"
	   "\n\t8. Structure");
    printf("\n\n\t-------------------------------------------------");
    printf("\n\tPage: 2/4\tPress any key to navigate next.");
    pause();
    header(paycode);
    printf("\n\tREFERENCES:"
            "\n\t1. BIC10204: Algorithm and Programming lecture"
            "\n\t   notes by Mr. Azizul Azhar bin Ramli");
    printf("\n\t2. D'Orazio, H. T. (1999). C Programming for "
            "\n\t   Engineering & Computer Science. Singapore:"
            "\n\t   McGraw-Hill.");
    printf("\n\t3. Sukhendu Dey, D. D. (2009). COMPLETE KNOWLEDGE "
           "\n\t   IN C. Oxford, U.K.: Alpha Science International "
           "\n\t   Ltd.");
    printf("\n\n\t-------------------------------------------------");
    printf("\n\tPage: 3/4\tPress any key to navigate next.");
    pause();
    header(paycode);
    printf("\n\tGNU General Public License:");
    printf("\n\tThis program is free software; you can redistribute"
	   "\n\tit and/or modify it under the terms of the "
	   "\n\tGNU General Public License as published by the "
	   "\n\tFree Software Foundation; either version 2 of the "
	   "\n\tLicense, or (at your option) any later version.\n"
	   "\n\tThis program is distributed in the hope that it will "
	   "\n\tbe useful, but WITHOUT ANY WARRANTY; without even "
	   "\n\tthe implied warranty of MERCHANTABILITY or FITNESS "
	   "\n\tFOR A PARTICULAR PURPOSE."
	   "\n\tSee the GNU General Public License for more details.\n"
	   "\n\tYou should have received a copy of the "
	   "\n\tGNU General Public License along with this program; "
	   "\n\tif not, write to the Free Software Foundation, Inc., "
	   "\n\t675 Mass Ave, Cambridge, MA 02139, USA.");
    printf("\n\n\t-------------------------------------------------");
    printf("\n\tPage: 4/4\tPress any key to back to main menu.");
    pause();
}
