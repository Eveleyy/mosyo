#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <dpp/dpp.h>

class MusicPlayer {
public:
    static void playMusic(dpp::cluster& bot, const std::string& songPath, const std::string& channelId);
};

#endif // MUSICPLAYER_H
