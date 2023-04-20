#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
   int health = 100;
   int treasure = 0;
   
    cout << "\nWelcome to the Adventure Game!\n\n";
    cout << "As you were part of a tour within the Khofu pyrmaid of the Great Pyramids of Giza, you purposely left the tour group to go find Tutankhamun's acient trasure.\n";
    cout << "As you go down, you explore the secrets through bridges, waterfalls, and more. Your main goal is to reach the lost treasure within the Pyramid.\n";
    cout << "You have 100 health. Along the way, you will face many challenges which require your basic mathematical skills.\n";
    cout << "Try to finish the game with as much health as you can.\n\n";
    
    string x;
    cout << "Please enter your name: \n";
    cin >> x;
    cout << "Nice to meet you " << x << ".\n";

   
   cout << "\nAs you enter the tunnel you see two creepy doors. Which door will you go through? (Enter 1 or 2): \n";
   cout << "1. Left Door\n";
   cout << "2. Right Door\n";
   int choice;
   cin >> choice;
   
   if (choice == 1) {
      int num1 = rand() % 10 + 1;
      int num2 = rand() % 10 + 1;
      int answer = num1 + num2;
      
      cout << "\nYou open the door and find a chest. To open it, answer this math question: " << num1 << " + " << num2 << " = ";
      int player_answer;
      cin >> player_answer;
      
      if (player_answer == answer) {
         cout << "Correct! You found a rare artifact. You gained 50 treasure points!\n";
         treasure += 50;
      } else {
         cout << "Incorrect! The chest was trapped and explodes. You lose 20 health points.\n";
         health -= 20;
      }
   } else if (choice == 2) {
      int num1 = rand() % 10 + 1;
      int num2 = rand() % 10 + 1;
      int answer = num1 * num2;
      
      cout << "\nYou open the door and find a statue. To proceed, answer this math question: " << num1 << " * " << num2 << " = ";
      int player_answer;
      cin >> player_answer;
      
      if (player_answer == answer) {
         cout << "Correct! You found a valuable gemstone. You gained 25 treasure points!\n";
         treasure += 25;
      } else {
         cout << "Incorrect! The statue comes to life and attacks you. You lose 30 health points.\n";
         health -= 30;
      }
   } else {
      cout << "Invalid input. You stand there confused and lose 10 health points.\n";
      health -= 10;
   }
   
   cout << "\nYou now have " << treasure << " treasure points and " << health << " health points.\n";
   
   cout << "\nYou enter the second room and see a hallway. At the end of the hallway, you see another door. What will you do? (Enter 1 or 2): \n";
   cout << "1. Run down the hallway\n";
   cout << "2. Take your time and carefully walk down the hallway\n";
   cin >> choice;
   
   if (choice == 1) {
      int num1 = rand() % 10 + 1;
      int num2 = rand() % 10 + 1;
      int answer = num1 - num2;
      
      cout << "\nYou run down the hallway and cause the trap to function. To escape, answer this math question: " << num1 << " - " << num2 << " = ";
            cout << num1 << " - " << num2 << " = ";
      int player_answer;
      cin >> player_answer;
      
      if (player_answer == answer) {
         cout << "You managed to dodge the traps and found a secret room. You gained 100 treasure points!\n";
         treasure += 100;
      } else {
         cout << "The trap activates and arrows drop down on you. You lose 50 health points.\n";
         health -= 50;
      }
   } else if (choice == 2) {
      int num1 = rand() % 10 + 1;
      int num2 = rand() % 10 + 1;
      int answer = num1 % num2;
      
      cout << "\nYou walk down the hallway and find a lock. To open it, answer this math question: " << num1 << " % " << num2 << " = ";
      int player_answer;
      cin >> player_answer;
      
      if (player_answer == answer) {
         cout << "You successfully unlocked the door and found the treasure room. Congratulations, you win!\n";
         treasure += 500;
      } else {
         cout << "The lock is jammed and won't open. You hear footsteps approaching. You lose 30 health points.\n";
         health -= 30;
      }
   } else {
      cout << "Invalid input. You stand there confused and lose 10 health points.\n";
      health -= 10;
   }
   
   cout << "\nYou now have " << treasure << " treasure points and " << health << " health points.\n";
   
   // Ending
   if (health <= 0) {
      cout << "\nGame over! You ran out of health points.\n";
   } else {
      cout << "\nCongratulations on finding the lost treasure! You win!\n";
   }
   
   return 0;
}
