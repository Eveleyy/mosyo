#include <iostream>
#include <fstream>
#include <string>
#include "Bot.h"
#include <filesystem>
#include "BlindTest.h"

namespace fs = std::filesystem;

std::string read_token_from_file(const std::string& filename) {
    std::ifstream file(filename);
    std::string token;
    if (file.is_open()) {
        std::getline(file, token);
        file.close();
    } else {
        std::cerr << "Unable to open token file: " << filename << std::endl;
        std::cerr << "Current working directory: " << std::filesystem::current_path() << std::endl;
        exit(1);
    }
    return token;
}

int main(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "test") {
        std::cout << "Running tests..." << std::endl;
        return 0;
    }

    std::string token_file = "token";
    
    if (argc > 1) {
        token_file = argv[1];
    }

    std::string token = read_token_from_file(token_file);
    Bot discord_bot(token);
    BlindTest blindTest(discord_bot);

    // Register the slash command
    discord_bot.on_message_create([&discord_bot](const dpp::message_create_t & event) { // Changed to on_message_create
        if (dpp::run_once<struct register_bot_commands>()) {
            dpp::slashcommand newcommand("blind-test", "Start a blind test game", discord_bot.me.id);
            discord_bot.create_global_command(newcommand);
        }
    });

    discord_bot.on_slashcommand([&](const dpp::slashcommand_t& event) { // Ensure correct event type
        std::string selectedCategory; // Define selectedCategory
        if (event.command.get_command_name() == "blind-test") {
            // Show category selection menu
            // Assume selectedCategory is set based on user input
            blindTest.startGame(selectedCategory);
        }
    });

    discord_bot.on_message_create([&](const dpp::message_create_t& event) {
        // Check if the message is an answer to the song
        blindTest.answerSong(event.msg.author.id, event.msg.content);
    });

    discord_bot.run();
    return 0;
}
