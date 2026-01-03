#include <iostream>

using namespace std;

class Account
{
public:
    explicit Account(double balance) : balance_(balance) {}
    virtual ~Account() = default;

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance_ += amount;
        }
    }

    virtual bool withdraw(double amount)
    {
        if (amount <= 0 || amount > balance_)
        {
            return false;
        }
        balance_ -= amount;
        return true;
    }

    double balance() const { return balance_; }

protected:
    double balance_;
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(double balance, double minBalance) : Account(balance), minBalance_(minBalance) {}

    bool withdraw(double amount) override
    {
        if (amount <= 0)
        {
            return false;
        }
        if (balance_ - amount < minBalance_)
        {
            return false;
        }
        balance_ -= amount;
        return true;
    }

private:
    double minBalance_;
};

int main()
{
    SavingsAccount sa(1000, 200);
    cout << "Balance: " << sa.balance() << "\n";
    cout << "Withdraw 850: " << (sa.withdraw(850) ? "ok" : "blocked") << "\n";
    cout << "Withdraw 700: " << (sa.withdraw(700) ? "ok" : "blocked") << "\n";
    cout << "Balance: " << sa.balance() << "\n";
    return 0;
}
