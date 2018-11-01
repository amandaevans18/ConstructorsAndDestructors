#include "highScoreTable.h"

std::vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	return hsVector;
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	return false;
}

HighScoreTable::HighScoreTable()
{
}

HighScoreTable::HighScoreTable(std::string fileName)//copying data from file into the vector of high score entrys.
{
	std::fstream file;
	int amtOfCommas = 0;
	HighScoreEntry temp;
	std::string tempName;
	std::string tempScore;
	std::string tempLevel;
	file.open(fileName, std::ios_base::in);
	if (!file.is_open()) 
	{
		std::cout << "Failed to open file!" << std::endl;
		return;
	}
	std::string buffer;
	//copying all the info into our dearest vector
	while (std::getline(file,buffer)) 
	{
		for (int i = 0; i < buffer.length(); i++) 
		{
			if (buffer[i] == ',') 
			{
				amtOfCommas++;
			}
			switch (amtOfCommas)
			{
			case 0:
				tempName += buffer[i];
				break;
			case 1:
				tempScore += buffer[i];
				break;

			case 2:
				tempLevel += buffer[i];
				break;
			}
		}
		hsVector.push_back(temp);
		tempLevel = "";
		tempName = "";
		tempScore = "";
	}
	file.flush();
	file.close();


}

HighScoreTable::~HighScoreTable()
{
}
