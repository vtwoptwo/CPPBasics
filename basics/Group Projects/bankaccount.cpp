#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
// generating a random number using time as the seed parameter to truly make the
// game playable

int genrandNum(){
  srand(time(0));
  long int num = (rand() % 100) * (3.14*1348);
  cout<<num;
  return num;
}
// recursive function to keep guessing the number
float recession() {
  float interest;
  cin >> interest;
  while (interest < 0.03) {
    cout << "please choose a different interest rate...the economy is fucked!";
    cin >> interest;
  }
  return interest;
}

class bankAc {

private:
  long int accountNumber;
  float currentBalance, interestRate;
  string userName;
  int pin;

public:
  int check(bankAc px[], int pn, string checkUserName, int checkPin) {
    bool test;
    do {
      for (int i = 0; i < pn; i++) {
        if (checkUserName == px[i].userName && checkPin == px[i].pin) {
          return i;
        }
      }

    } while (test == false);

    return 0;
  };

  void addAccount(bankAc px[], int pn) {

    for (int i = 0; i < pn; i++) {
      px[i].accountNumber = genrandNum();
      px[i].currentBalance = 0;
      cout << "\n\nADMIN ONLY! Enter today's interest rate (0-1) :   ";
      px[i].interestRate = recession();
      cout << "Enter the desired userName:   ";
      cin >> px[i].userName;

      cout << "Enter the desired pin number:   ";
      cin >> px[i].pin;
      while (pin <= 1000 && pin >= 9999) {
        cout << "That is not a valid PIN, please enter a new 4-digit PIN:";
        cin >> px[i].pin;
      }
    }
  };

  void balance(bankAc px[], int pn, int m) {
    string checkUserName;
    int checkPin;
    cout << "Enter your username:   ";
    cin >> checkUserName;
    cout << "Enter your pin:   ";
    cin >> checkPin;
    m = check(px, pn, checkUserName, checkPin);
    cout << "\nThe current balance of:   ";
    cout << px[m].accountNumber;
    cout << "is   " << endl;
    cout << px[m].currentBalance;
  };

  void withdraw(bankAc px[], int pn, float takenMoney, int w) {
    px[w].currentBalance = px[w].currentBalance - takenMoney;
    cout << "\nYou have withdrawn " << takenMoney
         << " and your current balance is " << px[w].currentBalance << "€.";
  };

  void deposit(bankAc px[], int pn, float addMoney, int z) {
    float negative = -px[z].currentBalance;
    if (px[z].currentBalance < 0) {
      px[z].currentBalance =
          px[z].currentBalance + addMoney - (negative * px[z].interestRate);

      cout << "\nYou have deposited " << addMoney
           << " and your current balance is " << px[z].currentBalance << "€."
           << endl;
      cout << "\nNotice!! As your account had a negative balance of "
           << negative << "€, a " << px[z].interestRate
           << " was applied to your deposit.";
    }

    else {
      px[z].currentBalance = px[z].currentBalance + addMoney;
      cout << "You have deposited " << addMoney
           << " and your current balance is " << px[z].currentBalance << "€."
           << endl;
    }
  };
};

int main() {
  int pn = 1;
  float takenMoney;
  float addMoney;
  bankAc bank[pn]; // initialize an object of a bank account which works as an
                   // array
  string checkUserName;
  int checkPin;
  int iAcc;

  cout << "Welcome to Banco Sabadell! How can we help you?\n";
  int c = 5;
  // initialize a do-while loop to simulate a menu
  do {
    cout << "\n1. Add an account \n2. Show the balance of the account\n3. "
            "Deposit money\n4. Withdraw money"
         << endl;
    cout << "Enter 0 to exit the bank." << endl;
    cin >> c;
    switch (c) {
    case 1:
      bank[pn].addAccount(bank, pn);
      break;

    case 2:

      cout << "Enter your username:   ";
      cin >> checkUserName;
      cout << "Enter your pin:   ";
      cin >> checkPin;
      iAcc = bank[pn].check(bank, pn, checkUserName, checkPin);
      bank[pn].balance(bank, pn, iAcc);
      break;

    case 3:

      cout << "Enter your username:   ";
      cin >> checkUserName;
      cout << "Enter your pin:   ";
      cin >> checkPin;
      iAcc = bank[pn].check(bank, pn, checkUserName, checkPin);
      cout << "\nHow much money do you want to add to your account?";
      cin >> addMoney;
      bank[pn].deposit(bank, pn, addMoney, iAcc);
      break;
    case 4:
      cout << "Enter your username:   ";
      cin >> checkUserName;
      cout << "Enter your pin:   ";
      cin >> checkPin;
      iAcc = bank[pn].check(bank, pn, checkUserName, checkPin);

      cout << "\nHow much money do you want take out of your account?";
      cin >> takenMoney;
      bank[pn].withdraw(bank, pn, takenMoney, iAcc);

      break;

    default:
      cout << "Invalid choice";
      break;
    };

  } while (c != 0);

  cout << "Exiting...";
  return 0;
}