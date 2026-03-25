//Library System
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
const int no_genre=6;
const int no_books=5;
class library
{
    protected:
    struct books
    {
        int id;
        string title;
        string author;
        double price;
        int stock;
    };
    books shelf[no_genre][no_books];
    string genre[no_genre];
    double t_bill;
    public:
    library()
    {
        t_bill=0;
        //Genre List
        genre[0] =" Crime & Mystery ";
        genre[1] = " Psychological Thriller ";
        genre[2] = " Science Fiction ";
        genre[3] = " Romance & Classics ";
        genre[4] = " Horror ";
        genre[5] = " True Crime ";
        //Crime & Mystery
        shelf[0][0] = { 101," Sherlock Holmes: The Hound of the Baskervilles ", " A. Conan Doyle ", 350 , 3 };
        shelf[0][1]={ 102, " Murder on the Orient Express ", " Agatha Christie ", 450, 5 };
        shelf[0][2]={ 103, " The Postman Always Rings Twice ", " James M. Cain ", 299, 6};
        shelf[0][3]={ 104, " Sherlock Holmes: The Valley of Fear "," A. Conan Doyle ", 350, 5};
        shelf[0][4]={ 105," And Then There Were None ", " Agatha Christie ", 499, 3};
        //Psychological Thriller
        shelf[1][0]={ 201, " 13 Reasons Why ", " Jay Asher ", 425, 5};
        shelf[1][1]={ 202, " The Silent Patient "," Alex Michaelides ", 550, 3};
        shelf[1][2]={ 203," Verity ", " Colleen Hoover ", 380, 5};
        shelf[1][3]={ 204, " The Girl on the Train ", " Paula Hawkins ",410,4};
        shelf[1][4]={ 205," Behind Closed Doors "," B.A. Paris ",390,5};
        //Science Fiction
        shelf[2][0]={ 301," Dune ", " Frank Herbert ",599,4};
        shelf[2][1]={ 302," 1984 ", " George Orwell ", 299,5};
        shelf[2][2]={ 303," The Martian "," Andy Weir ", 450,4};
        shelf[2][3]={ 304," Project Hail Mary "," Andy Weir ",550,5};
        shelf[2][4]={ 305," Brave New World "," Aldous Huxley ",350,4};
        //Romance & Classics
        shelf[3][0]={ 401," Pride and Prejudice "," Jane Austen ",299,5};
        shelf[3][1]={ 402," Little Women "," Louisa May Alcott ",350,4};
        shelf[3][2]={ 403," The Great Gatsby "," F. Scott Fitzgerald ",399,4};
        shelf[3][3]={ 404," Wuthering Heights "," Emily Brontë ",250,4};
        shelf[3][4]={ 405," Jane Eyre "," Charlotte Brontë ",325,6};
        //Horror
        shelf[4][0]={ 501," The Shining "," Stephen King ",499,6};
        shelf[4][1]={ 502," Dracula "," Bram Stoker ",299,5};
        shelf[4][2]={ 503," It "," Stephen King ",550,4};
        shelf[4][3]={ 504," The Exorcist "," William P. Blatty ",399,3};
        shelf[4][4]={505," Bird Box "," Josh Malerman ",450,4};
        //True Crime
        shelf[5][0]={ 601," Mindhunter "," John E. Douglas ",550,4};
        shelf[5][1]={ 602," In Cold Blood "," Truman Capote ",450,4};
        shelf[5][2]={603, " Stranger Beside Me ", " Ann Rule ", 599, 4};
        shelf[5][3]={604, " Gone in the Dark ", " M. McNamara ", 650, 3};
        shelf[5][4]={605, " Helter Skelter ", " V. Bugliosi ", 499, 5};
    }
    void display_genres()
    {
        cout << "\n========= LIBRARY SECTIONS =========" << endl;
        for (int i = 0; i < no_genre; i++) 
        {
            cout << i + 1 << ". " << genre[i] << endl;
        }
        cout << "====================================" << endl;
    }
    void display_books(int g_id)
    {
        cout << "\n--- " << genre[g_id] << " ---" << endl;
        cout << left << setw(6) << "ID" << setw(40) << "TITLE" << setw(20) << "AUTHOR" << setw(10) << "PRICE" << "STOCK" << endl;
        cout << string(85, '-') << endl;
        for (int i = 0; i < no_books; i++)
        {
            cout << left << setw(6) << shelf[g_id][i].id 
                 << setw(40) << shelf[g_id][i].title 
                 << setw(20) << shelf[g_id][i].author 
                 << "Rs." << setw(7) << shelf[g_id][i].price 
                 << shelf[g_id][i].stock << endl;
        }
    }
    void buy_book(int g_id, int b_id)
    {
        bool found = false;
        for (int i = 0; i < no_books; i++)
        {
            if (shelf[g_id][i].id == b_id)
            {
                found = true;
                if (shelf[g_id][i].stock > 0) 
                {
                    shelf[g_id][i].stock--; 
                    t_bill += shelf[g_id][i].price;
                    cout << "\n Successfully added: " << shelf[g_id][i].title << endl;
                    cout << " Current Bill: Rs." << t_bill << endl;
                } else
                {
                    cout << "\n Sorry, this book is out of stock!" << endl;
                }
                return;
            }
        }
        if (!found)
        cout << "\n Invalid Book ID for this section." << endl;
    }
    void final_bill() 
    {
        cout << "\n************************************" << endl;
        cout << "   TOTAL AMOUNT PAYABLE: Rs." << t_bill << endl;
        cout << "   Thank you for your visit!" << endl;
        cout << "************************************" << endl;
    }
};
int main()
{
    library lib;
    int ch;
    cout << "\n===============================================" << endl;
    cout << "   WELCOME TO THE GLOBAL MULTI-GENRE LIBRARY   " << endl;
    cout << "===============================================" << endl<<endl;
    do
    {
        lib.display_genres();
        cout<<" Choose your genre "<<endl<<" Choose 0 to finish and pay "<<endl;
        cin>>ch;
       if (ch == 0) 
        {
            lib.final_bill();
            break; 
        }
        else if (ch >= 1 && ch <= no_genre) 
        {
            int gId = ch - 1;
            int bookID;
            lib.display_books(gId);
            cout << "\n Enter Book ID to buy (or 0 to go back to genres): ";
            cin >> bookID;
            if (bookID == 0) 
            {
                cout << "\n Returning to Main Menu..." << endl;
                continue; 
            }
            if (bookID != 0) 
            {
                lib.buy_book(gId, bookID);
            }
        }
        else 
        {
            cout << "\n Invalid choice! Please select 1-6 or 0." << endl;
        }

    } while(true);
    return 0;
}