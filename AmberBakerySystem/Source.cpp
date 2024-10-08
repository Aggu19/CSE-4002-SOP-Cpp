#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Define a structure to represent bakery items
struct BakeryItem {
    string name;
    double price;
};

void login() {
    string username;  // Declare variables here
    string password;

    cout << "\n\t\t\tWelcome To Amber Bakery\t\t\t\n\n\n";
    cout << "\n=========================================\n"; //Login for ADMIN and CASHIER
    cout << "             L O G I N \n";
    cout << "Enter your username and password to login\n";
    cout << "==========================================\n";
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    if (username == "admin" && password == "admin123")
        // Check if the username and password are correct for admin page
    {
        cout << "\n***** Login successful for Admin Page!*****\n\n";

    }
    else if (username == "cashier" && password == "cashier123")
        // Check if the username and password are correct for cashier page
    {
        cout << "\n***** Login successful for Cashier Page!****\n\n";

    }
    else {
        cout << "\nInvalid credentials. Please try again.!!!" << endl;
    }
}
// Class to manage the bakery
class BakeryManager {
public:
    BakeryManager() {
        // Initialize the menu with some default items

        bakeryItems.push_back({ "Butter Cake\t\t", 2.50 });
        bakeryItems.push_back({ "Sponge Cake\t\t", 1.50 });
        bakeryItems.push_back({ "Chocolate Cake\t", 3.75 });
        bakeryItems.push_back({ "Muffin Cake\t\t", 2.00 });
        bakeryItems.push_back({ "Tea\t\t\t\t", 1.75 });
        bakeryItems.push_back({ "Cappuccino\t\t", 2.25 });
        bakeryItems.push_back({ "Soft drinks\t\t", 1.75 });
        bakeryItems.push_back({ "Mix Fruit Juice\t", 1.75 });
        bakeryItems.push_back({ "Bruschetta\t\t", 1.75 });
        bakeryItems.push_back({ "Cream white Bread", 1.75 });
        bakeryItems.push_back({ "Vanilla Cake\t", 1.75 });
        bakeryItems.push_back({ "Peanut butter Cake", 1.75 });
        bakeryItems.push_back({ "Puddin\t\t\t", 1.75 });
        bakeryItems.push_back({ "Caramel\t\t\t", 1.75 });
        bakeryItems.push_back({ "Watalappam\t\t", 1.75 });
        bakeryItems.push_back({ "Apple Pie\t\t", 1.75 });
    }

    void displayBakeryItems() {
        cout << "\n|====================================================================|\n";
        cout << "|        A M B E R  B A K E R Y - P A S T R Y  M E N U E S           |\n";
        cout << "|               'The famous Pastry shop in town'                     |\n";
        cout << "|====================================================================|\n\n";
        cout << "\tItems\t\t\t\t\t\t Price\n\n";

        for (int i = 0; i < bakeryItems.size(); ++i) {
            cout << i + 1 << ". " << bakeryItems[i].name << " - $" << fixed << setprecision(2) << bakeryItems[i].price << endl;
        }
    }

    void addNewItem(const BakeryItem& newItem) {
        bakeryItems.push_back(newItem);
    }

    const vector<BakeryItem>& getBakeryItems() const {
        return bakeryItems;
    }

private:
    vector<BakeryItem> bakeryItems;
};

// Class to manage orders and billing
class OrderManager {

public:
    void addOrder(const BakeryItem& item, int quantity) {
        orders.push_back({ item, quantity });
    }

    void editOrder(int index, int newQuantity) {
        if (index >= 0 && index < orders.size()) {
            orders[index].second = newQuantity;
        }
    }

    double calculateTotal() {
        double total = 0.0;
        for (const auto& order : orders) {
            total += order.first.price * order.second;
        }
        return total;
    }

    void printBill() {
        cout << "\n==================================\n";
        cout << " ---- Amber Bakery Invoice ----\n";
        cout << "==================================\n";

        for (const auto& order : orders) {
            cout << order.second << order.first.name << " - $" << fixed << setprecision(2) << order.first.price * order.second << endl;
        }

        cout << "\nTotal: $\t" << fixed << setprecision(2) << calculateTotal() << endl <<
            "\n***Thank You for Purchasing!***\n\n" << endl << "'The famous Pastry shop in town'\n\n ";
    }

private:
    vector<pair<BakeryItem, int>> orders;
};
int cashierChoice; // global variable

void welcomeUserType() {

    cout << "\n==================================\n";
    cout << " ----Welcome to Amber Bakery ----\n";
    cout << "==================================\n";
    cout << "User type (1-Cashier/2-Admin): ";

}
int main() {
    BakeryManager bakeryManager;
    OrderManager orderManager;
    while (true) {
        welcomeUserType();
        int role;
        cin >> role;
        switch (role) {
        case 1:// Cashier

            login();
            while (true) {


                cout << "\nCashier Menu" << endl;
                cout << "============\n";
                cout << "1. View Bakery Items" << endl;
                cout << "2. Make an Order" << endl;
                cout << "3. Edit Order" << endl;
                cout << "4. Calculate and Print Bill" << endl;
                cout << "5. Exit" << endl;
                cout << "Enter your Option (1-5): ";
                cin >> cashierChoice;

                if (cashierChoice == 1) {
                    bakeryManager.displayBakeryItems();
                }
                else if (cashierChoice == 2) {
                    int itemChoice, quantity;
                    bakeryManager.displayBakeryItems();
                    cout << "Enter the item number to order: ";
                    cin >> itemChoice;
                    if (itemChoice >= 1 && itemChoice <= bakeryManager.getBakeryItems().size()) {
                        cout << "Enter quantity: ";
                        cin >> quantity;
                        const BakeryItem& selectedItem = bakeryManager.getBakeryItems()[itemChoice - 1];
                        orderManager.addOrder(selectedItem, quantity);
                        cout << "Order added successfully!" << endl;
                    }
                    else {
                        cout << "Invalid item choice. Please try again." << endl;
                    }
                }
                else if (cashierChoice == 3) {
                    int orderIndex, newQuantity;

                    cout << "Enter the index of the item to edit: ";
                    cin >> orderIndex;
                    if (orderIndex >= 0 && orderIndex) {
                        cout << "Enter the new quantity: ";
                        cin >> newQuantity;
                        orderManager.editOrder(orderIndex, newQuantity);
                        cout << "Order edited successfully!" << endl;
                    }
                    else {
                        cout << "Invalid order index. Please try again." << endl;
                    }
                }
                else if (cashierChoice == 4) {
                    orderManager.printBill();
                }
                else if (cashierChoice == 5) {
                    cout << "Existing..\n\n (For Admin control please login) ";

                    break;
                }
                else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }

        case 2: { // Admin
            login();
            while (true) {
                int adminChoice;
                cout << "\nAdmin Menu:" << endl;
                cout << "============\n";
                cout << "1. Add New Item" << endl;
                cout << "2. View Billing History" << endl;
                cout << "3.Display Items" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter an Option (1-4): ";
                cin >> adminChoice;

                if (adminChoice == 1) {
                    string name;
                    double price;
                    cout << "Enter item name: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, name);
                    cout << "Enter item price: $";
                    cin >> price;
                    bakeryManager.addNewItem({ name, price });
                    cout << "Item added successfully!" << endl;
                }
                else if (adminChoice == 2) {
                    orderManager.printBill();

                }
                else if (adminChoice == 3) {
                    bakeryManager.displayBakeryItems();
                }
                else if (adminChoice == 4) {
                    cout << "Exiting..\n\n";
                    break;
                }
                else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            break;

        default: {

            cout << "Invalid role. Exiting..." << endl;
            return 0;
        }

        }

        }
        return 0;
    }
}