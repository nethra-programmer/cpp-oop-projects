//ATM SYSTEM 
#include<iostream>
using namespace std;
class BankAccount 
{
    private:
    int acc_no, num, min_balance=500, balance=5000, max_deposit=100000, deposit,depo=0, withdraw,ldigit,count,pin=1234;
    string acc_name;
    public:
    void CreateAccount();
    void ChangePin(int new_pin);
    void VerifyPin();
    void CashDeposit();
    void CashWithdraw();
    void DisplayBalance();
    void Receipt();
};
void BankAccount::CreateAccount()
{
    int i=0;
    returns:cout<<" Enter your Account Number "<<endl;
           cin>>acc_no;
           num=acc_no;
           count=0;
           while(num>0)
          {
            ldigit=num%10;
            count++;
            num=num/10;
          }
          if(count!=8)
         {
            i++;
            if(i>=3)
           {
               cout<<" Protection Mood "<<endl<<"Access Denied...Contact the Bank for further details "<<endl;
               exit(0);
           }
           cout<<" Enter the correct Account Number "<<endl;
           goto returns;
         }
         cout<<" Enter the Account Holder Name "<<endl;
         cin>>acc_name;
}
void BankAccount::ChangePin(int new_pin)
{
    pin=new_pin;
    cout<<" PIN Successfully changed "<<endl;
}
void BankAccount::VerifyPin()
{
    int i=0, entered_pin;
    retry:
    cout<<" Enter your 4-digit PIN "<<endl;
    cin>>entered_pin;
    if(pin==entered_pin)
    {
        cout<<" Access Granted "<<endl;
        return;
    }
    else
    {
       i++;   
        cout<<" Incorrect PIN "<<endl<<3-i<<" attempts remaining "<<endl;
        if(i>=3)
        {
            cout<<" Protection Mood Activated ....Contact the bank for further details "<<endl;
            exit(0);
        }
        goto retry;
    }
}
void BankAccount::CashDeposit()
{
    cout<<" Enter the amount to be deposited "<<endl;
    cin>>deposit;
    if(deposit>max_deposit)
    {
        cout<<" Maximum limit of deposition is rupees 1,00,000.00"<<endl;
        return;
    }
    else
    {
        balance=balance+deposit;
        cout<<" Balance = "<<balance<<endl;
        depo=depo+deposit;
    }
    if(depo>=200000)
    {
        cout<<" Exceeded daily limit...try again tomorrow "<<endl<<" Thank You "<<endl;
        exit(0);
    }
}
void BankAccount::CashWithdraw()
{
    cout<<" Enter the withdrawal amount "<<endl;
    cin>>withdraw;
    if((balance - withdraw) < min_balance)
    {
        cout<<" Insufficient Balance "<<endl<<" Thank you "<<endl;
    }
    else
    {
        balance=balance-withdraw;
        cout<<" Balance = "<<balance<<endl<<" Thank You "<<endl;
    }
}
void BankAccount::DisplayBalance()
{
    cout<<" Balance = "<<balance<<endl<<" Thank You "<<endl;
}
void BankAccount::Receipt()
{
    cout << "\n----------------------------------" << endl;
    cout << "       ATM TRANSACTION RECEIPT      " << endl;
    cout << "----------------------------------" << endl;
    cout << " Account Holder : " << acc_name << endl;
    cout << " Account Number : ********" << endl;
    cout << " Final Balance  : " << balance << endl;
    cout << "----------------------------------" << endl;
    cout << "     THANK YOU FOR VISITING!      " << endl;
    cout << "----------------------------------\n" << endl;
}
int main()
{
    int ch,i=0,new_pin;
    BankAccount b;
    b.CreateAccount();
    b.VerifyPin();
    do
    {
    cout<<" Choices : "<<endl<<" 1. Deposit "<<endl<<" 2. Withdraw "<<endl<<" 3. Check Balance "<<endl<<" 4. Exit "<<endl<<" 5. Change PIN "<<endl;
    cout<<" Enter your choice "<<endl;
    cin>>ch;
       switch(ch)
      {
          case 1: b.CashDeposit();
                  break;
          case 2: b.CashWithdraw();
                  break;
          case 3:b.DisplayBalance();
                 break;
          case 4:  b.Receipt();
                  cout<<" Exited "<<endl<<" Thank You "<<endl;
                  exit(0);
                  break;
           case 5:cout<<" Enter the new PIN "<<endl;
                  cin>>new_pin;
                  b.ChangePin(new_pin);
                  break;
         default: 
    cin.clear(); 
    cin.ignore(1000, '\n');
    i++;
           if(i>=3)
           {
                cout<<" Protection Mood "<<endl<<"Access Denied...Contact the Bank for further details "<<endl;
                exit(0);
           }
           cout<<" Enter the correct choice "<<endl;
      }
    }while(true);
    return 0;
}