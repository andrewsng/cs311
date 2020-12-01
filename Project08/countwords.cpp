// countwords.cpp
// Andrew S. Ng
// Started: 2020-11-29
// Updated: 2020-12-01
//
// For CS 311 Fall 2020
// Complete source for word counting program

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
using std::getline;
#include <map>
using std::map;
#include <cstddef>
using std::size_t;


int main()
{
    // Main Loop: count words in a given file
    while (true)
    {
        // User input loop for filename
        ifstream fin;
        while (true)
        {
            cout << "Please enter a file to count its words! (q to quit)\n";

            string filename;
            getline(cin, filename);

            // Enter q to quit
            if (filename == "q")
                return 0;

            fin.open(filename);
            if (!fin)
            {
                cerr << "ERROR: File cannot be opened.\n";
                continue;
            }
            
            break;
        }

        // Store words into container
        map<string, size_t> wordCounts;
        bool success = true;
        while (true)
        {
            string word;
            fin >> word;
            if (!fin)
            {
                if (fin.eof())
                    break;

                cerr << "ERROR: File could not be read.\n";
                success = false;
                break;
            }
            
            ++wordCounts[word];
        }
        if (!success)
        {
            fin.close();
            continue;
        }

        // Print words and counts
        cout << "---------------------------------\n";
        cout << "Number of distinct words: " << wordCounts.size() << "\n\n";
        for (const auto & pair : wordCounts)
        {
            cout << pair.first << ": " << pair.second << '\n';
        }
        cout << "---------------------------------\n" << endl;
    }
}