#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name;
    string filename;

    cout << "What is the filename(with extension) \n";
    cin >> filename;
    string compileCommand = "g++ " + filename + " -o temp";
    cout << "What is your name ";
    cin >> name;

    time_t now = time(0);
    string currentTime = ctime(&now);
    
    cout << "Current time is " <<currentTime<<endl;

    ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening the file!" << std::endl;
        return 1;
    }
    bool running = true;
    cout << "Start writing "<<endl;
    while (running) {
        string line; getline(cin,line);
        if (line=="quit" || line=="exit" || line=="end"){
            running = false;
            file << "//Written by " << name<<endl;
            file << "//Last write time: " << currentTime <<endl;
            file.close();
            return 0;
        }
        if (line=="run") {
            cout << "Running code \n";
            int returnCode = system(compileCommand.c_str());
            if (returnCode == 1) {
                cout << "Failed to execute command " << compileCommand<<endl;
                file.close();
                return 1;
            }
            int runCode = system("temp.exe");
            if (runCode==1) {
                cout << "Failed to execute temp "<<endl;
                return 1;
            }
        }
        file << line<<endl;
    }

    file.close();
    return 0;
}