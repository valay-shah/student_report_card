#include<iostream>
#include<fstream>
#include<iomanip>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include<string>
using namespace std;

class report_card
{
public:

    int roll_no;
    double per;
    char grade;
    char name[50];
    int p_marks,c_marks,m_marks,e_marks,cs_marks;
    void calculate();
    void get_data();
    int get_rollno();
};

void report_card :: calculate()
{
    per = (p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
    if (per>85)
            grade = 'A';
    else if (per<=85 && per>=75)
            grade = 'B';
    else if (per>=60 && per <75)
            grade = 'C';
    else if (per>=45 && per<60)
            grade = 'D';
    else if (per>=35 && per<45)
            grade = 'E';
    else
            grade = 'F';
}

void report_card :: get_data()
{
    cout<<"Enter the roll no of a student: ";
    cin>>roll_no;
    cout<<"\nEnter the name of a student: ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\nEnter the marks of chemistry subject ";
    cin>>c_marks;
    cout<<"\nEnter the marks of physics subject ";
    cin>>p_marks;
    cout<<"\nEnter the marks of maths subject ";
    cin>>m_marks;
    cout<<"\nEnter the marks of english subject ";
    cin>>e_marks;
    cout<<"\nEnter the marks of computer science subject ";
    cin>>cs_marks;
    calculate();
}


int  report_card :: get_rollno()
{
	return roll_no;
}


void intro();
void add_student();	        //write the record in file
void display_student(int);  //accept rollno and read record from file
void modify_student(int);	//accept rollno and update record in file
void delete_student(int);	//accept rollno and delete selected records from file
void class_result();	    //display all records in tabular format from file
void result();	            //display result menu
void intro();	            //display welcome screen
void edit_menu();           //display edit menu


int main()
{
    char ch;
    cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2);                      // These two lines will set the precision for the decimal values.
	intro();
	do
    {
        cout<<"\n\n\t\t\t Main Menu";
        cout<<"\n\n\t\t 01. Result Menu";
        cout<<"\n\n\t\t 02. Edit Menu";
        cout<<"\n\n\t\t 03. Exit";
        cout<<"\n\n\t\t Please select from (1/2/3) ";
        cin>>ch;
        switch(ch)
        {
                case '1':
                    result();
                    break;
                case '2':
                    edit_menu();
                    break;
                case '3':
                    break;
        }

    }while(ch!='3');

    return 0;
}


void intro()
{
    cout<<"\n\n\t\t Report Card System";
    cout<<"\n\n\t\t Made by Valay Shah";
    cout<<"\n\n\t\t Please press any key to continue";
    cin.get();
}


void result()       // display the result menu
{
    char ch;
    int roll_no;
    cout<<"\n\n\t\t\t RESULT MENU";
	cout<<"\n\n\t\t 1. Class Result";
	cout<<"\n\n\t\t 2. Student Report Card";
	cout<<"\n\n\t\t 3. Back to Main Menu";
	cout<<"\n\n\t\t Enter Choice (1/2/3)? ";
	cin>>ch;
	switch(ch)
	{
    case '1':
        class_result();
        break;
    case '2':
        cout<<"\n Enter Roll no of a student: ";
        cin>>roll_no;
        display_student(roll_no);
        break;
    case '3':
        break;


	}
}


void edit_menu()
{
	char ch;
	int num;
	system("clear");
	cout<<"\n\n\n\t ENTRY MENU";
	cout<<"\n\n\t 1. CREATE STUDENT RECORD";
	cout<<"\n\n\t 2. SEARCH STUDENT RECORD ";
	cout<<"\n\n\t 3. MODIFY STUDENT RECORD";
	cout<<"\n\n\t 4. DELETE STUDENT RECORD";
	cout<<"\n\n\t 5. BACK TO MAIN MENU";
	cout<<"\n\n\t Please Enter Your Choice (1-6) ";
	cin>>ch;
	switch(ch)
	{
	case '1':
	    add_student();
	    break;
    case '2':
        cout<<"Enter roll no of a student: ";
        cin>>num;
        display_student(num);
        break;
    case '3':
        cout<<"Enter roll no of a student: ";
        cin>>num;
        modify_student(num);
        break;
    case '4':
        cout<<"Enter roll no of a student: ";
        cin>>num;
        delete_student(num);
        break;
    case '5':
        break;
	}
}

void class_result()
{
    report_card rc;
    ifstream file;
    string line;
    file.open("data.txt",ios::in);
    if(!file)
    {
    cout<<"File opening failed!..Press any key!";
    cin.ignore();
    cin.get();
    return;
    }
    cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"===========================================================================\n";
	cout<<"R.No         Name         P       C     M      E     CS      %age    Grade"<<endl;
	cout<<"===========================================================================\n";

	while (getline(file,line))   //The test condition is TRUE
                                                  // only while there is something to read.
     {                                           //Works nicely as an end of file check.
          cout<<line<<endl;
     }
    cout<<"Please press any key to continue";
	cin.ignore();
	cin.get();
	file.close();
}

void display_student(int roll_no)
{
    report_card rc;
	ifstream file;
	string line;
	vector<string> result;

	file.open("data.txt",ios::in);
	if(!file)
	{
		cout<<"File could not open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag = false;
	while(getline(file,line))
    {
        boost::split(result, line, boost::is_any_of("\t"));  //this function is used to split the "line" string according to spaces.
        if(stoi(result[0])==roll_no)
		{
            cout<<"\nRoll no of a student:"<<result[0];
            cout<<"\nName of a student:"<<result[1];
            cout<<"\nMarks of Chemestry subject:"<<result[2];
            cout<<"\nMarks of Physics subject:"<<result[3];
            cout<<"\nMarks of Maths subject:"<<result[4];
            cout<<"\nMarks of English subject:"<<result[5];
            cout<<"\nMarks of computer science subject:"<<result[6];
            cout<<"\nPercentage of a student is:"<<result[7];
            cout<<"\nGrade of a student is:"<<result[8];
            cout<<"\nPlease press any key to continue";
            flag=true;
		}
    }
    file.close();
	if(flag==false)
		cout<<"\n\nRecord does not exist... Press any key to continue";
	cin.ignore();
	cin.get();

}


void add_student()
{
	report_card rc;
	ofstream file;
	file.open("data.txt",ios_base::app);
	rc.get_data();
	file<<rc.get_rollno()<<"\t"<<setw(15)<<rc.name<<"\t"<<rc.p_marks<<"\t"<<rc.c_marks<<"\t"<<rc.m_marks<<"\t"<<rc.e_marks<<"\t"<<rc.cs_marks<<"\t"<<rc.per<<"\t"<<rc.grade<<endl;
	file.close();
    cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}


void delete_student(int n)
{
	report_card st;
	string line;
	ifstream file;
	vector<string> result;
	file.open("data.txt",ios::in);
	if(!file)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.txt",ios_base::app);
	file.seekg(0,ios::beg);
	while(getline(file,line))
    {
        boost::split(result, line, boost::is_any_of("\t"));
        if(stoi(result[0])!=n)
        {
            outFile<<result[0]<<"\t"<<setw(15)<<result[1]<<"\t"<<result[2]<<"\t"<<result[3]<<"\t"<<result[4]<<"\t"<<result[5]<<"\t"<<result[6]<<"\t"<<result[7]<<"\t"<<result[8]<<endl;

        }
    }

	outFile.close();
	file.close();
	remove("data.txt");
	rename("Temp.txt","data.txt");
	cout<<"\n\n\tRecord Deleted or else record does not exist..";
	cin.ignore();
	cin.get();
}

void modify_student(int n)
{
	bool found=false;
	report_card rc;
	vector<string> result;
	string line;
	fstream File;
	File.open("data.txt",ios::in|ios_base::app);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
    outFile.open("Temp.txt",ios_base::app);
    File.seekg(0,ios::beg);

	while(getline(File,line))
	{
		boost::split(result, line, boost::is_any_of("\t"));

		if(stoi(result[0])!=n)
        {
            outFile<<result[0]<<"\t"<<setw(15)<<result[1]<<"\t"<<result[2]<<"\t"<<result[3]<<"\t"<<result[4]<<"\t"<<result[5]<<"\t"<<result[6]<<"\t"<<result[7]<<"\t"<<result[8]<<endl;
        }
		if(stoi(result[0])==n)
		{
			cout<<"\nRoll no of a student:"<<result[0];
            cout<<"\nName of a student:"<<result[1];
            cout<<"\nMarks of Chemestry subject:"<<result[2];
            cout<<"\nMarks of Physics subject:"<<result[3];
            cout<<"\nMarks of Maths subject:"<<result[4];
            cout<<"\nMarks of English subject:"<<result[5];
            cout<<"\nMarks of computer science subject:"<<result[6];
            cout<<"\nPercentage of a student is:"<<result[7];
            cout<<"\nGrade of a student is:"<<result[8];
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			rc.get_data();
            outFile<<rc.get_rollno()<<"\t"<<setw(15)<<rc.name<<"\t"<<rc.p_marks<<"\t"<<rc.c_marks<<"\t"<<rc.m_marks<<"\t"<<rc.e_marks<<"\t"<<rc.cs_marks<<"\t"<<rc.per<<"\t"<<rc.grade<<endl;
		    cout<<"\n\n\t Record Updated";
		    found=true;
		}
	}
	outFile.close();
	File.close();
	remove("data.txt");
	rename("Temp.txt","data.txt");
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();

}




