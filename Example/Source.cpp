#include <iostream>;
#include <vector>;
#include <string>;

using namespace std;

int plus_five(int);

void open_account();
void check_balance(int);
void make_deposit(int);
void make_withdrawl(int);
void list_accounts();

struct Account {
	string account_name;
	int account_pin;
	double balance = 0;
};

vector<Account> list_of_accounts;
vector<Account>::iterator it;

int main()
{
	bool exit = false;

	while (!exit) {

		int selection;
		double deposit;
		double withdrawl;
		int holder;

		cout << "\\\\\\\Welcome to your banking manager. Please select an option from below.///////" << endl << endl;

		cout << "1) Open Account" << endl;
		cout << "2) Check Balance" << endl;
		cout << "3) Make Deposit" << endl;
		cout << "4) Make Withdrawl" << endl;
		cout << "5) Exit" << endl;
		cout << "6) List Accounts" << endl << endl;

		cout << "Enter Selection: ";
		cin >> selection;

		while (!cin) {
			cin.clear();
			cin.ignore();
		}
			switch (selection) {
			case 1: open_account();
				break;
			case 2:
				cout << "Enter account number: ";
				cin >> holder;

				check_balance(holder);
				break;
			case 3:
				cout << "Enter account number: ";
				cin >> holder;

				make_deposit(holder);
				break;
			case 4:
				cout << "Enter account number: ";
				cin >> holder;

				make_withdrawl(holder);
				break;
			case 5: exit = true;
				break;
			case 6: list_accounts();
				break;
			default: cout << "Invalid Selection, please try again." << endl << endl;
			}
	
	}

	return 0;
}

int plus_five(int n) {
	return n = n + 5;
}

void open_account() {
	string name;
	cout << "\nYou are now opening an account. Please enter your name: ";
	
	Account* a = new Account;

	cin >> a->account_name;

	cout << "\nPlease enter a 4-digit PIN: ";

	cin >> a->account_pin;

	cout << "\nEnter the opening balance: ";

	cin >> a->balance;

	cout << "\nThank you! Your new account has been opened." << endl << endl;

	list_of_accounts.push_back(*a);
}

void check_balance(int pin) {
	for (it = list_of_accounts.begin(); it != list_of_accounts.end(); it++) {
		if (pin == it->account_pin) {
			cout << "\n Your account balance is: " << it->balance << endl << endl;
		}
	}
}

void make_deposit(int pin) {

	for (it = list_of_accounts.begin(); it != list_of_accounts.end(); it++) {
		if (pin == it->account_pin) {
			cout << "\n Enter amount to deposit: ";
			double deposit = 0.0;
			cin >> deposit;

			it->balance += deposit;
			cout << "\n\n";
		}
	}
}

void make_withdrawl(int pin) {

	for (it = list_of_accounts.begin(); it != list_of_accounts.end(); it++) {
		if (pin == it->account_pin) {
			cout << "\n Enter amount to withdrawl: ";
			double withdrawl = 0.0;
			cin >> withdrawl;

			it->balance -= withdrawl;
			cout << "\n\n";
		}
	}
}

void list_accounts() {
	for (it = list_of_accounts.begin(); it != list_of_accounts.end(); it++) {
		cout << it->account_name << endl;
	}
}