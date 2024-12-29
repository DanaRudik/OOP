#include <iostream>
#include <sstream>
#include "Life.h"

int main(int argc, char *argv[]) {
    std::cout << R"(
        (\ /)                                         (\_/)
        ( . .)                                        ( . .) 
        c(")(")    H E L L O ,    T H I S   I S       c(")(")
                 T H E   G A M E    O F   L I F E    
  
)";

    Life Life;
    if (argc > 1) {
        if (argv[1][0] != '-') {
            Life.loadFromFile(argv[1]);
        }
    }

    std::string arg;
    for (int i = 1; i < argc; i++) {
        arg = argv[i];

        if (arg == "-i") 
        {
            Life.tick(std::stoi(argv[i + 1]));

        } else if (arg.rfind("--iteration=", 0) == 0) 
        {
            Life.tick(std::stoi(arg.substr(arg.find('=') + 1)));
        }

        if (arg == "-o") 
        {
            Life.saveToFile((std::string)argv[i + 1]);
            return 0;
            
        } else if (arg.rfind("--output=", 0) == 0) 
        {
            Life.saveToFile(arg.substr(arg.find('=') + 1));
            return 0;
        }
    }

    Life.printGrid();

    std::string cmd;
    while (true) {
        getline(std::cin, cmd);

        if (cmd == "exit") {
            return 0;
        } else if (cmd == "help") {
            Life.showHelp();
        } else if (cmd.rfind("dump", 0) == 0) {
            std::string filename = cmd.substr(5);
            Life.saveToFile(filename);
        } else if (cmd.rfind("tick", 0) == 0) {
            int iteration = 1;
            std::istringstream inss(cmd.substr(cmd.find(' ') + 1));
            inss >> iteration;
            Life.tick(iteration);
            Life.printGrid();
        } else {
            std::cout << "To view the help enter: help" << std::endl;
        }
    }
}
