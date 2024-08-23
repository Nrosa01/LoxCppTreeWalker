#include <iostream>
#include <string>

using namespace std;

void println(const string&& str)
{
	cout << str << "\n";
}

void println(const string& str)
{
    cout << str << "\n";
}

void print(const string&& str)
{
	cout << str;
}

void runFile(const string& str);
void runPrompt();

int main(int argc, char* argv[])
{
    println("There are " + to_string(argc) + " arguments");
    
    for (int i = 0; i < argc; i++)
    {
        println(to_string(i).append(" ").append(argv[i]));
    }

    if (argc > 2) {
        println("Usage: jlox [script]");
        exit(64);
    }
    else if (argc == 2) {
        runFile(argv[1]);
    }
    else {
        runPrompt();
    }
}

void runFile(const string& str)
{
    println("Running File: " + str);
}

void runPrompt()
{
    println("Running in interactive mode");
}

