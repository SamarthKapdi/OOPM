#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Book
{
    string id;
    string title;
    bool available = true;
};

class Library
{
public:
    void addBook(const string &id, const string &title)
    {
        books_[id] = Book{id, title, true};
    }

    void list() const
    {
        cout << "Books:\n";
        for (const auto &kv : books_)
        {
            const Book &b = kv.second;
            cout << "- " << b.id << ": " << b.title << " (" << (b.available ? "available" : "borrowed") << ")\n";
        }
    }

    bool borrow(const string &id)
    {
        auto it = books_.find(id);
        if (it == books_.end() || !it->second.available)
        {
            return false;
        }
        it->second.available = false;
        return true;
    }

    bool giveBack(const string &id)
    {
        auto it = books_.find(id);
        if (it == books_.end() || it->second.available)
        {
            return false;
        }
        it->second.available = true;
        return true;
    }

private:
    unordered_map<string, Book> books_;
};

int main()
{
    Library lib;
    lib.addBook("B1", "C++ Basics");
    lib.addBook("B2", "OOP Concepts");
    lib.list();

    cout << "Borrow B2: " << (lib.borrow("B2") ? "ok" : "failed") << "\n";
    lib.list();

    cout << "Return B2: " << (lib.giveBack("B2") ? "ok" : "failed") << "\n";
    lib.list();
    return 0;
}
