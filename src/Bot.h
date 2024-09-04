#ifndef BOT_H
#define BOT_H

#include <string>
#include <dpp/dpp.h>
#include <memory>

class Bot {
private:
    // Bot token
    std::string token;
    // Bot object
    std::unique_ptr<dpp::cluster> bot;

public:
    // Constructor
    Bot(const std::string& token);

    // Destructor
    ~Bot();

    // Method to run the bot
    void run();
};

#endif // BOT_H
