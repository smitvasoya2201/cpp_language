#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class BankAccount
{
public:
    int accountNumber;
    string accountHolderName;
    double balance;
    static int totalBankAccount;

    BankAccount(int acc, string accname, double bal)
    {
        this->accountNumber = acc;
        this->accountHolderName = accname;
        this->balance = bal;
        totalBankAccount++;
    }

    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {

        if (this->balance >= amount)
        {
            this->balance -= amount;
            cout << amount << " withdrawal Successfully" << endl;
            return;
        }
        cout << "Not Valid Amount" << endl;
    }
    double getBalance()
    {
        return this->balance;
    }
    void displayAccountInfo()
    {
        cout << "Acount Holder Name :" << this->accountHolderName << endl;
        cout << "Acount Number :" << this->accountNumber << endl;
        cout << "Acount Balance :" << getBalance() << endl;
    }
};

class SavingAccount : public BankAccount
{
public:
    float interestRate;
    static int totalSavingBankAccount;

    SavingAccount(int acc, string accname, double bal, float intr) : BankAccount(acc, accname, bal)
    {
        this->interestRate = intr;
        totalSavingBankAccount++;
    }

    double calculateInterest()
    {
        cout << (this->getBalance() * (interestRate)) / 100 << endl;
    }

    void totalsavingbankaccount()
    {
        cout << totalSavingBankAccount;
    }
};

class CurrentAccount : public BankAccount
{
public:
    double overdraftLimit;
    static int totalCurrentBankAccount;

    CurrentAccount(int acc, string accname, double bal, double overfl) : BankAccount(acc, accname, bal)
    {
        this->overdraftLimit = overfl;
        totalCurrentBankAccount++;
    }

    void checkOverdraft()
    {
        if (this->overdraftLimit > 0)
        {
            cout << "OverDraft Available !!" << endl;
            return;
        }
        cout << "Limit Exceed" << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
public:
    int months;
    static int totalFixedBankAccount;

    FixedDepositAccount(int acc, string accname, double bal, int m) : BankAccount(acc, accname, bal)
    {
        this->months = m;
        totalFixedBankAccount++;
    }

    float calculateInterest()
    {
        cout << (this->getBalance() * (0.8 * this->months)) / 100 << endl;
    }
};

int BankAccount::totalBankAccount = 0;
int SavingAccount::totalSavingBankAccount = 0;
int CurrentAccount::totalCurrentBankAccount = 0;
int FixedDepositAccount::totalFixedBankAccount = 0;

int main()
{

    SavingAccount *s[100];
    SavingAccount s1(1001, "ABC", 10000, 5);
    SavingAccount s2(1002, "XYZ", 70000, 0.7);
    SavingAccount s3(1003, "ABC", 50000, 0.01);
    SavingAccount s4(1004, "XYZ", 70000, 0.7);
    s[0] = &s1;
    s[1] = &s2;
    s[2] = &s3;
    s[3] = &s4;

    CurrentAccount *c[100];
    CurrentAccount c1(1005, "BVD", 500000, 10000);
    CurrentAccount c2(1006, "asd", 10000, 1000);
    CurrentAccount c3(1007, "xzc", 9999, 999);
    CurrentAccount c4(1008, "Azc", 8888, 1000);
    c[0] = &c1;
    c[1] = &c2;
    c[2] = &c3;
    c[3] = &c4;

    FixedDepositAccount *f[100];
    FixedDepositAccount f1(1009, "DNMI", 10000, 12);
    FixedDepositAccount f2(1010, "VEENA", 9900, 12);
    FixedDepositAccount f3(1011, "XVGH", 5555, 12);
    f[0] = &f1;
    f[1] = &f2;
    f[2] = &f3;

    while (true)
    {
        int choice, bankacc;
        cout << "===========================================   bank account managment   =======================================================" << endl;

        cout << "1.number of bank account " << endl;
        cout << "2.Display all account details " << endl;
        cout << "3. deposite  " << endl;
        cout << "4. withdraw " << endl;
        cout << "5. check balence " << endl;
        cout << "6. interest calulation by saving account " << endl;
        cout << "7. over draft limit checking " << endl;
        cout << "8. fixed-deposite interest calculation " << endl;

        cout << "0. exit " << endl;

        cout << "enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);

        case 1:
            int choice1;
            cout << endl;
           
            cout << "1. all total bank account" << endl;
            cout << "2. saving-Account total bank account" << endl;
            cout << "3. current-Account total bank account" << endl;
            cout << "4. fixed-Account total bank account" << endl;
            cout << "0. exit" << endl;
            cout << "enter your choice : ";
            cin >> choice1;
            switch (choice1)
            {
            case 1:
                cout << endl;
                cout << BankAccount::totalBankAccount << endl;
                break;
            case 2:
                cout << SavingAccount::totalSavingBankAccount << endl;
                break;
            case 3:
                cout << CurrentAccount::totalCurrentBankAccount << endl;
                break;
            case 4:
                cout << FixedDepositAccount::totalFixedBankAccount << endl
                     << endl;
                break;
            case 0:
                exit(0);

            default:
                cout << "invalide choice " << endl;
                break;
            }

            break;

        case 2:
            cout << "==========saving accounts============== : " << endl;
            for (int i = 0; i < SavingAccount::totalSavingBankAccount; i++)
            {
                s[i]->displayAccountInfo();
            }

            cout << "======================current accounts====================== : " << endl;

            for (int i = 0; i < CurrentAccount::totalCurrentBankAccount; i++)
            {
                c[i]->displayAccountInfo();
            }
            cout << "======================fixed account accounts====================== : " << endl;

            for (int i = 0; i < FixedDepositAccount::totalFixedBankAccount; i++)
            {
                f[i]->displayAccountInfo();
            }

            break;

        case 3:
            int choice2;
            cout << "enter your which types account " << endl;
            cout << "1. saving account : " << endl;
            cout << "2. current account : " << endl;
            cout << "3. fixed deposite : " << endl;

            cout << "enter your choice : ";
            cin >> choice2;
            cout << "enter your bank account : ";
            cin >> bankacc;
            int deposite;

            switch (choice2)
            {
            case 1:
                for (int i = 0; i < SavingAccount::totalSavingBankAccount; i++)
                {
                    if (bankacc == s[i]->accountNumber)
                    {
                        cout << "enter deposite amount : ";
                        cin >> deposite;
                        s[i]->deposit(deposite);
                        cout << "========deposite successfull========" << endl;
                    }
                }
                break;
            case 2:
                for (int i = 0; i < CurrentAccount::totalCurrentBankAccount; i++)
                {
                    if (bankacc == c[i]->accountNumber)
                    {
                        cout << "enter deposite amount : ";
                        cin >> deposite;
                        c[i]->deposit(deposite);
                        cout << "========deposite successfull========" << endl;
                    }
                }

                break;
            case 3:
                for (int i = 0; i < FixedDepositAccount::totalFixedBankAccount; i++)
                {
                    if (bankacc == f[i]->accountNumber)
                    {
                        cout << "enter deposite amount : ";
                        cin >> deposite;
                        f[i]->deposit(deposite);
                        cout << "========deposite successfull========" << endl;
                    }
                }
                break;

            default:
                cout << "invalide choice " << endl;

                break;
            }
            break;

        case 4:
            int bankacc, choice3;
            cout << "enter your which types account " << endl;
            cout << "1. saving account : " << endl;
            cout << "2. current account : " << endl;
            cout << "3. fixed deposite account : " << endl;

            cout << "enter your choice : ";
            cin >> choice3;
            cout << "enter your bank account : ";
            cin >> bankacc;
            int withdraw_amount;

            switch (choice3)
            {
            case 1:
                for (int i = 0; i < SavingAccount::totalSavingBankAccount; i++)
                {
                    if (bankacc == s[i]->accountNumber)
                    {
                        cout << "enter withdraw amount : ";
                        cin >> withdraw_amount;
                        if (s[i]->balance >= withdraw_amount)
                        {
                            s[i]->withdraw(withdraw_amount);
                            cout << "========withdraw successfull========" << endl;
                        }
                        else
                        {
                            cout << "not valide balance!!" << endl;
                        }
                    }
                }
                break;
            case 2:
                for (int i = 0; i < CurrentAccount::totalCurrentBankAccount; i++)
                {
                    if (bankacc == c[i]->accountNumber)
                    {
                        cout << "enter withdraw amount : ";
                        cin >> withdraw_amount;
                        if (c[i]->balance >= withdraw_amount)
                        {
                            c[i]->withdraw(withdraw_amount);
                            cout << "========withdraw successfull========" << endl;
                        }
                        else
                        {
                            cout << "not valide balance!!" << endl;
                        }
                    }
                }
                break;
            case 3:
                for (int i = 0; i < FixedDepositAccount::totalFixedBankAccount; i++)
                {
                    if (bankacc == f[i]->accountNumber)
                    {
                        cout << "enter withdraw amount : ";
                        cin >> withdraw_amount;
                        if (f[i]->balance >= withdraw_amount)
                        {
                            f[i]->withdraw(withdraw_amount);
                            cout << "========withdraw successfull========" << endl;
                        }
                        else
                        {
                            cout << "not valide balance!!" << endl;
                        }
                    }
                }
                break;

            default:
                cout << "invalide choice " << endl;
                break;
            }

        case 5:

            int choice4;
            cout << "enter your which types account " << endl;
            cout << "1. saving account : " << endl;
            cout << "2. current account : " << endl;
            cout << "3. fixed deposite : " << endl;

            cout << "enter your choice : ";
            cin >> choice4;
            cout << "enter your bank account : ";
            cin >> bankacc;

            switch (choice4)
            {
            case 1:
                for (int i = 0; i < SavingAccount::totalSavingBankAccount; i++)
                {
                    if (bankacc == s[i]->accountNumber)
                    {
                        cout << "balance is : " << s[i]->getBalance() << endl;
                    }
                }
                break;
            case 2:
                for (int i = 0; i < CurrentAccount::totalCurrentBankAccount; i++)
                {
                    if (bankacc == c[i]->accountNumber)
                    {
                        cout << "balance is : " << c[i]->getBalance() << endl;
                    }
                }

                break;
            case 3:
                for (int i = 0; i < FixedDepositAccount::totalFixedBankAccount; i++)
                {
                    if (bankacc == f[i]->accountNumber)
                    {
                        cout << "balance is : " << f[i]->getBalance() << endl;
                    }
                }
                break;

            default:
                cout << "invalide choice " << endl;

                break;
            }
            break;

        case 6:
            cout << "enter your bank account : ";
            cin >> bankacc;
            for (int i = 0; i < SavingAccount::totalSavingBankAccount; i++)
            {
                if (bankacc == s[i]->accountNumber)
                {
                    cout << "your intrest is : " << s[i]->calculateInterest() << endl;
                }
            }
            break;

        case 7:
            cout << "enter your bank account : ";
            cin >> bankacc;

            for (int i = 0; i < CurrentAccount::totalCurrentBankAccount; i++)
            {
                if (bankacc == c[i]->accountNumber)
                {
                    c[i]->checkOverdraft();
                }
            }

            break;

        case 8:
            cout << "enter your bank account : ";
            cin >> bankacc;
            for (int i = 0; i < FixedDepositAccount::totalFixedBankAccount; i++)
            {
                if (bankacc == f[i]->accountNumber)
                {
                    cout << "you interset is fd : " << f[i]->calculateInterest() << endl;
                }
            }
            break;
            break;
        }
    }
    return 0;
}