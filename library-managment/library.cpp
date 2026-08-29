#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// ----------------------------------------------------   base Libraryitem class -----------------------------------------------------------

class LibraryItem
{
private:
    string title;
    string author;
    string duedate;

public:
    static int itemscount;
    bool isAvailable = true;
    LibraryItem(string title, string author, string duedate)
    {
        this->title = title;
        this->author = author;
        this->duedate = duedate;
        itemscount++;
    }
    ~LibraryItem()
    {
        cout << "Destructor Called" << endl;
    };

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    string getTitle()
    {
        return title;
    }
    string getAuther()
    {
        return author;
    }
    string getDueDate()
    {
        return duedate;
    }
    string setTitle(string newTitle)
    {
        title = newTitle;
    }
    string setAuthor(string newAuthor)
    {
        author = newAuthor;
    }
    string setDueDate(string newDueDate)
    {
        duedate = newDueDate;
    }
};
// =================================================  DERIVED CLASSES    ===================================================

// ----------------------------------------------------   Derived book class -----------------------------------------------------------

class Book : public LibraryItem
{
public:
    string pagenumber;

    Book(string title, string author, string duedate, string pagenumber) : LibraryItem(title, author, duedate) // constructore
    {
        this->pagenumber = pagenumber;
    }
    ~Book()
    {
        cout << "Book Destructor Called" << endl;
    }
    void checkOut()
    {
        if (isAvailable == true)
        {
            isAvailable = false;
            cout << " check out successfully " << endl;
        }
        else
        {
            cout << "not found" << endl;
        }
    }

    void returnItem()
    {
        if (isAvailable == false)
        {
            isAvailable = true;
            cout << " returned successfully " << endl;
        }
        else
        {
            cout << "this item not found " << endl;
        }
    }
    void displayDetails()
    {
        cout << "Title: " << getTitle() << endl
             << "Author: " << getAuther() << endl
             << "Due Date: " << getDueDate() << endl
             << "Pages Number: " << pagenumber << endl
             << "====================" << endl;
    }
};

// ----------------------------------------------------   Derived DVD class -----------------------------------------------------------

class DVD : public LibraryItem
{
public:
    string duration;
    DVD(string title, string author, string duedate, string duration) : LibraryItem(title, author, duedate) // constructor
    {
        this->duration = duration;
    }
    ~DVD()
    {
        cout << "DVD Destructor Called" << endl;
    }
    void checkOut()
    {
        if (isAvailable == true)
        {
            isAvailable = false;
            cout << " check out successfully " << endl;
        }
        else
        {
            cout << "not found" << endl;
        }
    }

    void returnItem()
    {
        if (isAvailable == false)
        {
            isAvailable = true;
            cout << " returned successfully " << endl;
        }
        else
        {
            cout << "this item not found " << endl;
        }
    }
    void displayDetails()
    {
        cout << "Title: " << getTitle() << endl
             << "Author: " << getAuther() << endl
             << "Due Date: " << getDueDate() << endl
             << "Duration: " << duration << endl
             << "====================" << endl;
    }
};

// ----------------------------------------------------   Derived magazine class -----------------------------------------------------------

class Magazine : public LibraryItem
{
public:
    string issueNumber;
    Magazine(string title, string author, string duedate, string issueNumber) : LibraryItem(title, author, duedate) // constructor
    {
        this->issueNumber = issueNumber;
    }
    ~Magazine()
    {
        cout << "Magazine Destructor Called" << endl;
    }
    void checkOut()
    {
        if (isAvailable == true)
        {
            isAvailable = false;
            cout << " check out successfully " << endl;
        }
        else
        {
            cout << "not found" << endl;
        }
    }

    void returnItem()
    {
        if (isAvailable == false)
        {
            isAvailable = true;
            cout << " returned successfully " << endl;
        }
        else
        {
            cout << "this item not found " << endl;
        }
    }
    void displayDetails()
    {
        cout << "Title: " << getTitle() << endl
             << "Author: " << getAuther() << endl
             << "Due Date: " << getDueDate() << endl
             << "Issue Number: " << issueNumber << endl
             << "====================" << endl;
    }
};
int LibraryItem::itemscount = 0;

// ----------------------------------------------------   main function -----------------------------------------------------------

int main()
{
    LibraryItem *LibraryItem[100];
    Book b1("algo", "osman", "20/12/2022", "200");
    LibraryItem[0] = &b1;
    Book b2("dataStructre", "ahmed", "20/12/2022", "300");
    LibraryItem[1] = &b2;

    DVD d1("harrypotter", "j.k.rowling", "20/12/2022", "120");
    LibraryItem[2] = &d1;
    DVD d2("wonderful", "j.k.rowling", "20/12/2022", "150");
    LibraryItem[3] = &d2;

    Magazine m1("geo", "humam", "20/12/2022", "3");
    LibraryItem[4] = &m1;
    Magazine m2("national", "salim", "20/12/2022", "5");
    LibraryItem[5] = &m2;

    while (true)
    {
        int choice;
        cout << "===============   library managment system  ===============" << endl;
        cout << "1. to display all items " << endl;
        cout << "2. to search for items " << endl;
        cout << "3. to check out " << endl;
        cout << "4. to return an item " << endl;
        cout << "5. exit " << endl;

        cout << "enter your choice  ";
        cin >> choice;
        string searchChoice;
        switch (choice)
        {
        case 1:
            for (int i = 0; i < LibraryItem::itemscount; i++)
            {
                LibraryItem[i]->displayDetails();
            }
            break;
        case 2:

            cout << "enter search book ";
            cin >> searchChoice;
            for (int i = 0; i < LibraryItem::itemscount; i++)
            {
                if (LibraryItem[i]->getTitle() == searchChoice)
                {
                    LibraryItem[i]->displayDetails();
                }
            }
            break;
        case 3:
            cout << "enter search book ";
            cin >> searchChoice;
            for (int i = 0; i < LibraryItem::itemscount; i++)
            {
                if (LibraryItem[i]->getTitle() == searchChoice)
                {
                    LibraryItem[i]->checkOut();
                }
            }
            break;
        case 4:
            cout << "enter your return  book name ";
            cin >> searchChoice;
            for (int i = 0; i < LibraryItem::itemscount; i++)
            {
                if (LibraryItem[i]->getTitle() == searchChoice)
                {
                    LibraryItem[i]->returnItem();
                }
            }

            break;

        case 5:
            exit(0);

        default:
            break;
        }
    }

    return 0;
}
