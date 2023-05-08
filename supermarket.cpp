#include<iostream>
#include<fstream>

#include<stdio.h>   

using namespace std;

//here we have created a shooping and billing program that can be used by th administrator with specific login and also a coustomer to purchace the product
class shopping {


    private:
          int pcode;
          float price;
          float dis;
          string pname;

          public:
               void menu();
               void administrator();
               void buyer();
               void add();
               void edit();
               void rem();
               void list();
               void receipt();
};

void shopping :: menu()
{    
    m:  
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t|_________________________________________________________|\n";
    cout<<"\t\t\t\t|                                                         |\n";
    cout<<"\t\t\t\t|                 SUPERMARKET MAIN MENU                   |\n";
    cout<<"\t\t\t\t|                                                         |\n";
    cout<<"\t\t\t\t|_________________________________________________________|\n";
    cout<<"\n\n\t\t\t\t||      1) Administrator    ||\n";
    cout<<"\n\n\t\t\t\t||      2) Buyer            ||\n";
    cout<<"\n\n\t\t\t\t||      3) Exit             ||\n";
    
    cout<<"\n\n\n\t\t\t\t\t Please select : ";
    cin>>choice;

    switch (choice)
    {
        case 1:
            cout<<"\n\n\t\t\t Please Login : ";
            cout<<"\n\n\n\t\t\t Enter Email : ";
            cin>>email;
            cout<<"\n\n\t\t\t Password : ";
            cin>>password;

            if (email=="harish123" && password=="1090")
            {
                administrator();
            }
            else 
            {
                cout<<"\n\n\t\t\t\tInvalid Email/Password";
              } 
              
              break;


         case 2:
            {
             buyer();
             }

             case 3:
                {
                 exit(0);
                 }

             default :
             {
                 cout<<"\n\n\t\t\t\tPlease select from the give options!!!";

                 }


    }
     goto m;
 



}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\t\t\t\t||       ADMINISTRATOOR MENU    ||\n";
    cout<<"\n\n\t\t\t\t||    1) Add the product        ||\n ";
    cout<<"\n\n\t\t\t\t||    2) Modify the product     ||\n";
    cout<<"\n\n\t\t\t\t||    3) Delete the product     ||\n";
    cout<<"\n\n\t\t\t\t||    4) Back to main menu      ||\n";

    cout<<"\n\n\n\t\t\t\t     Please enter your choice : ";
    cin>>choice;

    switch (choice)
    {
        case 1:
        
            add();
            break;

            case 2:

                   edit();
                   break;

                   case 3:

                     rem();
                     break;

                        case 4:
                               menu();
                               break;

             default:
                 cout<<"\n\n\t\t\t\tInvalid Choice";

       
    }
    goto m;

}

void shopping :: buyer()
{
    int choice;
    m:
    cout<<"\n\n\t\t\t\t||       BUYER MENU    ||\n";
    cout<<" \n\n\t\t\t\t     1) Buy product   ||\n";
    cout<<"\n\n\t\t\t\t      2) Go back       ||\n";
    cout<<"\n\n\t\t\t\t      Enter your choice : ";
    cin>>choice;

    switch (choice)
    {
        case 1:
        receipt();
        break;

        case 2:
        menu();

        default:
        cout<<"\n\n\t\t\t\tInvalid Choice";
            
    }
    goto m;
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;


    cout<<"\n\n\n\t\t\t Add new product ";
    cout<<"\n\n\t\t\t product code of the product : ";
    cin>>pcode;
    cout<<"\n\n\t\t\t name of the product : ";
    cin>>pname;
    cout<<"\n\n\t\t\t price of the product : ";
    cin>>price;
    cout<<"\n\n\t\t\t discount the product : ";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" " <<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();

    }
    else
    { 
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c == pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

    

       if(token == 1)
        { goto m;
        }
        else
         {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" " <<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
         }
    }

    cout<<"\n\n\t\t\t\t Record inserted successfully";




}

void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\n\t\t\t\t Modify the record ";
    cout<<"\n\n\n\t\t\t\t Product code : ";
    cin>>pkey;

    data.open("database.txt", ios::in);

    if(!data)
    {
        cout<<"\n\n\n\t\t\t\tfile Doesnt exist";
    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
       
            if(pkey==pcode)
            {
                cout<<"\n\n\t\t\t Product new code : ";
                cin>>c;
                cout<<"\n\n\t\t\t Name of product : ";
                cin>>n;
                cout<<"\n\n\t\t\t Price : ";
                cin>>p;
                cout<<"\n\n\t\t\t Discount : ";
                cin>>d;

                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\n\t\t\t\t Record Edited";

                token++;
                

            }
            else 
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";

            }
            data>>pcode>>pname>>price>>dis;


        
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n\t\t\t\t Record not found";
        }
    }
}

void shopping:: rem()
{
    fstream data, data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t\t\t Delete product : ";
    cout<<"\n\n\t\t\t Product code : ";
    cin>>pkey;
    data.open("database.txt", ios::in);

    if(!data)
    {
        cout<<" File do not exist";

    }
    else{
        data1.open("database1.txt", ios:: app|ios ::out);
        data>>pcode>>pname>>price>>dis;

        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t\t\t\tProduct deleted succesfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n ";

            }
            data>>pcode>>pname>>price>>dis;
            
    }
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt", " database.txt");

    if(token==0)
    {
        cout<<"\n\n Record not found";
    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<" \n\n ___________________________________LIST OF PRODUCTS________________________________________ \n\n";
    cout<<"\n\nProduct.no\t\tName\t\tprice\n";

    data>>pcode>>pname>>price>>dis;

    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }

    data.close();



}

void shopping:: receipt()
{
    
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t receipt";
    data.open("database.txt", ios::in);

    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    
    else{
        data.close();

        list();
        cout<<"Please plase your order";
        do{
            m:
            cout<<"\n\n Enter the product code : ";
            cin>>arrc[c];
            cout<<"\n\n Enter the quantity : ";
            cin>>arrq[c];

            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code please try again";
                    goto m;
                }

            }
            c++;
            cout<<"\n\n Do you want to buy another product y for yes and n for no : ";
            cin>>choice;
        }
        while(choice=='y');

        cout<<"reciept";
        cout<<"\n product number \t product name \t product quantuiyu \t price \t amount \t amount with discount \n ";

        for(int i=0; i<c;i++)
        {
            data.open("database.txt", ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\t"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<dis;

                    
                 }

                 data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();


    }

     cout<<"\n\n         YOUR BILL                        ";
     cout<<"\n\n\t\t\t\tTotat Amount : "<<total;


}

int main()
{
    shopping s;
    s.menu();

}