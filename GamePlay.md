# Game instructions:

## Win condition:
When the player opens all the chests and moves to the magic gate(![Gate](assets/Ice/Gate.png)), this gate will disappear. The player win this round.

## Movement
Player can press UP(↑), DOWN(↓), LEFT(←), RIGHT(→) for movement

## Map
There is one round and two themes:
- **Ice map:**
![IceMap]()

- **Forest map:**
![ForestMap]()

## Objects
Objects in each theme have different outlooks but the same interaction:

### Bush
- This is a temporary object, the player can walk into it, and then it will disappear. 
- Ice: ![IceBush](https://github.com/nbqduong/PassIt/blob/main/assets/Ice/Bush.png)
Forest: ![ForestBush](https://github.com/nbqduong/PassIt/blob/main/assets/Beach/Bush.png)
- Demo: ![BushDemo](demo/bush-interrac.gif)

### Rock
- This is a solid object, the player can push it horizontally, and it will fall if there is nothing under it. 
- Ice: ![IceRock](https://github.com/nbqduong/PassIt/blob/main/assets/Ice/Rock.png)
 Forest: ![ForestRock](https://github.com/nbqduong/PassIt/blob/main/assets/Beach/Rock.png)
- Demo: ![RockDemo](demo/rock-interract.gif)

### Tree
- This is a solid object, the player cannot pass it. 
- Ice: ![IceTree](https://github.com/nbqduong/PassIt/blob/main/assets/Ice/Box.png)
 Forest: ![ForestTree](https://github.com/nbqduong/PassIt/blob/main/assets/Beach/Box.png)

### Chest
- The player can open it and collect a key.
- Chest: ![IceRock](https://github.com/nbqduong/PassIt/blob/main/assets/Ice/Chest.png)

### Gate
- After collecting all chests, after contact with the gate, it will open and the player win the game.
- Gate: (![Gate](assets/Ice/Gate.png))

## Gameplay example
![GamePlay](demo/demo-gameplay.gif)
