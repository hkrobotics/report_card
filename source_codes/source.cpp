/*======================================================================================
========================================================================================
			  HEADER FILE USED IN PROJECT
========================================================================================
=======================================================================================*/

#include "fstream.h" //for performing input/output operation in file
#include "iomanip.h" //to control format of input/optput
#include "stdio.h"	 //for performing standard input/output operations
#include "conio.h"	 //for conditional input/output statements
#include "process.h" //for exit statement
#include "string.h"	 //for performing operations on strings
#include "dos.h"	 //for time delay
#include "stdlib.h"	 //for randomize function
/*===================================================================================
=====================================================================================
			 CLASS USED IN PROJECT
=====================================================================================
====================================================================================*/

class student
{
	int rollno;
	char name[20];
	float phy, chem, maths, eng, cs, percent;
	char grade;
	void calc_grade(); //function to calculate grade
public:
	void getdata();	 //function to accept data from user
	void showdata(); //function to show data on screen
	void show_table();
	int return_rollno();
}; //class ends here

void student::calc_grade()
{
	percent = (phy + chem + eng + maths + cs) / 5.0;
	if (percent >= 60)
		grade = 'A';
	else if (percent >= 50)
		grade = 'B';
	else if (percent >= 33)
		grade = 'C';
	else
		grade = 'F';
}

void student::getdata()
{
	cout << "\nENTER THE ROLL NUMBER OF THE STUDENT : ";
	cin >> rollno;
	cout << "\n\nENTER THE NAME OF THE STUDENT : ";
	gets(name);

	int x = strlen(name);
	for (int i = x; i < 20; i++)
		name[i] = NULL;

	cout << "\n\n\nENTER THE MARKS IN PHYSICS (MAX-100) : ";
	cin >> phy;
	cout << "\nENTER THE MARKS IN CHEMISTRY (MAX-100) : ";
	cin >> chem;
	cout << "\nENTER THE MARKS IN MATHEMATICS (MAX-100) : ";
	cin >> maths;
	cout << "\nENTER THE MARKS IN ENGLISH (MAX-100) : ";
	cin >> eng;
	cout << "\nENTER THE MARKS IN COMPUTER SCIENCE (MAX-100) : ";
	cin >> cs;
	calc_grade();
}

void student::showdata()
{
	cout << "\n\tROLL NUMBER OF STUDENT : " << rollno;
	cout << "\n\tNAME OF STUDENT : " << name;
	cout << "\n\tMARKS IN PHYSICS : " << phy;
	cout << "\n\tMARKS IN CHEMISTRY : " << chem;
	cout << "\n\tMARKS IN MATHEMATICS : " << maths;
	cout << "\n\tMARKS IN ENGLISH : " << eng;
	cout << "\n\tMARKS IN COMPUTER SCIENCE : " << cs;
	cout << "\n\tPECENTAGE OF STUDENT IS : " << percent;
	cout << "\n\n\tGrade of student is : " << grade;
	if (percent >= 35.5)
		cout << "\n\n\n\tCONGRATULATIONS !! YOU ARE PROMOTED/PASS ";
	else
		cout << "\n\n\n\tOOOPS !! YOU ARE FAIL/DEMOTED , BETTER LUCK NEXT TIME ";
}

void student::show_table()
{
	int w = 1;
	int y = 20;
	w = strlen(name);
	y = y - w;

	cout << rollno << "." << setw(2) << " " << name << setw(y) << phy << setw(8) << chem << setw(8) << maths << setw(8)
		 << eng << setw(8) << cs << setw(10) << percent << " %" << setw(6) << "| " << grade << " |\n";
}

int student::return_rollno()
{
	return rollno;
}

/*======================================================================================
========================================================================================
			      FUNCTION DECLARATION
========================================================================================
=======================================================================================*/

void write_student();  //to write the record in binary file
void display_all();	   //to read all record from binary file
void display_sp();	   //to read specific record from binary file
void display_sp(int);  //for report card
void modify_student(); //to update record of binary file
void delete_student(); //to delete selected records from binary file
void class_result();   //to display all records in tabular format from binary file
void result();		   //to display result menu
void introduction();   //to display introduction screen
void entry_menu();	   //to display entry menu on screen
void credentials();	   //to provide sign-in option
void esc();			   //to exit the program
void load();		   //to display loading screen
void match_load();	   //to display loading screen during matching password

/*======================================================================================
========================================================================================
			 MAIN FUNCTION OF THE PROGRAM
========================================================================================
=======================================================================================*/

void main()
{
	textcolor(1); //blue
	textbackground(7);
	char ch;
	cout.setf(ios::fixed | ios::showpoint);
	cout << setprecision(2); // program outputs decimal number to two decimal places
	clrscr();
	load();
	introduction();

	do //do-while loop
	{
	start:

		clrscr();
		cout << "\n\n\n\t\t\t\t      MAIN MENU";
		cout << "\n\n\n\n\n\t1. RESULT MENU";
		cout << "\n\n\n\t2. ENTRY/EDIT MENU";
		cout << "\n\n\n\t0. EXIT";
		cout << "\n\n\n\n\n\n\tPLEASE SELECT YOUR OPTION : ";
		cin >> ch;
		clrscr();
		switch (ch)
		{

		case '1':
			textcolor(6);
			load();
			result();
			break;
		case '2':
			textcolor(8);
			load();
			credentials();
			break;
		case '0':
			textcolor(4);
			esc();
			break;
		default:
		{
			textcolor(5);
			goto start;
		}
		}
	} while (ch != '0');
}

/*======================================================================================
		      FUNCTION TO DISPLAY LOADING SCREEN
=======================================================================================*/

void load(int time) //exit load
{

	_setcursortype(_NOCURSOR); //to hide away the cursor
	cout << "\n\n\n\n"
		 << setw(45) << "EXITING";
	cout << "\n\n\n"
		 << setw(46) << "THANK YOU";
	cout << "\n\n\n"
		 << setw(49) << "HAVE A NICE DAY";
	cout << "\n\n\n\n\n\n\t";
	for (int x = 0; x < 65; x++)
	{

		if (x % 2 == 0)
			sound(300);
		printf("%c", 222);
		delay(time);
		nosound();
	}
}

void match_load() //matching load
{
	clrscr();
	_setcursortype(_NOCURSOR); //to hide away the cursor
	cout << "\n\n\n\n"
		 << setw(45) << "PLEASE WAIT";
	cout << "\n\n\n"
		 << setw(48) << "MATCHING PASSWORD";
	cout << "\n\n\n\n\n\n\t";
	for (int x = 0; x < 65; x++)
	{
		if (x % 2 == 0)
			sound(400);
		printf("%c", 222);
		delay(30);
		nosound();
	}
}

void load() //function overloading    //normal load
{
	clrscr();
	_setcursortype(_NOCURSOR); //to hide away the cursor
	cout << "\n\n\n\n"
		 << setw(45) << "LOADING";
	cout << "\n\n\n"
		 << setw(46) << "PLEASE WAIT";
	cout << "\n\n\n\n\n\n\t";
	for (int x = 0; x < 65; x++)
	{
		printf("%c", 222);
		if (x % 2 == 0)
			sound(900);
		delay(5);
		nosound();
	}

	clrscr();
}

/*======================================================================================
		     FUNCTION FOR EXITING THE DOS SHELL
=======================================================================================*/

void esc()
{

	load(100);

	exit(0);
}

/*======================================================================================
		    FUNCTION DISPLAYING REPORT CARD
=======================================================================================*/

void display_sp(int n)
{
	clrscr();
	textcolor(6);
	textbackground(7);

	n = -1;
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		cout << "\n\t\t\t\t||  KV LONAVALA  || \n\t\t\t\t    CLASS XII-A \n\t\t\t\t    REPORT CARD";
		cout << "\n\n\n\tPLEASE ENTER THE ROLL NUMBER : ";
		cin >> n;
		student st;
		ifstream inFile;
		inFile.open("student.dat", ios::binary);
		if (!inFile)
		{
			cout << "File could not be open !! Press any Key...";
			getch();
			return;
		}

		int flag = 0;
		while (inFile.read((char *)&st, sizeof(student)))
		{
			if (st.return_rollno() == n)
			{
				st.showdata();
				flag = 1;
			}
		}
		inFile.close();
		if (flag == 0)
			cout << "\n\nrecord not exist";
		getch();
		cout << "\n\n\t DO YOU WANT TO SEE MORE RESULTS ? (Y/N) : ";
		cin >> ch;
		clrscr();
	}
	load();
}

/*======================================================================================
		    FUNCTION FOR PROVIDING SIGN-IN OPTIONS
=======================================================================================*/

void credentials()
{
	textcolor(4);
	int chance = 0;
	int at = 2;
	char line[200];
	char ch;

pass:

	cout << "\n\n\t\t\t\t    LOGIN ";
	cout << "\n\n\n\n\n\n\n PLEASE ENTER YOUR PASSWORD : ";

	int i = 0;
	while (i <= 199)
	{
		ch = getch();

		//v.imp code
		if (ch == 13)
			break;
		if (ch == 8)
		{
			i--;
			clrscr();
			cout << "\n\n\t\t\t\t    LOGIN ";
			cout << "\n\n\n\n\n\n\n PLEASE ENTER YOUR PASSWORD : ";
			for (int star = 0; star < i; star++)
				cout << "*";
			continue;
		}

		line[i] = ch;
		cout << "*";
		i++;
	}

	line[i] = '\0';
	if (strcmp(line, "hk") == 0 || strcmp(line, "HK") == 0)
	{
		match_load();
		load();
		entry_menu();
	}

	else
	{

		textcolor(4);
		match_load();
		clrscr();
		cout << "\n\n\t\t\t     !! INVALID PASSWORD !!";
		cout << "\n\n\t\t\t       !! ACCESS DENIED !!";

		chance++;

		cout << setw(48) << "\n\n\t\t\t       REMAINING ATTEMPS " << at << "\n\n";

		if (chance != 3)
		{
			at--;
			goto pass;
		}

		else
		{
			clrscr();
			cout << "\n\n\t\t\t\t     !! SORRY !! " << setw(48) << "\n\n\t\t\t      TOO MANY INVALID ATTEMPTS\n\n";

			esc();
		}
	}
}

/*======================================================================================
	  FUNCTION TO TAKE DATA AND WRITE IT IN THE FILE : "student.dat"
=======================================================================================*/

void write_student()
{
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		student st;
		ofstream outFile;
		outFile.open("student.dat", ios::binary | ios::app);
		st.getdata();
		outFile.write((char *)&st, sizeof(student));
		outFile.close();
		cout << "\n\nSTUDENT RECORD HAS BEEN CREATED ";
		cin.ignore();
		getch();
		cout << "\n\nDO YOU WANT TO ADD MORE RECORDS ? (Y/N) : ";
		cin >> ch;
		clrscr();
	}
}

/*======================================================================================
	   FUNCTION TO READ ALL RECORDS FROM THE FILE : "student.dat"
=======================================================================================*/

void display_all()
{
	textcolor(5);
	clrscr();

	student st;
	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		getch();
		return;
	}

	while (inFile.read((char *)&st, sizeof(student)))
	{
		textcolor(5);
		cout << "\n\n\n\t\t\tDISPLAY ALL RECORD !!!\n\n";
		st.showdata();
		cout << "\n\n================================================================================\n";
		cout << "================================================================================\n";

		getch();
		clrscr();
		textcolor(5);
		textbackground(7);
	}
	inFile.close();
	cout << "\n\n\nREACHED EOF , PRESS ANY KEY TO CONTINUE ";
	getch();
	clrscr();
}

/*======================================================================================
	FUNCTION TO READ SPECIFIC RECORDS FROM THE FILE : "student.dat"
=======================================================================================*/

void display_sp()
{
	clrscr();
	textcolor(5);
	textbackground(7);

	int n = -1;
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{

		cout << "\n\n\tPLEASE ENTER THE ROLL NUMBER : ";
		cin >> n;
		student st;
		ifstream inFile;
		inFile.open("student.dat", ios::binary);
		if (!inFile)
		{
			cout << "File could not be open !! Press any Key...";
			getch();
			return;
		}

		int flag = 0;
		while (inFile.read((char *)&st, sizeof(student)))
		{
			if (st.return_rollno() == n)
			{
				st.showdata();
				flag = 1;
			}
		}
		inFile.close();
		if (flag == 0)
			cout << "\n\nrecord not exist";
		getch();
		cout << "\n\n\t DO YOU WANT TO SEARCH MORE ? (Y/N) : ";

		textcolor(5);
		textbackground(7);
		cin >> ch;
		clrscr();
	}
	load();
}

/*======================================================================================
	     FUNCTION TO MODIFY RECORDS OF THE FILE : "student.dat"
=======================================================================================*/

void modify_student()
{
	clrscr();
	int n;
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{

		cout << "\n\n\tPLEASE ENTER THE ROLL NUMBER : ";
		cin >> n;
		int found = 0;
		student st;
		fstream File;
		File.open("student.dat", ios::binary | ios::in | ios::out);
		if (!File)
		{
			cout << "File could not be open !! Press any Key...";
			getch();
			return;
		}
		while (File.read((char *)&st, sizeof(student)) && found == 0)
		{
			if (st.return_rollno() == n)
			{
				st.showdata();
				getch();
				clrscr();

				cout << "\n\nPLEASE ENTER THE NEW DETAILS OF STUDENT" << endl;
				st.getdata();
				int pos = (-1) * sizeof(st);
				File.seekp(pos, ios::cur);
				File.write((char *)&st, sizeof(student));
				cout << "\n\n\t RECORD UPDATED";
				found = 1;
			}
		}
		File.close();
		if (found == 0)
			cout << "\n\n RECORD NOT FOUND ";
		getch();
		cout << "\n\n\t DO YOU WANT TO MODIFY MORE STUDENTS DATA ? (Y/N) : ";
		cin >> ch;
		clrscr();
	}
	load();
}

/*======================================================================================
	     FUNCTION TO DELETE RECORDS OF THE FILE : "student.dat"
=======================================================================================*/
void delete_student()
{

	clrscr();

	int n = 0;

	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		cout << "\n  PLEASE ENTER THE ROLL NUMBER OF THE STUDENT WHOSE RECORD IS TO BE DELETED : ";
		cin >> n;
		student st;
		ifstream inFile;
		inFile.open("student.dat", ios::binary);
		if (!inFile)
		{
			cout << "File could not be open !! Press any Key...";
			getch();
			return;
		}
		ofstream outFile;
		outFile.open("Temp.dat", ios::out);
		inFile.seekg(0, ios::beg);
		while (inFile.read((char *)&st, sizeof(student)))
		{
			if (st.return_rollno() != n)
			{
				outFile.write((char *)&st, sizeof(student));
			}
		}
		outFile.close();
		inFile.close();
		remove("student.dat");
		rename("Temp.dat", "student.dat");
		cout << "\n\n\tRecord Deleted ..";
		getch();

		cout << "\n\n\t DO YOU WANT TO DELETE MORE STUDENTS DATA ? (Y/N) : ";
		cin >> ch;
		clrscr();
	}

	load();
}

/*======================================================================================
	    FUNCTION TO DISPLAY ALL STUDENTS REPORT IN TABULAR FORM
=======================================================================================*/

void class_result()
{
	clrscr();
	student st;
	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout << "\n\n\t\t\t\tCLASS XII th RESULT \n\n";
	cout << "================================================================================\n";
	cout << " R.No     Name     PHY     CHEM    MATH     ENG    C S     PERCENTAGE    GRADE" << endl;
	cout << "================================================================================\n";
	while (inFile.read((char *)&st, sizeof(student)))
	{
		st.show_table();
	}
	getch();
	inFile.close();
	load();
}

/*======================================================================================
		      FUNCTION TO DISPLAY RESULT MENU
=======================================================================================*/

void result()
{
start:
	clrscr();
	int ch;
	int rno;
	cout << "\n\n\n\t\t\t\tRESULT MENU";
	cout << "\n\n\n\t1. RESULT IN TABULAR FORM";
	cout << "\n\n\t2. INDIVIDUAL STUDENT REPORT CARD";
	cout << "\n\n\t3. BACK TO MAIN MENU";
	cout << "\n\n\t0. EXIT";
	cout << "\n\n\n\tPLEASE ENTER YOUR CHOICE : ";
	cin >> ch;
	clrscr();
	switch (ch)
	{
	case 1:
		textcolor(4);
		load();
		class_result();
		goto start;
	case 2:
		textcolor(5);
		load();
		display_sp(1);
		goto start;
	case 3:
		textcolor(6);
		load();
		break;
	case 0:
		textcolor(4);
		esc();
	default:
		goto start;
	}
}

/*======================================================================================
			      INTRODUCTION FUNCTION
=======================================================================================*/

void introduction()
{
	cout << "\n\t\t   ||                 WELCOME                 ||";
	cout << "\n\n\n\n\t\t\t\tKENDRIYA VIDYALAYA";
	cout << "\n\n\t\t\t      INS SHIVAJI , LONAVALA ";
	cout << "\n\n\n\n\t\t      COMPUTER SCIENCE INVESTIGATORY PROJECT";
	cout << "\n\n\n\n\t\t      STUDENT REPORT CARD MANAGEMENT SYSTEM";
	cout << "\n\n\n\n\t\t\t||  PRESS ANY KEY TO CONTINUE  ||\n\n\n\n\a";
	getch();
}

/*======================================================================================
			ENTRY / EDIT MENU FUNCTION
=======================================================================================*/

void entry_menu()
{
	int ch;
	int num;
p1:
	textcolor(5);
	clrscr();
	cout << "\n\n\n\t\t\t\tENTRY MENU";
	cout << "\n\n\t1. CREATE STUDENT RECORD";
	cout << "\n\n\t2. DISPLAY ALL STUDENTS RECORDS ONE BY ONE";
	cout << "\n\n\t3. DISPLAY ALL RECORD IN TABULAR FORM";
	cout << "\n\n\t4. SEARCH STUDENT RECORD ";
	cout << "\n\n\t5. MODIFY STUDENT RECORD";
	cout << "\n\n\t6. DELETE STUDENT RECORD";
	cout << "\n\n\t7. DELETE ALL RECORDS";
	cout << "\n\n\t8. LOGOUT AND BACK TO MAIN MENU";
	cout << "\n\n\t0. EXIT";
	cout << "\n\n\tPLEASE ENTER YOUR CHOICE : ";
	cin >> ch;
	clrscr();

	if (ch == 1)
	{
		load();
		write_student();
		goto p1;
	}

	else if (ch == 2)
	{
		load();

		display_all();
		goto p1;
	}

	else if (ch == 3)
	{
		load();
		class_result();
		goto p1;
	}

	else if (ch == 4)
	{
		load();
		display_sp();
		goto p1;
	}

	else if (ch == 5)
	{
		load();
		modify_student();
		goto p1;
	}

	else if (ch == 6)
	{
		load();
		delete_student();
		goto p1;
	}

	else if (ch == 7)
	{
		clrscr();
		load();
		char cd;

		cout << "\n\n\t    ARE YOU SURE , DO YOU WANT TO DELETE ALL RECORDS ? (Y/N) ";
		cin >> cd;

		if (cd == 'y' || cd == 'Y')
			remove("student.dat");
		cout << "\n\n\n\n\n\n\t\t\t\tALL RECORDS DELETED !!";

		getch();
		goto p1;
	}

	else if (ch == 8)
	{
		load();
	}

	else if (ch == 0)
	{
		esc();
	}

	else
	{
		goto p1;
	}
}

/*======================================================================================
		 ||		END OF PROJECT     ||
=======================================================================================*/
