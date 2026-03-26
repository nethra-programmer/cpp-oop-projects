//Hospital Billing System
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class person
{
    protected:
    string name;
    person()
    {
        cout<<" Enter your name "<<endl;
        cin>>name;
    }
    virtual void displayReceipt()
    {
        cout << "\n\t===================================" << endl;
        cout << "\t         HOSPITAL BILLING          " << endl;
        cout << "\t===================================" << endl;
        cout << "\t " << left << setw(18) << "Name:" << name << endl;
    }
};
class patient : public person
{
    protected:
    int id;
    string bloodGroup;
    public:
    patient() : person()
    {
        cout<<" Enter the Patient ID "<<endl;
        cin>>id;
        cout<<" Enter your Blood Group "<<endl;
        cin>>bloodGroup;
    }
    void displayReceipt() override 
    {
        person::displayReceipt();//Print Name
        cout << "\t " << left << setw(18) << "ID:" << id << endl;
        cout << "\t " << left << setw(18) << "Blood Group:" << bloodGroup << endl;
    }
};
class op : public patient
{
    protected:
       string depart;
       string doc_name;
       int token;
       string vitals;
       double consult_fee;
       double test_fee;
       double med_fee;
       string next_appoint;
    public:
    op() : patient()
    {
        cout << " --- OP Registration ---" << endl;
        cout << " Enter Department: ";
        cin >> depart;
        cout << " Enter Doctor Name: "; 
        cin >> doc_name;
        cout << " Enter Token No: ";
        cin >> token;
        cout << " Enter Vitals (BP/Temp): "; 
        cin >> vitals;
        cout << " Fees (Consult/Test/Med): ";
        cin >> consult_fee >> test_fee >> med_fee;
        cout << " Next Appointment Date: "; 
        cin >> next_appoint;
    }
    void displayReceipt() override 
    {
        patient::displayReceipt(); //Displays Patient ID and Blood Group 
        cout << "\t " << left << setw(18) << "Department:" << depart << endl;
        cout << "\t " << left << setw(18) << "Consultant:" << "Dr. " << doc_name << endl;
        cout << "\t " << left << setw(18) << "Vitals:" << vitals << endl;
        cout << "\t " << left << setw(18) << "Token No:" << token << endl;
        cout << "\t-----------------------------------" << endl;
        cout << "\t " << left << setw(18) << "Consultation:" << "Rs. " << consult_fee << endl;
        cout << "\t " << left << setw(18) << "Lab/Tests:" << "Rs. " << test_fee << endl;
        cout << "\t " << left << setw(18) << "Medicines:" << "Rs. " << med_fee << endl;
        double subTotal = consult_fee + test_fee + med_fee;
        cout << "\t " << left << setw(18) << "OP Sub-Total:" << "Rs. " << subTotal << endl;
    }
};
class ward : public op
{
    protected:
    struct general
    {
        int bed_no;
        int days;
        string wname;
        double rent_day;
        double nursing_fee;
        double diet_fee;
    };
    struct icu
    {
        int vent_id;
        string monitor_type;
        double monitor_fee;
        double specialist_fee;
        double oxygen_fee;
    };
    general g;
    icu i;
    int choice;
    public:
    void inputGeneral()
    {
        choice = 1; 
        cout << "\n--- GENERAL WARD DETAILS ---" << endl;
        cout << "Enter Ward Name: "; cin >> g.wname;
        cout << "Enter Bed No: "; cin >> g.bed_no;
        cout << "Enter Days: "; cin >> g.days;
        cout << "Enter Rent/Day: "; cin >> g.rent_day;
        cout << "Enter Nursing/Diet Fees: "; cin >> g.nursing_fee >> g.diet_fee;
    }
    void inputICU() 
    {
        choice = 2;
        cout << "\n--- ICU DETAILS ---" << endl;
        cout << "Enter Ventilator ID: "; cin >> i.vent_id;
        cout << "Enter Monitor Type: "; cin >> i.monitor_type;
        cout << "Enter Days: "; cin >> g.days; // Reusing days for billing
        cout << "Enter ICU Fees (Monitor/Specialist/Oxygen): ";
        cin >> i.monitor_fee >> i.specialist_fee >> i.oxygen_fee;
    }
    void displayReceipt() override
    {
        op::displayReceipt(); 
        double stayCost = 0;
        if (choice == 1) 
       { 
           stayCost = (g.rent_day * g.days) + g.nursing_fee + g.diet_fee;
           cout << "\n\t --- GENERAL WARD STAY ---" << endl;
           cout << "\t " << left << setw(18) << "Ward Name:" << g.wname << endl;
           cout << "\t " << left << setw(18) << "Bed Number:" << g.bed_no << endl;
           cout << "\t " << left << setw(18) << "Days Stayed:" << g.days << endl;
           cout << "\t " << left << setw(18) << "Stay Sub-total:" << "Rs. " << stayCost << endl;
       } 
       else if (choice == 2) 
      {
          stayCost = (g.rent_day + i.monitor_fee + i.specialist_fee + i.oxygen_fee) * g.days;
          cout << "\n\t --- ICU CRITICAL CARE ---" << endl;
          cout << "\t " << left << setw(18) << "Ventilator ID:" << i.vent_id << endl;
          cout << "\t " << left << setw(18) << "Monitor Type:" << i.monitor_type << endl;
          cout << "\t " << left << setw(18) << "Days in ICU:" << g.days << endl;
          cout << "\t " << left << setw(18) << "ICU Sub-total:" << "Rs. " << stayCost << endl;
      }
      double grandTotal = (consult_fee + test_fee + med_fee) + stayCost;
      cout << "\t ===================================" << endl;
      cout << "\t " << left << setw(18) << "GRAND TOTAL:" << "Rs. " << grandTotal << endl;
      cout << "\t ===================================" << endl;
    }
};
class doctor : public person
{
    protected:
    string specialization;
    string employeeID;
    string shift_time;
    double salary;
    double bonus;
    public:
    doctor() : person()
    {
        cout << " --- Doctor Registration --- " << endl;
        cout << " Enter Employee ID: "; cin >> employeeID;
        cout << " Enter Specialization: "; cin >> specialization;
        cout << " Enter Shift (Morning/Evening): "; cin >> shift_time;
        cout << " Enter Monthly Base Salary: "; cin >> salary;
        cout << " Enter Performance Bonus: "; cin >> bonus;
    }
    void displayReceipt() override 
   {
        person::displayReceipt(); 
        double netSalary = salary + bonus;
        cout << "\t --- DOCTOR SALARY SLIP ---" << endl;
        cout << "\t " << left << setw(18) << "Employee ID:" << employeeID << endl;
        cout << "\t " << left << setw(18) << "Specialization:" << specialization << endl;
        cout << "\t " << left << setw(18) << "Shift Timing:" << shift_time << endl;
        cout << "\t-----------------------------------" << endl;
        cout << "\t " << left << setw(18) << "Base Salary:" << "Rs. " << salary << endl;
        cout << "\t " << left << setw(18) << "Bonus:" << "Rs. " << bonus << endl;
        cout << "\t " << left << setw(18) << "NET PAYABLE:" << "Rs. " << netSalary << endl;
        cout << "\t ===================================" << endl;
    }
};
int main()
{
    int ch;
    do
    {
        cout << "\n=========================================" << endl;
        cout << "   HOSPITAL MANAGEMENT SYSTEM            " << endl;
        cout << "=========================================" << endl;
        cout << " 1. Register Patient                     " << endl;
        cout << " 2. Register Doctor (Salary Slip)        " << endl;
        cout << " 3. Exit System                          " << endl;
        cout << "=========================================" << endl;
        cout << " Enter your choice "<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1:
                     {
                         ward w; 
                         int type;
                         preset:
                         cout << "\n Admission Type " << endl;
                         cout << " 1. General Consultation (OP Only)" << endl;
                         cout << " 2. Admission (Ward/ICU) " << endl;
                         cout << " Select your choice: ";
                         cin >> type;
                         if (type == 1)
                         {
                              w.op::displayReceipt(); 
                         }
                         else if (type == 2)
                        {
                              int wtype;
                              wreset:
                              cout << "\n Select Ward " << endl;
                              cout << " 1. General Ward " << endl;
                              cout << " 2. ICU " << endl;
                              cout << " Choice: ";
                              cin >> wtype;
                              if (wtype == 1)
                              {
                                   w.inputGeneral();
                                   w.displayReceipt(); 
                              }
                              else if (wtype == 2)
                             {
                                   w.inputICU();
                                   w.displayReceipt(); 
                              }
                              else 
                             {
                                  cout << "Invalid Ward Choice!" << endl;
                                  goto wreset;
                              }
                        }
                       else 
                      {
                            cout << "Invalid Admission Choice!" << endl;
                            goto preset; 
                      }
                    }
                    break;
            case 2:
                   {
                        doctor d;
                        d.displayReceipt();
                   }
                   break;
            case 3:
                   {
                       cout<<" Thank you for using the system "<<endl<<" Exiting the system....."<<endl;
                       exit(0);
                   }
                   break;
            default:cout<<" Invalid Choice "<<endl<<" Please Try Again...."<<endl;
        }
    }while(true);
    return 0;
}