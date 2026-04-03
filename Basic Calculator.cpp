//Basic Calculator
#include<iostream>
#include<math.h>
using namespace std;
class calculator
{
    private:
    double a, b, res,num;
    public:
    calculator(){}
    calculator(double n1, double n2)
    {
      a=n1;
      b=n2;
    }
    calculator(double n)
    {
        num=n;
    }
    void add();
    void sub();
    void multi();
    void divis();
    void sqr_rt();
    void power(double n, double b);
};
void calculator :: add()
{
    res=a+b;
    cout<<a<<" + "<<b<<" = "<<res<<endl; 
}
void calculator :: sub()
{
    res=a-b;
    cout<<a<<" - "<<b<<" = "<<res<<endl;
}
void calculator :: multi()
{
    res=a*b;
    cout<<a<<" x "<<b<<" = "<<res<<endl;
}
void calculator :: divis()
{
    res=a/b;
    cout<<a<<" / "<<b<<" = "<<res<<endl;
}
void calculator :: sqr_rt()
{
    res=sqrt(num);
    cout<<" Square root of "<<num<<" = "<<res<<endl;
}
void calculator :: power(double n, double b)
{
    res=pow(b,n);
    cout<<b<<" ^ "<<n<<" = "<<res<<endl;
}
int main()
{
    int ch;
    do
    {
        cout<<endl<<endl<<" 1.Addition "<<endl<<" 2.Subtraction "<<endl<<" 3.Multiplication "<<endl<<" 4.Division "<<endl<<" 5.Square Root "<<endl<<" 6.Square "<<endl<<" 7.Exit "<<endl;
        cout<<" Enter your choice "<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1:{
                       double n1,n2;
                       cout<<" Enter the two numbers "<<endl;
                       cin>>n1>>n2;
                       calculator c(n1,n2);
                       c.add();
                   }
                   break;
            case 2:{
                       double n1,n2;
                       cout<<" Enter the two numbers "<<endl;
                       cin>>n1>>n2;
                       calculator c(n1,n2);
                       c.sub();
                   }
                   break;
            case 3:{
                       double n1,n2;
                       cout<<" Enter the two numbers "<<endl;
                       cin>>n1>>n2;
                       calculator c(n1,n2);
                       c.multi();
                   }
                   break;
            case 4:{
                       double n1,n2;
                       cout<<" Enter the two numbers "<<endl;
                       cin>>n1>>n2;
                       calculator c(n1,n2);
                       c.divis();
                   }
                   break;
            case 5:{
                       double n;
                       cout<<" Enter the number "<<endl;
                       cin>>n;
                       calculator c(n);
                       c.sqr_rt();
                   }
                   break;
            case 6:{
                       double n,b;
                       cout<<" Enter the base and exponent "<<endl;
                       cin>>b>>n;
                       calculator c;
                       c. power(n,b);
                   }
                   break;
            case 7:{
                       cout<<" Exiting the System "<<endl<<" Thank You..."<<endl;
                       exit(0);
                   }
                   break;
            default: cout<<" Entered choice is incorrect "<<endl<<" Try Again..."<<endl;
        }
    }while(true);
    return 0;
}