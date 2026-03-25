//Hotel Managment
#include<iostream>
using namespace std;
class guest
{
    protected:
    int gid,days,gnum;
    string gname;
    public:
    guest()//default constructor
    {
        cout<<" Enter the GuestID "<<endl;
        cin>>gid;
        cout<<" Enter the Name "<<endl;
        cin>>gname;
        cout<<" Enter your Number "<<endl;
        cin>>gnum;
        cout<<" Enter the no. of days staying "<<endl;
        cin>>days;
    }
    void dsp();
};
void guest::dsp()
{
    cout<<" Guest ID: "<<gid<<endl<<" Name: "<<gname<<endl<<" Contact Details: "<<gnum<<endl<<" No. of Days Stayed "<<days<<endl;
}
class standard:public guest
{
    private:
    float total, rent;
 
    public:
    standard()
    {
        rent=5000;
    }
 
    void dsp();
};
void standard::dsp()
{
    cout << endl<<"----------- FINAL BILL -----------" << endl;
    cout << " Room Category: Standard " << endl;
    cout << " Rent per day : Rs. " << rent << endl;
    total = rent * days;
    cout << " Total Days   : " << days << endl;
    cout << "----------------------------------" << endl;
    cout << " NET PAYABLE  : Rs. " << total << endl;
    cout << "----------------------------------" << endl;
}
class deluxe:public guest
{
    private:
    float total, rent, fcharge;
 
    public:
    deluxe()
    {
        rent=7000;
        fcharge=2000;
    }
  
    void dsp()
    {
         cout << endl<<"----------- FINAL BILL -----------" << endl;
         cout << " Room Category: Deluxe " << endl;
         cout << " Rent per day : Rs. " << rent << endl;
         cout<<" Food Charge per day : Rs. "<<fcharge<<endl;
         total=(rent*days)+(days*fcharge);
         cout << " Total Days   : " << days << endl;
         cout << "----------------------------------" << endl;
         cout << " NET PAYABLE  : Rs. " << total << endl;
         cout << "----------------------------------" << endl;
    }
};
class suite:public guest
{
    float total, rent, fcharge, scharge;
   
    public:
    suite()
    {
        rent=9000;
        fcharge=4000;
        scharge=2000;
    }
 
    void dsp()
    {
         cout << endl<<"----------- FINAL BILL -----------" << endl;
         cout << " Room Category: Suite " << endl;
         cout << " Rent per day : Rs. " << rent << endl;
         cout<<" Food Charge per day : Rs. "<<fcharge<<endl;
         cout<<" Room Service : Rs. "<<scharge<<endl;
         total=(rent*days)+(days*fcharge)+scharge;
         cout << " Total Days   : " << days << endl;
         cout << "----------------------------------" << endl;
         cout << " NET PAYABLE  : Rs. " << total << endl;
         cout << "----------------------------------" << endl;
    }
};
int main()
{
    int ch;
    do1
    {
        cout<<endl<<endl<<endl<<"==============================================================="<<endl<<endl;
        cout<<" 1.Standard "<<endl<<" 2.Deluxe "<<endl<<" 3.Suite "<<endl<<" 4.Exit "<<endl<<" Enter your choice "<<endl;
          cin>>ch;
        switch (ch)
        {
            case 1: 
                   {standard s;
                      
                    cout<<" ___________________________________________________"<<endl;
                    s.guest::dsp();
                   s.dsp();
                   break;
                     }
            case 2: {
                     deluxe del;
                    
                    cout<<" ___________________________________________________"<<endl;
                    del.guest::dsp();
                   del.dsp();
                    break;
                     }
            case 3: {
                     suite o;
                      
                    cout<<" ___________________________________________________"<<endl;
                    o.guest::dsp();
                   o.dsp();
                   break;
                   }
            case 4: cout<<endl<<endl<<" End of the program "<<endl;
                    exit(0);
                    break;
            default:cout<<endl<<endl<<" Incorrect choice chossen "<<endl;
        }
    }while(true);
    return 0;
}