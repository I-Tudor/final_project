#include "songlist.h"

songList::songList()
{
}

std::vector<Song> songList::getSongs() {
    return songs;
}

void songList::addSong(Song song) {
    songs.push_back(song);
}

Song songList::getSong(int i) {
    return songs[i];
}

void songList::deleteSong(int i) {
    songs.erase(songs.begin() + i);
}
