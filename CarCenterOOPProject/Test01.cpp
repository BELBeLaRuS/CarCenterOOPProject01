#include <iostream> 
#include <string> 
using namespace std;

class Car {
public: string make; string model; int price;


      Car(string _make, string _model, int _price) {
          make = _make;
          model = _model;
          price = _price;
      }
};

class CarDealer {
public: 
    string name;
      Car cars[3];


      CarDealer(string _name, Car _car1, Car _car2, Car _car3) {          // тут ошибку выдает 
          name = _name;                                                   //
          cars[0] = _car1;                                                //
          cars[1] = _car2;                                                //
          cars[2] = _car3;                                                //
      }                                                                   //
};                                                                        //

int main() {
    Car car1("Toyota", "Corolla", 20000); 
    Car car2("Honda", "Civic", 25000); 
    Car car3("Ford", "Focus", 18000);


    CarDealer dealer1("Affordable Cars", car1, car2, car3);

    Car car4("Mercedes", "C-Class", 40000);
    Car car5("BMW", "3 Series", 35000);
    Car car6("Audi", "A4", 30000);

    CarDealer dealer2("Luxury Cars", car4, car5, car6);

    Car car7("Chevrolet", "Spark", 15000);
    Car car8("Hyundai", "Elantra", 17000);
    Car car9("Kia", "Forte", 16000);

    CarDealer dealer3("Budget Cars", car7, car8, car9);

    CarDealer* currentDealer = &dealer1;
    int balance = 30000;

    cout << "Welcome to the Car Dealership!" << endl;
    cout << "You currently have $" << balance << endl;

    while (true) {
        cout << "Choose a dealership to visit:" << endl;
        cout << "1. Affordable Cars" << endl;
        cout << "2. Luxury Cars" << endl;
        cout << "3. Budget Cars" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            currentDealer = &dealer1;
        }
        else if (choice == 2) {
            currentDealer = &dealer2;
        }
        else if (choice == 3) {
            currentDealer = &dealer3;
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        while (true) {
            cout << "Choose a car to buy:" << endl;
            for (int i = 0; i < 3; i++) {
                cout << i + 1 << ". " << currentDealer->cars[i].make << " " << currentDealer->cars[i].model << " - $" << currentDealer->cars[i].price << endl;
            }
            cout << "4. Go back" << endl;

            cin >> choice;

            if (choice == 4) {
                break;
            }
            else if (choice >= 1 && choice <= 3) {
                if (currentDealer->cars[choice - 1].price > balance) {
                    cout << "You don't have enough money to buy this car." << endl;
                }
                else {
                    balance -= currentDealer->cars[choice - 1].price;
                    cout << "Congratulations! You bought a " << currentDealer->cars[choice - 1].make << " " << currentDealer->cars[choice - 1].model << "." << endl;
                    cout << "You now have $" << balance << " remaining." << endl;
                }
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    cout << "Thank you for visiting the Car Dealership. Goodbye!" << endl;

    return 0;
}