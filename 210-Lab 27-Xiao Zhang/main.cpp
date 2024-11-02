// COMSC-210 | Lab 27 | Xiao Zhang

#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;

using vil = tuple<int, string, string>;

void display (map<string, vil>& villagers);
void addvil (map<string, vil>& villagers);
void deletevil (map<string, vil>& villagers);
void increase_friend (map<string, vil>& villagers);
void decrease_friend (map<string, vil>& villagers);
void searchvil (map<string, vil>& villagers);

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
