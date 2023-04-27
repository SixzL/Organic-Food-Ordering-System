#include<stdio.h>
#include<string.h>
#define P_A 2.50   //define the price of one Apple to RM2.50 
#define P_B 20.00     //define the price of one Broccoli to RM20
#define P_C 2.00     //define the price of one Carrot to RM2
#define P_CU 6.00     //define the price of one Cucumber to RM6
#define P_S 20.00     //define the price of one Strawberry to RM20
#define GST 0.06   //define the tax of gst 6%
struct account
{	char name[30], usern[40], password[30], pnum[20];  //variables to keep member's info
	
}member;

float account();
void menu();
void order();

int main()
{	int access = 0;//to check if the user has completed the login/register
	access = account();
	
	if(access == 1);//after login/register.
	{	menu();
		order();
	}
}


float account()
{	char a_code, l_usern[30], l_pass[30], enter, pass2[30], scanusern[30], scanpass[30], checkuser[30], checkpass[30], checkname[30], checkpnum[20];
	int a = 0, b = 0, c = 0, d = 0;  //to keep track whether the step is completed or not
	
	
	
	FILE *fp, *fp2;//create a file pointer
	
	fp = fopen("register.txt", "a+");//open the file called register.txt for read and write
	fp2 = fopen("login.txt", "a+");
	do
	{	system("cls");//clear previous output
		printf("\t---------------------------------------------------\n");
		printf("\t|               Summer Organic Food               |\n");
		printf("\t|                  Supply Company                 |\n");
		printf("\t---------------------------------------------------\n");
		printf("\t|                                                 |\n");
		printf("\t|        Do you have a registered account?        |\n");//ask the user whether the user has an account or not
		printf("\t|                 1. Login Account                |\n");
		printf("\t|                2. Register Account              |\n");
		printf("\t|                                                 |\n");
		printf("\t *************************************************\n");
		printf("\t                Enter your choice: ");
		scanf("\t%c", &a_code);
		system("cls");
		fflush(stdin);
	
		switch(a_code)
		{	case '1'://when user entered 1
			
				printf("\n\t*******************|  LOGIN  |*******************");
				printf("\n\n\t      Enter your username: ");//ask users to enter their username
				scanf("%s", l_usern);//scan user's username
				fflush(stdin);
				printf("\t      Enter your password: ");//ask users to enter their password
				gets(l_pass);//scan user's password
				fflush(stdin);
				rewind(fp2);/*to rewind the file to the top, without this, if the user entered the wrong username or password
				        	 the file wont be able to find the account record*/
			
				while(!feof(fp2))
				{	fscanf(fp2, "%s %s", scanusern, scanpass);//find the account record (username/password) in the text file (register.txt)
					if(strcmp(scanusern, l_usern)==0 && strcmp(scanpass, l_pass)==0) //If username and password that user entered
					{	strcpy(member.usern, scanusern);                             //are recorded in the text file(register.txt),it will run below code.     
						printf("\n\t              **********************"); 
						printf("\n\t               Welcome back, %s.", member.usern);//welcome the user to the program
						printf("\n\t             Press ENTER to continue");
						scanf("%c", &enter);
						system("cls");//clear previous output
						a = 1;//'a' is a checker that proff user is logged on
					}	
					
				}
				while(!feof(fp))//this while loop is to find the user name and phone number from the register.txt file
				{	fscanf(fp,"%s %s %s %s", checkuser, checkpass, checkname, checkpnum);
					if(strcmp(checkuser,member.usern)==0 && strcmp(checkpass, l_pass)==0)//if the username and pass are matched, copy the name and phonenumber
					{	strcpy(member.name, checkname);
						strcpy(member.pnum, checkpnum);
					}
				}
				
				
			                 //if the user entered wrong username/password the 'a' won't be 1
			                 //and the program will run the code below
				if(a != 1) 
				{	printf("\n\t               *********************");
					printf("\n\t             Wrong username or password!");//outputs that tell user they have entered the wrong username/password
					printf("\n\t Press ENTER to return the login/register menu.");
					scanf("%c", &enter);
					fflush(stdin);
				}
			
			break;
			
			case '2': //when user entered 2, the user will go to registration
				printf("\n\t****************|  Registration  |****************");
				printf("\n\n\t          Enter your name: ");//ask users to enter their name
				gets(member.name);//scan user's name
				fflush(stdin);
				
				printf("\n\t          Enter your phone number: ");//ask users to enter their phone number
				scanf("%s", member.pnum);//scan user's phone number
				do
				{	b = 0;//to reset the username checker
					printf("\n\t          Enter your username: ");//ask users to enter the username
					scanf("%s", member.usern);//scan the username
					fflush(stdin);
					
					rewind(fp);//rewind the text tile (register.txt) to ensure next used username will be scanned
					while(!feof(fp))//check whether the username that user entered is used or not
					{	
						fscanf(fp, "%s %s", l_usern, l_pass);//scanning the text file(register.txt)
						if(strcmp(member.usern, l_usern)== 0)//if the user entered an used username
						{	printf("\n\t               ********************\n");
							printf("\n\t             Username is been used...");
							printf("\n\t Press Enter to try again with different Username\n");	
							scanf("%c", &enter);
							b = 1; //'b' is a checker that check whether username is  used or not. 1 = used
							system("cls");                                //clear previous output
							printf("\n\t****************|  Registration  |****************");
							printf("\n\n\t          Enter your name: ");
							printf("%s\n", member.name);
							printf("\n\t          Enter your phone number: ");
							printf("%s\n", member.pnum);
						}
					}	
						
				}while(b == 1);//user entered an used username, 'b' became 1, then user will need to reenter an username
				
				do//users reach here if they entered the new username
				{	c = 0;                                         //to reset password length checker
					printf("\n\t          Enter your password \n\t          (atleast 8 words)  : ");//ask the user to enter a password
					gets(member.password);//scan the password from user
					fflush(stdin);
					if(strlen(member.password) < 8)//if the password length not over 8
					{	c = 1;//'c' is a checker that check whether password length is less than 8.  c = 1 means less than 8
						printf("\n\t               *******************\n");
						printf("\n\t            password not long enough!");
						printf("\n\t press Enter to try again with different password\n");
						scanf("%c", &enter);
						system("cls");//clear previous output
						printf("\n\t****************|  Registration  |****************");//redisplay the output without password length warning
						printf("\n\n\t          Enter your name: ");
						printf("%s\n", member.name);
						printf("\n\t          Enter your phone number: ");
						printf("%s\n", member.pnum);
						printf("\n\t          Enter your username: ");
						printf("%s\n", member.usern);
					}
					
				}while(c == 1);//password length less than 8, c will become 1. then the program will repeat.
				
				do
				{	d = 0;//reset the password checker
					printf("\n\t          Re-enter your password: ");//ask the user to reenter to make sure the password can be memorized by user
					scanf("%s", pass2);//scan the password from user.
					fflush(stdin);
					if(strcmp(pass2, member.password)!= 0)//if the first and the reentered passwords are not same, the program display warning
					{	d = 1;//'d' is a checker that check whether the passwords are same or not. d = 1 means different
						printf("\n\t               ********************\n");
						printf("\n\t            Passwords are not the same!");
						printf("\n\t       press Enter to re-enter your password");
						scanf("%c", &enter);
						system("cls");//clear previous output
						printf("\n\t****************|  Registration  |****************");//redisplay output without different password warning
						printf("\n\n\t          Enter your name: ");
						printf("%s\n", member.name);
						printf("\n\t          Enter your phone number: ");
						printf("%s\n", member.pnum);
						printf("\n\t          Enter your username: ");
						printf("%s\n", member.usern);
						printf("\n\t          Enter your password \n\t          (atleast 8 words)  : ");
						printf("%s\n", member.password);
					}
				}while(d == 1);
				fprintf(fp, "\n%s %s %s %s", member.usern, member.password, member.name, member.pnum);//record the user info into the  text  file
				fprintf(fp2, "\n%s %s", member.usern, member.password);
				//this will be display if user complete the registration                                (register.txt), so the user can come back
				printf("\n\t               ********************\n");                                    //with the same account next time.
				printf("\n\t             Registration successfuly!");
				printf("\n\t              Press ENTER to proceed");
				scanf("%c", &enter);
				fflush(stdin);
				system("cls");
				
				fclose(fp);                                                                           
				a = 1;                                                                                
				break;
			
				
		}
		
	}while(a != 1);//'a' is a checker that proff user is logged on
	
	return a; //return the 'a' with value 1;
	
}

void menu()//function menu
{	char enter;
	float total_a,total_c;
	printf("\n\t--------------------------------------------------------------");//this is the Welcoming display to customer
	printf("\n\t|                                                            |");
	printf("\n\t|       WELCOME TO Summer Organic Food Supply Company        |");
	printf("\n\t|                                                            |");
	printf("\n\t--------------------------------------------------------------");
	
	printf("\n\n\t\t\t    Press ENTER to continue");//ask user enter the enter and clean the output 
	scanf("%c", &enter);
	system("cls");//clean the previous output screen
	
}

void order()//function order and display receipt
{
	int counter, extra,a=0,c=0,s=0,b=0,cu=0,i,time=0,total_t=0;
	float total_a=0, total_c=0, total_s=0, total_b=0, total_cu=0, choice,total_p=0, f_total=0, tax, nettotal;
	char food[50],enter;
	

	printf("\n\t---------------------------------------------------------------");
	printf("\n\t| 1. APPLE                                                    |");
	printf("\n\t| 2. CARROT                                                   |");
	printf("\n\t| 3. STRAWBERRY                                               |");
	printf("\n\t| 4. BROCCOLI                                                 |");
	printf("\n\t| 5. CUCUMBER                                                 |");
	printf("\n\t---------------------------------------------------------------");
	printf("\n\n\t          How many types of foods you want to buy : ");
	scanf("%d",&time);   //ask user for enter how many types of the food they want to buy
	
	
	for(i=0;i<time;i++)   //check the types of customer want to buy and let the user pick the types of the food everytime repeated
	{
		printf("\n\t                Which Food Do You Wish To Buy ?  \n");
		printf("\n\t              Enter The Code Of The Food [1-5] : ");   //ask user to input the code of the food
		scanf("%d",&counter);
		fflush(stdin);
		while(counter<=0 || counter>5)//this while loop is used to check whether the code is between 1-5
		{	printf("\n\t                         ************\n");
			printf("\n\t             You Are Entering An Incorrect Code!\n");
			printf("\t            Re Enter the Code To Order Food [1-5] : ");
			scanf("%d",&counter);   //make sure the code is between 1-5 or else ask the user re-enter the code
		}
	
		
	
	switch (counter) 
		{
		case 1:   //if the user enter 1
			strcpy(food,"Apple");   //let the code "food" become apple
			printf("\t           How Many KG of %s Do You Want To Buy : ",food);
			scanf("%f",&choice);   //ask user to input the value
			printf("\n\t                         ************\n");
			a= a+choice;   //calculate the quantity customer ordered
			total_a=a*P_A;   //calculate the price
			
		break ;
		case 2:   //if the user enter 2
			strcpy(food,"Carrot");   //let the code "food" become carrot
			printf("\t           How Many KG of %s Do You Want To Buy : ",food);
			scanf("%f",&choice);   //ask user to input the value
			printf("\n\t                         ************\n");
			c = c+choice;   //calculate the quantity customer ordered
			total_c=c*P_C;   //calculate the price
		break ;
			
		case 3:   //if the user enter 3
			strcpy(food,"Strawberry");   //let the code "food" become strawberry
			printf("\t         How Many KG of %s Do You Want To Buy : ",food);
			scanf("%f",&choice);   //ask user to input the value
			printf("\n\t                         ************\n");
			s = s+choice;   //calculate the quantity customer ordered
			total_s=s*P_S;   //calculate the price
			
			
		break ;
		case 4://if the user enter 4
			strcpy(food,"Broccoli");   //let the code "food" become broccoli
			printf("\t          How Many KG of %s Do You Want To Buy : ",food);
			scanf("%f",&choice);   //ask user to input the value
			printf("\n\t                         ************\n");
			b = b + choice;   //calculate the quantity customer ordered
			total_b=b*P_B;   //calculate the price
			
		break;
		case 5:   //if the user enter 5
			strcpy(food,"Cucumber");   //let the code "food" become cucumber
			printf("\t           How Many KG of %s Do You Want To Buy : ",food);
			scanf("%f",&choice);  //ask user to input the value
			printf("\n\t                         ************\n");
			cu = cu+choice;   //calculate the quantity customer ordered
			total_cu=cu*P_CU;   //calculate the price
		}
	}
	total_t=a+c+s+b+cu;//calculate the total kg
	total_p=total_a+total_c+total_s+total_b+total_cu;//calculate the total price
	tax=total_p * GST;//calculate the final price with tax
	nettotal= tax + total_p;
	fflush(stdin);
	
	printf("\n\n\t\t\t    Press ENTER to continue\n\n"); 
	scanf("%c", &enter);   //ask user to enter to proceed to the next
	system("cls");   //clean the previous output
	
		
	
	printf("\t -----------------------------------------------------------------------\n");
	printf("\t \t       SUMMER Organic Food Supply Company (123456I)                  \n");//company name and address
	printf("\t \t  No.699, Jalan Lagenda, Taman 1 Lagenda, 75400 Melaka.              \n");
	printf("\t -----------------------------------------------------------------------\n");
	printf("\t \t                         RECEIPT                                     \n");
	printf("\t \t                        *********                                    \n");
	printf("\t \tName Of Product \tPrice per KG\t\tTotal Price                        \n");//title of each column
	printf("\t \t                                                                     \n");
	printf("\t \tApple     : %dKG \tRM %.2f /KG \t\tRM %.2f                           \n", a, P_A, total_a);//apple row which shows apple price per kg and total price of apple
	printf("\t \tCarrot    : %dKG \tRM %.2f /KG \t\tRM %.2f                           \n", c, P_C, total_c);//carrot row which shows apple price per kg and total price of carrot
	printf("\t \tStrawberry: %dKG \tRM %.2f/KG \t\tRM %.2f                            \n", s, P_S, total_s);//strawberry row which shows apple price per kg and total price of strawberry
	printf("\t \tBroccoli  : %dKG \tRM %.2f/KG \t\tRM %.2f                            \n", b, P_B, total_b);//Broccoli row which shows apple price per kg and total price of Broccoli
	printf("\t \tCucumber  : %dKG \tRM %.2f /KG \t\tRM %.2f                           \n", cu, P_CU, total_cu);//Cucumber row which shows apple price per kg and total price of Cucumber
	printf("\t \t                                                                     \n");
	printf("\t -----------------------------------------------------------------------\n");
	printf("\t \t                                                                     \n");
	printf("\t \tTotal KG  : %dKG                                                     \n",total_t);//total kg of food purchased
	printf("\t \t                                    Total     : RM %.2f              \n", total_p);//total price of food purchased
	printf("\t \t                                    Gst (6%)   : RM %.2f             \n",tax);//the tax of purchase
	printf("\t \t                                    Net Total : RM %.2f              \n", nettotal);//net total of total and tax
	printf("\t \t                                                                     \n");
	printf("\t -----------------------------------------------------------------------\n");
	printf("\t \t                       CUSTOMER INFO                                 \n");
	printf("\t \t                         *********                                   \n");
	printf("\t \t                                                                     \n");
	printf("\t \t\t\t  Name         : %s                                              \n", member.name); //client's name
	printf("\t \t\t\t  Phone number : %s                                              \n", member.pnum); //client's phone number
	printf("\t \t                                                                     \n");
	printf("\t \t          Thank you for the purchasing, %s.                          \n", member.usern);
	printf("\t \t                                                                     \n");
	printf("\t -----------------------------------------------------------------------\n");
	
		    
}
