#include<iostream>
#include<fstream>
#include <list>

#include "models/entityListBuilder.h"
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

    string i; 
    getline(file,i);
    file.close();

    auto entityList = models::entityListBuilder::build(i);

    auto comp = [] (models::entity a, models::entity b) {
        return a.getFrequency() > b.getFrequency();
    };

    entityList.sort(comp);

    ofstream out(output_file_path, ios_base::out);
    out << string("Words;Frequency;Percent") << endl;

    auto l_front = entityList.begin();
    for(int i = 0; i < entityList.size(); i++)
    {
        models::entity temp = *l_front;
        out << temp;
        advance(l_front, 1);
    }
    out.close();

    return 0;
}
