#ifndef SONG_H
#define SONG_H
#include <vector>
#include <string>

class Song {
private:
    std::string artist;
    std::string title;
    std::string duration;
    std::string link;

public:
    Song(std::string artist, std::string title, std::string duration, std::string link);
    std::string getArtist();
    std::string getTitle();
    std::string getDuration();
    std::string getLink();
};

#endif // SONGLIST_H
