#include <iostream>
#include <map>

#include <vector>
using namespace std;

int main() {
    
    // declarations
    map<string, tuple<int, string,string>> villagerList;
    int choice;
    cout <<"1. Add Villager/n2. Delete Villager/n3. Increase Friendship/n4. Decrease Friendship/n5. Search for Villager/n6. Exit";
     do {
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
                addVillager(villagerColors);
                break;
            case 2:
                deleteVillager(villagerColors);
                break;
            case 3:
                increaseFriendship(villagerColors);
                break;
            case 4:
                decreaseFriendship(villagerColors);
                break;
            case 5:
                searchVillager(villagerColors);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerList["Audie"] = {8, "Alligator", "Got a snack?"};
    villagerList["Raymond"] = {10, "Wolf", "Hubba hubba!"};
    villagerList.insert(make_pair("Raymond", make_tuple(8, "Cat", "Nice fit")));

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair :  villagerList) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it =  villagerList.begin(); 
                                               it !=  villagerList.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
     villagerLists.erase("Raymond");

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

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " <<  villagerList.size() << endl;
    villagerList.clear();
    cout << "Size after clear: " <<  villagerList.size() << endl;

    return 0;
}
