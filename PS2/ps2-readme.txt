/**********************************************************************
 *  ps2-readme template                                                   
 *  Recursive Graphics (Pythagoras tree)                       
 **********************************************************************/

Your name: Anas Ahmed

Hours to complete assignment: 15 Hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The goal of this assignment was to recursively draw a pythagoras tree using the SFML library. 


 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
I used the Rectangle drawing method, although I originally intended on using the convex shape method, once I revisited the rectangle function it made my code and the recursion much simpler.
I also created a class called PTree which held all the important factors in making the tree.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
This code uses two overloaded functions called in the constructor in order to generate the tree. The first function draws the middle square,

  if(N < 1) return; // Ends the recursion
  target.draw(parent);
  auto const& sz = parent.getSize();
  auto const& tf = parent.getTransform();


 then sets up the recursion for the left and right squares

  // Left side recursion call
  auto childL = parent;
  childL.setSize(sz * halfSqrt2);
  childL.setOrigin(0, childL.getSize().y);
  childL.setPosition(tf.transformPoint({0, 0}));
  childL.rotate(-45);
  PTree::drawPtree(target, N - 1, childL);

  // Right side recursion call
  auto childR = parent;
  childR.setSize(sz * halfSqrt2);
  childR.setOrigin(childR.getSize());
  childR.setPosition(tf.transformPoint({sz.x, 0}));
  childR.rotate(45);
  PTree::drawPtree(target, N - 1, childR);



 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
I learned how to draw shapes using the SFML library and also had more of an advanced application of recursion. Prior to this assignment I had only used iterative as it was what I preferred. 
It is good to be able to use recursion in a more complicated project such as this.


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/
I originally tried to use the ConvexShape function, but my code was not working, so I went back to using sf::RectangleShape. I left my previous code commented out in case you would like to look.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
I also made my PTree colored for the extra credit.