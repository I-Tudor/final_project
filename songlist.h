#ifndef SONGLIST_H
#define SONGLIST_H
#include <string>
#include <vector>
#include "song.h"

class songList
{
private:
    std::vector<Song> songs;

public:
    songList();
    std::vector<Song> getSongs();
    Song getSong(int i);
    void addSong(Song song);
    void deleteSong(int i);
};



#endif // SONGLIST_H
