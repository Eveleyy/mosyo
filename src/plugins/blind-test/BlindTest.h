#ifndef BLINDTEST_H
#define BLINDTEST_H

#include <string>
#include <map>
#include <vector>
#include <dpp/dpp.h>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <thread>
#include "../../Bot.h"

class BlindTest {
private:
    std::map<std::string, int> globalScoreboard;
    std::map<std::string, int> sessionScoreboard;
    std::string currentCategory;
    std::string currentSong;
    dpp::cluster& bot;

public:
    BlindTest(Bot& discord_bot); // Constructor accepting a Bot reference
    void startGame(const std::string& category);
    void answerSong(const std::string& userId, const std::string& answer);
    void endGame();
    void displayScoreboards(dpp::message& msg);
    void playMusic(const std::string& url);
    void on_message_create(const dpp::message_create_t& event); // Add this line
};

#endif // BLINDTEST_H
