//Student Report Card Managment System
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
class Student
{
    private:
    int marks[10],total;
    float avg;
    public:
    bool id_verification(char student_id[]);
    void marks_calculation();
    void grade_display(char student_id[], string student_name);
};
bool Student::id_verification(char student_id[])
{
    if(strlen(student_id)!=8)
       return false;
    for(int i=0;i<3;i++)
    {
        if(!isalpha(student_id[i]))
           return false;
    }
    for(int i=3;i<8;i++)
    {
        if(!isdigit(student_id[i]))
           return false;    
    }
    return true;
}
void Student ::  marks_calculation()
{
    total=0;
    cout<<" Enter the marks for the 6 subjects "<<endl;
    for(int i=0;i<6;i++)
    {
        cin>>marks[i];
    }
    for(int i=0;i<6;i++)
    {
        total=total+marks[i];
    }
    avg=total/6.0;
}
void Student::grade_display(char student_id[], string student_name)
{
    cout<<"_______________________________________________________"<<endl;
    cout<<" Student Report Card "<<endl;
    cout<<" Student ID: "<<student_id<<endl;
    cout<<" Student Name: "<<student_name<<endl;
    cout<<"_______________________________________________________"<<endl;
    cout<<" Maximum Marks "<<" \t "<<" Marks Obtained "<<endl;
    for(int i=0;i<6;i++)
    {
        cout<<" 100 "<<"\t\t\t\t\t"<<marks[i]<<endl;
    }
    if(avg>=75)
    {
         cout<<endl<<" Grade A "<<endl;
    }
    else 
    if(avg>=60&&avg<=74)
    {
        cout<<endl<<" Grade B "<<endl;
    }
    else
    if(avg>=50&&avg<=59)
    {
        cout<<endl<<" Grade C "<<endl;
    }
    else 
    cout<<endl<<" Fail "<<endl;
}
int main()
{
    char student_id[10];
    string student_name;
    int attempts=0;
    Student s;
    retry:
          cout<<" Enter your Student ID "<<endl;
          cin>>student_id;
    if(s.id_verification(student_id))
    {
        cout<<" Student ID verified successfully "<<endl;
        cout<<" Enter your name "<<endl;
        cin.ignore();
        getline(cin,student_name);
    }
    else
    {
        attempts++;
        if(attempts<3)
        {
            cout<<" Incorrect Student ID...Please Retry "<<endl;
             goto retry;  
        }
      else
      {
          cout<<" Too many attempts "<<endl<<" Access Denied...Please contact the college for further informations "<<endl;
          exit(0);
      }
    }
    s.marks_calculation();
    s.grade_display(student_id, student_name);
    return 0;
}