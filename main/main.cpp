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
    cin >> name;
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
    cin >> name;

    if (villagers.erase(name)) {
        cout << "Villager deleted successfully.\n";
    } else {
        cout << "Villager not found.\n";
    }
}
void increaseFriendship(map<string, tuple<int, string, string>> &villagers) {
    string name;
    cout << "Enter villager name to increase friendship: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        get<0>(it->second)++;
        cout << "Friendship level increased for " << name << ".\n";
    } else {
        cout << "Villager not found.\n";
    }
}
void decreaseFriendship(map<string, tuple<int, string, string>> &villagers) {
    string name;
    cout << "Enter villager name to decrease friendship: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        get<0>(it->second)--;
        cout << "Friendship level decreased for " << name << ".\n";
    } else {
        cout << "Villager not found.\n";
    }
}
void searchVillager(const map<string, tuple<int, string, string>> &villagers) {
    string name;
    cout << "Enter villager name to search: ";
    cin >> name;

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

int main() {
    
    // declarations
    map<string, tuple<int, string,string>> villagerList;
    villagerList["Audie"] = {8, "Alligator", "Got a snack?"};
    villagerList["Raymond"] = {10, "Wolf", "Hubba hubba!"};
    villagerList.insert(make_pair("Raymond", make_tuple(8, "Cat", "Nice fit")));

    int choice;
    do{
        cout << "\nMenu:\n";
        cout << "1. Add Villager\n";
        cout << "2. Delete Villager\n";
        cout << "3. Increase Friendship\n";
        cout << "4. Decrease Friendship\n";
        cout << "5. Search for Villager\n";
        cout << "6. Exit\n";
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
                increaseFriendship(villagerList);
                break;
            case 4:
                decreaseFriendship(villagerList);
                break;
            case 5:
                searchVillager(villagerList);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
         cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it =  villagerList.begin(); 
                                               it !=  villagerList.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }
    } while (choice != 6);
    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    
    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair :  villagerList) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
   

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it =  villagerList.find(searchKey);
    if (it !=  villagerList.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    return 0;
}
