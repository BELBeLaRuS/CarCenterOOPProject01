#include <iostream> 
#include <string>
using namespace std;

class Car {
public:
    string brand;
    string model;
    int price;

    Car(string b, string m, int p) : brand(b), model(m), price(p) {}
};

class AutoSalon {
public:
    string type;
    Car cars[3];
    int count = 0;

    AutoSalon(string t) : type(t) {}

    void addCar(const Car& car) {
        if (count < 3) {
            cars[count++] = car;
        }
        else {
            cout << "Cannot add more cars to the salon." << endl;
        }
    }

    void displayCars() {
        cout << "---------" << type << "---------" << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << cars[i].brand << " " << cars[i].model << " - $" << cars[i].price << endl;
        }
    }
};

int main() {

    AutoSalon salon1("Budget");
    salon1.addCar(Car("Toyota", "Corolla", 10000));
    salon1.addCar(Car("Honda", "Civic", 12000));
    salon1.addCar(Car("Nissan", "Sentra", 11000));

    AutoSalon salon2("Mid-range");
    salon2.addCar(Car("Ford", "Fusion", 20000));
    salon2.addCar(Car("Chevrolet", "Malibu", 22000));
    salon2.addCar(Car("Hyundai", "Sonata", 19000));

    AutoSalon salon3("Luxury");
    salon3.addCar(Car("Mercedes-Benz", "E-Class", 50000));
    salon3.addCar(Car("BMW", "5 Series", 48000));
    salon3.addCar(Car("Audi", "A6", 52000));

    AutoSalon salons[] = { salon1, salon2, salon3 };

    int balance = 30000;
    int choice;

    while (true) {
        cout << "Welcome to the Auto Salons!" << endl;
        cout << "Your current balance: $" << balance << endl;

        cout << "Select an Auto Salon to visit:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << salons[i].type << endl;
        }

        cin >> choice;

        if (choice < 1 || choice > 3) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        cout << "You have selected " << salons[choice - 1].type << " Auto Salon." << endl;
        salons[choice - 1].displayCars();

        int carChoice;
        cout << "Select a car to purchase (enter 0 to go back): ";
        cin >> carChoice;

        if (carChoice == 0) {
            continue;
        }

        if (carChoice < 1 || carChoice > salons[choice - 1].count) {
            cout << "Invalid car choice. Please try again." << endl;
            continue;
        }

        if (balance < salons[choice - 1].cars[carChoice - 1].price) {
            cout << "Insufficient balance. Please select another car or add funds." << endl;
            continue;
        }

        balance -= salons[choice - 1].cars[carChoice - 1].price;
        cout << "Congratulations! You have purchased " << salons[choice - 1].cars[carChoice - 1].brand << " " << salons[choice - 1].cars[carChoice - 1].model << "!" << endl;
        cout << "Remaining balance: $" << balance << endl;

        char option;
        cout << "Do you want to visit another Auto Salon? (y/n): ";
        cin >> option;

        if (option == 'n') {
            cout << "Thank you for visiting the Auto Salons. Have a great day!" << endl;
            break;
        }
    }

    return 0;
}
