#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Book
{
public:
    string title;
    string isbn;
    int price;
    vector<string> authors;

    Book(string title, string isbn, int price, vector<string> authors)
    {
        this->title = title;
        this->isbn = isbn;
        this->price = price;
        this->authors = authors;
    }
};

class BookStore
{
public:
    vector<Book> books;
    vector<int> copies;

    BookStore(vector<Book> books, vector<int> copies)
    {
        this->books = books;
        this->copies = copies;
    }
};

set<string> getISBN(BookStore store)
{
    set<string> isbns;
    for (int i = 0; i < store.books.size(); i++)
    {
        isbns.insert(store.books[i].isbn);
    }
    return isbns;
}

int noOfCopies(BookStore store, string isbn)
{
    for (int i = 0; i < store.books.size(); i++)
    {
        if (store.books[i].isbn == isbn)
        {
            return store.copies[i];
        }
    }
    return 0;
}

int totalCost(BookStore store)
{
    int total = 0;
    for (int i = 0; i < store.books.size(); i++)
    {
        total += store.books[i].price * store.copies[i];
    }
    return total;
}

int main()
{
    vector<string> authors1 = {"Author1", "Author2"};
    vector<string> authors2 = {"Author3", "Author4"};
    vector<string> authors3 = {"Author5", "Author6"};
    vector<string> authors4 = {"Author7", "Author8"};
    vector<string> authors5 = {"Author9", "Author10"};

    Book book1("Book1", "ISBN1", 100, authors1);
    Book book2("Book2", "ISBN2", 200, authors2);
    Book book3("Book3", "ISBN3", 300, authors3);
    Book book4("Book4", "ISBN4", 400, authors4);
    Book book5("Book5", "ISBN5", 500, authors5);

    vector<Book> books = {book1, book2, book3, book4, book5};
    vector<int> copies = {1, 2, 3, 4, 5};

    BookStore store(books, copies);

    set<string> isbns = getISBN(store);
    cout << "ISBNs: ";
    for (auto isbn : isbns)
    {
        cout << isbn << " ";
    }
    cout << endl;

    cout << "No of copies of ISBN2: " << noOfCopies(store, "ISBN2") << endl;

    cout << "Total cost: " << totalCost(store) << endl;

    return 0;
}