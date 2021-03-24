#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {

private:
    string user;
    string accountNum;
    double ballance;

public:
    BankAccount(string user, string accountNum, double ballance) :
        user(user),
        accountNum(accountNum),
        ballance(ballance) {
    }

    void setInitialBallance(double ballance_) {
        ballance = ballance_;
    }

    void setAccountNumber(string newAccNumber) {
        accountNum = newAccNumber;
    }

    double GetBallance(void) { return ballance;  }

    void Print(ostream & output) {
        output << "Name : " << user << endl
            << "Account number : " << accountNum << endl
            << "Ballance : " << ballance << endl;
    }

    void addBallance(double addedBallance, ostream& output) {
        ballance += addedBallance;
        output << "Added: " << addedBallance << endl
            << "New Ballance: " << ballance << endl;
    }

    void withdrawBallance(double withdrawedBallance, ostream& output) {
        if (ballance < withdrawedBallance) {
            output << "Not Enought Balance !" << endl;
            return;
        }
        ballance -= withdrawedBallance;
    }

};


enum class conditions { Exit = 0, ShowAll, Add, Withdraw };

conditions Process(BankAccount & account) {

    cout << "Would you like to do ?" << endl;
    cout << "Press 1 to Show All Information..." << endl;
    cout << "Press 2 to Add Balance..." << endl;
    cout << "Press 3 to Withdraw Balance..." << endl;
    cout << "Press 0 to Exit Program..." << endl;

    int choice;
    cin >> choice;

    double ballanceChange;

    switch ((conditions)choice) {
        case conditions::ShowAll:
            account.Print(cout);
            break;
        case conditions::Add:
            cout << "Enter Balance to Add :" << endl;
            cin >> ballanceChange;
            account.addBallance(ballanceChange, cout);
            break;
        case conditions::Withdraw:
            cout << "Enter Balance to Withdraw :" << endl;
            cin >> ballanceChange;
            account.withdrawBallance(ballanceChange, cout);
            break;
        case conditions::Exit: break;
        default:
            // error message, incorrect choice by the user
            break;
    }

    return (conditions)choice;
}

void Problem3(void) {

    string user;
    string accountNum;
    double ballance;

    cout << "Enter Name :" << endl;
    cin >> user;
    cout << "Enter 5 charactes IBAN Code :" << endl;
    cin >> accountNum;
    cout << "Enter Initial Balance :" << endl;
    cin >> ballance;

    BankAccount acc(user, accountNum, ballance);

    while (Process(acc) != conditions::Exit);

}
