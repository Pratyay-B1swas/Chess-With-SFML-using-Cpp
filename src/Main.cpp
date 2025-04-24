#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

bool login() {
    string username, password;
    string storedUsername = "chess";
    string storedPassword = "checkmate";

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == storedUsername && password == storedPassword) {
        cout << "Login successful!" << endl;
        return true;
    } else {
        cout << "Invalid username or password. Try again." << endl;
        return false;
    }
}
int WinMain()
{
    if (!login()) {
        return 0;
    }
   
label:
    sf::RenderWindow window(sf::VideoMode(1200, 800),"The Chess", sf::Style::Titlebar | sf::Style::Close);
    Game chess(sf::Color::Black, sf::Color::White);
    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
            if (e.type == sf::Event::MouseButtonPressed)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    if (e.mouseButton.x >= 0 && e.mouseButton.x <= 800 && e.mouseButton.y >= 0 && e.mouseButton.y <= 800)
                    {
                        int x = e.mouseButton.y / 100, y = e.mouseButton.x / 100;
                        if (!chess.getSelected() && chess.isOver == false)
                        {
                            chess.SelectPiece(chess.cells, x, y);
                        }
                        else
                        {
                            chess.moveSelected(chess.cells, e.mouseButton.y / 100, e.mouseButton.x / 100);
                        }
                    }
                    if (e.mouseButton.x >= 850 && e.mouseButton.x <= 1024 && e.mouseButton.y >= 5 && e.mouseButton.y <= 55)
                    {
                        goto label;
                        
                    }
                }
                
            }
        }
        window.draw(chess);
        window.display(); 
    }
    return 0 ;
}