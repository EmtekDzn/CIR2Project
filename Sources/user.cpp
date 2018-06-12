#include "../Headers/user.hpp"

User::User(int id_usr, string usrnm , string pwd) {
    id_user = id_usr;
    username = usrnm;
    password = pwd;
}

string User::getUsername() {
    return username;
}
