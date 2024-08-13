#include <bits/stdc++.h>

using namespace std;

#define INTEREST_RATE 0.05

class SavingsAccount
{
private:
    static int idCounter;
    int id;
    double balance;
    string name;

public:
    SavingsAccount(string name, double initialBalance)
    {
        id = ++idCounter;
        this->name = name;
        if (initialBalance < 1000)
        {
            cout << "Minimum balance should be 1000. Setting balance to 1000.\n";
            balance = 1000;
        }
        else
        {
            balance = initialBalance;
        }
    }
    void deposit(double amount)
    {
        balance += amount;
        cout << "Amount deposited successfully\n";
    }

    void withdraw(double amount)
    {
        if (balance - amount < 1000)
        {
            cout << "Insufficient balance\n";
            return;
        }
        balance -= amount;
        cout << "Amount withdrawn successfully\n";
    }

    void applyInterest()
    {
        balance += balance * INTEREST_RATE;
    }

    void printAccount() const
    {
        cout << "Account ID: " << id << ", Name: " << name << ", Balance: " << balance << endl;
    }

    double getBalance() { return balance; }
    string getName() { return name; }
};

int SavingsAccount::idCounter = 0;

int main()
{
    int n;
    cout << "Enter number of accounts: ";
    cin >> n;

    vector<SavingsAccount> accounts(n);

    srand(time(0));
    double totalInterest = 0;

    for (int i = 0; i < n; ++i)
    {
        double balance = (rand() % (100000 - 1000 + 1)) + 1000;
        string name = "Account " + to_string(i + 1);

        accounts[i] = SavingsAccount(name, balance);
        accounts[i].applyInterest();

        totalInterest += balance * INTEREST_RATE;
        accounts[i].printAccount();
        cout << "Interest to " << accounts[i].getName() << " is: " << accounts[i].getBalance() * INTEREST_RATE << endl;
    }

    cout << "Total interest: " << fixed << setprecision(2) << totalInterest << endl;

    return 0;
}
