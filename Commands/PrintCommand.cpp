//
// Created by daniel on 12/22/18.
//

#include <iostream>
#include "PrintCommand.h"
#include "ShuntingYard.h"

PrintCommand::PrintCommand(SymbolTable *table) {
    this->_table = table;
}


int PrintCommand::doCommand(vector<string> &commandInfo) {

    /*
       *
       * all the cases that i can have:
       * 1. x
       * 3. "zibi"
*/

    string toPrint;
    //init what we have in the vector to one string
    for (auto iter:commandInfo) {
        toPrint += iter;
    }
    try {
        if (toPrint.empty()) {
            throw invalid_argument("the  word is empty");
        }
    } catch (invalid_argument e) {
        cout << e.what() << endl;
    }
    // if we dont have "--> just send to shunting yard
    if (toPrint.find('\"') > toPrint.length()) {
        double value = ShuntingYard(this->_table).calculateExpression(commandInfo);
        cout << value << endl;
        return 0;
    }//else we need to print string
    else {
//        if (toPrint.find("done") < toPrint.length()) {
//            cout << "Process finished with exit code done";
//            exit(0);
//        }
        string tempToPrint = splitWord(toPrint);
        cout << tempToPrint << endl;
    }
}

PrintCommand::~PrintCommand() {

}

string PrintCommand::getWord(const string &wordToWorkOn) {

    string wordToReturn;
    size_t pos1 = wordToReturn.find('"', 0);// the first position of "
    size_t pos2 = wordToReturn.find('"', wordToReturn.length());//the second position of "
    return string(wordToReturn.c_str() + pos1, pos2);// return the string from pos1 to pos2

}

/*
 * split the string to be with-out " "
 */
string PrintCommand::splitWord(const string &str) {
    string result;
    result = str.substr(1, str.length() - 2);
    return result;
}
