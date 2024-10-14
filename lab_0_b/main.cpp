#include<iostream>
#include<fstream>
#include "models/entity.h"

using namespace std;

int main(int, char**)
{
    ifstream file("resources/a.txt", ios_base::in); 
    for(string i; getline(file,i);)
    {
        models::entity af(i);
    };
    file.close();
}
