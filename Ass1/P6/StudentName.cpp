#include "StudentName.h"
//Parametrize constructor

StudentName::StudentName(string s) {
    name = s;
    //delete the spaces in the front of the string if founded
    while (name[0]==' '){
        name.erase(name.begin());
    }

    //delete the spaces from the end of the name if founded
    while (name[name.size()-1]==' '){
        name.pop_back();
    }

    s = "";
    int numofspaces = 0;
    //count the number of names in the whole name
    for (int i = 0; i < name.size(); ++i) {
        if (name[i] == ' ')
            numofspaces++;

    }

    //get the the last name of the whole name if the number of names less than 3
    if (numofspaces < 2) {
        for (int i = name.size() - 1; i >= 0; --i) {
            if (name[i] == ' ')
                break;
            s = name[i] + s;

        }
    }

    //repeat the last name once if the names of the whole name less than 3
    if (numofspaces == 1) {
        name += ' ';
        name += s;
    }    else if (!numofspaces) {
        name += ' ';
        name += s;
        name += ' ';
        name += s;
    }


}
//Print all details about the whole name
void StudentName::print() {
    cout << "detailed parts of the name are\n";
    string s = "";
    int j = 1;

    for (int i = 0; i < name.size(); ++i) {
        if (name[i] != ' ')
            s += name[i];
        else {
            cout << j << ')' << s << endl;
            s = "";
            j++;
        }
    }

    cout << j << ')' << s << endl;

}

//replace between two names in the whole name
bool StudentName::replace(int i, int j) {
    if (i == j)
        return true;
    int numofspaces = 0;

    //Get number of names
    for (int k = 0; k < name.size(); ++k) {
        if (name[k] == ' ')
            numofspaces++;
    }

    string Names[++numofspaces], Name = "";

    // return false if the indices out of boundary
    if (i > numofspaces || j > numofspaces || i <= 0 || j <= 0)
        return false;

    for (int k = 0, x = 0; k < name.size(); ++k) {
        if (name[k] == ' ') {
            Names[x] = Name;
            Name = "";
            x++;
        } else if (k == name.size() - 1) {
            Name += name[k];
            Names[x] = Name;
            x++;
        } else {
            Name += name[k];
        }
    }


    Names[i- 1] = Names[j - 1];
    name = "";

    for (int k = 0; k < numofspaces; ++k) {
        name += Names[k];
        if (k != numofspaces - 1)
            name += ' ';
    }

    return true;
}

//Get the whole name
string StudentName::getName() const {
    return name;
}






