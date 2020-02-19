#include "Song.h"
#include <string>
#include <vector>

Song::Song(string songTitle, string songFirstLine, int numPlays) {
	name = songTitle; 
	firstLine = songFirstLine;
	plays = numPlays; 
}

string Song::GetName() {
	return name;
}

string Song::GetLine() {
	return firstLine; 
}

int Song::GetPlays() {
	return plays;
}
void Song::SetName(string songName) {
	name = songName;
}
void Song::SetLine(string songLine) {
	firstLine = songLine;
}
void Song::SetPlays(int songPlays) {
	plays = songPlays; 
}
//void Song::AddSong(vector<Song*>& songLibrary, string songName, string songLine) {
//	songLibrary.push_back(new Song(songName, songLine)); 
//}
void Song::RemoveSong(Song* songToRemove) {

}

//void Song::ListSongs(vector<Song*> songLibrary) {
//	for (int i = 0; i < songLibrary.size(); i++) {
//		Song currentSong = *songLibrary.at(i);
//		cout << currentSong.GetName() << ": \"" << currentSong.GetLine() << "\", " << currentSong.GetPlays() << " play(s)." << endl;
//	}
//}