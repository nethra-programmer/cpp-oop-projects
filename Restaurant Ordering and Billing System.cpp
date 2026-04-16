//Restaurant Ordering and Billing System
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Restaurant
{
public:
    int n = 0;
    int flag = 0;
    double daily_sales = 0;

    struct menu
    {
        int id;
        string name;
        double price;
        string category;
    };
    struct order
    {
        int id;
        string name;
        int qty;
        double price;
        double total;
    };
    menu m[100];
    order o[100];
    void add_item();
    void dsp_menu();
    void update_item();
    void delete_item();
    void take_order();
    void daily_report();
};
void Restaurant::add_item()
{
    int count = 1;
    int x;
    cout<<" Enter number of items "<<endl;
    cin>>x;
    for(int i=0;i<x;i++)
    {
        cout<<endl<<count<<"."<<endl;
        retry:
        cout<<" Enter item ID "<<endl;
        cin>>m[n].id;
        for(int j=0;j<n;j++)
        {
            if(m[n].id == m[j].id)
            {
                cout<<" ID already exists, re-enter "<<endl;
                goto retry;
            }
        }
        cout<<" Enter item name "<<endl;
        cin>>m[n].name;
        cout<<" Enter category "<<endl;
        cin>>m[n].category;
        cout<<" Enter price "<<endl;
        cin>>m[n].price;
        n++;
        flag++;
        count++;
    }
}
void Restaurant::dsp_menu()
{
    if(flag==0)
    {
        cout<<" Menu is empty "<<endl;
        return;
    }
    cout << endl << string(60,'-') << endl;
    cout << left << setw(5)<<"No."
         << setw(10)<<"ID"
         << setw(15)<<"Name"
         << setw(15)<<"Category"
         << setw(10)<<"Price"<<endl;
    cout << string(60,'-') << endl;
    for(int i=0;i<n;i++)
    {
        cout << left << setw(5)<<i+1
             << setw(10)<<m[i].id
             << setw(15)<<m[i].name
             << setw(15)<<m[i].category
             << fixed << setprecision(2)<<m[i].price<<endl;
    }
    cout << string(60,'-') << endl;
}
void Restaurant::update_item()
{
    int pos;
    dsp_menu();
    cout<<" Enter position to update "<<endl;
    cin>>pos;
    if(pos<1 || pos>n)
    {
        cout<<" Invalid position "<<endl;
        return;
    }
    pos--;
    cout<<" Enter new price "<<endl;
    cin>>m[pos].price;
    cout<<" Updated successfully "<<endl;
}
void Restaurant::delete_item()
{
    int pos;
    dsp_menu();
    cout<<" Enter position to delete "<<endl;
    cin>>pos;
    pos--;
    if(pos<0 || pos>=n)
    {
        cout<<" Deletion not possible "<<endl;
        return;
    }
    for(int i=pos;i<n-1;i++)
    {
        m[i] = m[i+1];
    }
    n--;
    cout<<" Item deleted "<<endl;
}
void Restaurant::take_order()
{
    int count = 0;
    char ch;
    double total = 0;
    do
    {
        int id, qty;
        bool found = false;
        dsp_menu();
        cout<<" Enter item ID "<<endl;
        cin>>id;
        for(int i=0;i<n;i++)
        {
            if(id == m[i].id)
            {
                cout<<" Enter quantity "<<endl;
                cin>>qty;
                o[count].id = m[i].id;
                o[count].name = m[i].name;
                o[count].qty = qty;
                o[count].price = m[i].price;
                o[count].total = qty * m[i].price;
                total += o[count].total;
                count++;
                found = true;
            }
        }
        if(!found)
        {
            cout<<" Invalid ID "<<endl;
        }
        cout<<" Add more items? (y/n) "<<endl;
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    double gst = total * 0.05;
    double discount = 0;
    if(total > 1000)
    {
        discount = total * 0.10;
    }
    double final_bill = total + gst - discount;
    cout << endl << string(60,'-') << endl;
    cout<<" BILL "<<endl;
    cout << string(60,'-') << endl;
    cout << left << setw(10)<<"ID"
         << setw(15)<<"Name"
         << setw(10)<<"Qty"
         << setw(10)<<"Price"
         << setw(10)<<"Total"<<endl;
    for(int i=0;i<count;i++)
    {
        cout << left << setw(10)<<o[i].id
             << setw(15)<<o[i].name
             << setw(10)<<o[i].qty
             << setw(10)<<o[i].price
             << setw(10)<<o[i].total<<endl;
    }
    cout << string(60,'-') << endl;
    cout<<" Subtotal: "<<total<<endl;
    cout<<" GST (5%): "<<gst<<endl;
    cout<<" Discount: "<<discount<<endl;
    cout<<" Final Bill: "<<final_bill<<endl;
    cout << string(60,'-') << endl;
    daily_sales += final_bill;
}
void Restaurant::daily_report()
{
    cout<<" Total sales for today: "<<daily_sales<<endl;
}
int main()
{
    Restaurant r;
    int ch;
    do
    {
        cout<<endl<<" 1.Add Menu Items "<<endl
            <<" 2.Display Menu "<<endl
            <<" 3.Update Item "<<endl
            <<" 4.Delete Item "<<endl
            <<" 5.Take Order "<<endl
            <<" 6.Daily Sales "<<endl
            <<" 7.Exit "<<endl;
        cout<<" Enter choice "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1: r.add_item();
                    break;
            case 2: r.dsp_menu();
                    break;
            case 3: r.update_item(); 
                    break;
            case 4: r.delete_item();
                    break;
            case 5: r.take_order(); 
                    break;
            case 6: r.daily_report();
                    break;
            case 7: cout<<" Exiting "<<endl;
                    exit(0);
            default: cout<<" Invalid choice "<<endl;
        }
    }while(true);
    return 0;
}