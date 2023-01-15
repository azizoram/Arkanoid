# Arkanoid

## Name
Arkanoid game by Azizov Ramir

## Task
It is necessary to develop a computer program that implements the game "Arkanoid" in the C++ programming language. This program implements the classic version of the Arkanoid game. The main window contains a platform that moves horizontally from one wall to another, blocks fixed in place, and a ball that bounces off the platform, walls and blocks, destroying them in the process. The platform is controlled using the keys "A" and "D", the launch of the ball at the beginning of the game by pressing the "space" key

## Description
Simple implementation of Arkanoid game 
## Implementation
    * GameObject:
This class is the base for all objects in the game. It handles all the movements and also collisions between two GameObjects.

    * Ball: 
Derived from GameObject. This is used before the user hits spacebar to start the game.

    * Brick:
Derived from GameObject. Not moveable. Has hitpoints and can be flaged destroyed.


    * Arkanoid:
Handles everything which happens in one played game.

    *Map:
Represents a game map

    *Paddle:
Derived from GameObject. The only thing new here is that it can be reset to the init position. 
More in Doxygen Documentation
    
## Installation
The program is run from the command line.

## Authors and acknowledgment
@azizoram 2023 

## Project status
Completed
