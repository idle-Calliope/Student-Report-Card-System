//1923636 - Ellaine Fontamillas IPC ICA Artefact 2020

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

//Class for student
class student_details
{
    public:
    char name[40], result[30], r1[30] = {"Third Class"}, r2[30]= {"Second Class"}, r3[30]{"First Class"}, r4[30]={"Distinction"};
	int st_id, eng, fre, ses, mat, sci, soc, total = 0, ave = 0, class_ave = 0, grade;

    void results(); //Function to determine results
public:
    int student_id_generator();//Function for class average and total
    void showDetails(); //Function to SHOW DATA on screen
    void showClassResults(); //Function to SHOW CLASS RESULTS on screen in a tabular like form
    void getDetails();//Function to ACCEPT STUDENT DETAILS from Teachers/User
    void reportCard(); //Function to GENERATE REPORT CARD
    void class_results();//Function for CLASS RESULTS Header

    //Function for student ID
    int student_id()
    {
        return st_id;
    }
};
//Function to CALCULATE CLASS RESULTS
void student_details::results()
{
	ave = (eng + fre + ses + mat + soc + sci) / 6;
	if (ave >= 50 && ave < 60)
		strcpy(result,r1);
	else if (ave >= 60 && ave < 70)
		strcpy(result,r2);
	else if (ave >= 70 && ave < 80)
		strcpy(result,r3);
	else (ave >= 80 && ave <= 100);
		strcpy(result,r4);
}

int student_details::student_id_generator()
{
   srand(time(0));

    for(int x = 1;  x <= 1; x++)
    {
        int id;
        id = 100001+ rand () % 103000;
        st_id = id;
    }
}

//Function to GET STUDENT DETAILS FROM THE TEACHER/USER
void student_details::getDetails()
{
        cout<<"\tStudent ID:      \t\t"<<st_id;
        cout<<endl<<endl;

        cout<<"\tEnter Student Name:    \t\t";
        cin.ignore();
        cin.getline(name, 25);
        cout<<"\tEnter Student Grade/Class:   \t";
        cin>>grade;

        cout<<endl;
        cout<<"\tEnter Marks out of 100 ------------\n";
        cout<<"\tEnglish:   \t\t\t";
        cin>>eng;
        cout<<"\tFrench:    \t\t\t";
        cin>>fre;
        cout<<"\tSesotho:   \t\t\t";
        cin>>ses;
        cout<<"\tMaths:   \t\t\t";
        cin>>mat;
        cout<<"\tScience:   \t\t\t";
        cin>>sci;
        cout<<"\tSocial:    \t\t\t";
        cin>>soc;
        results();

    }
//Function to DISPLAY STUDENT RECORD
void student_details::showDetails ()
{
        cout<<"\tStudent ID:     \t\t"<<st_id;
        cout<<endl<<endl;

        cout<<"\tStudent Name:    \t\t"<<name;
        cout<<"\n\tStudent Grade/Class:   \t\t"<<grade;

        cout<<endl<<endl;
        cout<<"\t------------- Marks out of 100 ------------\n";
        cout<<"\tEnglish:   \t\t\t"<<eng<<"\n";
        cout<<"\tFrench:    \t\t\t"<<fre<<"\n";
        cout<<"\tSesotho:   \t\t\t"<<ses<<"\n";
        cout<<"\tMaths:   \t\t\t"<<mat<<"\n";
        cout<<"\tScience:   \t\t\t"<<sci<<"\n";
        cout<<"\tSocial:    \t\t\t"<<soc<<"\n";
}
//Function to SHOW CLASS RESULTS
void student_details::showClassResults () //show Class Results function inherits from student details class
{
    const char seperator  = ' ';
    cout<<left<<setw(12)<<setfill(seperator)<<st_id;
    cout<<left<<setw(11)<<setfill(seperator)<<name;
    cout<<left<<setw(8)<<setfill(seperator)<<eng;
    cout<<left<<setw(9)<<setfill(seperator)<<fre;
    cout<<left<<setw(9)<<setfill(seperator)<<ses;
    cout<<left<<setw(9)<<setfill(seperator)<<mat;
    cout<<left<<setw(9)<<setfill(seperator)<<sci;
    cout<<left<<setw(9)<<setfill(seperator)<<soc;
    cout<<left<<setw(11)<<setfill(seperator)<<ave;
    cout<<left<<setw(14)<<setfill(seperator)<<result<<endl;
    //cout<<left<<setw(n)<<setfill(seperator)<<classaverage;

}
//Function to GENERATE REPORT CARD
void student_details::reportCard()
{
    int m = 100, n;
    cout<<"\n\n\t\tStudent ID: "<<st_id<<endl;
    cout<<"\t\tStudent Name: "<<name<<endl;
    cout<<"\t\tClass/Grade: "<<grade<<"th Grade"<<endl;
    cout<<"\t\tSubjects\t\tMaximum Marks\t\tMarks Scored\n";

    cout<<"\t\tEnglish\t"<<setw(24)<<m<<setw(24)<<eng<<endl;
    cout<<"\t\tFrench\t"<<setw(24)<<m<<setw(24)<<fre<<endl;
    cout<<"\t\tSesotho\t"<<setw(24)<<m<<setw(24)<<ses<<endl;
    cout<<"\t\tMaths\t"<<setw(24)<<m<<setw(24)<<mat<<endl;
    cout<<"\t\tScience\t"<<setw(24)<<m<<setw(24)<<sci<<endl;
    cout<<"\t\tSocial\t"<<setw(24)<<m<<setw(24)<<soc<<endl;
    cout<<"\t\tTotal\t"<<setw(24)<<m * 6<<setw(24)<<eng + fre + ses + mat + sci + soc<<endl;
    cout<<"\t\t-------------------------------------------------------------"<<endl;
    cout<<"\t\tAverage\t"<<setw(24)<<m<<endl;
    //cout<<"\t\tEnglish\t"<<setw(24)<<m<<setw(24)<<classaverage<<endl;
    cout<<"\t\tResult\t"<<setw(32)<<result<<endl;
    cout<<"\t\t-------------------------------------------------------------"<<endl;
    cout<<"\t\tSignatures: \n\n";
    cout<<"\t\t...........          ............           ............ \n";
    cout<<"\t\tTeacher\t\t     Principal\t\t    Parent/Guardian";

}
//Function for Class Results header
void student_details::class_results()
{
     cout<<"\t\t\t\tSt. Peter International School, Student Report Card system \n";
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<"\n";
    cout<<"\t\t\t\t\tDisplay Results Window \n";
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<"\n";
    cout<<"\t\t\t\t\t    Class/Grade:  "<<grade<<"th grade \n";
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<"\n";
    cout<<"Stu_ID      Name       Eng     Fre      Ses      Mat      Sci      Soc      Ave        Result        Class Ave        "<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<"\n";
}

//Function Declarations
void writeIntoFile();
void generate_student_report_card(int);
void display_all_records();
void search_student_record(int);
void modify_record(int);
void delete_record(int);
void classResults(int);
int main();


//1.Function to WRITE IN FILE
void writeIntoFile()
{
    student_details st;//instantiating student details class object
    st.student_id_generator();

    ofstream my_File; //instantiating ofstream class object

    cout<<"\t\t\tSt. Peter International School, Student Report Card system \n";
    cout<<"     -------------------------------------------------------------------------------------------------------------"<<"\n";
    cout<<"\t\t\t\t\tAdd Student Record Window \n";
    cout<<"     -------------------------------------------------------------------------------------------------------------"<<"\n";

    my_File.open("student_details.txt",ios::binary|ios::app);//opens the instance, gives it a name and a .dat extension, uses binary mode to output to the file
    st.getDetails();//using st object to call getDetails function that accepts input from the user
    my_File.write(reinterpret_cast<char*> (&st), sizeof(student_details));//writes into student details occupied by st, expects a char* and converts pointer of one type to another that may not be related
    my_File.close();//closes

    cout<<"\n\n \tStudent Record Has Been Captured ";
    cin.ignore();
    cin.get();
    system("cls");
    main();
}
//2.Function to GENERATE STUDENT REPORT CARD
void generate_student_report_card(int n)
{
     student_details st;
        ifstream myFile;
        myFile.open("student_details.txt", ios::binary);

        //Check for presence of file
        if(!myFile)
        {
            cout<<"Cannot Open File ! ! It is either Missing or Non-Existent  Press a Key to continue. . . \n";
            cin.ignore();
            cin.get();
            system("cls");
            main();
        }
        //HEADING
        cout<<"\n\n\t\t\t\tSt. Peter International School \n";
        cout<<"                                                                                                         \n";
        cout<<"\t\t\t\t      Student Report Card \n";

        bool flag=false;
        while(myFile.read(reinterpret_cast<char*> (&st), sizeof(student_details)))
        {
            //Check if student id exists
            if(st.student_id()==n)
            {
                //Then using st to call showDetails function
                st.reportCard();
                flag=true;
            }
        }
        myFile.close();
        //Actions when ID is invalid/or missing
        if(flag==false)
        cout<<"\n\n\t The Record Missing/Non-Existent ! ! ! ";
        cin.ignore();
        cin.get();
        system("cls");
        main();
}
//3.Function to DELETE A RECORD
void delete_record(int n)
{
    char input, input2;
    student_details st;
    ifstream File__;
    File__.open("student_details.txt", ios::binary);

     //Checks for presence of file
    if(!File__)
    {
        cout<<"Cannot Open File ! ! It is either Missing or Non-Existent  Press a Key to continue. . . \n";
        cin.ignore();
        cin.get();
        system("cls");
        main();
    }

    bool exist=false;
    while(File__.read(reinterpret_cast<char*>(&st),sizeof(student_details)))
    {
        if(st.student_id()==n)
        {
            cout<<"\n\n\t Are you sure you want to delete [Y/N]?";
            cin>>input;

                        if(input=='Y')
                        {
                                ofstream File__2;
                                File__2.open("Temp.txt", ios::out);
                                File__.seekg(0,ios::beg);
                                while(File__.read(reinterpret_cast<char*> (&st), sizeof(student_details)))
                                {
                                    if(st.student_id()!=n)
                                    {
                                        File__2.write(reinterpret_cast<char*> (&st), sizeof(student_details));
                                    }
                                }
                                File__2.close();
                                File__.close();

                                system("cls");
                                remove("student_details.txt");
                                rename("Temp.txt", "student_details.txt");
                                cout<<"\n\n\tThe Record has been deleted \n";
                                cin.ignore();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else if(input=='N')
                        {
                            system("cls");
                            cout<<"\n\n\tWould you like to return to the Menu [Y/N]? ";
                            cin>>input2;
                            if(input2=='Y')
                            {
                                system("cls");
                                main();
                            }
                        }
                        else
                        {
                                system("cls");
                                cout<<"\n\n\tERROR: Invalid Input!!!!\n\n";
                        }
                        exist=true;
        }
    }

    //Test when ID is not Valid
    if(exist==false)
        cout<<"\n\n\t Record Missing/Non-Existent ! ! !";
        cin.ignore();
        cin.get();
        system("cls");
        main();
}
//4. Function to MODIFY A SINGLE RECORD
void modify_record(int n)
{
    bool flag=false;
    student_details st;
    fstream _my_file_;
    _my_file_.open("student_details.txt", ios::binary|ios::in|ios::out);

    //Creation Check
    if(!_my_file_)
    {
        cout<<"Cannot Open File ! ! It is either Missing or Non-Existent  Press a Key to continue. . . \n";
        cin.ignore();
        cin.get();
        system("cls");
        main();
    }
    while(!_my_file_.eof() && flag==false)
    {
        _my_file_.read(reinterpret_cast<char*> (&st), sizeof(student_details));
        if(st.student_id()==n)
        {
            //Header
            cout<<"\t\t\tSt. Peter International School, Student Report Card system \n";
            cout<<"     -------------------------------------------------------------------------------------------------------------"<<"\n";
            cout<<"\t\t\t\t\tModify Student Record Window \n";
            cout<<"     -------------------------------------------------------------------------------------------------------------"<<"\n";

            st.showDetails();
            cout<<"\n\n\tEnter the New Record for the Student\n\n"<<endl;
            st.getDetails();
                int position=(-1)*static_cast<int>(sizeof(st));
                _my_file_.seekp(position, ios::cur);
                _my_file_.write(reinterpret_cast<char*> (&st), sizeof(student_details));
                system("cls");
                cout<<"\n\n\t Student Record Has Been Updated";
                flag=true;
                cin.ignore();
                cin.get();
                system("cls");
                main();
        }
    }

    _my_file_.close();
    if(flag==false)
        cout<<"\n\n\tRecord Missing/Non-Existent ! ! ! ";
        cin.ignore();
        cin.get();
        system("cls");
        main();
}
//5.Function to SEARCH AND DISPLAY A SINGLE RECORD
void search_student_record(int n)
{
        student_details st;
        ifstream myFile;
        myFile.open("student_details.txt", ios::binary);

        //Check for presence of file
        if(!myFile)
        {
            cout<<"Cannot Open File ! ! It is either Missing or Non-Existent  Press a Key to continue. . . \n";
            cin.ignore();
            cin.get();
            system("cls");
            main();
        }

        bool flag=false;
        while(myFile.read(reinterpret_cast<char*> (&st), sizeof(student_details)))
        {
            //Check if student id exists
            if(st.student_id()==n)
            {
                cout<<"\t\t\tSt. Peter International School, Student Report Card system \n";
                cout<<"     -------------------------------------------------------------------------------------------------------------"<<"\n";
                cout<<"\t\t\t\t\tSearch Student Records Window \n";
                cout<<"     -------------------------------------------------------------------------------------------------------------"<<"\n";

                st.showDetails();
                flag=true;
            }
        }
        myFile.close();
        if(flag==false)
        cout<<"\n\n\t Record is Missing/Non-Existent ! ! !";
        cin.ignore();
        cin.get();
}
//6. Function to DISPLAY ALL STUDENT RECORDS
void display_all_records()
{
    student_details st;
    ifstream my_File2;
    my_File2.open("student_details.txt", ios::binary);

    //Check if file was created
    if(!my_File2)
    {
        cout<<"Cannot Open File ! ! It is either Missing or Non-Existent  Press a Key to continue. . . \n";
        cin.ignore();
        cin.get();
        system("cls");
        main();
    }

    cout<<"\t\t\tSt. Peter International School, Student Report Card system \n";
    cout<<"                                               \n";
    cout<<"\t\t\t\tDisplay All Student Records Window ";


    while(my_File2.read(reinterpret_cast<char*> (&st), sizeof(student_details)))
    {
       cout<<"\n\n     =============================================================================================================\n";
        st.showDetails();

    }
    my_File2.close();
    cin.ignore();
    cin.get();
    system("cls");
    main();
}
//7.Function to DISPLAY CLASS RESULTS
void classResults(int n)
{
    student_details st;
    ifstream intoFile;
    intoFile.open("student_details.txt", ios::binary);
    if(!intoFile)
    {
        cout<<"Cannot Open File ! ! It is either Missing or Non-Existent  Press a Key to continue. . . \n";
        cin.ignore();
        cin.get();
        system("cls");
        main();
    }

    bool flag = false;
    while(intoFile.read(reinterpret_cast<char*>(&st), sizeof(student_details)))
    {
        if(st.grade==n)
        {
         st.class_results();
         st.showClassResults();
         flag = true;
        }
    }
    intoFile.close();
    if(flag==false)
    cout<<"\n\n\tThis grade does not exist!!!";
    cin.ignore();
    cin.get();

}
//Function for Main Menu
int main()
{
    int option, n;

    cout<<" \n\n\n\t\t\t\t\tSt.Peter International School"<<endl;
    cout<<"\t\"Striving to produce well-rounded, confident, educated, responsible individuals to be global \n \t\t\t\t\t\t citizens,\" "<<endl;
    cout<<"                                                                                \n";
    cout<<"\t============================================================================================="<<endl;
    cout<<"                                                                                \n";
    cout<<"\t\t     Welcome to Student Report Card system of St. International School \n\n";
    cout<<"\t============================================================================================="<<endl;
    cout<<"                                                                                \n";
    cout<<" \t\t\t\t\t\tMain Menu \n";
    cout<<"                                                                                \n";
    cout<<"\t============================================================================================="<<endl;
    cout<<"\n\t\t1. Create Student Record"<<endl;
    cout<<"\t\t2. Generate Student Report Card"<<endl;
    cout<<"\t\t3. Delete Student Record"<<endl;
    cout<<"\t\t4. Modify Student Record"<<endl;
    cout<<"\t\t5. Search for Student Record"<<endl;
    cout<<"\t\t6. Display all Student Records"<<endl;
    cout<<"\t\t7. Display Class Result and Average"<<endl;
    cout<<"\t\t8. Exit"<<endl;
    cout<<"\t\t    Please enter your choice (1-8) ";
    cin>> option;
    system("cls"); //Clears the screen after input

    switch(option)
        {
            //CREATE
            case 1:
                        writeIntoFile();
                break;
            //GENERATE
            case 2: cout<<"\n \tPlease Enter a Student ID: ";
                        cin>>n;
                        system("cls");
                        generate_student_report_card(n);
                break;
            //DELETE
            case 3:
                        cout<<"\n\n \tPlease Enter a Student ID: ";
                        cin>>n;
                        system("cls");
                        delete_record(n);
                break;
            //MODIFY
            case 4: cout<<"\n \tPlease Enter a Student ID: ";
                        cin>>n;
                        system("cls");
                        modify_record(n);
                break;
            //SEARCH
            case 5: cout<<"\n \tPlease Enter a Student ID: ";
                        cin>>n;
                        system("cls");
                        search_student_record(n);
                        system ("cls");
                        main();
                break;
            //DISPLAY ALL
            case 6: display_all_records();
                break;
            //CLASS RESULT && CLASS AVERAGE
            case 7:  cout<<"\n \tPlease Enter a the grade of the class: ";
                        cin>>n;
                        system("cls");
                        classResults(n);
                        system("cls");
                        main();
                break;
            //EXIT
            case 8:  system("cls"); break;
            default: cout<<"\a"; main();
        }
    return 0;
}


