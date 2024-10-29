#include "entityListBuilder.h"
#include <unordered_map>

using namespace models;

entityListBuilder::entityListBuilder()
{

}

list<entity> entityListBuilder::build(string str)
{
    unordered_map<string, int> table;
    float count = 0;
    string word;
    for(int i = 0; i <= str.length(); i++)
    {
        if (
            (str[i] >= '0' && str[i] <= '9') 
            || 
            (str[i] >= 'A' && str[i] <= 'Z') 
            ||
            ( str[i] >= 'a' && str[i] <= 'z')
            )
        {
            word += str[i];
        }
        else if(word.length() != 0)
        {
            if (table.find(word) == table.end())
                table[word] = 1;
            else
                table[word]++;
            count++;
            word = "";
        }
    };

    list<entity> result;
    for(auto kv : table)
    {
        models::entity af(kv.first, kv.second, (kv.second/count)*100);
        result.push_back(af);
    }
    return result;

}