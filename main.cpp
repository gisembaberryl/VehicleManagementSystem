#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <limits>

using namespace std;

// Global variable
string companyName = "SuperVehicles Ltd Solutions";

// Base class
class Vehicle {
protected:
    string brand;
    string model;
    static int count;

public:
    Vehicle(string b, string m) : brand(b), model(m) {
        count++;
    }

    virtual void displayInfo() {
        cout << "Brand: " << brand << ", Model: " << model << endl;
    }

    void updateModel() {
        string newModel;
        cout << "Enter new model for " << brand << ": ";
        cin >> newModel; // Local variable
        model = newModel;
    }

    static int getCount() {
        return count;
    }

    virtual string getDetails() {
        return brand + " " + model;
    }

    virtual ~Vehicle() {}
};

int Vehicle::count = 0;

// Derived class: Car
class Car : public Vehicle {
private:
    int seats;

public:
    Car(string b, string m, int s) : Vehicle(b, m) {
        if (s < 0) throw invalid_argument("Seats cannot be negative.");
        seats = s;
    }

    void displayInfo() override {
        cout << "[Car] Brand: " << brand << ", Model: " << model << ", Seats: " << seats << endl;
    }

    string getDetails() override {
        return "Car: " + brand + " " + model + " Seats: " + to_string(seats);
    }
};

// Derived class: Motorbike
class Motorbike : public Vehicle {
private:
    int engineCapacity;

public:
    Motorbike(string b, string m, int ec) : Vehicle(b, m) {
        if (ec < 0) throw invalid_argument("Engine capacity cannot be negative.");
        engineCapacity = ec;
    }

    void displayInfo() override {
        cout << "[Motorbike] Brand: " << brand << ", Model: " << model 
             << ", Engine Capacity: " << engineCapacity << "cc" << endl;
    }

    string getDetails() override {
        return "Motorbike: " + brand + " " + model + " Engine: " + to_string(engineCapacity) + "cc";
    }
};

// Helper function: Save vehicles automatically
void saveVehicles(const vector<Vehicle*>& vehicles) {
    ofstream outFile("vehicles.txt");
    if (outFile.is_open()) {
        for (Vehicle* v : vehicles) {
            outFile << v->getDetails() << endl;
        }
        outFile.close();
        cout << "Vehicles saved to vehicles.txt\n";
    }
}

// Helper function: Pause before returning to menu
void pauseForMenu() {
    int back;
    cout << "\nEnter 1 to go back to Main Menu: ";
    cin >> back;
}

int main() {
    cout << "Welcome to " << companyName << "'s Vehicle Management System\n" << endl;

    vector<Vehicle*> vehicles;

    // Pre-populate with 3 cars and 3 motorbikes
    try {
        vehicles.push_back(new Car("Toyota", "Corolla", 5));
        vehicles.push_back(new Car("Honda", "Civic", 4));
        vehicles.push_back(new Car("Mazda", "CX-5", 7));

        vehicles.push_back(new Motorbike("Yamaha", "R15", 150));
        vehicles.push_back(new Motorbike("Suzuki", "GSX", 250));
        vehicles.push_back(new Motorbike("Kawasaki", "Ninja", 400));
    } catch (const exception& e) {
        cerr << "Error creating vehicle: " << e.what() << endl;
    }

    saveVehicles(vehicles); // initial save

    int choice;
    do {
        cout << "\n--- Vehicle Management Menu ---\n";
        cout << "1. Add Car\n";
        cout << "2. Add Motorbike\n";
        cout << "3. Display All Vehicles\n";
        cout << "4. Update Vehicle Model\n";
        cout << "5. Save Vehicles to File\n";
        cout << "6. Read Vehicles from File\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
    string brand, model;
    int seats;
    cout << "Enter brand, model, seats: ";
    cin >> brand >> model >> seats;

    // Flush leftover newline
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    try {
        vehicles.push_back(new Car(brand, model, seats));
        cout << "Car added successfully!\n";
        saveVehicles(vehicles); // optional auto-save
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Pause before returning to menu
    cout << "Press Enter to return to the main menu...";
    cin.get();
    break;
}


            case 2: {
    string brand, model;
    int engineCapacity;
    cout << "Enter brand, model, engine capacity: ";
    cin >> brand >> model >> engineCapacity;

    // Clear leftover newline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    try {
        vehicles.push_back(new Motorbike(brand, model, engineCapacity));
        cout << "Motorbike added successfully!\n";
        saveVehicles(vehicles); // if auto-save is active
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Pause before returning to menu
    cout << "Press Enter to return to the main menu...";
    cin.get();
    break;
}

            case 3:
                cout << "\n--- Vehicle Details ---\n";
                for (Vehicle* v : vehicles) {
                    v->displayInfo();
                }
                cout << "Total Vehicles: " << Vehicle::getCount() << endl;
                pauseForMenu();
                break;
 case 4: {
    if (vehicles.empty()) {
        cout << "No vehicles available to update.\n";
    } else {
        cout << "\n--- Vehicles Available for Update ---\n";
        for (int i = 0; i < vehicles.size(); ++i) {
            cout << "[" << i << "] ";
            vehicles[i]->displayInfo();
        }

        int index;
        cout << "Enter vehicle index to update: ";
        cin >> index;

        // Flush leftover newline
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (index >= 0 && index < vehicles.size()) {
            vehicles[index]->updateModel();
            cout << "Model updated!\n";
            saveVehicles(vehicles);
        } else {
            cout << "Invalid index.\n";
        }
    }

    // Pause before returning to menu
    cout << "Press Enter to return to the main menu...";
    cin.get();
    break;
}


            case 5:
                saveVehicles(vehicles);
                pauseForMenu();
                break;
            case 6: {
                cout << "\n--- Reading from File ---\n";
                ifstream inFile("vehicles.txt");
                string line;
                if (!inFile.is_open()) {
                    cout << "No saved vehicles found.\n";
                } else {
                    while (getline(inFile, line)) {
                        cout << line << endl;
                    }
                    inFile.close();
                }
                pauseForMenu();
                break;
            }
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 0);

    // Cleanup
    for (Vehicle* v : vehicles) {
        delete v;
    }

    return 0;
}
