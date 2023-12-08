# Meeting Notes

In this file, you are required to take notes for your weekly meetings.
In each meeting, you are required to discuss:

1. What each member has done during the week?
2. Are there challenges or problems? Discuss the possible solutions
3. Plan for the next week for everyone
4. Deviations and changes to the project plan, if any

# Meeting 23.10.2023 12::00

**Participants**:

1. Mikhail Romanov
2. Kalle Lindgren
3. Aki Oura
4. Leo Teodosin

## Actions

1. Mikhail Romanov will start level class
2. Leo Teodosin will start object class
3. Kalle Lindgren will look into sfml
4. Aki Oura will help Leo with object class, and start designing models for towers and enemies

## Project status

Planning is complete, starting work on object and level classes. Also looking into sfml library

### TODOs

1. Level and Object classes
2. Get to know sfml library
3. Graphics

### ------------------------------------------------------------------------------------------------------

# Meeting 1.11.2023 14::00

**Participants**:

1. Mikhail Romanov
2. Kalle Lindgren
3. Aki Oura
4. Leo Teodosin

## Summary of works

1. Kalle Lindgren

   Watched sfml, look into cmake and made "src/game.hpp"

2. Aki Oura

   Drew five new characters

3. Leo Teodosin

   Made object, tower and enemy classes, also started making classes for each charrecter

4. Mikhail Romanov

   Made level and square classes

## Challenges

1. Random generated map function in level.hpp / level.cpp

## Actions

1. Kalle starts designing gui for the game
2. Aki draws all missing charrecters
3. Leo starts making classes for each charrecter
4. Mikhail makes cmake file for tests and helps leo

> Please reflect these action decisions in your git commit messages so that
> your group members and advisor can follow the progress.

## Project status

Under work

### TODOs

1. GUI
2. object class
3. charrecters textures

### ------------------------------------------------------------------------------------------------------

# Meeting 08.11.2023 14::00

**Participants**:

1. Mikhail Romanov
2. Kalle Lindgren
3. Aki Oura
4. Leo Teodosin

## Summary of works

1. Mikhail Romanov

   Modified Level and square classes that level stores all information of objects
   Helped Leo with object classes

2. Leo Teodosin

   Made subclasses to object for different towers and enemies

3. Aki Oura

   Made four new graphics for towers and enemies

4. Kalle Lindgren

   Made game class for GUI, and for future control of whole game

## Challenges

1. Attack function in object
2. In square class occupied_by enum was done first wrong

## Actions

1. Mikhail will update level if needed and will help leo with object class
2. Leo will continue with object class
3. Aki will do rest of the graphics
4. Kalle will continue with gui and ui

> Please reflect these action decisions in your git commit messages so that
> your group members and advisor can follow the progress.

## Project status

Under work

### TODOs

1. Mikhail: level and object classes
2. Leo: Object class
3. Aki: Graphics
4. Kalle: GUI

### ------------------------------------------------------------------------------------------------------

# Meeting 14.11.2023 14::00

**Participants**:

1. Mikhail Romanov
2. Kalle Lindgren
3. Aki Oura
4. Leo Teodosin

## Summary of works

1. Mikhail Romanov

   Made sfml to show textures of enemies and towers. Connecterd level to game class better

2. Kalle Lindgren

   Continues with GUI

3. Aki Oura

   Made five new charrecters

4. Leo Teodosin

   Made working object class with basic towers and enemies

## Challenges

1. Object class in general
2. Showing grid from level

## Actions

1. Mikhail will continue with connecting objects to game class
2. Aki will do textures for road, grass and all other charecters
3. Leo will continue with object and will do classes for every object type
4. Kalle will do finnish with gui

> Please reflect these action decisions in your git commit messages so that
> your group members and advisor can follow the progress.

## Project status

Under work

### TODOs

1. Mikhail will continue with sfml and level
2. Aki textures
3. Leo will continue with objects
4. Kalle will continue with gui

### ------------------------------------------------------------------------------------------------------

# Meeting 22.11.2023 14::00

**Participants**:

1. Mikhail Romanov
2. Kalle Lindgren
3. Aki Oura
4. Leo Teodosin

## Summary of works

1. Mikhail Romanov

   Connected object and its subclasses, modified move() function

2. Leo Teodosin

   Continued with object

3. Aki Oura

   Continued with textures, made then smaller and added textures for grass and road

4. Kalle Lindgren

   Developed sidemenu and started source handler.

## Challenges

1. Include mess in object class
2. Move function

## Actions

1. Mikhail will continue with animation and multithreading
2. Leo will finnish object subclasses
3. Aki will do UI
4. Kalle will continue with side menu UI and GUI

> Please reflect these action decisions in your git commit messages so that
> your group members and advisor can follow the progress.

## Project status

Under work

### TODOs

1. Mikhail animation and multithreading
2. Leo object subclasses
3. Aki UI
4. Kalle UI and GUI

### ------------------------------------------------------------------------------------------------------

# Meeting 29.11.2023 16::00

**Participants**:

1. Mikhail Romanov
2. Kalle Lindgren
3. Aki Oura
4. Leo Teodosin

## Summary of works

1. Mikhail Romanov

   Made animation for textures, added functions to level class, and started writhing documentation

2. Leo Teodosin

   Continued object class

3. Aki Oura

   Made design for UI and maps with Kalle

4. Kalle Lindgren

   Made tower drag button, side menu and upgrade mechanism

## Challenges

1. Animation
2. Multithreading so idea got canceled
3. remove_tower in level class is not working

## Actions

1. Mikhail balance enemies and towers abilities with Leo
2. Leo balance enemies and towers abilities with Mikhail
3. Aki will continues with UI
4. Kalle will continue with UI and sidemenu

> Please reflect these action decisions in your git commit messages so that
> your group members and advisor can follow the progress.

## Project status

Finishing touches

### TODOs

1. Mikhail balance of object
2. Leo balance of object
3. Aki UI
4. Kalle UI and GUI

### ------------------------------------------------------------------------------------------------------

# Meeting 05.12.2023 14::00

**Participants**:

1. Mikhail Romanov
2. Kalle Lindgren
3. Aki Oura
4. Leo Teodosin

## Summary of works

1. Mikhail

   Wrote documentation and debugged game for errors and made list of todos

2. Leo

   Balanced game, fixed objects and made abilities for enemies

3. Aki

   Aki helped UI and made screens for "you lost" and "you win"

4. Kalle

   Main menu, level chooser, and made manager for game states

## Challenges

1. Object abilities
2. Build instruction

## Actions

1. Mikhail will finish documentation, will fix animations
2. Leo will balance game and finish abilities
3. Kalle will comment his classes
4. Aki will help with documentation
5. All will write comments to their classes

## Project status

Finishing touched

### TODOs

1. Mikhail documentation
2. Leo abilities and balance
3. Kalle and aki documentation
