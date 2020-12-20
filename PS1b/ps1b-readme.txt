/**********************************************************************
 *  Linear Feedback Shift Register (part B) ps1b-readme.txt template
 **********************************************************************/

Name: Anas Ahmed
OS: Ubuntu Virtual Machine
Machine (e.g., Dell Latitude, MacBook Pro): Dell XPS 15
Text editor: Emacs 
Hours to complete assignment: 8 hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The goal of the assignment was to apply the previously built FibLSFR structure in order to encrypt and decrypt an image. That was done by feeding the input file name,
output file name, and seed number in the command line when calling the program. Once started, the program will initialize a FibLSFR with the stated seed and proceed to run the generate(8)
function 3 times for each pixel as part of the transform function. In doing so, each pixel is given a completely new value. Once the transform function is finished, two windows will appear
one with the morphed image, another with the original. Executing the program again with the same seed on the encrypted image will transform it back into the original.


/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/
N/A



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I had help on my transform function from Ambioris Lora. 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
One issue I encountered was I could not decrypt my image, but this was fixed by properly XORing the bits in the transform function.

I also initialized the windows last as I had found it greatly optimized the run time of my program.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/