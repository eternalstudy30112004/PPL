#include <iostream>
#include <stdexcept>
using namespace std;
class BankAccount {
private:
    double balance;

public:
    BankAccount() : balance(0.0) {}

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount." << amount<<endl;

            throw invalid_argument("Amount must be greater than zero.");
        }
        balance += amount;
        cout << "Deposit of amount "<<amount<<" successful."<<endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << amount<<endl;
            throw invalid_argument("Amount must be greater than zero.");
        }
        if (amount > balance) {
            throw runtime_error("Insufficient balance. Cannot withdraw more than the available balance.");
        }
        balance -= amount;
        cout << "Withdrawal of amount "<<amount<<" successful."<< endl;
    }

    double getBalance()  {
        return balance;
    }
    void displayBalance()  {
        const double balance = this->getBalance();
        cout<< "Current Balance : " << balance<< endl;
    }
};

int main() {
    BankAccount account;

    try {
        account.displayBalance();

        account.deposit(1000.0);
        account.displayBalance();
        account.withdraw(500.0);
        account.displayBalance();

        account.deposit(-200.0);  
        account.displayBalance();

        account.withdraw(1500.0); 
        account.displayBalance();

    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (...) {
        cerr << "An unexpected error occurred." << endl;
    }
    
    cout << "Final account balance: " << account.getBalance() << endl;

    return 0;
}
