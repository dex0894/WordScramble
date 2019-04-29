#include "ScoreBoardCSVReader.h"



namespace io
{


ScoreBoardCSVReader::ScoreBoardCSVReader()
{
    //ctor
}

ScoreBoardCSVReader::~ScoreBoardCSVReader()
{
    //dtor
}

vector<Player> ScoreBoardCSVReader::parseCSVFile()
{
    string line;
    string field;
    int score;
    vector<string> storedFields;
    ifstream myFile (FILENAME);

    if (myFile.is_open())
    {

        while ( getline (myFile,line) )
        {

            stringstream dataOnLine(line);

            while (getline (dataOnLine, field,','))
            {
                storedFields.push_back(field);

                if (storedFields.size() == MINIMUM_FIELDS)
                {
                    string firstname = storedFields[FIRST_NAME];
                    string lastname = storedFields[LAST_NAME];
                    firstname = toUpper(firstname);
                    lastname = toUpper(lastname);
                    score = stoi(storedFields[SCORE]);
                    Player player(firstname,lastname,score);
                    this->players.push_back(player);
                    storedFields.clear();
                    dataOnLine.clear();
                }
            }

        }
        myFile.close();
    }

    else
    {
        cout << FILE_ERROR << endl << endl;
    }
    return this->players;
}
}
