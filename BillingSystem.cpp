#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class Bill{
    private:
        string name;
        string address;
        string phone;
        string email;
        string productName;
        int quantity;
        double pricePerUnit;
        double totalPrice;

    public:
        void setCustomerDetails(string n, string a, string p, string e){
            name = n;
            address = a;
            phone = p;
            email = e;
        }

        void setProductDetails(string pn, int q, double ppu){
            productName = pn;
            quantity = q;
            pricePerUnit = ppu;
            totalPrice = quantity * pricePerUnit;
        }

        void generateBill(){
            ofstream billFile("bill.txt");
            billFile << "Customer Name: " << name << endl;
            billFile << "Address: " << address << endl;
            billFile << "Phone: " << phone << endl;
            billFile << "Email: " << email << endl;
            billFile << "Product Name: " << productName << endl;
            billFile << "Quantity: " << quantity << endl;
            billFile << "Price per Unit: $" << pricePerUnit << endl;
            billFile << "Total Price: $" << totalPrice << endl;
            billFile.close();
        }
        void displayBill(){
            ifstream billFile("bill.txt");
            string line;
            while(getline(billFile, line)){
                cout << line << endl;
            }
            billFile.close();
        }

};

int main(){
    Bill bill;
    string name, address, phone, email, productName;    
    int quantity;
    double pricePerUnit;
    double totalPrice;
    bill.setCustomerDetails("John Doe", "123 Main St", "555-1234", "john@123gmail.com");
    bill.setProductDetails("Laptop", 2, 799.99);
    bill.generateBill();
    bill.displayBill();
    // Open the bill file and print its contents to the console
    ifstream billFile("bill.txt");
    if (billFile.is_open()) {
        string line;
        while (getline(billFile, line)) {
            cout << line << endl;
        }
        billFile.close();
    } else {
        cout << "Unable to open bill file." << endl;
    }
    // Wait for user input before closing the console window
    cout << "Press Enter to exit..." << endl;
    cin.ignore();
    cin.get();
    // Close the console window
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE); // Hide the console window
    // Alternatively, you can use the following line to close the console window
    // PostMessage(hwnd, WM_CLOSE, 0, 0); // Close the console window
    // Note: The above line will close the console window immediately, without waiting for user input.
    // Uncomment the line you prefer to use.
    // ShowWindow(hwnd, SW_HIDE); // Hide the console window
    // PostMessage(hwnd, WM_CLOSE, 0, 0); // Close the console window
    // Note: The above line will close the console window immediately, without waiting for user input.
    // ShowWindow(hwnd, SW_HIDE); // Hide the console window
    // PostMessage(hwnd, WM_CLOSE, 0, 0); // Close the console window
    // Note: The above line will close the console window immediately, without waiting for user input.

    return 0;
}