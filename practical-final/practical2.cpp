#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    float balance;
    string ownerName;

public:
    static int autoAccountNumbercounter;
    BankAccount(int accountNumber, float balance, string ownerName)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->ownerName = ownerName;
        autoAccountNumbercounter++;
    }
    void setDetails(int accountNumber, float balance, string ownerName)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->ownerName = ownerName;
    }
  
    int getAccountNumber()
    {
        return accountNumber;
    }

    void credit(float creditamount)
    {
        balance += creditamount;
        cout << "Amount credited successfully" << endl;
    }
    void debit(float debitamount)
    {
        if (balance >= debitamount)
        {
            balance -= debitamount;
            cout << "Amount debited successfully" << endl;
        }
        else
        {
            cout << "Amount withdrawn exceeds balance amount" << endl;
        }
    }
    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Balance: " << balance << endl;
        cout << "Account Owner Name: " << ownerName << endl;
    }
};
int BankAccount::autoAccountNumbercounter = 0;
int main()
{
    BankAccount *b[100];
    int object;
    cout << "Enter how many accounts to create: ";
    cin >> object;
    for (int i = 0; i < object; i++)
    {
        cout << "Enter details of account " << i + 1 << endl;
        int accountNumber;
        float balance;
        string ownerName;
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Account Balance: ";
        cin >> balance;
        cout << "Enter Account Owner Name: ";
        cin >> ownerName;
        b[i] = new BankAccount(accountNumber, balance, ownerName);
        cout << endl;
    }
    while (true)
    {
        int choice;
        cout << "Enter your choice\n1.credit\n2.debit\n3.display\n4.exit" << endl;
     
        cin >> choice;
        switch (choice)
        {
      
        case 1:
        {
            int accountnumber;
            cout << "Enter account number to credit: ";
            cin >> accountnumber;
            float amount;
            cout << "Enter amount to be credited: ";
            cin >> amount;
            for (int i = 0; i < BankAccount::autoAccountNumbercounter; i++)
            {
                if (b[i]->getAccountNumber() == accountnumber)
                {
                    b[i]->credit(amount);
                }
            }
            break;
        }
        case 2:
        {
            int accountnumber;
       
            cout << "Enter account number to debit: ";
            cin >> accountnumber;
            float amount;
            cout << "Enter amount to be debited: ";
            cin >> amount;
            for (int i = 0; i < BankAccount::autoAccountNumbercounter; i++)
            {
                if (b[i]->getAccountNumber() == accountnumber)
                {
                    b[i]->debit(amount);
                }
            }
            break;
        }
        case 3:
        {
            int accountnumber;
            cout << "Enter account number to display: ";
            cin >> accountnumber;
            for (int i = 0; i < BankAccount::autoAccountNumbercounter; i++)
            {
                if (b[i]->getAccountNumber() == accountnumber)
                {
                    b[i]->display();
                }
            }
            break;
        }
        case 4:
        {
           exit(0);
        }
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
    return 0;
}
