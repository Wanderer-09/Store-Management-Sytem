#include<iostream>
#include<vector>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include <string>
#include <iomanip> 
using namespace std;


class grocery {
public:
    int Item_number;
    string Item_Name;
    double Price;
    int quantity;
    int item_number, quantity_of_items;

    vector<grocery> products;
    vector<pair<int, int>> cart;  // To store item_number and quantity in the cart

    void purchase() {
        ifstream file("grocery.txt");

        if (!file) {
            cerr << "Error opening file: grocery.txt" << endl;
            return;
        }

        grocery newItem;

        while (file >> newItem.Item_number >> newItem.Item_Name >> newItem.Price >> newItem.quantity) {
            products.push_back(newItem);
        }

        file.close(); 
        cout << "no.     Name    Price    quantity_available" << endl;
        cout << endl;
        for (int i = 0; i < products.size(); ++i) {
            cout << i << " " << products[i].Item_number << "     " << products[i].Item_Name << "     "
                << products[i].Price << "     " << products[i].quantity << endl;
     
        
        }
        cout << "Please enter -> ITEM NUMBER to add to your cart: " << endl;
        cin >> item_number;
        cout << "Please enter -> QUANTITY OF THIS ITEM: " << endl;
        cin >> quantity_of_items;

        if (quantity_of_items > 0 && quantity_of_items <= products[item_number].quantity) {
            cart.push_back({ item_number, quantity_of_items });
            products[item_number].quantity -= quantity_of_items;
            cout << "Item added to the cart successfully!" << endl;
        }
        else {
            cout << "Invalid quantity or not enough stock. Please try again." << endl;
        }
    }

    void viewCart() {
        if (cart.empty()) {
            cout << "Your cart is empty." << endl;
            return;
        }

        cout << "Cart" << endl;
        cout << "-------------------------------------------" << endl;
        cout << setw(5) << "Item#" << setw(15) << "Item Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(15) << "Total" << endl;
        cout << "-------------------------------------------" << endl;

        double totalCost = 0.0;

        for (const auto& cartItem : cart) {
            for (const auto& product : products) {
                if (product.Item_number == cartItem.first) {
                    double itemTotal = product.Price * cartItem.second;
                    totalCost += itemTotal;

                    cout << setw(5) << product.Item_number << setw(15) << product.Item_Name
                        << setw(10) << product.Price << setw(10) << cartItem.second << setw(15) << itemTotal << endl;
                }
            }
        }

        cout << "-------------------------------------------" << endl;
        cout << setw(30) << "Total Cost:" << setw(15) << totalCost << endl;
        cout << "-------------------------------------------" << endl;
    }

    void generateReceipt() {
        cout << "Receipt" << endl;
        cout << "-------------------------------------------" << endl;
        cout << setw(5) << "Item#" << setw(15) << "Item Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(15) << "Total" << endl;
        cout << "-------------------------------------------" << endl;

        double totalCost = 0.0;

        for (const auto& cartItem : cart) {
            for (auto& product : products) {
                if (product.Item_number == cartItem.first) {
                    double itemTotal = product.Price * cartItem.second;
                    totalCost += itemTotal;

                    cout << setw(5) << product.Item_number << setw(15) << product.Item_Name
                        << setw(10) << product.Price << setw(10) << cartItem.second << setw(15) << itemTotal << endl;

                    // Update quantity in stock
                    product.quantity -= cartItem.second;
                }
            }
        }

        cout << "-------------------------------------------" << endl;
        cout << setw(30) << "Total Cost:" << setw(15) << totalCost << endl;
        cout << "-------------------------------------------" << endl;

        // Clear the cart after generating the receipt
        cart.clear();
    }
};

class clothing {
public:
    int Item_number;
    string Item_Name;
    double Price;
    int quantity;
    int item_number, quantity_of_items;

    vector<clothing> products;
    vector<pair<int, int>> cart;

    void purchase() {
        ifstream file("clothing.txt");

        if (!file) {
            cerr << "Error opening file: clothing.txt" << endl;
            return;
        }

        clothing newItem;

        while (file >> newItem.Item_number >> newItem.Item_Name >> newItem.Price >> newItem.quantity) {
            products.push_back(newItem);
        }

        file.close();
        cout << "no.   Name  Price quantity_available" << endl;
        cout << endl;
        for (int i = 0; i < products.size(); ++i) {
            cout << products[i].Item_number << " " << products[i].Item_Name << " "
                << products[i].Price << " " << products[i].quantity << endl;
        }

        cout << "Please enter -> ITEM NUMBER to add to your cart: " << endl;
        cin >> item_number;
        cout << "Please enter -> QUANTITY OF THIS ITEM: " << endl;
        cin >> quantity_of_items;


        if (quantity_of_items > 0 && quantity_of_items <= products[item_number].quantity) {
            cart.push_back({ item_number, quantity_of_items });
            products[item_number].quantity -= quantity_of_items;
            cout << "Item added to the cart successfully!" << endl;
        }
        else {
            cout << "Invalid quantity or not enough stock. Please try again." << endl;
        }
    }

    void viewCart() {
        if (cart.empty()) {
            cout << "Your cart is empty." << endl;
            return;
        }

        cout << "Cart" << endl;
        cout << "-------------------------------------------" << endl;
        cout << setw(5) << "Item#" << setw(15) << "Item Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(15) << "Total" << endl;
        cout << "-------------------------------------------" << endl;

        double totalCost = 0.0;

        for (const auto& cartItem : cart) {
            for (const auto& product : products) {
                if (product.Item_number == cartItem.first) {
                    double itemTotal = product.Price * cartItem.second;
                    totalCost += itemTotal;

                    cout << setw(5) << product.Item_number << setw(15) << product.Item_Name
                        << setw(10) << product.Price << setw(10) << cartItem.second << setw(15) << itemTotal << endl;
                }
            }
        }

        cout << "-------------------------------------------" << endl;
        cout << setw(30) << "Total Cost:" << setw(15) << totalCost << endl;
        cout << "-------------------------------------------" << endl;
    }

    void generateReceipt() {
        cout << "Receipt" << endl;
        cout << "-------------------------------------------" << endl;
        cout << setw(5) << "Item#" << setw(15) << "Item Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(15) << "Total" << endl;
        cout << "-------------------------------------------" << endl;

        double totalCost = 0.0;

        for (const auto& cartItem : cart) {
            for (auto& product : products) {
                if (product.Item_number == cartItem.first) {
                    double itemTotal = product.Price * cartItem.second;
                    totalCost += itemTotal;

                    cout << setw(5) << product.Item_number << setw(15) << product.Item_Name
                        << setw(10) << product.Price << setw(10) << cartItem.second << setw(15) << itemTotal << endl;

                    // Update quantity in stock
                    product.quantity -= cartItem.second;
                }
            }
        }

        cout << "-------------------------------------------" << endl;
        cout << setw(30) << "Total Cost:" << setw(15) << totalCost << endl;
        cout << "-------------------------------------------" << endl;

        // Clear the cart after generating the receipt
        cart.clear();
    }
};

class electronics {
public:
    int Item_number;
    string Item_Name;
    double Price;
    int quantity;
    int item_number, quantity_of_items;

    vector<clothing> products;
    vector<pair<int, int>> cart;

    void purchase() {
        ifstream file("Electronics.txt");

        if (!file) {
            cerr << "Error opening file: clothing.txt" << endl;
            return;
        }

        clothing newItem;

        while (file >> newItem.Item_number >> newItem.Item_Name >> newItem.Price >> newItem.quantity) {
            products.push_back(newItem);
        }

        file.close();
        cout << "no.   Name  Price quantity_available" << endl;
        cout << endl;
        for (int i = 0; i < products.size(); ++i) {
            cout << products[i].Item_number << " " << products[i].Item_Name << " "
                << products[i].Price << " " << products[i].quantity << endl;
        }

        cout << "Please enter -> ITEM NUMBER to add to your cart: " << endl;
        cin >> item_number;
        cout << "Please enter -> QUANTITY OF THIS ITEM: " << endl;
        cin >> quantity_of_items;


        if (quantity_of_items>0 && quantity_of_items <= products[item_number].quantity) {
            cart.push_back({ item_number, quantity_of_items });
            products[item_number].quantity -= quantity_of_items;
            cout << "Item added to the cart successfully!" << endl;
        }
        else {
            cout << "Invalid quantity or not enough stock. Please try again." << endl;
        }
    }

    void viewCart() {
        if (cart.empty()) {
            cout << "Your cart is empty." << endl;
            return;
        }

        cout << "Cart" << endl;
        cout << "-------------------------------------------" << endl;
        cout << setw(5) << "Item#" << setw(15) << "Item Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(15) << "Total" << endl;
        cout << "-------------------------------------------" << endl;

        double totalCost = 0.0;

        for (const auto& cartItem : cart) {
            for (const auto& product : products) {
                if (product.Item_number == cartItem.first) {
                    double itemTotal = product.Price * cartItem.second;
                    totalCost += itemTotal;

                    cout << setw(5) << product.Item_number << setw(15) << product.Item_Name
                        << setw(10) << product.Price << setw(10) << cartItem.second << setw(15) << itemTotal << endl;
                }
            }
        }

        cout << "-------------------------------------------" << endl;
        cout << setw(30) << "Total Cost:" << setw(15) << totalCost << endl;
        cout << "-------------------------------------------" << endl;
    }

    void generateReceipt() {
        cout << "Receipt" << endl;
        cout << "-------------------------------------------" << endl;
        cout << setw(5) << "Item#" << setw(15) << "Item Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(15) << "Total" << endl;
        cout << "-------------------------------------------" << endl;

        double totalCost = 0.0;

        for (const auto& cartItem : cart) {
            for (auto& product : products) {
                if (product.Item_number == cartItem.first) {
                    double itemTotal = product.Price * cartItem.second;
                    totalCost += itemTotal;

                    cout << setw(5) << product.Item_number << setw(15) << product.Item_Name
                        << setw(10) << product.Price << setw(10) << cartItem.second << setw(15) << itemTotal << endl;

                    // Update quantity in stock
                    product.quantity -= cartItem.second;
                }
            }
        }

        cout << "-------------------------------------------" << endl;
        cout << setw(30) << "Total Cost:" << setw(15) << totalCost << endl;
        cout << "-------------------------------------------" << endl;

        // Clear the cart after generating the receipt
        cart.clear();
    }
};



class store
{
public:
    void store_management();
    void add_Item();
    void show_Item();
    void check_Item();
    void update_Item();
    void remove_Item();
};
void store::store_management()
{
    system("cls");
    cout << "\n\n\t\t\t\tSTORE MANAGEMENT SYSTEM";
    cout << "\n\n 1. Add New Item";
    cout << "\n 2. Display Items";
    cout << "\n 3. Check Specific Item";
    cout << "\n 4. Update Item";
    cout << "\n 5. Delete Item";
    cout << "\n 6. Exit";
}

void store::add_Item()
{
    system("cls");
    fstream file;
    int quantity;
    string item_name, date, item_id, type;
    cout << "\n\n\t\t\t\t ADD New Item";
    cout << "is item grocery,electronics or clothing ?";
    cin >> type;
    cout << "\n\n Item ID(0,1,2,3,4,5,...) : ";
    cin >> item_id;
    cout << "\n\n\t\t\t Item Name : ";
    cin >> item_name;
    cout << "\n\n Price : ";
    cin >> date;
    cout << "\n\n\t\t\t quantity : ";
    cin >> quantity;
    if (type == "grocery") {
        file.open("Grocery.txt", ios::out | ios::app);
        file << " " << item_id << " " << item_name << " " << date << " " << quantity << "\n";
        file.close();
    }
    else if (type == "clothing") {
        file.open("Clothing.txt", ios::out | ios::app);
        file << " " << item_id << " " << item_name << " " << date << " " << quantity << "\n";
        file.close();
    }
    else if (type == "electronics") {
        file.open("Electronics.txt", ios::out | ios::app);
        file << " " << item_id << " " << item_name << " " << date << " " << quantity << "\n";
        file.close();
    }

}

void store::show_Item()
{
    system("cls");
    fstream file;
    int quantity;
    string item_name, item_id, date;

    cout << "\n\n\t\t\t\tShow All Items";
    cout << "\n\n Item ID   Item        Price        quantity\n\n";
    file.open("Clothing.txt", ios::in);
    if (!file)
        cout << "\n\n";
    else
    {

        file >> item_id >> item_name >> date >> quantity;
        while (!file.eof())
        {
            cout << "    " << item_id << "      " << item_name << "        " << date << "\t      " << quantity << "\n\n";
            file >> item_id >> item_name >> date >> quantity;
        }
        file.close();
    }
    file.open("Grocery.txt", ios::in);
    if (!file)
        cout << "\n\n";
    else
    {

        file >> item_id >> item_name >> date >> quantity;
        while (!file.eof())
        {
            cout << "    " << item_id << "      " << item_name << "        " << date << "\t      " << quantity << "\n\n";
            file >> item_id >> item_name >> date >> quantity;
        }
        file.close();
    }
    file.open("Electronics.txt", ios::in);
    if (!file)
        cout << "\n\n";
    else
    {

        file >> item_id >> item_name >> date >> quantity;
        while (!file.eof())
        {
            cout << "    " << item_id << "      " << item_name << "        " << date << "\t      " << quantity << "\n\n";
            file >> item_id >> item_name >> date >> quantity;
        }
        file.close();
    }
    system("pause");
}

void store::check_Item() {
    system("cls");
    fstream file;
    int quantity, count = 0;
    string item_id, item_name, date, item_idd;

    cout << "\n\n\t\t\t\tCheck Specific Item";
    cout << "\n\n Item ID : ";
    cin >> item_idd;
    // Check Clothing.txt
    file.open("Clothing.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error...";
    }
    else {

        file >> item_id >> item_name >> date >> quantity;
        while (!file.eof()) {
            if (item_idd == item_id) {
                system("cls");
                cout << "\n\n\t\t\t\tCheck Specific Item";
                cout << "\n\n Item ID : " << item_id;
                cout << "\n\n\t\t\tName : " << item_name;
                cout << "\n\n Price : " << date;
                cout << "\n\n\t\t\tquantity : " << quantity;
                count++;
                break;
            }
            file >> item_id >> item_name >> date >> quantity;
        }
        file.close();
    }

    // Check Grocery.txt if Clothing.txt did not find the item
    if (count == 0) {
        file.open("Grocery.txt", ios::in);
        if (!file) {
            cout << "\n\n File Opening Error...";
        }
        else {

            file >> item_id >> item_name >> date >> quantity;
            while (!file.eof()) {
                if (item_idd == item_id) {
                    system("cls");
                    cout << "\n\n\t\t\t\tCheck Specific Item";
                    cout << "\n\n Item ID : " << item_id;
                    cout << "\n\n\t\t\tName : " << item_name;
                    cout << "\n\n Date : " << date;
                    cout << "\n\n\t\t\tquantity : " << quantity;
                    count++;
                    break;
                }
                file >> item_id >> item_name >> date >> quantity;
            }
        }
        file.close();
    }

    // Check Clothing.txt if Grocery.txt also did not find the item
    if (count == 0) {
        file.open("Electronics.txt", ios::in);
        if (!file) {
            cout << "\n\n";
        }
        else {

            file >> item_id >> item_name >> date >> quantity;
            while (!file.eof()) {
                if (item_idd == item_id) {
                    system("cls");
                    cout << "\n\n\t\t\t\tCheck Specific Item";
                    cout << "\n\n Item ID : " << item_id;
                    cout << "\n\n\t\t\tName : " << item_name;
                    cout << "\n\n Date : " << date;
                    cout << "\n\n\t\t\tquantity : " << quantity;
                    count++;
                    break;
                }
                file >> item_id >> item_name >> date >> quantity;
            }
        }
        file.close();
    }

    if (count == 0) {
        cout << "\n\n";
        cout << "Item not found" << endl;
    }

    system("pause");
}



void store::update_Item() {
    system("cls");

    int quantity, no_co, count = 0;
    string item_name, date, item_idd, item_id;
    cout << "\n\n\t\t\t\tUpdate Item Record";
    cout << "\n\n Item ID : ";
    cin >> item_id;

    // Update Grocery file
    fstream file("Grocery.txt", ios::in);
    fstream file1("Grocery1.txt", ios::out | ios::app);

    if (!file) {
        cout << "\n\n";
    }
    else {


        while (file >> item_idd >> item_name >> date >> quantity) {
            if (item_id == item_idd) {
                system("cls");
                cout << "\n\n\t\t\t\tUpdate Grocery Item Record";
                cout << "\n\n New Item Name : ";
                cin >> item_name;
                cout << "\n\n\t\t\tPrice : ";
                cin >> date;
                cout << "\n\n Quantity : ";
                cin >> no_co;

                file1 << item_id << " " << item_name << " " << date << " " << no_co << "\n";
                count++;
            }
            else {
                file1 << item_idd << " " << item_name << " " << date << " " << quantity << "\n";
            }
        }

        file.close();
        file1.close();
        remove("Grocery.txt");
        rename("Grocery1.txt", "Grocery.txt");

        // Update Electronics file
        if (count == 0) {
            count = 0;
            {
                fstream file2("Electronics.txt", ios::in);
                fstream file3("Electronics1.txt", ios::out | ios::app);

                if (!file2) {
                    cout << "\n\n";
                }
                else {


                    while (file2 >> item_idd >> item_name >> date >> quantity) {
                        if (item_id == item_idd) {
                            system("cls");
                            cout << "\n\n\t\t\t\tUpdate Electronics Item Record";
                            cout << "\n\n New Item Name : ";
                            cin >> item_name;
                            cout << "\n\n\t\t\tPrice : ";
                            cin >> date;
                            cout << "\n\n Quantity : ";
                            cin >> no_co;

                            file3 << item_id << " " << item_name << " " << date << " " << no_co << "\n";
                            count++;
                        }
                        else {
                            file3 << item_idd << " " << item_name << " " << date << " " << quantity << "\n";
                        }
                    }

                    file2.close();
                    file3.close();
                    remove("Electronics.txt");
                    rename("Electronics1.txt", "Electronics.txt");

                    // Update Clothing file
                    if (count == 0) {
                        count = 0;
                        {
                            fstream file4("Clothing.txt", ios::in);
                            fstream file5("Clothing1.txt", ios::out | ios::app);

                            if (!file4) {
                                cout << "\n\n";
                            }
                            else {


                                while (file4 >> item_idd >> item_name >> date >> quantity) {
                                    if (item_id == item_idd) {
                                        system("cls");
                                        cout << "\n\n\t\t\t\tUpdate Clothing Item Record";
                                        cout << "\n\n New Item Name : ";
                                        cin >> item_name;
                                        cout << "\n\n\t\t\tDate : ";
                                        cin >> date;
                                        cout << "\n\n Quantity : ";
                                        cin >> no_co;

                                        file5 << item_id << " " << item_name << " " << date << " " << no_co << "\n";
                                        count++;
                                    }
                                    else {
                                        file5 << item_idd << " " << item_name << " " << date << " " << quantity << "\n";
                                    }
                                }

                                file4.close();
                                file5.close();
                                remove("Clothing.txt");
                                rename("Clothing1.txt", "Clothing.txt");

                                if (count == 0) {
                                    cout << "\n\n";
                                    cout << "could not open the file" << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}



void store::remove_Item()
{
    system("cls");
    fstream file, file1;
    int quantity, count = 0;
    string item_id, item_idd, item_name, date;
    cout << "\n\n\t\t\t\tDelete Item Record";
    cout << "\n\n Item ID : ";
    cin >> item_id;
    file1.open("Clothing1.txt", ios::app | ios::out);
    file.open("Clothing.txt", ios::in);
    if (!file)
        cout << "\n\n ";
    else
    {
        file >> item_idd >> item_name >> date >> quantity;
        while (!file.eof())
        {
            if (item_id == item_idd)
            {
                system("cls");
                cout << "\n\n\t\t\t\tDelete Item Record";
                cout << "\n\n One Item is Deleted Successfully...";
                count++;
            }
            else
                file1 << " " << item_idd << " " << item_name << " " << date << " " << quantity << "\n";
            file >> item_idd >> item_name >> date >> quantity;
        }
        file.close();
        file1.close();
        remove("Clothing.txt");
        rename("Clothing1.txt", "Clothing.txt");

        if (count == 0)
            cout << "\n\n Item ID Not Found...";
    }
    count = 0;
    file1.open("Grocery1.txt", ios::app | ios::out);
    file.open("Grocery.txt", ios::in);
    if (!file)
        cout << "\n\n";
    else
    {
        file >> item_idd >> item_name >> date >> quantity;
        while (!file.eof())
        {
            if (item_id == item_idd)
            {
                system("cls");
                cout << "\n\n\t\t\t\tDelete Item Record";
                cout << "\n\n One Item is Deleted Successfully...";
                count++;
            }
            else
                file1 << " " << item_idd << " " << item_name << " " << date << " " << quantity << "\n";
            file >> item_idd >> item_name >> date >> quantity;
        }
        file.close();
        file1.close();
        remove("Grocery.txt");
        rename("Grocery1.txt", "Grocery.txt");

        if (count == 0)
            cout << "\n\n";
    }
    count = 0;
    file1.open("Electronics1.txt", ios::app | ios::out);
    file.open("Electronics.txt", ios::in);
    if (!file)
        cout << "\n\n File Openning Error...";
    else
    {
        file >> item_idd >> item_name >> date >> quantity;
        while (!file.eof())
        {
            if (item_id == item_idd)
            {
                system("cls");
                cout << "\n\n\t\t\t\tDelete Item Record";
                cout << "\n\n One Item is Deleted Successfully...";
                count++;
            }
            else
                file1 << " " << item_idd << " " << item_name << " " << date << " " << quantity << "\n";
            file >> item_idd >> item_name >> date >> quantity;
        }
        file.close();
        file1.close();
        remove("Electronics.txt");
        rename("Electronics1.txt", "Electronics.txt");
        system("pause");
        if (count == 0)
            cout << "\n\n";
    }


}

int main() {
    string customer_username;
    string customer_password;
    int store_category;
    char next_step;
    int interface = 0;
    char interface_user_manager;

    // Variables for Product management interface
    int choice;
    char x;
    store b;

    cout << endl;
    cout << "  ********* STORE MANAGEMENT SYSTEM *********" << endl;

    bool loggedIn = false;  // Flag to track if the user has logged in

    while (1) {
        cout << "Please select the Interface " << endl;
        cout << "Enter the number for respective interfaces" << endl;
        cout << endl;
        cout << "1) Product Management " << endl;
        cout << "2) Customer Interface " << endl;
        cin >> interface;

        if (interface == 1) {
        p:
            // Check if the user is already logged in
            if (!loggedIn) {
                while (1) {
                    cout << endl;
                    cout << "Please enter your USERNAME : " << endl;
                    cin >> customer_username;
                    cout << endl;
                    cout << "Please enter your PASSWORD :" << endl;
                    cin >> customer_password;

                    if (customer_username == "user" && customer_password == "abc") {
                        loggedIn = true;  // Set the flag to true after successful login
                        cout << endl;
                        cout << endl;
                        cout << endl;

                        cout << "#######__Welcome to ONLINE SHOPPING STORE__####### " << endl;
                        break;
                    }
                    else {
                        cout << endl;
                        cout << endl;

                        cout << "Your USERNAME or PASSWORD is incorrect " << endl;
                        cout << "Please Try Again " << endl;
                    }
                }
            }

            cout << endl;
            cout << endl;
            cout << endl;
            b.store_management();
            cout << "\n\n Your Choice : ";
            cin >> choice;
            switch (choice) {
                // ... Your existing code for product management
            case 1:
                do
                {
                    b.add_Item();
                    cout << "\n\n Do You Want to Add another Item (y,n) : ";
                    cin >> x;
                } while (x == 'y');
                break;
            case 2:
                b.show_Item();
                break;
            case 3:
                b.check_Item();
                break;
            case 4:
                b.update_Item();
                break;
            case 5:
                b.remove_Item();
                break;
            case 6:
                exit(0);
            default:
                cout << "\n\n Invalid Value...Please Try Again...";
            }
            goto p;
        }
        else if (interface == 2) {
            cout << endl;
            cout << endl;
            cout << endl;

            cout << "1) Grocery" << endl;
            cout << "2) Clothings" << endl;
            cout << "3) Electronic components" << endl;
            cout << endl;
            cout << endl;
            cout << "Please Enter the number of category you want to select :" << endl;
            cin >> store_category;

            // Declare instances outside the if-else block to ensure persistence
            electronics e1;
            grocery p1;
            clothing c1;

            if (store_category == 1) {
                while (1) {
                    p1.purchase();
                    // ... your existing code for handling the purchase
                    cout << endl;
                    cout << endl;
                    cout << "Please enter  -> LETTER (a) to go to products again " << endl;
                    cout << "Please enter  -> LETTER (c) to show your cart" << endl;
                    cout << "Please enter  -> LETTER (r)   to generate receipt otherwise press any other character" << endl;
                    cin >> next_step;
                    cout << endl;


                    while (1) {
                        if (next_step == 'a') {
                            p1.purchase();
                            cout << endl;
                            cout << endl;
                            cout << "Please enter  -> LETTER (a) to go to products again " << endl;
                            cout << "Please enter  -> LETTER (c) to show your cart" << endl;
                            cout << "Please enter  -> LETTER (r)   to generate receipt otherwise press any other character" << endl;
                            cin >> next_step;
                            cout << endl;
                        }
                        else if (next_step == 'c') {
                            p1.viewCart();
                            cout << endl;
                            cout << endl;
                            cout << "Please enter  -> LETTER (a) to go to products again " << endl;
                            cout << "Please enter  -> LETTER (c) to show your cart" << endl;
                            cout << "Please enter  -> LETTER (r)   to generate receipt otherwise press any other character" << endl;
                            cin >> next_step;
                            cout << endl;
                        }
                        else if (next_step == 'r') {
                            p1.generateReceipt();
                            break;
                        }
                    }
                    break;
                }
                cout << "___THANK YOU FOR SHOPPING HERE___ " << endl;
            }
            else if (store_category == 2) {
                while (1) {
                    c1.purchase();
                    // ... your existing code for handling the purchase
                    cout << endl;
                    cout << endl;
                    cout << "Please enter  -> LETTER (a) to go to products again " << endl;
                    cout << "Please enter  -> LETTER (c) to show your cart" << endl;
                    cout << "Please enter  -> LETTER (r)   to generate receipt otherwise press any other character" << endl;
                    cin >> next_step;
                    cout << endl;


                    while (1) {
                        if (next_step == 'a') {
                            c1.purchase();
                            cout << endl;
                            cout << endl;
                            cout << "Please enter  -> LETTER (a) to go to products again " << endl;
                            cout << "Please enter  -> LETTER (c) to show your cart" << endl;
                            cout << "Please enter  -> LETTER (r)   to generate receipt otherwise press any other character" << endl;
                            cin >> next_step;
                            cout << endl;
                        }
                        else if (next_step == 'c') {
                            c1.viewCart();
                            cout << endl;
                            cout << endl;
                            cout << "Please enter  -> LETTER (a) to go to products again " << endl;
                            cout << "Please enter  -> LETTER (c) to show your cart" << endl;
                            cout << "Please enter  -> LETTER (r)   to generate receipt otherwise press any other character" << endl;
                            cin >> next_step;
                            cout << endl;
                        }
                        else if (next_step == 'r') {
                            c1.generateReceipt();
                            break;
                        }
                    }
                    break;
                }
                cout << "___THANK YOU FOR SHOPPING HERE___ " << endl;
            }
            else if (store_category == 3) {
                while (1) {
                    e1.purchase();
                    // ... your existing code for handling the purchase
                    cout << endl;
                    cout << endl;
                    cout << "Please enter  -> LETTER (a) to go to products again " << endl;
                    cout << "Please enter  -> LETTER (c) to show your cart" << endl;
                    cout << "Please enter  -> LETTER (r)   to generate receipt otherwise press any other character" << endl;
                    cin >> next_step;
                    cout << endl;


                    while (1) {
                        if (next_step == 'a') {
                            e1.purchase();
                            cout << endl;
                            cout << endl;
                            cout << "Please enter  -> LETTER (a) to go to products again " << endl;
                            cout << "Please enter  -> LETTER (c) to show your cart" << endl;
                            cout << "Please enter  -> LETTER (r)   to generate receipt otherwise press any other character" << endl;
                            cin >> next_step;
                            cout << endl;
                        }
                        else if (next_step == 'c') {
                            e1.viewCart();
                            cout << endl;
                            cout << endl;
                            cout << "Please enter  -> LETTER (a) to go to products again " << endl;
                            cout << "Please enter  -> LETTER (c) to show your cart" << endl;
                            cout << "Please enter  -> LETTER (r)   to generate receipt otherwise press any other character" << endl;
                            cin >> next_step;
                            cout << endl;
                        }
                        else if (next_step == 'r') {
                            e1.generateReceipt();
                            break;
                        }
                    }
                    break;
                }
                cout << "___THANK YOU FOR SHOPPING HERE___ " << endl;
            }
            else {
                cout << "Please enter valid input " << endl;
            }
        }


        cout << endl;
        cout << endl;
        cout << "Do you want to select the interface again (y/n) ? " << endl;
        cin >> interface_user_manager;
        if (interface_user_manager == 'n') {
            break;
        }
        else if (interface_user_manager != 'y') {
            cout << endl;
            cout << "Please enter valid input" << endl;
        }
    }

    return 0;
}


