#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool inSystem() { // This will check if the user is in the system or not.
  string username;
  string password;
  string checkUser;
  string checkPass;

  cout << "Username: ";
  cin >> username;

  cout << "Password: ";
  cin >> password;

  ifstream read("customers\\" + username + ".txt"); // Reads the customers folder for text files that match the username

  getline(read, checkUser);
  getline(read, checkPass);

  if (checkUser == username && checkPass == password) { // Checks if the user is in the system or not
    cout << "Login Successful. Welcome " << username << endl;
    return true;               // If so, the function will return a true
  } 
  else {                     // If not, the function will return a false
    return false;
  }
  // may need to consider a case if there is no file to read
}

int main() {
  char choice = 'p';
  string newUser;
  string newPass;

  while (choice != 'x' && choice != 'X') {

    cout << "a) Register into System" << endl; // Present user with Menu Options
    cout << "b) Sign into System" << endl;
    cout << "x) Quit" << endl;
    cout << "> ";
    cin >> choice;

    if (choice == 'a' || choice == 'A') { // If registering a new user
      cout << "<<Registering New User>>" << endl;

      cout << "Enter a Username: "; //Get the new user's information
      cin >> newUser;

      cout << "Enter a Password: ";
      cin >> newPass;

      ofstream file; // Write a new file
      file.open("customers\\" + newUser + ".txt"); //Make the file with the user's selected username
      file << newUser << endl << newPass; //Store the data into a new file
      file.close(); // Close the file
    }
    else if (choice == 'b' || choice == 'B') { // If signing into the system
      bool inTheSystem = inSystem(); // Check the user into the system
      if (inTheSystem == false) { // If the user isn't in the system
        cout << "Error. Invalid Login." << endl; // Declare an error
      }
    } 
    else if (choice == 'x' || choice == 'X') { // If quitting the program
      cout << "Quitting Program." << endl; // Output goodbye statement
    }
    else { // If invalid input option
      cout << "Error. Invalid input. Please try again." << endl; // Output error statement.
    }
  }
}