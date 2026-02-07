//Shopping Cart Billing System
#include<iostream>
using namespace std;
struct products
{
    string item_name;
    int quantity;
    float price;
};
class ShoppingCart
{
    private:
    products cart[50];
    int n;
    float total,disc,ototal;
    public:
    void input();
    void add_items();
    void calculate();
    void receipt();
};
void ShoppingCart::input()
{
     cout<<" Enter the number of items "<<endl;
     cin>>n;
     if(n>5)
     cout<<" Maximum limit is 50 items "<<endl;
}
void ShoppingCart::add_items()
{
    cout<<" Enter the item name, quantity and price "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>cart[i].item_name;
        cin>>cart[i].quantity;
        cin>>cart[i].price;
    }
}
void ShoppingCart::calculate()
{
  total=0;
  for(int i=0;i<n;i++)
  {
      total=total+(cart[i].quantity*cart[i].price);
  }
  if(total>5000)
  {
      ototal=total;
      disc=total*0.10;
      total=ototal-disc;
  }
  else
  {
      disc=0;
      ototal=total;
  }
}
void ShoppingCart::receipt()
{
    cout<<"________________________________________________________"<<endl;
    cout<<"                    Receipt                             "<<endl;
    cout<<"________________________________________________________"<<endl;
    cout<<" Items \t"<<" \t\t\tQuantity\t "<<"\t\t\t Price "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<cart[i].item_name<<"\t\t\t\t\t"<<cart[i].quantity<<"\t\t\t\t\t\t"<<cart[i].price<<endl;
    }
    cout<<endl<<" Total = "<<ototal<<endl;
    cout<<" Discount = "<<disc<<endl;
    cout<<endl<<" Amount Payable = "<<total<<endl;
}
int main()
{
    ShoppingCart s;
    s.input();
    s.add_items();
    s.calculate();
    s.receipt();
    return 0;
}