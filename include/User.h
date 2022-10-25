//
// Created by simon on 2022-10-26.
//

#ifndef BOOKINGSYSTEM_USER_H
#define BOOKINGSYSTEM_USER_H

class User {
public:
    const char *username;
    const char *last_name;
    const char *first_name;
    const char *email;
    const unsigned int passwordHash;

    bool isAdmin() { return admin; };

private:
    bool admin;
};

#endif //BOOKINGSYSTEM_USER_H
