#include "Bot.h"
#include <iostream>

// Constructor implementation
Bot::Bot(const std::string& token) : token(token) {
    // Create a new dpp::cluster object with the bot token
    bot = new dpp::cluster(token);
}

// Destructor implementation
Bot::~Bot() {
    // Clean up the dynamically allocated bot object
    delete bot;
}

// Method to run the bot
void run() {
    // Set up event handlers
    bot->on_log([](const dpp::log_t& event) {
        std::cout << "Log: " << event.message << std::endl;
    });

    bot->on_ready([this](const dpp::ready_t& event) {
        std::cout << "Bot is ready! Logged in as " << bot->me.username << std::endl;
    });

    // Start the bot
    bot->start(false);
}
