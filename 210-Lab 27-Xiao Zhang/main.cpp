// COMSC-210 | Lab 27 | Xiao Zhang

#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;

using vil = tuple<int, string, string>; // to define a type alias for the villager data structure
void addvil (map<string, vil>& villagers); //Function to add new villager
void deletevil (map<string, vil>& villagers); //Function to delete new villager
void increase_friend (map<string, vil>& villagers);  //Function to increase the friendship level
void decrease_friend (map<string, vil>& villagers); //Function to decrease the friendship level
void searchvil (const map<string, vil>& villagers); //Function to search the villager and display its information
void display (const map<string, vil>& villagers); // Function to display all villagers

int main(){
    map<string, vil> villagers; // Create a map to store villagers
    
    int choice = 0;
    
    do {
           cout << "\nMenu:\n" << "1. Add Villager\n" << "2. Delete Villager\n" << "3. Increase Friendship\n" << "4. Decrease Friendship\n" << "5. Search for Villager\n" << "6. Exit\n" << "Enter: ";
        
           cin >> choice;

           switch (choice) {
               case 1:
                   addvil(villagers);
                   break;
               case 2:
                   deletevil(villagers);
                   break;
               case 3:
                   increase_friend(villagers);
                   break;
               case 4:
                   decrease_friend(villagers);
                   break;
               case 5:
                   searchvil(villagers);
                   break;
               case 6:
                   break;
           }

           if (choice != 6) { // display the villagers after any operation except exit
               display(villagers);
           }
       } while (choice != 6);
    
}

void addvil (map<string, vil>& villagers){
    string name;
    string species;
    string catchphrase;
    int level = -1; // I set the friendship level to be -1 for validation
    
    cout << "Villager name: ";
    cin >> name;
    cout << "Friendship level: ";
    cin >> level;
    if (level < 0){
        cout<<"Friendship Level can't be negative!"; //to ensure that the friendship level can't be negative
        return;
    }
    cout << "Species: ";
    cin >> species;
    cout << "Catchphrase: ";
    cin>>catchphrase;
    cin.ignore(); //we have to write this to ignore the newline after species input
    getline(cin, catchphrase);
    
    villagers[name] = make_tuple(level, species, catchphrase); // Store villager data in the map
    cout << name << " added.\n";
}

void deletevil (map<string, vil>& villagers) {
    string name;
    cout << "Which villager do you want to delete: ";
    cin >> name;

    villagers.erase(name); // Remove villager from the map
    cout << name << " is deleted.\n";
}

void increase_friend (map<string, vil>& villagers){
    string name;
    cout << "Which villager do you want to increase friendship: ";
    cin >> name;
    
    auto it = villagers.find(name); //get the iterator of the villager
    if (it != villagers.end()) {
        int& level = get<0>(it->second); //I learned this to get the reference to friendship level
        if (level < 10) {
            level++;
            cout << "Increased friendship level for " << name << ".\n";
        } else {
                cout << name << "'s friendship level is already 10.\n"; // can't exceed 10
            }
        } else {
            cout<<"can't find "<<name<<endl;
        }
}

void decrease_friend (map<string, vil>& villagers){ //This one is same as the previous increase function, only change increase to decrease
    string name;
    cout << "Which villager do you want to decrease friendship: ";
    cin >> name;
    
    auto it = villagers.find(name);
    if (it != villagers.end()) {
        int& level = get<0>(it->second);
        if (level > 0) {
            level--;
            cout << "Decreased friendship level for " << name << ".\n";
        } else {
                cout << name << "'s friendship level is already 0.\n";
            }
        } else {
            cout<<"can't find "<<name<<endl;
        }
}

void searchvil (const map<string, vil>& villagers){
    string name;
    cout << "Which villager do you want to search: ";
    cin >> name;
    
    int level;
    string species, catchphrase;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        cout<<"Found "<<name<<endl; //First to show that we found the villager
        tie(level, species, catchphrase) = it->second; // Get villager details
        cout << name << " [" << level << ", " << species << ", " << catchphrase << "]\n";
        } else {
            cout<<"can't find "<<name<<endl;
        }
}

void display (const map<string, vil>& villagers){
    int level;
    string species, catchphrase;
    cout << "Villager details:\n";
    
    for (const auto& [name, info] : villagers) { // Loop through the map and display each villager's details
            tie(level, species, catchphrase) = info;
            cout << name << " [" << level << ", " << species << ", " << catchphrase << "]\n";
        }
    
}
