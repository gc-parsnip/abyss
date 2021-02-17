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
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
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
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
