/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name: Anas Ahmed
Hours to complete assignment: 25 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The goal of this assignment was to render a galaxy using two classes, universe and cBody. Universe is a class which contains a vector of cBodies and also has a function to draw the planets by accessing
the vector.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
universe was a vector of cBody which was used to hold all the planets that were received from planets.txt. cBody was similar to a base class because universe uses functions from cBody when accessing
the class.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
  std::unique_ptr<universe>u(new universe());
	I used a smart pointer to represent the universe which helped avoid memory troubles. The universe was allocated through the following for loop:
 for(int i = 0; i < uParticles;i++)
    {
      planet = new cBody();
      cin >> *planet;
      (*u).pushback(*planet);
      cout << *planet;
    }
	
	I had to make a pushback function in order to assign cBodies to the vector. 

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I had some compiler errors initially but after troubleshooting, I realized that it was a problem with my Makefile.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 I added the background image for extra credit.