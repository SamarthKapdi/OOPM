#include <iostream>
#include <string>

using namespace std;

class Account
{
public:
    Account(string owner, int pin, double balance)
        : owner_(std::move(owner)), pin_(pin), balance_(balance) {}

    const string &owner() const { return owner_; }

    bool authenticate(int pin) const
    {
        return pin == pin_;
    }

    double balance() const { return balance_; }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance_ += amount;
        }
    }

    bool withdraw(double amount)
    {
        if (amount <= 0 || amount > balance_)
        {
            return false;
        }
        balance_ -= amount;
        return true;
    }

private:
    string owner_;
    int pin_;
    double balance_;
};

class ATM
{
public:
    explicit ATM(Account &account) : account_(account) {}

    void run()
    {
        cout << "Welcome, " << account_.owner() << "\n";
        cout << "Enter PIN: ";
        int pin = 0;
        cin >> pin;
        if (!account_.authenticate(pin))
        {
            cout << "Invalid PIN\n";
            return;
        }

        while (true)
        {
            cout << "\n1) Balance\n2) Deposit\n3) Withdraw\n4) Exit\nChoose: ";
            int choice = 0;
            cin >> choice;

            if (choice == 1)
            {
                cout << "Balance = " << account_.balance() << "\n";
            }
            else if (choice == 2)
            {
                cout << "Amount: ";
                double amt = 0;
                cin >> amt;
                account_.deposit(amt);
                cout << "Done\n";
            }
            else if (choice == 3)
            {
                cout << "Amount: ";
                double amt = 0;
                cin >> amt;
                cout << (account_.withdraw(amt) ? "Done\n" : "Insufficient funds\n");
            }
            else if (choice == 4)
            {
                cout << "Goodbye\n";
                return;
            }
            else
            {
                cout << "Invalid choice\n";
            }
        }
    }

private:
    Account &account_;
};

int main()
{
    Account acc("User", 1234, 1000);
    ATM atm(acc);
    atm.run();
    return 0;
}
