#include "BlindTest.h"
#include <iostream>
#include <thread>
#include <chrono>

BlindTest::BlindTest(dpp::cluster& bot) : bot(bot) {}

void BlindTest::startGame(const std::string& category) {
    currentCategory = category;
    // Here you would select a random song from the category
    // For demonstration, we will use a placeholder YouTube URL
    std::string youtubeUrl = "https://www.youtube.com/watch?v=YOUR_SONG_ID"; // Replace with actual URL
    playMusic(youtubeUrl);

    // Start a timer for 10 minutes
    std::thread([this]() {
        std::this_thread::sleep_for(std::chrono::minutes(10));
        endGame();
    }).detach();
}

void BlindTest::playMusic(const std::string& url) {
    std::string command = "ffmpeg -i \"$(youtube-dl -f bestaudio -g " + url + ")\" -f wav - | aplay";
    system(command.c_str());
}

void BlindTest::answerSong(const std::string& userId, const std::string& answer) {
    // Check if the answer is correct
    if (answer == currentSong) {
        globalScoreboard[userId]++;
        sessionScoreboard[userId]++;
        // Notify the user of their score
    }
}

void BlindTest::endGame() {
    // Logic to end the game, disconnect from voice channel, and display scores
}

void BlindTest::displayScoreboards(dpp::message& msg) {
    // Logic to display the global and session scoreboards
}

void BlindTest::on_message_create(const dpp::message_create_t& event) {
    // Check if the message is an answer to the song
    answerSong(std::to_string(event.msg.author.id), event.msg.content);
}