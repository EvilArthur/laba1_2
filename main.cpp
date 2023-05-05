#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <windows.h>

class AnimatedText {
private:
    std::string sfmlText;
    int duration;
    int currentDuration = 0;

public:
    AnimatedText(const std::string& text, const int& durationText) {
        sfmlText = text;
        duration = durationText;
    }

    std::string animatedText() {
        currentDuration++;
        std::string out = sfmlText.substr(0, currentDuration);
        return out;
    }


    AnimatedText() {

    }
};



int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    sf::Font font;
    if (!font.loadFromFile("D:/IAMC/sfml_sample-main/Fonts/arial.ttf"))
        std::cout << "The font didn't load!" << std::endl;
    sf::Text sfmlText;
    sfmlText.setFont(font);
    sfmlText.setPosition(170, 250);


    std::string text = "Hello, world!";
    int durationText = 13;
    AnimatedText animatedText(text, durationText);
    while (window.isOpen())
    {
        sf::Event event;
        for (int i = 0; i < (durationText); i++)
        {
            sfmlText.setString(animatedText.animatedText());
            window.draw(sfmlText);
            window.display();
            Sleep(1000);
        }
        Sleep(500);
        window.close();


    }

    return 0;
}