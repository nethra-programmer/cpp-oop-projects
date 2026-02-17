//ONLINE SHOPPING SYSTEM
#include<iostream>
using namespace std;
class costumer
{
    private:
    string cname;
    int cnum;
    public:
    void input();
    void output();
};
void costumer::input()
{
    cout<<" Enter the costumer name and mobile no. "<<endl;
    cin>>cname>>cnum;
}
void costumer::output()
{
    cout<<" Costumer Name: "<<cname<<endl<<" Mobile No. "<<cnum<<endl;
}
class shop: public costumer
{
    public:
    struct electronics
    {
        string name;
        string brand;
        string power;
        float price;
        int quantity;
    };
    struct clothing
    {
        string type;
        string brand;
        string size;
        float price;
        int quantity;
    };
    struct grocery
    {
        string item;
        string expdate;
        float price;
        int quantity;
    };
};
int main()
{
    shop s;
    int ch;
    s.input();
    shop::electronics e[50];
    shop::clothing c[50];
    shop::grocery g[50];
    int ecount=0,ccount=0, gcount=0;
    float etotal=0, ctotal=0, gtotal=0,edisc, cdisc, gdisc, efinal, gfinal, cfinal;
    do
    {
        cout<<" 1.Electronics "<<endl<<" 2.Clothing "<<endl<<" 3.Grocery "<<endl<<" 4. Receipt "<<endl;
        cout<<" Enter your choice "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"======================================================"     <<endl<<"              Available Items                    "<<endl;
                    cout<<" Laptop "<<endl<<" Dell "<<endl<<" 65W "<<endl<<" 55000 "<<endl;
                    cout<<" _____________________________________________________"     <<endl;
                    cout<<" Refrigerator "<<endl<<" LG "<<endl<<" 150W "<<endl<<" 32000 "<<endl;
                    cout<<" _____________________________________________________"     <<endl;
                    cout<<" Microwave Oven "<<endl<<" Samsung "<<endl<<" 1200W "<<endl<<" 15000 "<<endl;
                     cout<<"_____________________________________________________"     <<endl;
                    cout<<" Induction Stove "<<endl<<" Philips "<<endl<<" 1800W "<<endl<<" 3500 "<<endl; 
                    cout<<"_____________________________________________________"     <<endl;
                    cout<<" LED TV "<<endl<<" Sony "<<endl<<" 110W "<<endl<<" 42000 "<<endl;
                    cout<<"_____________________________________________________"     <<endl;
                    cout<<" Washing Machine "<<endl<<" Whirlpool "<<endl<<" 500W "<<endl<<" 28000 "<<endl;
                     cout<<"_____________________________________________________"     <<endl;
                      cout<<"_____________________________________________________"     <<endl;
                    cout<<"Enter product name: "<<endl;
                    cin>>e[ecount].name;
                    cout<<"Enter brand: "<<endl;
                    cin>>e[ecount].brand;
                    cout<<"Enter power: "<<endl;
                    cin>>e[ecount].power;
                    cout<<"Enter price: "<<endl;
                    cin>>e[ecount].price;
                    cout<<"Enter quantity: "<<endl;
                    cin>>e[ecount].quantity;
                    etotal += e[ecount].price * e[ecount].quantity;
                    ecount++;
                    break;
            case 2: cout<<"======================================================"     <<endl<<"              Available Items                    "       <<endl;    
                    cout<<" Formal Shirt "<<endl<<" Allen Solly "<<endl<<" M "<<endl<<" 1800 "<<endl;
                    cout<<"_____________________________________________________"     <<endl;
                    cout<<" Jeans "<<endl<<" Levi's "<<endl<<" 28 "<<endl<<" 2500 "<<endl;
                    cout<<"_____________________________________________________"     <<endl;
                    cout<<" Jacket "<<endl<<" Puma "<<endl<<" L "<<endl<<" 4000 "<<endl;
                    cout<<"_____________________________________________________"     <<endl;
                    cout<<" T-Shirt "<<endl<<" Nike "<<endl<<" M "<<endl<<" 1200 "<<endl;
                    cout<<"_____________________________________________________"     <<endl;
                    cout<<" Kurta "<<endl<<" Avaasa "<<endl<<" L "<<endl<<" 2200 "<<endl;
                    cout<<"_____________________________________________________"     <<endl;
                    cout<<" Hoodie "<<endl<<" Adidas "<<endl<<" XL "<<endl<<" 3000 "<<endl;
                    cout<<"Enter clothing type: "<<endl;
                    cin>>c[ccount].type;
                    cout<<"Enter brand: "<<endl;
                    cin>>c[ccount].brand;
                    cout<<"Enter size: "<<endl;
                    cin>>c[ccount].size;
                    cout<<"Enter price: "<<endl;
                    cin>>c[ccount].price;
                    cout<<"Enter quantity: "<<endl;
                    cin>>c[ccount].quantity;
                    ctotal += c[ccount].price * c[ccount].quantity;
                    ccount++;
                    break;
            case 3:cout<<"======================================================"     <<endl<<"              Available Items                    "       <<endl;
                   cout<<" Rice "<<endl<<" 60 per kg "<<endl;
                   cout<<"_____________________________________________________"     <<endl;
                   cout<<" Sugar "<<endl<<" 45 per kg "<<endl;
                   cout<<"_____________________________________________________"     <<endl;
                    cout<<" Wheat Flour "<<endl<<" 50 per kg "<<endl;
                   cout<<"_____________________________________________________"     <<endl;
                   cout<<" Milk "<<endl<<" 55 per litre "<<endl;
                    cout<<"_____________________________________________________"     <<endl;
                    cout<<" Cooking Oil "<<endl<<" 150 per litre "<<endl;
                    cout<<"_____________________________________________________"     <<endl;
                    cout<<" Egg "<<endl<<" 6 per piece "<<endl; 
                    cout<<"Enter grocery item: "<<endl;
                    cin>>g[gcount].item;
                    cout<<"Enter price per unit: "<<endl;
                    cin>>g[gcount].price;
                    cout<<"Enter quantity: "<<endl;
                    cin>>g[gcount].quantity;
                    gtotal += g[gcount].price * g[gcount].quantity;
                    gcount++;
                    break;
            case 4: edisc=etotal * 0.10;
                    cdisc=ctotal * 0.20;
                    gdisc=gtotal * 0.05;
                    efinal=etotal-edisc;
                    cfinal=ctotal-cdisc;
                    gfinal=gtotal-gdisc;
                    cout<<"_____________________________________________________"     <<endl;
                     cout <<" ==================== RECEIPT ==================== "<<endl;
                     s.output();
                     for(int i = 0; i < ecount; i++)
                     {
                        cout << "[ELECTRONICS]"<<endl;
                        cout << "Name: " <<e[i].name<<endl;
                        cout << "Brand: " <<e[i].brand<<endl;
                        cout << "Power: " <<e[i].power<<endl;
                        cout << "Quantity: " <<e[i].quantity<<endl;
                        cout << "Item Total: " <<e[i].price * e[i].quantity<<endl;
                        cout << "-----------------------------------------------"<<endl;
                    }
                    for(int i = 0; i < ccount; i++)
                    {
                        cout << "[CLOTHING]"<<endl;
                        cout << "Type: " << c[i].type<<endl;
                        cout << "Brand: " << c[i].brand<<endl;
                        cout << "Quantity: " << c[i].quantity<<endl;
                        cout << "Item Total: " << c[i].price * c[i].quantity<<endl;
                        cout << "-----------------------------------------------"<<endl;
                     }
                     for(int i = 0; i < gcount; i++)
                    {
                        cout << "[GROCERY]"<<endl;
                        cout << "Item: " << g[i].item<<endl;
                        cout << "Quantity: " << g[i].quantity<<endl;
                        cout << "Item Total: " << g[i].price * g[i].quantity<<endl;
                        cout << "-----------------------------------------------"<<endl;
                    }
                     cout << "==================================================="<<endl;
                     cout<<"                 Category Total                     "<<endl;
                     cout<<" Electronics Total: "<<etotal<<endl;
                     cout<<" Clothing Total: "<<ctotal<<endl;
                     cout<<" Grocery Total: "<<gtotal<<endl;
                    cout << "==================================================="<<endl;
                    cout << " Grand Total: " << etotal+ctotal+gtotal<<endl;
                    cout<<" Total Discount: "<<edisc+cdisc+gdisc<<endl;
                    cout<<" Amount Payable: "<<efinal+cfinal+gfinal<<endl;
                   cout << "==================================================="<<endl;
                   exit(0);
            default: cout<<" Invalid Choice "<<endl;
        }
    }while(true);
    return 0;
}