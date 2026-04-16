//Retail Store Inverntory Managment
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Manage_Products
{
    public:
    int flag;
    int n;
    struct products
    {
        int id;
        string name;
        int stock;
        double price_unit;
    };
    products p[100];
    void add_products();
    void dsp_products();
    void search_product();
    void update_product();
    void delete_product();
    void stock_alert();
};
void Manage_Products::add_products()
{
    int count =1;
    cout<<" Enter the number of products "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    { 
        cout<<endl<<endl<<count<<"."<<endl;
        retry:
        cout<<" Enter the product id "<<endl;
        cin>>p[i].id;
        for(int j=0;j<i;j++)
        {
            if(p[i].id==p[j].id)
            {
                cout<<" Product ID cannot be same "<<endl;
                cout<<" Re-enter the product id "<<endl;
                goto retry;
            }
        }
        cout<<" Enter the product name "<<endl;
        cin>>p[i].name;
        cout<<" Availability "<<endl;
        cin>>p[i].stock;
        cout<<" Price per unit "<<endl;
        cin>>p[i].price_unit;
        count++;
        flag++;
    }
}
void Manage_Products::dsp_products()
{
    if(flag==0)
    {
        cout<<endl<<" Inventory is empty "<<endl<<" Add new products "<<endl;
    }
    else
    {
        cout << endl << string(60, '-') << endl;
        cout << left << setw(5)  << "No." 
         << setw(10) << "ID" 
         << setw(20) << "Product Name" 
         << setw(10) << "Stock" 
         << setw(10) << "Price" << endl;
         cout << string(60, '-') << endl;
         for(int i = 0; i < n; i++)
         {
             cout << left << setw(5)  << (i + 1)
             << setw(10) << p[i].id
             << setw(20) << p[i].name
             << setw(10) << p[i].stock
             << fixed << setprecision(2) << p[i].price_unit << endl;
          }
          cout << string(60, '-') << endl;
    }
}
void Manage_Products::search_product()
{
    int s;
    bool found=false;
     cout<<" Product ID "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i].id<<endl;
    }
    cout<<" Enter the product id of the product to be searched "<<endl;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s==p[i].id)
        {
            cout<<" The searched product: "<<endl;
            cout<<" Product ID: "<<p[i].id<<endl;
            cout<<" Product Name: "<<p[i].name<<endl;
            cout<<" Product Availability: "<<p[i].stock<<endl;
            cout<<" Price per unit: "<<p[i].price_unit<<endl;
            found=true;
        }
    }
    if(!found)
    {
        cout<<" Product ID: "<<s<<" is not found "<<endl;
    }
}
void Manage_Products::update_product()
{
    int ch,p_ch;
    int n_stock;
    double n_price;
    dsp_products();
    cout<<" Enter the position of the product to be updated "<<endl;
    cin>>p_ch;
    if(p_ch < 1 || p_ch > n)
    {
        cout <<" Invalid position "<< endl;
    }
    p_ch=p_ch-1;
    cout<<endl<<" 1. Stock updation "<<" 2.Price updation "<<endl;
    cout<<" Enter your choice "<<endl;
    cin>>ch;
    if(ch==1)
    {
        cout<<" Enter the new stock for the choosen product "<<endl;
        cin>>n_stock;
        p[p_ch].stock=n_stock;
        cout<<" Updated Product Details "<<endl;
        cout<<" Product ID: "<<p[p_ch].id<<endl;
        cout<<" Product Name: "<<p[p_ch].name<<endl;
        cout<<" Product Availability: "<<p[p_ch].stock<<endl;
        cout<<" Price per unit: "<<p[p_ch].price_unit<<endl;
    }
    else if(ch==2)
    {
        cout<<" Enter the new price per unit for the choosen product "<<endl;
        cin>>n_price;
        p[p_ch].price_unit=n_price;
        cout<<" Updated Product Details "<<endl;
        cout<<" Product ID: "<<p[p_ch].id<<endl;
        cout<<" Product Name: "<<p[p_ch].name<<endl;
        cout<<" Product Availability: "<<p[p_ch].stock<<endl;
        cout<<" Price per unit: "<<p[p_ch].price_unit<<endl;
    }
    else
    cout<<" Enter a valid choice "<<endl;
}
void Manage_Products::delete_product()
{
   int pos;
   int ele;
   dsp_products();
   cout<<" Enter the product id tht to be deleted "<<endl;
   cin>>ele;
   cout<<" Enter the position of the product to be updated "<<endl;
   cin>>pos;
   pos=pos-1;
   if(pos<0||pos>=n)
   {
       cout<<" Deletion is not possible "<<endl;
       return;
   }
   else
   {
       ele=p[pos].id;
       for(int i=pos;i<n-1;i++)
       {
           p[i]=p[i+1];
       }
       n=n-1;
       cout<<ele<<" is deleted "<<endl;
   }
}
void Manage_Products::stock_alert()
{
    for(int i=0;i<n;i++)
    {
        if(p[i].stock<10)
        {
            cout<<" Product ID: "<<p[i].id<<" have insufficient stock "<<endl;
            cout<<" Stock: "<<p[i].stock<<endl;
        }
    }
}
int main()
{
     Manage_Products m;
     int ch;
     do 
     {
         cout<<endl<<endl<<" 1.Add New Products "<<endl<<" 2.Display Products "<<endl<<" 3.Search Product "<<endl<<" 4.Update Product "<<endl<<" 5.Delete Product "<<endl<<" 6.Stock Alert "<<endl<<" 7.Exit the system "<<endl;
         cout<<" Enter your choice "<<endl;
         cin>>ch;
         switch(ch)
         {
            case 1:{
                        cout<<endl<<endl<<" Add new products "<<endl;
                        m.add_products();
                    }
                    break;
            case 2:{
                        m.dsp_products();
                    }
                    break;
            case 3:{
                        cout<<endl<<endl<<endl<<" Product Search "<<endl;
                        m.search_product();
                   }
                   break;
            case 4:{
                        cout<<endl<<endl<<endl<<" Product Updation "<<endl;
                        m.update_product();
                   }
                   break;
            case 5:{
                        cout<<endl<<endl<<endl<<" Product Deletion "<<endl;
                        m.delete_product();
                   }
                   break;
            case 6:{
                        cout<<endl<<endl<<endl<<" Low Stock Alert "<<endl;
                        m.stock_alert();
                   }
                   break;
            case 7:{
                        cout<<" Exiting the system "<<endl<<" Thank You "<<endl;
                        exit(0);
                   }
                    break;
            default: cout<<" Entered choice is invalid "<<endl<<" Try Again "<<endl;
         }
     }while(true);
    return 0;
}