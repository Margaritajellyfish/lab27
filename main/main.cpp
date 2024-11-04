#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <string>
using namespace std;

void addVillager(map<string, tuple<int, string, string>> &villagers) {
    string name, species, description;
    int friendshipLevel;

    cout << "Enter villager name: ";
    cin.ignore(); // To clear any leftover newline
    getline(cin, name);
    cout << "Enter friendship level (integer): ";
    cin >> friendshipLevel;
    cout << "Enter species: ";
    cin.ignore();
    getline(cin, species);
    cout << "Enter description: ";
    getline(cin, description);

    villagers.insert(make_pair(name, make_tuple(friendshipLevel, species, description)));
    cout << "Villager added successfully.\n";
}

void deleteVillager(map<string, tuple<int, string, string>> &villagers) {
    string name;
    cout << "Enter villager name to delete: ";
    cin.ignore();
    getline(cin, name);

    if (villagers.erase(name)) {
        cout << "Villager deleted successfully.\n";
    } else {
        cout << "Villager not found.\n";
    }
}

void adjustFriendship(map<string, tuple<int, string, string>> &villagers, const string &operation) {
    string name;
    cout << "Enter villager name to " << operation << " friendship: ";
    cin.ignore();
    getline(cin, name);

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        if (operation == "increase") {
            get<0>(it->second)++;
            cout << "Friendship level increased for " << name << ".\n";
        } else if (operation == "decrease") {
            if (get<0>(it->second) > 0) {
                get<0>(it->second)--;
                cout << "Friendship level decreased for " << name << ".\n";
            } else {
                cout << "Friendship level cannot be decreased below zero for " << name << ".\n";
            }
        }
    } else {
        cout << "Villager not found.\n";
    }
}

void searchVillager(const map<string, tuple<int, string, string>> &villagers) {
    string name;
    cout << "Enter villager name to search: ";
    cin.ignore();
    getline(cin, name);

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        int friendshipLevel = get<0>(it->second);
        string species = get<1>(it->second);
        string description = get<2>(it->second);

        cout << "Villager: " << name << "\nFriendship Level: " << friendshipLevel
             << "\nSpecies: " << species << "\nDescription: " << description << endl;
    } else {
        cout << "Villager not found.\n";
    }
}

void displayAllVillagers(const map<string, tuple<int, string, string>> &villagers) {
    cout << "\nAll Villagers:\n";
    if (villagers.empty()) {
        cout << "No villagers to display.\n";
    } else {
        for (const auto &villager : villagers) {
            string name = villager.first;
            int friendshipLevel = get<0>(villager.second);
            string species = get<1>(villager.second);
            string description = get<2>(villager.second);

            cout << name << " [Friendship Level: " << friendshipLevel
                 << ", Species: " << species
                 << ", Description: " << description << "]" << endl;
        }
    }
}

int main() {
    map<string, tuple<int, string, string>> villagerList;

    villagerList["Audie"] = make_tuple(8, "Alligator", "Got a snack?");
    villagerList["Raymond"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagerList.insert(make_pair("Marshal", make_tuple(8, "Cat", "Nice fit")));

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Villager\n";
        cout << "2. Delete Villager\n";
        cout << "3. Increase Friendship\n";
        cout << "4. Decrease Friendship\n";
        cout << "5. Search for Villager\n";
        cout << "6. Display All Villagers\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addVillager(villagerList);
                break;
            case 2:
                deleteVillager(villagerList);
                break;
            case 3:
                adjustFriendship(villagerList, "increase");
                break;
            case 4:
                adjustFriendship(villagerList, "decrease");
                break;
            case 5:
                searchVillager(villagerList);
                break;
            case 6:
                displayAllVillagers(villagerList);
                break;
            case 7:
                cout << "Are you sure you want to exit? (y/n): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    cout << "Exiting program.\n";
                } else {
                    choice = 0;  // Keep running the program
                }
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
