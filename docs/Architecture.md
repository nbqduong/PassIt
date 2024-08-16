# Game architecture
This game can be parsed into:
- Setting: Init game setting
- UI components: Display windows, buttons, game components, input keyboard
- Command and logic: Handle inputs from UI components, control game logic
- Game components: Contains game components and their attributes

Similar to UI applications, this game can designed based on:
- Three-tiered architecture
- Model-View architectures
  - **In this project, UI components always update at FPS, UI components should access direct to Game components to get information, MV will be better choice**

