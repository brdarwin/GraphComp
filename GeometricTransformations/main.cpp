#include <iostream>
#include <SFML/Graphics.hpp>


int main(){
    float maxSizeX = 1000;
    float maxSizeY = 1000;
    sf:: RenderWindow theWindow(sf::VideoMode(maxSizeX,maxSizeY),  "Geometric Transformations");
    
    theWindow.setFramerateLimit(60);
    float squareDimensions = 100;
    sf :: RectangleShape red(sf :: Vector2f(squareDimensions,squareDimensions));
    red.setFillColor(sf :: Color(255,0,0));
    sf :: RectangleShape blue(sf :: Vector2f(squareDimensions,squareDimensions));
    blue.setFillColor(sf :: Color(0,0,255));
    
    sf :: RectangleShape green(sf :: Vector2f(squareDimensions,squareDimensions));
    green.setFillColor(sf :: Color(0,255,0));  
    sf :: Transform transformBlue;
    sf :: Transform transformGreen;
    sf :: Transform transformRed;
    float transfIndex = 1; 
    red.setOrigin(50,50);
    red.setPosition(500,500);
    blue.setPosition(550,550);
    //blue.setOrigin(500,500);
    //mySquare.setOrigin(sf :: Vector2f(100, 100));
    //mySquare.setPosition(sf :: Vector2f(maxSizeX/2, maxSizeY/2));
    while(theWindow.isOpen()){
       

        sf::Event event;
        while (theWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                theWindow.close();
            }
        
        }
        //red.rotate(1);
        //blue.setOrigin(red.getPosition.y)
        //blue.rotate(1);
        theWindow.draw(blue);
        theWindow.draw(red);
        theWindow.display();
        theWindow.clear();
        
	    
    }

    return 0;
};