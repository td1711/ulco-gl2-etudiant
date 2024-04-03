#include <todolist-cpp/Task.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <todolist-cpp/View.hpp>


int main(){
    Board b;

    while(true){
        std::cout << showBoard(b) << std::endl;
        std::string response, cmd, rst;
        std::getline(std::cin, response);

        if(response == "quit"){
            break;
        }

        std::istringstream iss(response);
        std::getline(iss, cmd, ' ');
        std::getline(iss, rst);

        
        if(cmd == "add"){
            b.addTodo(rst);
        }
        if(cmd == "done"){
            b.toDone(std::stoi(rst));
        }

    }

    return 0;
}

