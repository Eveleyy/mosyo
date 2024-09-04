#include "Bot.h"
#include <iostream>
#include <memory>

// Constructor implementation
Bot::Bot(const std::string& token) : token(token) {
    // Create a new dpp::cluster object with the bot token
    bot = std::make_unique<dpp::cluster>(token);
}

// Destructor implementation
Bot::~Bot() {
    // Clean up the dynamically allocated bot object
    //delete bot;
}

// Method to run the bot
void Bot::run() {
    // Set up event handlers
    bot->on_log([](const dpp::log_t& event) {
        // Log the event message
        std::cout << "Log: " << event.message << std::endl;
    });

    bot->on_ready([this](const dpp::ready_t& event) {
        // Log when the bot is ready
        std::cout << "Bot is ready! Logged in as " << bot->me.username << std::endl;
    });

    // Start the bot
    bot->start(false);
}
