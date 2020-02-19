#pragma once
#include "Song.h"
#include <vector>
#include <string>
using namespace std; 

class Playlist {
public:
	Playlist(vector<Song*> playlistSongs, string playlistName = "none");
	string GetName();
	vector<Song*> GetSongs(); 
	//void AddSong(Song* songToAdd, Playlist currentPlaylist); 
	//void PrintPlaylists(vector<Playlist> playlistVector);
private:
	string name;
	vector<Song*> songs; 
};
