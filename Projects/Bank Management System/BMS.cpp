//Bank management project;

///////////////////////////////////////////////////////
//  BANK MANAGEMENT SYSTEM                           //
//  ----------------------                           //
//                                                   //
//  FEATURES :                                       //
//     * Object oriented programming.                //
//     * File Handling with C++.                     //
//						     //
//  				By Kartik Patel	     //
//                                                   //
///////////////////////////////////////////////////////

// Programme Starts Here.
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
int main_exit;

void fordelay(int);
void title(); 
void close(void);
int main();
void menu_e();
void employee();
void customer();
void menu_c();
void retry(string person);

class Bank
{
public:
    string account_number;
	string name;
    string dob;
    string age;
    string date;
    string address;
    string phone;
    string doc;
    string depo;
    string acc_type;
    string password;
    string interest;
public:
    void read_data();
    void acc_write();
	void modify_account();
	void search_rec();
	void deposit_withdraw();
	void display_all();
	void transfer();
};

float inter(float t,float amount,int rate)
{
    float SI = (rate * t * amount) / 100.0;
    return SI;
}

void Bank::read_data()
{
	int x,i=0;
	string acc_no;
	Retry:
		cout << "\nEnter Account Number: ";
		cin >> account_number;
		ifstream is("Account_info.csv");
		do
		{
			getline(is,acc_no, ',');
			getline(is,password, '\n');
			if(acc_no == account_number)
			{
				cout << "\n Account No. Matches with Existing Account!";
				cout << "\n 1. Try Again!\n 2. Login To Account";
				cin >> x;
				if(x == 1)		goto Retry;
				else			customer();
			}
			break;
		} while(is.good());
    fflush(stdin);
    cout << "\nEnter Name: ";
    getline(cin, name);
    cout << "\nEnter the  of birth(mm/dd/yyyy): ";
    fflush(stdin);
	cin >> dob;
    cout << "\nEnter the age: ";
    cin >> age;
    cout << "\nEnter the address: ";
    fflush(stdin);
	getline(cin, address);
    cout << "\nEnter the phone number: ";
    fflush(stdin);
    cin >> phone;
    cout << "\nYou want to deposit amount:\n\t1.Yes\n\t2.No\n\t: ";
    cin >> x;
    if(x == 1)
    {
    	cout<<"\nEnter the amount to deposit: $ ";
		cin>>depo;    	
	}
	else		depo = to_string(0);
    cout << "\nType of account: \n\t #Saving \n\t #Current \n\n\t Enter your choice: ";
    fflush(stdin);
	cin >> acc_type;    
    cout << endl;
    time_t now = time(0);
    string dt = ctime(&now);
    cout << "\nDate and Time of Account Creation: " << dt << endl;
    date = dt;
	struct tm *ltm = localtime(&now);
    doc = to_string(ltm -> tm_mday);
    doc = doc.substr(0, doc.size()-1);
    interest = to_string(i++);
    cout << "\nEnter Password For Your Account:";
    cin >> password;
    printf("\nAccount created successfully!");

	retry("customer");
}
void Bank::acc_write()
{
	ofstream MyFile1, MyFile2;
	read_data();
	MyFile1.open("Bank_Record.csv", ios::out|ios::app);
	MyFile1 << account_number << "," << name  << "," << dob << ","  << age << "," << address << "," 
			<< phone << "," << depo  << "," << acc_type << "," << date << "," << doc << "," << interest << "\n";
	MyFile1.close();
	MyFile2.open("Account_info.csv", ios::out|ios::app);
	MyFile2 << account_number << "," << password << "," << "\n"; 
	MyFile2.close();
}
void Bank::modify_account()
{
	Bank ac;
	int test = 0;
	string acc_no;
	cout << "For Verification:\n";
	cout << "Enter the Account Number again: ";
	cin >> acc_no;
	ifstream is("Bank_Record.csv");
    do
    {
       	getline(is,account_number, ',');
       	getline(is, name, ',');
       	getline(is, dob, ',');
       	getline(is, age, ',');
       	getline(is, address, ',');
      	getline(is, phone, ',');
       	getline(is, depo, ',');
      	getline(is, acc_type, ',');
      	getline(is, date, ',');
      	getline(is, doc,',');
      	getline(is, interest, '\n');
        if(acc_no == account_number)
    	{   
    		test = 1;
			cout << "\n Account NO.: " << account_number;
			cout << "\n Name: " << name;
			cout << "\n DOB: " << dob;
			cout << "\n Age: " << age;
			cout << "\n Address: " << address;
			cout << "\n Phone number: "<< phone;
			cout << "\n Type Of Account: " << acc_type;
			cout << "\n Date of Account creation: " << date;
			cout << "\n Amount deposited: " << depo << endl;
			break;
        }
	} while (is.good());
	is.close();
	string x, y, z;
	int choice;
	int opt;
	if(test == 1)
	{
		ifstream file ("Bank_Record.csv");
		ofstream ofile ("temp.csv");
		do
		{
			cout << "\n\n\n\t\t 1.Update Name\n";
			cout << "\t\t 2.Update dob Of Birth\n";
			cout << "\t\t 3.Update Age\n";
			cout << "\t\t 4.Update Address\n";
			cout << "\t\t 5.Update Phone No.\n";
			cin >> choice;
			switch(choice)
			{
			case 1:	
				system("color 3");
				cout << "\t\tUpdate Name\n\n";
				cout << "Enter Old Name: ";
				cin >> y;
				cout << "Enter New Name: ";
				cin >> z;
				while (!file.eof())
				{	
					getline(file,x,',');
					if (x == y)		ofile << z <<",";
					else			ofile << x << ",";
				}
				break;
			case 2:
				system("color 4");
				cout << "\t\tUpdate dob Of Birth\n\n";
				cout << "Enter Old dob Of Birth(mm/dd/yyyy): ";
				cin >> y;
				cout << "Enter New dob Of Birth(mm/dd/yyyy): ";
				cin >> z;
				while (!file.eof())
				{	
					getline(file,x,',');
					if (x == y)		ofile << z <<",";
					else			ofile << x << ",";
				}
				break;
			case 3:
				system("color 5");
				cout << "\t\tUpdate Age\n\n";
				cout << "Enter Old Age: ";
				cin >> y;
				cout<<"Enter New Age: ";
				cin >> z;
				while (!file.eof())
				{	
					getline(file,x,',');
					if (x == y)		ofile << z <<",";
					else			ofile << x << ",";
				}
				break;
			case 4:
				system("color 6");
				cout << "\t\tUpdate Address\n\n";
				cout << "Enter Old Address: ";
				cin >> y;
				cout << "Enter New Address: ";
				cin >> z;
				while (!file.eof())
				{	
					getline(file,x,',');
					if (x == y)		ofile << z <<",";
					else			ofile << x << ",";
				}
				break;
			case 5:
				system("color 2");
				cout << "\t\tUpdate Phone No.\n\n";
				cout << "Enter Old Phone No. : ";
				cin >> y;
				cout << "Enter New Phone No. : ";
				cin >> z;
				while (!file.eof())
				{	
					getline(file,x,',');
					if (x == y)		ofile << z <<",";
					else			ofile << x <<",";
				}
				break;
			default: cout << "Invalid Input";
			}
			remove("Bank_Record.csv");
			rename("temp.csv","Bank_Record.csv");	
			file.seekg(0, ios::beg);
			ofile.seekp(0, ios::beg);
			cout << "\n\n\t\tDo You Want Update Any Other Field : \n\t\t 1: YES \n\t\t 2: NO \n\t\t : ";
			cin >> opt;
		} while(opt != 2);
		file.close();
		ofile.close();
	}
	else		cout << "\n Account Doesn't Exist";
	retry("customer");
}
void Bank::search_rec()
{
    int test=0,rate;
    int choice, date1;
    float t;
    string intrst, x, y;
    int amount, b;
    string acc_no, name_s;
    ifstream is("Bank_Record.csv");
    
    cout << "Do you want to check by\n <1> Account no.\n <2> Name \n\t\t : ";
    cin >> choice;
    if (choice == 1)
    {   
		cout << "Enter the account number: ";
        cin >> acc_no;
        do
        {
        	getline(is,account_number, ',');
       		getline(is, name, ',');
       		getline(is, dob, ',');
       		getline(is, age, ',');
       		getline(is, address, ',');
      		getline(is, phone, ',');
       		getline(is, depo, ',');
      		getline(is, acc_type, ',');
      		getline(is, date, ',');
      		getline(is, doc,',');
      		getline(is, interest,'\n');
        	amount = atoi(depo.c_str());
    		if(acc_no == account_number)
    		{
    			test = 1; system("cls");   
				cout << "\n Account NO.: " << account_number;
				cout << "\n Name: " << name;
				cout << "\n DOB: " << dob;
				cout << "\n Age: " << age;
				cout << "\n Address: " << address;
				cout << "\n Phone number: "<< phone;
				cout << "\n Type Of Account: " << acc_type;
				cout << "\n Date of Account creation: " << date;
				cout << "\n Amount deposited: " << depo << endl;
				
				ifstream file ( "Bank_Record.csv" );
				ofstream ofile ( "temp.csv" );
				
            	if(acc_type == "Saving")
                {
                	time_t now = time(0);
					struct tm *ltm = localtime(&now);
					date1 = ltm -> tm_mday;
                    if(date1 != atoi(doc.c_str()))    
					{
						t = date1 - atoi(doc.c_str());
						rate=15;
						intrst=std::to_string(inter(t,amount,rate));						
						cout<<"\n\nYou will get $ " <<intrst <<" as interest";
						file.clear();
						while (!file.eof())
						{		
							getline(file,x,',');
    						if (x == interest)		ofile << intrst <<",";
    						else if(x == depo)
        					{
        						y=(atoi(depo.c_str())+atoi(intrst.c_str()));
        						ofile << y << ",";
							}	
        					else					ofile << x <<","; 
						}
					}	
					else
						cout<<"\n\n You will get $ 0 as interest for today...";
					break;                    
                }
                else if(acc_type == "Current")
                {
                    time_t now = time(0);
					struct tm *ltm = localtime(&now);
					date1 = ltm -> tm_mday;
                    if(date1 != atoi(doc.c_str()))    
					{
						t = date1 - atoi(doc.c_str());
						rate=15;
						intrst=std::to_string(inter(t,amount,rate));						
						cout << "\n\n You will get $ " << intrst << "as interest";
						file.clear();
						while (!file.eof())
						{		
							getline(file,x,',');
    						if (x == interest)			ofile << intrst <<",";
    						else if(x == depo)
        					{
	        					y=(atoi(depo.c_str())+atoi(intrst.c_str()));
    	    					ofile << y << ",";
							}
							else					ofile << x <<","; 
						}
					}	
					else
						cout << "\n\n You will get $ 0 as interest for today...";
					break;
				}
            }
        } while (is.good());
    }
    else if (choice == 2)
    {   
		cout << "Enter the Name of Account Holder:";
        cin >> name_s;
        do
        {
        	getline(is,account_number, ',');
       		getline(is, name, ',');
       		getline(is, dob, ',');
       		getline(is, age, ',');
       		getline(is, address, ',');
      		getline(is, phone, ',');
       		getline(is, depo, ',');
      		getline(is, acc_type, ',');
      		getline(is, date, ',');
      		getline(is, doc,',');
      		getline(is, interest, '\n');
        	amount = atoi(depo.c_str());
    		if(name_s == name)
            {   
				test = 1; system("cls");   
				cout << "\n Account NO.: " << account_number;
				cout << "\n Name: " << name;
				cout << "\n DOB: " << dob;
				cout << "\n Age: " << age;
				cout << "\n Address: " << address;
				cout << "\n Phone number: "<< phone;
				cout << "\n Type Of Account: " << acc_type;
				cout << "\n Date of Account creation: " << date;
				cout << "\n Amount deposited: " << depo << endl;
				
				ifstream file ( "Bank_Record.csv" );
				ofstream ofile ( "temp.csv" );
				
            	if(acc_type == "Saving")
                {
                	time_t now = time(0);
					struct tm *ltm = localtime(&now);
					date1 = ltm -> tm_mday;
                    if(date1 != atoi(doc.c_str()))    
					{
						t = date1 - atoi(doc.c_str());
						rate = 15;
						intrst=std::to_string(inter(t,amount,rate));						
						cout<<"\n\nYou will get $ " << intrst <<" as interest";
						file.clear();
						while (!file.eof())
						{		
							getline(file,x,',');
    						if (x == interest)		ofile << intrst <<",";
    						else if(x == depo)
        					{
        						y=(atoi(depo.c_str()) + atoi(intrst.c_str()));
        						ofile << y << ",";
							}
							else					ofile << x <<","; 
						}
					}	
					else	cout << "\n\n You will get $ 0 as interest for today...";
					break;                    
                }
                else if(acc_type == "Current")
                {
                    time_t now = time(0);
					struct tm *ltm = localtime(&now);
					date1 = ltm->tm_mday;
                    if(date1 != atoi(doc.c_str()))    
					{
						t = date1 - atoi(doc.c_str());
						rate = 15;
						intrst = std::to_string(inter(t,amount,rate));						
						cout << "\n\n You will get $ " << intrst << " as interest";
						file.clear();
						while (!file.eof())
						{		
							getline(file,x,',');
    						if (x == interest)			ofile << intrst <<",";
    						else if(x == depo)
        					{
        						y=(atoi(depo.c_str())+atoi(intrst.c_str()));
        						ofile << y << ",";
							}
							else						ofile << x <<","; 
						}
					}	
					else		cout<<"\n\nYou will get $ 0 as interest for today...";
					break;
				}
            }
        } while (is.good());
    }
    
	if(test == 0)		cout<<"\n\n\t\t Account doesn't Exist!";

    remove("Bank_Record.csv");
   	rename("temp.csv","Bank_Record.csv");	
	is.close();
	retry("customer");
}
void Bank::deposit_withdraw()
{
	int choice,test=0,amt,amount;
	string acc_no, y, x;
    ifstream file ("Bank_Record.csv" );
	ofstream ofile ("temp.csv" );
	Bank ac;
	cout << "Enter the account number: ";
	cin >> acc_no;
    do
    {
       	getline(file,account_number, ',');
       	getline(file, name, ',');
       	getline(file, dob, ',');
       	getline(file, age, ',');
       	getline(file, address, ',');
      	getline(file, phone, ',');
       	getline(file, depo, ',');
      	getline(file, acc_type, ',');
      	getline(file, date, ',');
      	getline(file, doc,',');
      	getline(file, interest, '\n');
        amount = atoi(depo.c_str());
    	if(acc_no == account_number)
    	{   
			test = 1;
			cout << "\n Account No.: " << account_number;
			cout << "\n Name: " << name;
			cout << "\n DOB: " << dob;
			cout << "\n Age: " << age;
			cout << "\n Address: " << address;
			cout << "\n Phone number: " << phone;
			cout << "\n Date of Creation: " << date;
			cout << "\n Type Of Account: " << acc_type;
			cout << "\n Balance:" << depo;
			test = 1;
            cout << "\n\n Do you want to \n 1.Deposit \n 2.Withdraw? \n\n\t\t : ";
            cin >> choice;
            
			if (choice == 1)
            {
                cout << "Enter the amount you want to deposit: ";
                cin >> amt;
                file.seekg(0, ios::beg);
                amt = atoi(depo.c_str()) + amt;
                y = to_string(amt);
                cout << "\n\t Balance : " << y;
                int i = 1;
                while (file.good())
				{	
					getline(file,x,',');
    				if (x == depo)		ofile << y <<",";
    				else   				ofile << x <<",";
				}
                printf("\n\n Deposited successfully!");
            }
            else
            {
                cout << "Enter the amount you want to Withdraw: ";
                cin >> amt;
                file.seekg(0, ios::beg);
                if(amt > atoi(depo.c_str()))	cout << "Not Enough Balance\n";
                else
                {
                    amt = atoi(depo.c_str()) - amt;
                    y =  std::to_string(amt);
                    cout << "\n\t Balance : " << y;
                    while (file.good())
					{	
						getline(file,x,',');
    					if (x == depo)		ofile << y <<",";
    					else				ofile << x <<",";
        			}
					printf("\n\n Withdrawn successfully!");        	
				}
            }
        }
    } while (file.good());
   	file.close();
	ofile.close();
	remove("Bank_Record.csv");
	rename("temp.csv","Bank_Record.csv");

   	if(test==0) 	cout<<"\n\nRecord not found!!";
	retry("customer");
}
void Bank::display_all()
{
	int amount;
	cout << "\n\n\t\t ACCOUNT HOLDER LIST\n\n";
    cout << "====================================================="
		 << "========================================================="
		 << "=========================\n";
    cout << "  Account No.\t\t Name \t\t Type \t\t Balance \t\t Address" 
		 << "\t\t Phone No.\t\tCreation Date\n";
    cout << "====================================================="
		 << "========================================================="
		 << "=========================\n";
    ifstream is("Bank_record.csv");
	
	int i = 1, sz = 0, sz1 = 0;
	char c;
	is.seekg(0,ios::end);
	sz=is.tellg();
	//cout<<sz<<endl;
	is.seekg(0,ios::beg);
	while (!is.eof())
    {
    	cout<<i<<". ";
    	i++;
    	getline(is,account_number, ',');
       	getline(is, name, ',');
       	getline(is, dob, ',');
       	getline(is, age, ',');
       	getline(is, address, ',');
      	getline(is, phone, ',');
       	getline(is, depo, ',');
      	getline(is, acc_type, ',');
      	getline(is, date, ',');
      	getline(is, doc,',');
      	getline(is, interest,'\n');
        amount = atoi(depo.c_str());
        sz1=is.tellg();
        //cout<<sz1<<" ";
    	cout << account_number << "\t\t" << name << "\t\t" << acc_type <<"\t\t" 
			 << amount <<"\t\t" << address << "\t\t" << phone << "\t\t" << date << endl;
		if(sz == (sz1))		break;
	}
	retry("customer");
}
void Bank::transfer()
{
	int amount,amt, test = 0;
	string acc_no, y, x;
	{
	ifstream file ("Bank_Record.csv" );
	ofstream ofile ("temp.csv" );
	Bank ac;
	cout << "Enter Your account number:";
	cin >> acc_no;
    do
    {
       	getline(file,account_number, ',');
       	getline(file, name, ',');
       	getline(file, dob, ',');
       	getline(file, age, ',');
       	getline(file, address, ',');
      	getline(file, phone, ',');
       	getline(file, depo, ',');
      	getline(file, acc_type, ',');
      	getline(file, date, ',');
      	getline(file, doc,',');
      	getline(file, interest,'\n');
		
		if(acc_no == account_number)
    	{   
    		test = 1;
			cout << "\n Account No.: "<< account_number;
			cout << "\n Name: " << name;
			cout << "\n DOB: " << dob;
			cout << "\n Age: " << age;
			cout << "\n Address: " << address;
			cout << "\n Phone number: " << phone;
			cout << "\n Type Of Account: " << acc_type;
			cout << "\n Balance: " << depo << endl;
			
			cout<<"\n Enter the amount you want to transfer: ";
   			cin >> amt;
   			file.seekg(0, ios::beg);
    		
			if(amt > atoi(depo.c_str()))	cout<<"Not Enough Balance\n";
    		else
    		{
       			amount = atoi(depo.c_str()) - amt;
        		y =  std::to_string(amount);
        		cout<<"\n\tBalance : "<<y;
        		while (file.good())
				{	
					getline(file,x,',');
    				if (x == depo)		ofile << y <<",";
   					else				ofile << x <<",";
        		}						
			}
			break;
		}
	} while (file.good());
	
	file.close();
	ofile.close();
	remove("Bank_Record.csv");
	rename("temp.csv","Bank_Record.csv");
	}
	ifstream file ("Bank_Record.csv" );
	ofstream ofile ("temp.csv" );
	
	if(test == 0)		cout<<"\n\n\t\t Account doesn't Exist!";
	
	cout<<"\n Enter account number where to transfer: ";
	cin >> acc_no;
	test = 0;
	file.seekg(0, ios::beg);
    do
    {
       	getline(file,account_number, ',');
       	getline(file, name, ',');
       	getline(file, dob, ',');
       	getline(file, age, ',');
       	getline(file, address, ',');
      	getline(file, phone, ',');
       	getline(file, depo, ',');
      	getline(file, acc_type, ',');
        if(acc_no == account_number)
    	{   
			test = 1;
			cout << "Account No.: " << account_number;
			cout<<"Name: " << name;			
    		amt = atoi(depo.c_str()) + amt;
        	y =  std::to_string(amt);
        	file.seekg(0, ios::beg);
        	while (file.good())
			{	
				getline(file,x,',');
    			if (x == depo)		ofile << y <<",";
    			else				ofile << x <<",";
        	}
        	cout<<"\n\t Transfer Successful!";
        	break;
        }
	} while (file.good());
	
	file.close();
	ofile.close();
	remove("Bank_Record.csv");
	rename("temp.csv","Bank_Record.csv");
	
	if(test == 0)    	cout<<"\n\n\t\tAccount doesn't Exist!";
	
	retry("customer");
        		
}

// ->   A function in which there is a loop which runs 100000000 times, to make some delay.
void fordelay(int j)
{   int i,k;
    for(i = 0; i < j; i++)
        k = i;
}
// -> A function to display a message on closing the program.
void close(void)
{
	cout << "\n\n\t\t\t Loading";
	for(int i = 0; i < 6; i++)
    {
        fordelay(100000000);
        printf(".");
    }
	system("cls");
	system("color 7");
	title();
    printf("\n\n\t\t\tThis Program is Closed...Thank You\n\n\n\n\n\n");
}
// -> It provide access to the employee menu after inputting correct Employee Id and Password.
void employee()
{
	char pass[10];
    char c;
    string s, name;
    int i=0;
    system("cls");
    system("color D");
	title();
	cout << "\n\t\t\t\t BANK RECORD SYSTEM";
    cout << "\n\n\t\t\t\t EMPLOYEE PORTAL\n";
    cout << "\n\n\t\t For Security Reasons\n";
    cout << "\n\t\t Enter your userneme: ";
    cin >> name;
    cout << "\n\t\t Enter the password: ";
	while(1)
	{
    	c=getch();
        printf("*");
        s+=c;
    	if(c == '\r')		break;  	
	}
 	s = s.substr(0, s.size()-1);
    cout<<endl;
    
	if(s == "0170" && name == "Kartik")
    {
		system("color A");
		printf("\n\n Access Granted!\n LOADING");
	   	for(i=0;i<=6;i++)
       	{
           	fordelay(100000000);
           	printf(".");
       	}
        system("cls");
        menu_e();
    }
    else
    {   
		system("cls");
		system("color 4");
		title();
		cout << "\n\t\t\t\t BANK RECORD SYSTEM";
    	cout << "\n\n\t\t\t\t EMPLOYEE PORTAL\n";
		printf("\n\n\t\t\t Wrong password or Emplyoee Id!!");
		retry("employee");
    }
}
// -> It provide menu for employee, to perform few operations.
void menu_e()
{
	int choice;
    Bank B;
    system("cls");
    system("color D");
	title();
	cout << "\n\t\t\t\t BANK RECORD SYSTEM";
    cout << "\n\n\t\t\t\t EMPLOYEE PORTAL\n";
	cout << "\t\t <1> Account Summary\n";
    cout << "\t\t <2> Display All Account Holder Name\n";
	cout << "\t\t <3> Back to Home Page\n";
	cout << "\t\t <4> Logout\n";
	cout << "\t\t <0> Exit\n";
	cout << "\n\t\t Enter your choice: ";
    cin >> choice;
    system("cls");
    switch(choice)
    {
        case 1:	B.search_rec();		break;
        case 2: B.display_all();	break;
		case 3: main();				break;
		case 4: employee();			break;
        case 0:	close();			break;
        default:
			system("color 9");
			cout<<"Invalid Input!\n";
			retry("employee");
    }
}
// -> It provide access to the customer menu after inputting correct Employee Id and Password for the existing user and direct access to the new user.
void customer()
{
	char pass[10];
    char c;
    string s, name, acc_no, password;
    int choice;
	bool check = false;
	system("cls");
	system("color 6");
	title ();
	cout << "\n\t\t\t\t BANK RECORD SYSTEM";
	cout << "\n\n\t\t\t\t CUSTOMER PORTAL \n\n";
	cout << "\t\t\t <1> New Customer\n";
	cout << "\t\t\t <2> Existing Customer\n";
	cout << "\t\t\t <3> Return to Home Page\n";
	cout << "\t\t\t <4> Exit\n";
	cout << "\n\t\t Enter Your Choice : ";
	cin >> choice;

	switch(choice)
	{
	case 1:	menu_c();		break;
	case 2: 
	{
		system("cls");
		system("color 6");
		title ();
		cout << "\n\t\t\t\t BANK RECORD SYSTEM";
		cout << "\n\n\t\t\t\t CUSTOMER PORTAL \n";
		cout << "\n\n\t\t For Security Reasons\n";
		cout << "\t\t\t Enter your name: ";
		cin >> name;
		cout << "\n\t\t\t Enter the password: ";
		while(1)
		{
			c = getch();
			printf("*");
				s += c;
				if(c == '\r')       break; 
			}   	
	
			s = s.substr(0, s.size()-1);
			cout << endl;
	
			ifstream is("Account_info.csv");
			do
			{
				getline(is,acc_no, ',');
				getline(is,password, '\n');
				if(acc_no == name)
				{
					if(password == s)
						check = true;
						printf("\n\n Access Granted!\n LOADING");
						for(int i = 0; i <= 6; i++)
						{
							fordelay(100000000);
							printf(".");
						}
					system("cls");
					menu_c();
				}
			} while(is.good());
		
			if(check == false)
			{   
				system("color 4");
				printf("\n\n\t\tWrong password or Customer Id!!");
				retry("customer");
			}
		break;
	}
	case 3:	main();			break;
	case 4: close();		break;
	default:
		system("cls");
		system("color 4");
		title ();
		cout << "\n\t\t\t\t BANK RECORD SYSTEM";
		cout << "\n\n\t\t\t\t CUSTOMER PORTAL \n\n";
		cout << "\t\tInvalid Input! Try Again";
		for(int i = 0; i < 6; i++)
    	{
        	fordelay(100000000);
        	printf(".");
    	}
		retry("customer");
	};
	
}
// -> It provide menu for customer, to perform few operations
void menu_c(void)
{
	int choice;
    Bank B;
	system("cls");
	system("color 6");
	title();
	cout << "\n\n\t\t\t\t BANK RECORD SYSTEM";
    cout << "\n\n\t\t\t CUSTOMER PORTAL\n";
	cout << "\n\t\t\t <1> Create new account\n";
	cout << "\t\t\t <2> Update information of existing account\n";
	cout << "\t\t\t <3> For transactions\n";
	cout << "\t\t\t <4> Check the details of existing account\n";
	cout << "\t\t\t <5> For Transfer\n";
	cout << "\t\t\t <6> Exit\n";
	cout << "\n\t\t Enter your choice: ";
	cin >> choice;

	system("cls");
	switch(choice)
	{
		case 1:	B.acc_write();			break;
		case 2:	B.modify_account();		break;
		case 3:	B.deposit_withdraw();	break;
		case 4:	B.search_rec();			break;
		case 5:	B.transfer();			break;
		case 6:	close();				break;
		default:
			system("color 4"); 
			cout<<"Invalid Input!\n";
			retry("customer");
	}
}
// ->  It involves the option for employee and customer. 
int main()
{
	int ch, i;
	system("cls");
	system("color 7");
	title();
	cout << "\n\n\t\t\t###### WELCOME TO SWISS BANK SYSTEM ######";
	cout << "\n\n\t\t\t Loading";
	for(i = 0; i < 6; i++)
    {
        fordelay(100000000);
        printf(".");
    }
	menu:
		system("cls");
		system("color 3");
		title();
		cout << "\n\t\t\t\t     OPTIONS \n\n";
		cout << "\t\t\t <1> Employee Portal\n";
		cout << "\t\t\t <2> Customer Portal\n";
		cout << "\t\t\t <3> Exit\n";
		cout << "\n\t\t Enter Your Choice: ";
		cin >> ch;

		switch(ch)
		{
			case 1: employee();			break;
			case 2: customer();			break;
			case 3: close();			break;
			default :	
				cout << "\t\tInvalid Input! Try Again...\n";
				fordelay(1000000000);
				goto menu;
		}
}

void retry(string person)
{
		login_try:

           	cout << "\n\n\t\t <1> Try Again! \n\t\t <2> Home Page \n\t\t <0> Exit \n\n\t Enter your choice: ";
            scanf("%d",&main_exit);
			
			if (main_exit==1)
			{
				system("cls");
				if (person == "employee")	employee();
				else if(person == "customer")	customer();
			}
			else if (main_exit==0)
			{
				system("cls");
				close();
			}
			else if (main_exit == 2)
			{
				system("cls");
				main();
			}
			else
			{
				printf("\nInvalid!");
				fordelay(1000000000);
				system("cls");
				goto login_try;
			}
}

void title()
{
	cout << "\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO SWISS BANK "
	 	 << 	 "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
}

// Programme Ends Here.
