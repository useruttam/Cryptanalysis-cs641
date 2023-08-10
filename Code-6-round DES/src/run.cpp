#include <bits/stdc++.h>
using namespace std;
int main(){
    string mypwd, mygrp, mygppwd, infile;
    cout << "Enter your SSH Password : ";
    cin >> mypwd;
    cout << "\nEnter your team name : ";
    cin >> mygrp;
    cout << "\nEnter your team pwd : ";
    cin >> mygppwd;

    freopen("run_it.sh", "w", stdout);
    cout<< "#!/usr/bin/expect\n";
    cout<< "log_file -a allout.log\n";
    cout<< "spawn ssh student@172.27.26.188\n";

    cout<< "expect  \"student@172.27.26.188's password:\"\n";
    cout<< "send -- \"";
    cout<< mypwd;
    cout<< "\\r\"\n\n";
    cout<< "expect  \"group name:\"\n";
    cout<< "send -- \"";
    cout<< mygrp;
    cout<< "\\r\"\n\n";
    cout<< "expect  \"word:\"\n";
    cout<< "send -- \"";
    cout<< mygppwd;
    cout<< "\\r\"\n\n";
    cout<< "expect  \"at:\"\n";
    cout<< "send -- \"4\\r\"\n\n";
    cout<< "expect  \"> \"\n";
    cout<< "send -- \"read\\r\"\n\n";
    ifstream input_random("input_pairs.txt");
    string line;
    if (input_random.is_open())
    {
        while (std::getline(input_random, line))
        {
            cout<< "expect  \"> \"\n";
            cout<< "send -- \"";
            cout<< line;
            cout<< "\\r\"\n\n";
            cout<< "expect  \"> \"\n";
            cout<< "send -- \"c\\r\"\n\n";
        }
        input_random.close();
    }
}