#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Song {
public:
	Song(string songName = "none", string songLine = "none", int numPlays = 0);
	string GetName();
	string GetLine();
	int GetPlays(); 
	void SetName(string songName);
	void SetLine(string songLine);
	void SetPlays(int songPlays);
	void RemoveSong(Song* songToRemove);
	//void ListSongs(vector<Song*> songLibrary);

private:
	string name;
	string firstLine; 
	int plays; 
	vector<Song*> library;


};