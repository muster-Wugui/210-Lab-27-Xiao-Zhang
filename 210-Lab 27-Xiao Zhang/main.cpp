// COMSC-210 | Lab 27 | Xiao Zhang

#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;

using vil = tuple<int, string, string>;

void addvil (map<string, vil>& villagers);
void deletevil (map<string, vil>& villagers);
void increase_friend (map<string, vil>& villagers);
void decrease_friend (map<string, vil>& villagers);
void searchvil (const map<string, vil>& villagers);
void display (const map<string, vil>& villagers);

int main(){
    map<string, vil> villagers;
    
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

           if (choice != 6) {
               cout << "\nVillager details:\n";
               display(villagers);
           }
       } while (choice != 6);
    
}

void addvil (map<string, vil>& villagers){
    string name;
    string species;
    string catchphrase;
    int level = -1;
    
    cout << "Villager name: ";
    cin >> name;
    cout<<endl;
    cout << "Friendship level: ";
    cin >> level;
    if (level < 0){
        cout<<"Friendship Level can't be negative!";
        return;
    }
    cout<<endl;
    cout << "Species: ";
    cin >> species;
    cout<<endl;
    cout << "Catchphrase: ";
    cin>>catchphrase;
    cin.ignore();
    getline(cin, catchphrase);
    
    villagers[name] = make_tuple(level, species, catchphrase);
    cout << name << " added.\n";
}

void deletevil (map<string, vil>& villagers) {
    string name;
    cout << "Which villager do you want to delete: ";
    cin >> name;

    villagers.erase(name);
    cout << name << " is deleted.\n";
}

void increase_friend (map<string, vil>& villagers){
    string name;
    cout << "Which villager do you want to increase friendship: ";
    cin >> name;
    
    auto it = villagers.find(name);
    if (it != villagers.end()) {
        int& level = it->second;
        if (level < 10) {
            level++;
            cout << "Increased friendship level for " << name << ".\n";
        } else {
                cout << name << "'s friendship level is already 10.\n";
            }
        } else {
            cout<<"can't find "<<name<<endl;
        }
}

void decrease_friend (map<string, vil>& villagers){
    string name;
    cout << "Which villager do you want to decrease friendship: ";
    cin >> name;
    
    auto it = villagers.find(name);
    if (it != villagers.end()) {
        int& level = it->second;
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
        cout<<"Found "<<name<<endl;
        tie(level, species, catchphrase) = it->second;
        cout << name << " [" << level << ", " << species << ", " << catchphrase << "]\n";
        } else {
            cout<<"can't find "<<name<<endl;
        }
}

void display (const map<string, vil>& villagers){
    cout << "Villager details:\n";
    
}
