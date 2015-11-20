#include "Brick.h"
#include "../Scenes/GameplayScene.h"

Brick::Brick(Scene *scene, sf::Texture &texture) : GraphicalEntity(scene, "Brick", texture){
   velocity = 0.0;
}

void Brick::update() {
}

void Brick::manageCollision(GraphicalEntity *ge) {
   isBroken = true;
   GameplayScene* gameplayScene = dynamic_cast<GameplayScene*>(scene);
   if (gameplayScene != NULL) {
      gameplayScene->addPoints(100);
      gameplayScene->subtractEntity();
   }
}
