#include<iostream>
#include<fstream>
#include <list>

#include "models/entity.h"

using namespace std;

int main(int argc, char** argv)
{
    string input_file_path = "resources/a.txt", output_file_path = "output.csv";
    if(argc != 1)
    {
        input_file_path = argv[1];
        output_file_path = argv[2];    
    }

    ifstream file(input_file_path, ios_base::in); 
    if (!file.is_open()) {
        std::cout << "An error occurred when opening the file. Check the correctness of the data";
        return -1;
    }

    list<models::entity> entities;
    for(string i; getline(file,i);)
    {
        models::entity af(i);
        entities.push_back(af);
    }
    file.close();

    auto comp = [] (models::entity a, models::entity b) {
        return a.getFrequency() < b.getFrequency();
    };

    entities.sort(comp);

    ofstream out(output_file_path, ios_base::out);
    out << string("Words;Frequency;Percent") << endl;

    auto l_front = entities.begin();
    for(int i = 0; i < entities.size(); i++)
    {
        models::entity temp = *l_front;
        out << temp;
        advance(l_front, 1);
    }
    out.close();

    return 0;
}
