#include <iostream>
#include <fstream>
#include <string>

#include <cstdio>

#include "UnorderedList.h"

using namespace std;

void fileError(string filename) {
    cout << "File " << filename << " could not be opened." << endl;
    exit(1);
}

void trim(istream& in) {
    char c;
    while ((c = in.get())) {
        if (c == 0x0a || c == 0x07) {

            // Skip linefeeds or carriage returns
            continue;
        }
        in.putback(c);
        break;
    }
}

void processCommands(ifstream& infile, ofstream& outfile, string title) {
    string command;
    int itemValue, i = 0;
    UnorderedList ul;
    ItemType item;
    bool found;
    bool done = false;
    outfile << title << endl;
    while (!done && (infile >> command)) {
        if (command == "PutItem") {
            infile >> itemValue;
            item.Initialize(itemValue);
            ul.PutItem(item);
            item.Print(outfile);
            outfile << " is in list " << endl;
        } else if (command == "GetItem") {
            infile >> itemValue;
            item.Initialize(itemValue);
            ul.GetItem(item, found);
            item.Print(outfile);
            if (found) {
                outfile << " found in list" << endl;
            } else {
                outfile << " not in list" << endl;
            }
        } else if (command == "PrintList") {
            ul.PrintList(outfile);
        } else if (command == "GetLength") {
            outfile << "Length is: " << ul.GetLength() << endl;
        } else if (command == "DeleteItem") {
            infile >> itemValue;
            item.Initialize(itemValue);
            ul.DeleteItem(item);
            item.Print(outfile);
            outfile << " is deleted" << endl;
        } else if (command == "MakeEmpty") {
            ul.MakeEmpty();
            outfile << "Made Empty" << endl;
        } else if (command == "IsFull") {
            if (ul.IsFull()) {
                outfile << "List is full." << endl;
            } else {
                outfile << "List is not full." << endl;
            }
        } else if (command == "Quit") {
            done = true;
        } else {
            cout << command << " is not a valid command." << endl;
            continue;
        }
        i += 1;
        cout << "Command number " << i << " completed." << endl;
    }
}

int main() {
    string filename, title;
    ifstream infile;
    ofstream outfile;
    cout << "Enter input filename to test:" << endl;
    cin >> filename;
    infile.open(filename);
    if (!infile) fileError(filename);
    cout << "Enter output filename to write test results to:" << endl;
    cin  >> filename;
    outfile.open(filename);
    if (!outfile) fileError(filename);
    cout << "Enter a title for this test run:" << endl;
    trim(cin);
    getline(cin, title, '\n');
    processCommands(infile, outfile, title);
    infile.close();
    outfile.close();
};
