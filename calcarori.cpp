#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Function prototypes
void printMenu();
void calculateCarHorsepower();
void calculateCarCC();
void calculateCarBatteryPerformance();
void calculateOilConsumption();
void displayFunFact();
double calculateHorsepower(double& torque, double& rpm);
double calculateElectricHorsepower(double& watts);
double calculateCC(int& numCylinders, double& cylinderRadius, double& cylinderHeight);
void checkBatteryPerformance(double& battery);
void calculateFuelConsumptionRate(float& fuelConsumed, float& distanceDriven);
void displayErrorMessage();

int main() {
    int choice;

    do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            calculateCarHorsepower();
            break;

        case 2:
            calculateCarCC();
            break;

        case 3:
            calculateCarBatteryPerformance();
            break;

        case 4:
            calculateOilConsumption();
            break;

        case 5:
            displayFunFact();
            break;

        case 6:
            cout << "Exiting the program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 6);

    return 0;
}

void printMenu() {
    cout << "\nCar Information Program\n";
    cout << "1. Calculate Car's Horsepower\n";
    cout << "2. Calculate Car's CC\n";
    cout << "3. Calculate Car's Battery Performance\n";
    cout << "4. Calculate Oil Consumption\n";
    cout << "5. Random Fun Fact about Car's Maintenance\n";
    cout << "6. Exit\n";
}

void calculateCarHorsepower() {
    int engineType;
    double torque, rpm, watts;

    do {
        cout << "Enter engine type (1 for combustion, 2 for electric): ";
        cin >> engineType;

    } while (engineType != 1 && engineType != 2);

    double horsepower;
    if (engineType == 1) {
        do {
            cout << "Enter engine torque (in lb-ft): ";
            cin >> torque;

        } while (torque < 0);

        do {
            cout << "Enter engine rpm: ";
            cin >> rpm;

        } while (rpm < 0);

        horsepower = calculateHorsepower(torque, rpm);
        cout << "Car's Horsepower: " << horsepower << " HP" << endl;
    }
    else {
        cout << "Electric cars do not have engine cylinders. Skipping horsepower calculation.\n";

        do {
            cout << "Enter electric motor power (in watts): ";
            cin >> watts;

        } while (watts < 0);

        horsepower = calculateElectricHorsepower(watts);
        cout << "Electric Car's Horsepower: " << horsepower << " HP" << endl;
    }
}

void calculateCarCC() {
    int numCylinders;
    double cylinderRadius, cylinderHeight;

    do {
        cout << "Enter number of cylinders: ";
        cin >> numCylinders;

    } while (numCylinders <= 0);

    do {
        cout << "Enter cylinder radius (in inches): ";
        cin >> cylinderRadius;

    } while (cylinderRadius <= 0);

    do {
        cout << "Enter cylinder height (in inches): ";
        cin >> cylinderHeight;

    } while (cylinderHeight <= 0);

    double cc = calculateCC(numCylinders, cylinderRadius, cylinderHeight);
    cout << "Car's CC: " << cc << " cc" << endl;
}

void calculateCarBatteryPerformance() {
    double battery;

    do {
        cout << "Enter car's battery performance (in percentage): ";
        cin >> battery;

    } while (battery < 0 || battery > 100);

    checkBatteryPerformance(battery);
}

void calculateOilConsumption() {
    int engineType;
    float fuelConsumed, distanceDriven;

    do {
        cout << "Enter engine type (1 for combustion, 2 for electric): ";
        cin >> engineType;

    } while (engineType != 1 && engineType != 2);

    if (engineType == 1) {
        do {
            cout << "Enter amount of fuel consumed (in litres): ";
            cin >> fuelConsumed;

        } while (fuelConsumed < 0);

        do {
            cout << "Enter distance driven (in kilometres): ";
            cin >> distanceDriven;

        } while (distanceDriven < 0);

        calculateFuelConsumptionRate(fuelConsumed, distanceDriven);
    }
    else {
        cout << "Electric cars do not consume oil. Skipping fuel-related calculations.\n";
    }
}

void displayFunFact() {
    cout << "Fun Fact: Regular maintenance checks can significantly extend the lifespan of your car!" << endl;
}

double calculateHorsepower(double& torque, double& rpm) {
    return (torque * rpm) / 5252;
}

double calculateElectricHorsepower(double& watts) {
    return watts / 746;
}

double calculateCC(int& numCylinders, double& cylinderRadius, double& cylinderHeight) {
    double engineVolume = numCylinders * 3.14159265359 * pow(cylinderRadius, 2) * cylinderHeight;
    return engineVolume * 16.3871;
}

void checkBatteryPerformance(double& battery) {
    (battery < 30) ? cout << "Car's battery needs to be changed!" << endl :
        cout << "Car's battery is in good condition." << endl;
}

void calculateFuelConsumptionRate(float& fuelConsumed, float& distanceDriven) {
    if (distanceDriven == 0) {
        displayErrorMessage();
    }
    else {
        float fuelConsumptionRate = (fuelConsumed / distanceDriven) * 100;
        cout << "Oil consumption rate: " << fuelConsumptionRate << " L/100km" << endl;
    }
}

void displayErrorMessage() {
    cout << "Error: Distance driven cannot be zero." << endl;
}