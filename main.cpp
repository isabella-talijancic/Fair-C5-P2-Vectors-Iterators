// Hero's Inventory 3.0 demonstrates vectors and iterators

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

string groceryItem;
int MAX = 8;
int price0, price1, price2, price3, price4, price5, price6, price7;
int total;
char playAgain = 'Y';

void introduction();
void shoppingList();
void showList();
void addItems();
void removeItem();
void replaceItems();
void calculateBill();
void endProgram();

vector<string> inventory;
vector<string>::iterator myIterator;
vector<string>::const_iterator iter;

int main()
{
	introduction();
	while ((playAgain == 'Y') || (playAgain == 'y'))
	{
		inventory.clear();
		shoppingList();
		showList();
		addItems();
		showList();
		replaceItems();
		calculateBill();
	
		cout << "\nWould you like to shop again with us (Y/N)? ";
		cin >> playAgain;
		cout << string(60, '-') << "\n";
	}
	endProgram();
	return 0;	
}
void introduction()
{
	cout << "🍋 🍉 Whole Foods 🍉 🍋\n\n";
	cout << "Welcome to our store!";
    cout << " \nBefore we begin, our inventory must be refreshed...";
    cout << "\nPlease type your shopping list of 8 items:";
    cout << "\n" << string(60, '-') << "\n";
}
void shoppingList()
{
	for (int i = 0; i < MAX; i++)
	{
		cout << "Grocery Item: ";
		getline(cin, groceryItem);
		inventory.push_back(groceryItem);
	}
	cout << string(60, '-') << "\n";
	
}
void addItems()
{
	cout << string(60, '-');
	cout << "\nAdd any other item to your list: ";
	getline(cin, groceryItem);
	inventory.push_back(groceryItem);
	
}
void showList()
{
	cout << "Your grocery list:\n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
        cout << *iter << endl;
	}
}
void removeItem()
{
	cout << "\nUh oh! Looks like we ran out of '" << inventory[0] << "'.";
	inventory.erase(inventory.begin()+0);
}
void replaceItems()
{
	cout << string(60, '-');
	removeItem();
	cout << "\nWhat item would you like instead? ";
	getline(cin, groceryItem);
	myIterator = inventory.begin();
	*myIterator = groceryItem;
    cout << "Your grocery list:\n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
        cout << *iter << endl;
	}
	cout << string(60, '-');
}
void calculateBill()
{
	price0 = inventory[0].size() * (2);
	price1 = inventory[1].size() * (3);
	price2 = inventory[2].size() * (4);
	price3 = inventory[3].size() * (5);
	price4 = inventory[4].size() * (2);
	price5 = inventory[5].size() * (3);
	price6 = inventory[6].size() * (4);
	price7 = inventory[7].size() * (5);
	
	cout << "\nHere is your current bill:";
	cout << "\n" << inventory[0] << ": $" << price0;
	cout << "\n" << inventory[1] << ": $" << price1;
	cout << "\n" << inventory[2] << ": $" << price2;
	cout << "\n" << inventory[3] << ": $" << price3;
	cout << "\n" << inventory[4] << ": $" << price4;
	cout << "\n" << inventory[5] << ": $" << price5;
	cout << "\n" << inventory[6] << ": $" << price6;
	cout << "\n" << inventory[7] << ": $" << price7;
	cout << "\n" << string(60, '-');
}
void endProgram()
{
	total = price0 + price1 + price2 + price3 + price4 + price5 + price6 + price7;
	cout << "Your total for this shopping trip is $ " << total << ".";
	cout << "\n" << string(60, '-');
	cout << "\n\n🍇 Thank you for shopping with 🍇";
	cout << "\n       🍊 Whole Foods 🍊";
}