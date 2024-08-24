#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;
namespace fs = std::filesystem;

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
void run(const string& str);

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

static std::string readFile(fs::path path)
{
	// Open the stream to 'lock' the file.
	std::ifstream f(path, std::ios::in | std::ios::binary);

	if (f.fail())
	{
		cout << "Filed failed to open \n";
		return "";
	}

	// Obtain the size of the file.
	const auto sz = fs::file_size(path);

	// Create a buffer.
	std::string result(sz, '\0');

	// Read the whole file into the buffer.
	f.read(result.data(), sz);

	return result;
}

void runFile(const string& str)
{
	println("Running File: " + str);
	run(readFile(str));
}

void runPrompt()
{
	println("Running in interactive mode");
	string line;

	while (true)
	{
		cout << "> ";
		getline(cin, line);
		if (line.empty())
			break;
		else
			run(line);
	}
}

void run(const string& str)
{
	std::istringstream iss(str);
	std::string word;

	while (iss >> word)
		cout << word << "\n";

	cout << std::flush;
}

