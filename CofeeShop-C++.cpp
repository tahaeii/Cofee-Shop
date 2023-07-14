#include <iostream>
#include <string>

using namespace std;


struct Order {
    string orderName;
    double orderPrice;
};

struct Customer {
    string customerName;
    string customerNumber;
    string date;
};


class CoffeeShop {
private:
    static const int cDrinkX = 3;

    string cDrink[cDrinkX];
    double cDrinkPrices[cDrinkX];

    int cDrinkCount;

    static const int hDrinkX = 3;

    string hDrink[hDrinkX];
    double hDrinkPrices[hDrinkX];

    int hDrinkCount;

    static const int foodsX = 3;

    string foods[foodsX];
    double fPrices[foodsX];

    int fCount;

    static const int customerX = 10;

    Customer customers[customerX];
    int customerCount;

    double dailyTotal;

public:
    CoffeeShop() {
        cDrinkCount = 0;
        hDrinkCount = 0;
        fCount = 0;
        customerCount = 0;
        dailyTotal = 0.0;
    }


    void addColdDrink(string name, double price) {
        if (cDrinkCount < cDrinkX) {
            cDrink[cDrinkCount] = name;
            cDrinkPrices[cDrinkCount] = price;
            cDrinkCount++;
        }
    }

    void addHotDrink(string name, double price) {
        if (hDrinkCount < hDrinkX) {
            hDrink[hDrinkCount] = name;
            hDrinkPrices[hDrinkCount] = price;
            hDrinkCount++;
        }
    }

    void addFood(string name, double price) {
        if (fCount < foodsX) {
            foods[fCount] = name;
            fPrices[fCount] = price;
            fCount++;
        }
    }

    void printOrders(Order *orders, int count) {
        cout << "Your Order :" << endl;
        for (int i = 0; i < count; i++) {
            cout << orders[i].orderName << " - " << orders[i].orderPrice << " $" << endl;
        }
    }

    void showMenu() {
        cout << endl << " ~ Cold Drinks !" << "\n";
        for (int i = 0; i < cDrinkCount; i++) {
            cout << "\t" << cDrink[i] << " - " << cDrinkPrices[i] << " $" << endl;
        }

        cout << endl << " ~ Hot Drinks !" << "\n";
        for (int i = 0; i < hDrinkCount; i++) {
            cout << "\t" << hDrink[i] << " - " << hDrinkPrices[i] << " $" << endl;
        }

        cout << endl << " ~ Foods !" << "\n";
        for (int i = 0; i < fCount; i++) {
            cout << "\t" << foods[i] << " - " << fPrices[i] << " $" << endl;
        }
    }

    void takeOrder() {
        string order;
        double total = 0.0;
        int orderCount = 0;
        Order *orders = new Order[cDrinkX + hDrinkX + foodsX];

        cout << endl << "Write 'Finish' to end your order !" << endl;
        cout << "Now, Write Ur Order ! " << endl << endl;

        while (true) {
            cout << "Any Thing You Need ? " << endl;
            getline(cin, order);

            if (order == "finish") {
                break;
            }

            bool found = false;


            for (int i = 0; i < cDrinkCount; i++) {
                if (cDrink[i] == order) {
                    orders[orderCount].orderName = cDrink[i];
                    orders[orderCount].orderPrice = cDrinkPrices[i];
                    total += cDrinkPrices[i];
                    orderCount++;
                    found = true;
                    break;
                }
            }

            if (found) {
                total += orders[orderCount].orderPrice;
                continue;
            }


            for (int i = 0; i < hDrinkCount; i++) {
                if (hDrink[i] == order) {
                    orders[orderCount].orderName = hDrink[i];
                    orders[orderCount].orderPrice = hDrinkPrices[i];
                    total += hDrinkPrices[i];
                    orderCount++;
                    found = true;
                    break;
                }
                
            }


            if (found) {
                continue;
            }


            for (int i = 0; i < fCount; i++) {
                if (foods[i] == order) {
                    orders[orderCount].orderName = foods[i];
                    orders[orderCount].orderPrice = fPrices[i];
                    total += fPrices[i];
                    orderCount++;
                    found = true;
                    break;
                }
            }

            if (found) {
                dailyTotal += total;
                continue;
            }

            if (!found) {
                cout << "Wrong !" << endl;
            }
        }

        cout << "Total Price: " << total << " $" << endl;


        printOrders(orders, orderCount);


        takeCustomerInformation();

        delete[] orders;
    }


    void takeCustomerInformation() {
        if (customerCount >= customerX) {
            cout << "eeeee" << endl;
            return;
        } else {
            Customer customer;
            cout << "Enter customer orderName: ";
            getline(cin, customer.customerName);
            cout << "Enter customer phone number: ";
            getline(cin, customer.customerNumber);
            cout << "Enter date: ";
            getline(cin, customer.date);

            customers[customerCount] = customer;
            customerCount++;
        }

    }

    void showCustomers() {
        cout << "Customers' Information:" << endl;
        for (int i = 0; i < customerCount; i++) {
            cout << "Customer " << (i + 1) << ":" << endl;
            cout << "Name: " << customers[i].customerName << endl;
            cout << "Your Number: " << customers[i].customerNumber << endl;
            cout << "Date: " << customers[i].date << endl;
            cout << endl;
        }
    }


    void daily() {
        cout << "Daily Total : " << dailyTotal << " $" << endl;
    }
};

int main() {
    CoffeeShop coffeeShop;


    coffeeShop.addColdDrink("Cola", 10.0);
    coffeeShop.addColdDrink("Lemonade", 15.0);
    coffeeShop.addColdDrink("Cold Milk", 8.0);


    coffeeShop.addHotDrink("Coffee", 20.0);
    coffeeShop.addHotDrink("Cappuccino", 12.0);
    coffeeShop.addHotDrink("Tea", 25.0);


    coffeeShop.addFood("Pizza", 30.0);
    coffeeShop.addFood("Cheeseburger", 40.0);
    coffeeShop.addFood("Sushi", 35.0);


    coffeeShop.showMenu();


    while (true) {

        coffeeShop.takeOrder();


        coffeeShop.showCustomers();

        string option;
        cout << "Do you want to take another order? (yes/no): ";
        getline(cin, option);
        if (option != "yes") {
            break;
        }
    }
    coffeeShop.daily();

    return 0;
}