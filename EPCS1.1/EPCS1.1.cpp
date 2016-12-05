/****************************************************************************
*	UNIVERSITI TUN HUSSEIN ONN MALAYSIA									    *
*	LECTURER'S NAME:	AZIZUL AZHAR BIN RAMLI							    *
*	SUBJECT: ALGORITHM AND PROGRAMMING (BIC 10204 SECTION 3)			    *
*																            *
*	GROUP PROJECT QUESTION 8:	EMPLOYEE PAYMENT CALCULATOR SYSTEM  (V1.1)  *
*	GROUP MEMBERS:		1. MOHD HAFIZUL AFIFI BIN ABDULLAH	(AI130061)      *
*						2. NURSHAFIZA BINTI W.MINI  (AI130117)              *
*						3. NURUL FARHANA BINTI MOHAMED TAHIR    (AI130178)  *
*						4. SITI NA'AISHAH BINTI AZMI    (AI130103)          *
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

/*GLOBAL VARIABLES*/
char projectname[]="EMPLOYEE PAYMENT CALCULATOR SYSTEM";

/*FUNCTION PROTOTYPE*/
void header();
void pause();
void dateandtime();
void uthmlogo();

int main()
{
    int man_cyc=0, hourly_cyc=0, comm_cyc=0, piece_cyc=0;   //counter initialization value
	int paycode=0, piece_amount;
	float hourly_total, hourly_overtime;
	float man_salary;								//variable for MANAGER (paycode: 1)
	float hourly_wage;								//variable for HOURLY WORKERS (paycode: 2)
	float comm_fixed=250, comm_sales;				//variable for COMMISSION WORKERS (paycode: 3)
	float piece_wages;								//variable for PIECEWORKER (paycode:4)
	float pay, total_pay=0;

    while(paycode!=-1)                              //if paycode entered is -1, program terminates
    {
        header();
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
                header();
                ++man_cyc;
                printf("\n\tManager Selected.");
                printf("\n\tEnter weekly salary: ");
                scanf("%f",&man_salary);
                pay=man_salary;
                printf("\n\tThe manager's pay is $%.2f",pay);
                total_pay=total_pay+pay;
                pause();
            }
            break;
            case 2:			//if HOURLY WORKER selected, run this code
            {
                header();
                ++hourly_cyc;
                printf("\n\tHourly Worker Selected.");
                printf("\n\tEnter hourly salary: ");
                scanf("%f",&hourly_wage);
                printf("\n\tEnter total hours worked: ");
                scanf("%f",&hourly_total);
                if (hourly_total>40)
                {
                    hourly_overtime=hourly_total-40;
                    pay=(40*hourly_wage)+(hourly_overtime*1.5*hourly_wage);
                    printf("\n\tWorker worked %.2f overtime hours",hourly_overtime);
                    printf("\n\tWorker's pay is $%.2f",pay);
                    total_pay=total_pay+pay;
                }
                else
                {
                    pay=(hourly_total*hourly_wage);
                    printf("\n\tWorker has not worked for overtime hours");
                    printf("\n\tWorker's pay is $%.2f",pay);
                    total_pay=total_pay+pay;
                }
                pause();
            }
            break;
            case 3:			//if COMMISSION WORKER selected, run this code
            {
                header();
                ++comm_cyc;
                printf("\n\tCommission Worker Selected.");
                printf("\n\tEnter gross weekly sales: ");
                scanf("%f",&comm_sales);
                pay=((5.7/100)*comm_sales)+comm_fixed;
                printf("\n\tCommission worker's pay is $%.2f",pay);
                total_pay=total_pay+pay;
                pause();
            }
            break;
            case 4:			//if PIECEWORKER selected, run this code
            {
                header();
                ++piece_cyc;
                printf("\n\tPieceworker Selected.");
                printf("\n\tEnter number of pieces: ");
                scanf("%d",&piece_amount);
                printf("\n\tEnter wage per piece: ");
                scanf("%f",&piece_wages);
                pay=piece_wages*piece_amount;
                printf("\n\tPieceworker's pay is $%.2f",pay);
                total_pay=total_pay+pay;
                pause();
            }
            break;
            case -1: 		//if TERMINATE selected, run this code
            {
                header();
                printf("\n\tComputation completed!");
                printf("\n\tPress any key to view receipt.");
                pause();
            }
            break;
            case -2: 		//if HELP selected, run this code
            {
                header();
                printf("\n\t\t===Welcome to the Help Wizard.===\n");
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
                header();
                printf("\n\t\t===Welcome to the Help Wizard.===\n");
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
                header();
                printf("\n\t\t===Welcome to the Help Wizard.===\n");
                printf("\n\tREFERENCES:"
                       "\n\t1. BIC10204: Algorithm and Programming lecture"
                       "\n\t   notes by Mr. Azizul Azhar bin Ramli");
                printf("\n\n\t-------------------------------------------------");
                printf("\n\tPage: 3/4\tPress any key to navigate next.");
                pause();
                header();
                printf("\n\t\t===Welcome to the Help Wizard.===\n");
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
            break;
            default: 		//if INVALID paycode entered, run paycode input cycle
            {
                header();
                printf("\n\tPaycode INVALID.");
                printf("\n\tPress any key to back to menu.");
                pause();
            }
        }
    }
    header();
    printf("\n\tHere is summary for your actions:");
    printf("\n\t1. %d Manager(s) have been paid.",man_cyc);
    printf("\n\t2. %d Hourly worker(s) have been paid.",hourly_cyc);
    printf("\n\t3. %d Commission worker(s) have been paid.",comm_cyc);
    printf("\n\t4. %d Pieceworker(s) have been paid.",piece_cyc);
    printf("\n\n\tTOTAL PAYMENT made is $%.2f",total_pay);
    pause();
    system("cls");
    printf("\n\n\n\t");
    uthmlogo();
    printf("\n\t\t--------------------------------"
           "\n\t\tThis program will now QUIT. Bye!"
           "\n\t\t--------------------------------");
    return 0;
}

void header()
{
    system("cls");
    printf("\n");
    printf("\t+-----------------------------------------------+\n");
    printf("\t|\t%s\t|\n",projectname);
    printf("\t+-----------------------------------------------+\n");
    dateandtime();
    printf("\n\t");
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
	printf("\tVersion 1.1\t");
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
    "\n\n\tDengan Hikmah Kita Meneroka."
    "\tWWWE: With Wisdom We Explore."
    "\n\n\t");
}
