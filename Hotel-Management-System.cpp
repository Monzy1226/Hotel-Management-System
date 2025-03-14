#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Guest {
public:
    string name;
    int age;
    string roomType;
    int roomNumber;

    Guest(string n, int a, string rType, int rNumber) 
        : name(n), age(a), roomType(rType), roomNumber(rNumber) {}
};

class Hotel {
private:
    vector<Guest> guests;
    int totalRooms;
    int availableRooms;

public:
    Hotel(int total) : totalRooms(total), availableRooms(total) {}

    void addGuest() {
        if (availableRooms == 0) {
            cout << "No rooms available!" << endl;
            return;
        }

        string name;
        int age;
        string roomType;
        int roomNumber;

        cout << "Enter guest name: ";
        cin >> name;
        cout << "Enter guest age: ";
        cin >> age;
        cout << "Enter room type (Single/Double): ";
        cin >> roomType;
        cout << "Enter room number: ";
        cin >> roomNumber;

        guests.push_back(Guest(name, age, roomType, roomNumber));
        availableRooms--;
        cout << "Guest added successfully!" << endl;
    }

    void displayGuests() {
        if (guests.empty()) {
            cout << "No guests currently." << endl;
            return;
        }

        cout << "Current Guests:" << endl;
        for (const auto& guest : guests) {
            cout << "Name: " << guest.name 
                 << ", Age: " << guest.age 
                 << ", Room Type: " << guest.roomType 
                 << ", Room Number: " << guest.roomNumber << endl;
        }
    }

    void displayAvailableRooms() {
        cout << "Total Rooms: " << totalRooms << endl;
        cout << "Available Rooms: " << availableRooms << endl;
    }

    void removeGuest() {
        if (guests.empty()) {
            cout << "No guests to remove." << endl;
            return;
        }

        string name;
        cout << "Enter guest name to remove: ";
        cin >> name;

        for (auto it = guests.begin(); it != guests.end(); ++it) {
            if (it->name == name) {
                guests.erase(it);
                availableRooms++;
                cout << "Guest removed successfully!" << endl;
                return;
            }
        }
        cout << "Guest not found!" << endl;
    }
};

int main() {
    int totalRooms;
    cout << "Enter total number of rooms in the hotel: ";
    cin >> totalRooms;

    Hotel hotel(totalRooms);
    int choice;

    do {
        cout << "\nHotel Management System" << endl;
        cout << "1. Add Guest" << endl;
        cout << "2. Display Guests" << endl;
        cout << "3. Display Available Rooms" << endl;
        cout << "4. Remove Guest" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.addGuest();
                break;
            case 2:
                hotel.displayGuests();
                break;
            case 3:
                hotel.displayAvailableRooms();
                break;
            case 4:
                hotel.removeGuest();
                break;
            case 5:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
