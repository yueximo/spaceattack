# spaceattack
Using C++ and the ge211 game engine, I designed a basic space shooter game.

Specifications:
1. The game starts with a space background with a spaceship at the bottom.
2. The user spaceship’s movement is controlled by the arrow keys (left and right arrows).
3. The user spaceship’s missiles, which travel at a constant initial velocity that does not change throughout the game, can be fired by pressing the spacebar.
4. The user spaceship has a set amount of health which will be displayed somewhere on the screen.
5. There is a timer somewhere on the screen that counts down starting from thirty seconds. This timer is used to establish when the game is over (as well as health points).
6. The user spaceship can only travel horizontally (y-coordinate is stationary). If it hits the sides of the screen, it will not be able to move further in that y direction.
7. Throughout the game, enemy spaceships will enter, moving from the top of the screen to the bottom. The enemy spaceships will vary from size, velocity, and health. As the game goes on, “stronger” (higher velocity and more health) enemies will show up. 
8. If the missiles launched by the user spaceship touches the enemy spaceship, it will take 1 health point off of the enemy. Once the enemy hits 0 health, it will disappear.
9. If an enemy spaceship hits the bottom of the screen, without being destroyed, it will take off a certain amount of health off the user spaceship (depending on the type of enemy spaceship, the more “stronger” enemies will take off more health off the user).
10.The game will end once the user survives for 30 seconds. If the user reaches 0 health points before the end of the 30 seconds, the user will lose.
END GAME:
If the user survives for 3 minutes and wins, the game will stop and text saying “YOU WIN!” will appear on the screen.
If the user does not survive for 3 minutes and loses, the game will stop and text saying “YOU LOSE!” will appear on the screen.

<p align="center">
  <img width="1920" height="1080" src="https://user-images.githubusercontent.com/94990857/144702317-a21a75e3-a632-4feb-958e-0a6c4bab0725.gif">
</p>


