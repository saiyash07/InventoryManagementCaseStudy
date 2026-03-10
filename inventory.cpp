#include <iostream>
using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    float price;
};

int main() {

    Product inventory[100];   
    int count = 0;            
    int choice;
//i have used do while loop to make sure that the menu is displayed at least once and continues until the user chooses to exit by entering 4. 
    do {

        cout << "\n===== Inventory Management System =====\n                       By Saiyash Poojari\n";
        cout << "1. Add Product\n";
        cout << "2. Update Stock\n";
        cout << "3. View Inventory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1:

            cout << "\nEnter Product ID: ";
            cin >> inventory[count].id;

            cout << "Enter Product Name: ";
            cin >> inventory[count].name;

            cout << "Enter Quantity: ";
            cin >> inventory[count].quantity;

            cout << "Enter Price of Single Item: ";
            cin >> inventory[count].price;

            count++;

            cout << "Product Added Successfully!\n";
            break;

        case 2:
        {
            int searchID;
            cout << "\nEnter Product ID to update stock: ";
            cin >> searchID;

            bool found = false;

            for(int i = 0; i < count; i++) {

                if(inventory[i].id == searchID) {

                    int addQty;

                    cout << "Enter quantity to add: ";
                    cin >> addQty;

                    inventory[i].quantity += addQty;

                    cout << "Stock Updated Successfully!\n";
                    cout << "Current Quantity: " << inventory[i].quantity << endl;

                    found = true;
                    break;
                }
            }

            if(!found) {
                cout << "Product not found!\n";
            }

            break;
        }

        case 3:
        {
            cout << "\n===== Inventory Report =====\n";

            float totalInventoryValue = 0;

            if(count == 0) {
                cout << "No products available.\n";
            }
            else {

                for(int i = 0; i < count; i++) {

                    float productValue = inventory[i].quantity * inventory[i].price;

                    cout << "\nProduct ID: " << inventory[i].id;
                    cout << "\nName: " << inventory[i].name;
                    cout << "\nQuantity: " << inventory[i].quantity;
                    cout << "\nPrice: " << inventory[i].price;
                    cout << "\nTotal Value: " << productValue;
                    cout << "\n----------------------";

                    totalInventoryValue += productValue;
                }

                cout << "\n\nTotal Inventory Value: " << totalInventoryValue << endl;
            }

            break;
        }

        case 4:
        cout << "Exiting Program...\nPROGRAM TERMINATED SUCCESSFULLY!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}