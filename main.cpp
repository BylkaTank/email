#include <iostream>
#include <string>

using namespace std;

bool first_part_email(string emailFirst) {
    string symbols = "!#_$%&'*+-/=?^`{|}~.1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool match = false;
    if ((emailFirst.find("@") <= 64) && (emailFirst.find("@") >= 1)) {
        match = true;
        for(int i = 0; (i < emailFirst.find("@")) && match; i++){
            for(int j = 0; j < symbols.length(); j++){
                if(emailFirst[i] != symbols[j]){
                    match = false;
                } else {
                    match = true;
                    break;
                }
            }
        }
    }
    return match;
}

bool second_part_email(string emailSecond){
    bool match = false;
    string symbols = "-.1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if(emailSecond.length() - (emailSecond.find("@") + 1) <= 63 && (emailSecond.length() - (emailSecond.find("@") + 1) >= 1)){
        match = true;
        for(int i = emailSecond.find("@") + 1; i < emailSecond.length() && match; i++){
            for(int j = 0; j < symbols.length(); j++){
                if(emailSecond[i] != symbols[j]){
                    match = false;
                } else {
                    match = true;
                    break;
                }
                if (emailSecond[i] == '@'){
                    return false;
                }
            }
        }
    }
    return match;
}

int main() {
    int iter = 0;
    bool match = false;
    cout << "Enter the email: \n" ;
    string email;
    getline(cin,email);

    for(int i = 0; i < email.length(); i++){
        if (email.find("@") == -1){
            match = true;
            break;
        } else if ((email[0] == '.') || (email[email.find("@") - 1] == '.') || (email[email.find("@") + 1] == '.') || (email[email.length() - 1] == '.') || (email[i] == '.' && email[i + 1] == '.')){
            match = true;
            break;
        } else if (email[i] == '@'){
            iter++;
            if (iter > 1){
              match = true;
              break;
            }
        }
    }
    cout << (match ? "No" : first_part_email(email) && second_part_email(email) ? "Yes" : "No");

}