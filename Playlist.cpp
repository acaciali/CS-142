#include "Playlist.h"
#include "Song.h"

#include <string>
#include <vector>

Playlist::Playlist(vector<Song*> playlistSongs, string playlistName) {
	name = playlistName; 
	songs = playlistSongs; 
}

string Playlist::GetName() {
	return name; 
}

vector<Song*> Playlist::GetSongs() {
	return songs; 
}

//void Playlist::AddSong(Song* songToAdd, Playlist currentPlaylist) {
//	
//}

//void Playlist::PrintPlaylists(vector<Playlist> playlistVector) {
//	for (int i = 0; i < playlistVector.size(); i++) {
//		cout << i << ": " << playlistVector.at(i).GetName() << endl;
//	}
//}
