#include "Song.h"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

Song::Song(std::string artist, std::string title, std::string duration, std::string link) : artist(artist), title(title), duration(duration), link(link)
{
    this->artist = artist;
    this->title = title;
    this->duration = duration;
    this->link = link;
}

std::string Song::getArtist()
{
    return artist;
}

std::string Song::getTitle()
{
    return title;
}

std::string Song::getDuration()
{
    return duration;
}

std::string Song::getLink()
{
    return link;
}
