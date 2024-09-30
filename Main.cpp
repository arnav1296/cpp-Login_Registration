#include <iostream>
#include <fstream>
using namespace std;

class temp { 
    string searchName, searchPass, searchEmail;
    string username, Email, password;
    fstream file;
    
    public:
    void login();
    void signup();
    void forgot();
}obj;


int main() {
    int choice;
    cout << "\n1. Login" 
    << "\n2. Signup" 
    << "\n3. Forgot Password"
    << "\nEnter your choice :: ";

    cin >> choice;

    switch (choice) {
    case 1:
    obj.login();

        break;
    case 2:
    obj.signup();

        break;
    case 3:
    obj.forgot();

        break;

    default :
    cout << "Error";

    }
    return 0;
}

//Fuction Definitions

// Make a file with all the user data
void temp :: signup() {
    cout << "------------SIGNUP------------" << endl;
    cout << "\nEnter Your Username: ";
    cin >> username;
    cout << "\nEnter Your Email: ";
    cin >> Email;
    cout << "\nEnter Your Password: ";
    cin >> password;

    file.open("loginData.txt", ios :: out | ios :: app);
    file << username << "*" << Email << "*" << password << endl;
    file.close();
}

// Make user enter details for login
void temp :: login() {
    cout << "------------LOGIN------------" << endl;
    cout << "\nEnter your Username: ";
    cin >> searchName;
    cout << "\nEnter your Password: ";
    cin >> searchPass;


    // Read and match data from data file for login
    file.open ("loginData.txt", ios::in);
    getline(file,username,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    while(!file.eof()) {
        if(searchName == username) {
            if(searchPass == password) {
                cout << "\nLogin Successful!!!";
                cout << "\nEmail: " << Email;
                cout << "\nUsername: " << username;
        }
        } else {cout << "Username/Password is incorrect.";}
    getline(file, username,'*');
    getline(file, password,'*');
    getline(file,Email,'\n');
    }
    file.close();
}

//search Email and match it with data in text file
void temp :: forgot() {
    cout << "------------FORGOT PASSWORD------------" << endl;
    cout << "\nEnter your Email: ";
    cin >> searchEmail;

    file.open("loginData.txt", ios::in);
    getline(file,username,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');

    while (!file.eof()) {
        if (Email == searchEmail) {
            cout << "\nLogin details are: ";
            cout <<"\nUsername: " << username;
            cout << "\nPassword: " << password;

        } else {cout << "Record Not Found!!";}
    
    getline(file,username,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');

    }

    file.close();
}