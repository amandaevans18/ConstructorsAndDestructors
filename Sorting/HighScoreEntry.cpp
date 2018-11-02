#include "HighScoreEntry.h"

HighScoreEntry::HighScoreEntry()
{
}

HighScoreEntry::~HighScoreEntry()
{
}

bool HighScoreEntry::operator<(HighScoreEntry & entry)
{
	if (score < entry.score) 
	{
		return true;
	}
	return false;
}

bool HighScoreEntry::operator>(HighScoreEntry & entry)
{
	if (score > entry.score)
	{
		return true;
	}
	return false;
}

bool HighScoreEntry::operator<=(HighScoreEntry & entry)
{
	if (score <= entry.score)
	{
		return true;
	}
	return false;
}

bool HighScoreEntry::operator>=(HighScoreEntry & entry)
{
	if (score >= entry.score)
	{
		return true;
	}
	return false;
}


void HighScoreEntry::clear()
{
	name = nullptr;
	score = NULL;
	level = NULL;

}