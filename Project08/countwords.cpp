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
#include <limits>


int main()
{
    while (true)
    {
        cout << "Please enter a .txt file name! (q to quit)\n";

        ifstream fin;
        while (true)
        {
            string filename;
            getline(cin, filename);

            if (filename == "q")
                return 0;

            fin.open(filename);
            if(fin)
            {
                // Find file extension
                const auto pos = filename.find_last_of('.');
                const string ext = filename.substr(pos + 1);

                if (ext == "txt")
                    break;

                fin.close();
                cerr << "ERROR: File is not a .txt file." << endl;
            }
            else
                cerr << "ERROR: File is unreadable or doesn't exist." << endl;
        }

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

                cerr << "ERROR: File could not be read." << endl;
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

        cout << "---------------------------------\n";
        cout << "Number of distinct words: " << wordCounts.size() << "\n\n";
        for (const auto & pair : wordCounts)
        {
            cout << pair.first << ": " << pair.second << '\n';
        }
        cout << "---------------------------------\n\n";
    }
}