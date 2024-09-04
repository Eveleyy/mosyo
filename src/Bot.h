#ifndef BOT_H
#define BOT_H

#include <string>
#include <dpp/dpp.h>

class Bot {
private:
    std::string token;
    dpp::cluster* bot;

public:
    // Constructor
    Bot(const std::string& token);

    // Destructor
    ~Bot();

    // Method to run the bot
    void run();
};

#endif // BOT_H
