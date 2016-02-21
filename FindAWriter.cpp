#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;

        while(getline(inputFile,line))
        {
            if(!line.empty())
            {
                string authorCoded;
                string code;
                char delimiter = '|';

                size_t delLocation = 0;

                stringstream codeStream;

                vector<int> codeVals;
                string temp;
                string author;

                //cout << line << endl;

                delLocation = line.find(delimiter);

                authorCoded = line.substr(0,delLocation);

                //cout << authorCoded << endl;
    
                // make sure to ignore the space after the delimiter character
                code = line.substr(delLocation+2);

                //cout << code << endl;

                codeStream << code;

                while(getline(codeStream,temp, ' '))
                {
                    stringstream val(temp);

                    int num;
                    char c;

                    val >> num;

                    c = authorCoded[num-1];

                    author.append(1, c);

                    //codeVals.push_back(num);
                }

                cout << author << endl;
            }
        }

        inputFile.close();
    }
    else
    {
        cout << "Error with input file" << endl;
    }

    return 0;
}
