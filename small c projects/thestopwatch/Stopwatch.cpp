//stop watch generator 

//this creates a pop up window that will show the user their time
// press space to start, press space to stop
//only in seconds no minutes 

//how to run:
//cd thestopwatch
//clang++ -std=c++17 Stopwatch.cpp -o stopwatch -lsfml-graphics -lsfml-window -lsfml-system

//./stopwatch


#include <SFML/Graphics.hpp>
#include <chrono>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 200), "Stopwatch");

    sf::Font font;
    // Replace this with your own font path!
    if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) {
        return -1;  // Failed to load font
    }

    sf::Text text("Press Space to start/stop", font, 24);
    text.setPosition(20.f, 50.f);
    text.setFillColor(sf::Color::White);

    bool running = false;
    auto start = std::chrono::steady_clock::now();
    std::chrono::seconds elapsed(0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                if (!running) {
                    running = true;
                    start = std::chrono::steady_clock::now();
                } else {
                    running = false;
                    elapsed += std::chrono::duration_cast<std::chrono::seconds>(
                        std::chrono::steady_clock::now() - start);
                }
            }
        }

        // Calculate current elapsed time
        std::chrono::seconds displayTime = elapsed;
        if (running) {
            displayTime += std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::steady_clock::now() - start);
        }

        // Update text string
        text.setString("Time: " + std::to_string(displayTime.count()) + " seconds\nPress Space to start/stop");

        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }

    return 0;
}
