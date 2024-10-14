#include<iostream>
#include<fstream>
#include "models/entity.h"

using namespace std;

int main(int, char**)
{
    ifstream file("a.txt", ios_base::in); 
    for(string i; getline(file,i);)
    {
        models::entity af(i);
    };
    cout << "Hello, from lab0b!\n";
}
