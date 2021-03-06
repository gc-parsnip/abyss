# Abyss
 > Authors: [James Liem](https://github.com/S-Kurisu), [James Zhang](https://github.com/MachineLearningAmateur), [Gavin Ceballos](https://github.com/gc-parsnip)

## Project Description
 > This project will be an endless game. The player will descend from floor to floors, thus going deeper into the abyss. Each floor will contain mobs or possibly a puzzle. This is an interesting project because it is very open ended and there will be a lot of user interactions that need to be anticipated and adding code that will enable various forms of floors. There is also room for creativity in the dialogue of this game project. A storyboard may also be considered.
 > This project will use mainly C++.
 > The input of this project will be user text inputs and the output of this project will be machine and program text outputs.
 > The two design patterns that will be used in the project are:
 > * Composite:
 >   * The first design pattern was chosen because of class hierarchical structure and it will help implement things like the player characters, enemies, items, and room structure. This allows objects and compositions to be treated pretty uniformly.
 >   * There may be some problems when making the project like combat and exploration and those can be resolved by using this design pattern. 
 >   * This design pattern will be a good fix for that problem because the base class interface would allow a single function call that could recursively find and summate things like items or status that would affect the players actions.
 
 > * Builder:
 >   * The second design pattern was chosen because several aspects of the game are complex objects and it will help implement ways to build these complex objects without having to manually connect these objects together when we need them. (i.e. Creatures with items).  
 >   * There may be some problems when making the project like creating a system for generating floor levels with mobs that contain references to other objects. Problems like this can be resolved by using this design pattern.
 >   * The builder design pattern will allow these complex objects to be used with ease by separating its construction from its representation.
 >   * It will be a good fix for manually connecting objects together because builders can instead be reused to create the objects we need.
 
 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > The builder pattern is laid out in the top right of the diagram, showing both how floors and monsters can be built and that building monsters is a requirment of building floors. The bottom of the diagram has the class StatPot, which implements the Composite pattern, allowing for pots that will be used to generate interesting stat changes for the user by combining AttPots and HealthPots through the use of ComboPot and NegatePot Classes. The left side of the diagramm contains the common interfaces for both floors and BasicUnits which make up the main pieces of the game (placed by builders).
 > ![OMT.png](https://github.com/cs100/final-project-jliem001-gceba003-jzhan326/blob/master/Images/FinalProjectUpdatedOMT.png?raw=true)

 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 >  ![1.png](https://github.com/cs100/final-project-jliem001-gceba003-jzhan326/blob/master/Images/1.png?raw=true)
 >  * Main Menu/Initial Instances
 >  
 >  ![2.png](https://github.com/cs100/final-project-jliem001-gceba003-jzhan326/blob/master/Images/2.png?raw=true)
 >  * Combat/Consumable Interaction
 >  
 >  ![3.png](https://github.com/cs100/final-project-jliem001-gceba003-jzhan326/blob/master/Images/2.png?raw=true)
 >  * Combat/EndGame
 >  
 ## Installation/Usage
 > * Open terminal. Run these commands on terminal. 
 >     1. git clone https://github.com/cs100/final-project-jliem001-gceba003-jzhan326.git
 >     2. cd into cloned directory. 
 >     3. cmake .
 >     4. make
 >     5. ./abyss
 >     6. Enjoy the game!
 ## Testing
 > We tested our program with unit tests selected for each specific sets of class. We also used Valgrind to address the memory leaks and identify the segmentation faults. 
 
