/*! \page how_to_contribute how to contribute
 *
 *  how_to_contribute.h
 *
 * @copyright said0042:Maryan Said.
 * 
 * how to contribute:
 *
 * Our work process on our git-hub repository for iterations was that for each sprint we would create a new 
 * milestone that has the deadline. For each sprint we prepared a list of things to do in our project on Github at 
 * the start and then each member assigned themselves one of the list items and created an issue for it. 
 * The issues were labeled differently based on their categories and keys. The developer assigned to the issue 
 * created a new branch in the feature/issue branches for each issue, and the name of the issue included the 
 * issue's functionality/pattern name as well as how many points it was worth. When a developer is finished with an 
 * issue, he or she submits a pull request to the developer branch with the same name as the branch that was created for  the issue, and one 
 * other developer reviews the changes and either accepts or comments on what is wrong with the new modifications. 
 * Both the issues and the pull requests were assigned to the corresponding milestones. At the end of the milestone 
 * all finished issues and pull requests were closed, and items that were completed were removed to the done section 
 * of the project and the developer branch was merged with the mainin branch. In Terms of Coding style, This project’s coding style was mainly based on the google c++ guide. 
 * Mainly, all our .cc files have a .h file associated with them to ease readability and better performance.  
 * Also, all header files had #define guards to prevent multiple inclusion. We have also used general naming rules by 
 * assigning variables names that have meanings within the contexts. Moreover, we used classes instead of structs
  * for this project; this also goes along with the google guide as it advises to use structs only for passive 
  * objects that carry data that we do not have in this project. More importantly, we had to use classes for
   * inheritance purposes as a lot of our classes use the same method repeatedly as the filter classes. 
   * Also, classes were more suited for this project as the objects of this class were mostly non-passive and it was more
    * appropriate for them to be private and not edited by mistakes such as the unsigned char that holds the pixel 
  * values in the image class. We have also included the big-3, a destructor, an overloader, and a copy constructor 
  * in every class that uses dynamic allocation to prevent memory leaks and segfaults.
  */
