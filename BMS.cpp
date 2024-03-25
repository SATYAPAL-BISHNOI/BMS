// // // // // // // // // // // // // // // // /////// ////   // //// //// ////
#include<iostream>
#include<iomanip>
#include<cctype>
#include<fstream>
using namespace std;
// 
class Bank_account{
    //
    int account_number;
    char name[50];
    char type;
    long deposit_money;
    public:
    void report() const;
    int retacno() const{
        return account_number;
    }
    // void deposit(int amt)
    // {
    //     deposit_money+= amt;
    // }
    // void draw(int amt)
    // {
    //     deposit_money-= amt;
    // }
    // int redeposit() const
    // {
    //     return deposit_money;
    // }
    void create_account();
    void display_account();
    //
};
//
void Bank_account::report() const{
    cout<<account_number<<setw(10)<<"              "<< name<<setw(10)<<"             "<<type<<setw(6)<<"              "<<deposit_money<<endl;
}
//
void Bank_account::create_account()
{
    //
    system("cls");
    cout<<"\tEnter the account number : ";
    cin>>account_number;
    cout<<"\tEnter the account holder name : ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\tEnetr the type of account(C/S) : ";
    cin>>type;
    type=toupper(type);
    cout<<"\tEnter the initial ammount(Saving <=5000 and Currnent <=85000)";
    cin>>deposit_money;
    cout<<endl;
    //
}
//
void Bank_account::display_account()
{
    //
    cout<<endl;
    cout<<"\tAccount Holder Name : "<<name<<endl;
    cout<<"\tAccount Nmuber is : "<<account_number<<endl;
    cout<<"\tType of Account : "<<type<<endl;
    cout<<"\tAccount Balance is : "<<deposit_money<<endl;
    cout<<endl;
    //
}
//
void writeAccount()
{
    //
    Bank_account AC;
    ofstream outFile;
    outFile.open("Account.dat",ios::binary|ios::app);
    AC.create_account();
    outFile.write(reinterpret_cast<char *>(&AC),sizeof(Bank_account));
    outFile.close();
}
//
void deleteAccount(int n)
{
    //
    Bank_account AC;
    ifstream inFile;        //input file stream
    ofstream outFile;       //output file stream
    inFile.open("Account.dat",ios::binary);
    if (!inFile)
    {
        cout<<"File could not open!! Press any key....."<<endl;
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);

    while (inFile.read(reinterpret_cast<char *> (&AC),sizeof(Bank_account)))
    {
        if (AC.retacno()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&AC), sizeof(Bank_account));
        }
        
    }
    inFile.close();
    outFile.close();
    remove("Account.dat");
    rename("temp.dat","Account.dat");
    ofstream zeroOut("Temp.dat", ios::binary | ios::trunc);
    zeroOut.close();
    cout<<endl;
    cout<<"\tAccount has been deleted."<<endl;
}
//
void display_detail(int n)
{
    //
    Bank_account AC;
    bool flag = false;
    ifstream inFile;
    inFile.open("Account.dat",ios::binary);
    if (!inFile)
    {
        cout<<"File is not opened!! Press any key";
        return;
    }
    //
    while (inFile.read(reinterpret_cast<char *> (&AC),sizeof(Bank_account)))
    {
        if (AC.retacno()==n)
        {
             cout<<"....Accounrt detail is...."<<endl;
            AC.display_account();
            flag=true;
        }
        
    }
    inFile.close();
    if (flag==false)
    {
        cout<<"Account number dose not exist"<<endl;
    }
    //
    //
}
//
void display_All()
{
    //
    system("cls");
    Bank_account AC;
    ifstream inFile;
    inFile.open("Account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File cloud not be open!! press any key"<<endl;
        return;
    }
    //
    cout<<"\t ..Bank account holder list.."<<endl;
    cout<<"========================================================"<<endl;
    cout<<"A/c no.          NAME            TYPE            BALANCE"<<endl;
    cout<<"========================================================"<<endl;
    //
    while (inFile.read(reinterpret_cast<char *> (&AC), sizeof(Bank_account)))
    {
        AC.report();
    }
    inFile.close();
    //
}
// void money_Deposit_With_Withdrow(int n,int option)
// {
//     int amt;
//     bool found = false;
//     Bank_account AC;
//     fstream File;
//     File.open("Account.dat",ios::binary|ios::in|ios::out);
//     if (!File)
//     {
//         cout<<"File cloud not be open!! Press any key";
//         return;
//     }
//     while (!File.eof() && found == false)
//     {
//         File.read(reinterpret_cast<char *> (&AC),sizeof(Bank_account));
//         if (AC.retacno()==n)
//         {
//             AC.display_account();
//             if (option==1)
//             {
//                 cout<<"Enter the ammount to be deposit : ";
//                 cin>>amt;
//                 cout<<endl;
//                 AC.deposit(amt);
//             }
//             if (option == 2)
//             {
//                   cout<<"Enter the ammount to be withdrow : ";
//                   cin>>amt;
//                   cout<<endl;
//                   int balance = AC.redeposit() - amt;
//                   if (balance < 0)
//                   {
//                     cout<<"Check bank balance!!!..";
//                   }
//                   else
//                   {
//                     AC.draw(amt);
//                   }   
//             }
//             int pos =(-1)*static_cast<int>(sizeof(Bank_account));
//             File.seekg(pos,ios::cur);
//             File.write(reinterpret_cast<char *> (&AC),sizeof(Bank_account));
//         }
//         File.close();
        
//     }
    
    
// }


int main()
{
    //
    char choice;
    int num;
    //
    do{
    cout<<"\t\t======================================================="<<endl;
    cout<<"\t\t|.........Wallcome to bank manegement systum.........|"<<endl;
    cout<<"\t\t======================================================="<<endl;
    cout<<endl;
    cout<<"\t-----Main Menu-----"<<endl;
    cout<<"\t1. Create Account: "<<endl;        //ok
    cout<<"\t2.Deposit money: "<<endl;          
    cout<<"\t3.Withdraw money: "<<endl;
    cout<<"\t4.Check balence: "<<endl;          //ok
    cout<<"\t5.All account holder list: "<<endl;
    cout<<"\t6.Modifiy in Account: "<<endl;
    cout<<"\t7.Close Account: "<<endl;          //ok
    cout<<"\t8.Exit"<<endl;
    cout<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    cout<<endl;
    //
    switch (choice)
    {
    case '1':
        writeAccount();

    break;
    case '2':
        system("cls");
        cout<<"Enter your Account number : ";
        cin>>num;
        // deposit function

    break;
    case '3':
         system("cls");
        cout<<"Enter your Account number : ";
        cin>>num;
            // withdrow function
    break;
    case '4':
        system("cls");
        cout<<"Enter your Account number : ";
        cin>>num;
        display_detail(num);
            // balence function
    break;
    case '5':
    display_All();
        // All display function
    break;
    case '6':
         system("cls");
        cout<<"Enter your Account number : ";
        cin>>num;
            // Modify function
    break;
    case '7':
         system("cls");
        cout<<"Enter your Account number : ";
        cin>>num;
        deleteAccount(num);
            // close function
    break;
    }
    //
    cin.ignore();
    cin.get();
    }while (choice!='8');
    return 0;
    
    // Bank_account BankAccount;
    // BankAccount.create_account();
    // BankAccount.display_account();
    // return 0;
 
    //
}

