#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

string tolower(string s) {
	for (char& c : s) {
		c = tolower(c);
	}
	return s;
}
string toUpper(string s) {
	for (char& c : s) {
		c = toupper(c);
	}
	return s;
}

struct VehicalInfo {
	float TOE;
	string Vehicle, Checkpoint , RegNum;
	int violations = 0;
	int totalFine = 0;
	bool Blacklisted = false;
};

void BlacklistingVehicle(VehicalInfo& v) {
	fstream FileName;
	FileName.open("blacklist.txt", ios::app);
	if (!FileName) {
		cout << "Error File Not Found";
	}
	else {
		FileName << v.RegNum << "\tHigh Risk\n";

	}
	FileName.close();

	v.Blacklisted = true;
	cout << "Vehicle Blacklisted";

}

void VehicleEntryLogging(VehicalInfo Vehicles[], int &count) {
	string Checkpoint, type,RegNum;
	cout << "Enter the registration number of vehicle: ";
	cin >> RegNum;
	Vehicles[count].RegNum = toUpper(RegNum);
	cout << "Enter the Time of Entry for the vehicle (0.00): ";
	cin >> Vehicles[count].TOE;
	cout << "Enter the type of vehicle: ";
	cin >> type;
	Vehicles[count].Vehicle = tolower(type);
	cout << "Enter the Checkpoint of Vehicle: ";
	cin.ignore();
	getline(cin, Checkpoint);
	Vehicles[count].Checkpoint = tolower(type);

	count++;
	cout << "Vehicle Recorded Successfully !" << endl;
	
}

void RecordingTrafficViolation(VehicalInfo Vehicle[], int count) {
	string RegNum, Violation, type,temp,Reg;
	int dupli = 0;
	bool found = false;

	cout << "Enter the Vehicle Registration Number: ";
	cin >> Reg;
	RegNum = toUpper(Reg);
	cin.ignore();

	for (int i = 0; i < count; i++) {
		if (Vehicle[i].RegNum == RegNum)
			dupli++;
	}

	if (dupli == 0) {
		cout << "No such Vehicle Found";
		return;
	}

	if (dupli > 1) {
		cout << "Multiple vehicles found. Enter vehicle type: ";
		cin >> type;
		cin.ignore();
	}

	for (int i = 0; i < count; i++) {
		if (Vehicle[i].RegNum == RegNum && (dupli == 1 || Vehicle[i].Vehicle == type)) {

			found = true;

			cout << "Enter the Violation: ";
			getline(cin, temp);
			Violation = tolower(temp);

			if (Violation == "speeding") Vehicle[i].totalFine += 5000;
			else if (Violation == "red signal") Vehicle[i].totalFine += 7000;
			else if (Violation == "wrong way") Vehicle[i].totalFine += 8000;
			else Vehicle[i].totalFine += 2000;

			Vehicle[i].violations++;

			cout << "Total Fine: " << Vehicle[i].totalFine << endl;
			cout << "Total Violations: " << Vehicle[i].violations << endl;

			if (Vehicle[i].violations >= 3 && !Vehicle[i].Blacklisted)
				BlacklistingVehicle(Vehicle[i]);

			break;
		}
	}
}


void VehicleSearch(VehicalInfo vehicle[], int &count) {
	string regnum,reg;
	bool found = false;
	cout << "Enter the Vehicle's registeration Number: ";
	cin >> reg;
	regnum = toUpper(reg);

	for (int i = 0; i < count; i++) {
		if (vehicle[i].RegNum == regnum) {
			found = true;
			cout <<"The time of Entry for the Vehicle is: " << vehicle[i].TOE << endl;
			cout << "The type of Vehicle is : " << vehicle[i].Vehicle << endl;
			cout << "The Number of Violations the Vehicle has Performed is: " << vehicle[i].violations << endl;
			cout << "Total Fine the vehicle has: " << vehicle[i].totalFine << endl;
			if (vehicle[i].Blacklisted == true) {
				cout << "The vehicle is blacklisted" << endl;
			}
			else {
				cout << "The vehicle is clear" << endl;
			}
		}
	}
	if (found == false) {
		cout << "No such Vehicle in the record" << endl;
	}
}

void DisplayOffenders(VehicalInfo vehicle[], int count) {
	int totalviolations = 0;
	int Car = 0;
	int Bus = 0;
	int Bike = 0;
	int Truck = 0;

	cout << "\n--------- Offending Vehicle--------\n";
	for (int i = 0; i < count; i++) {
		if (vehicle[i].violations > 0) {
			cout << "Registeration Number: " << vehicle[i].RegNum << endl;
			cout << "Vehicle Type: " << vehicle[i].Vehicle << endl;
			cout << "Violations Performed: " << vehicle[i].violations << endl;
			cout << "Fine on Vehicle: " << vehicle[i].totalFine << endl;
			if (vehicle[i].Blacklisted == true) {
				cout << "Is the vehicle blacklisted?: " << "Yes" << endl;
			}
			else {
				cout << "Is the vehicle blacklisted?: " << "No" << endl;
			}

			totalviolations += vehicle[i].violations;

			if (vehicle[i].Vehicle == "car") {
				Car += 1;
			}
			else if (vehicle[i].Vehicle == "bus") {
				Bus += 1;
			}
			else if (vehicle[i].Vehicle == "truck") {
				Truck += 1;
			}
			else {
				Bike += 1;
			}

			
		}
		
	}

	cout << "Total Violations for today: " << totalviolations << endl;
	cout << "Vehicle Type Analysis:\n";
	cout << "Cars: " << Car << endl;
	cout << "Bikes: " << Bike << endl;
	cout << "Buses: " << Bus << endl;
	cout << "Trucks: " << Truck << endl;

}

int main() {
	int choice;
	VehicalInfo vehicles[100];
	int totalVehicles = 0;
	do {
		cout << "\n============== Welcome to Safe City Project =================\n";
		cout << "1. Enter Vehicle Information\n";
		cout << "2. Record Vehicle's Violation\n";
		cout << "3. Search for Vehicle\n";
		cout << "4. Display all Offenders\n";
		cout << "Enter 0 to exit\n";

		do {
			cout << "What do you want to perform: ";
			cin >> choice;

			if (choice < 0 || choice > 4) {
				cout << "Invalid choice! Enter a number between 0 and 4.\n";
			}

		} while (choice < 0 || choice > 4);

		switch (choice) {
		case 1:
			VehicleEntryLogging(vehicles, totalVehicles);
			break;
		case 2:
			RecordingTrafficViolation(vehicles, totalVehicles);
			break;
		case 3:
			VehicleSearch(vehicles, totalVehicles);
			break;
		case 4:
			DisplayOffenders(vehicles, totalVehicles);
			break;
		}

	} while (choice != 0);

	
	return 0;

}

	

