/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Anas Ahmed
Hours to complete assignment: 15 Hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The goal of this assignment was to create a Linear Shift Feedback Register using a class implementation. This will be utilized in encrypting images. I implemented this by using a string in
as my class member variable which contained the bit string. I then included the string library so I would be able to access string functions which would help automate the process. The step function
took a long time to implement, but it was vital as the generate function calls the step function. The step function makes a new string and computes the XOR function first, then the bits are shifted
into the new string and the result of the XOR function is put at the back of the string.



/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/
N/A



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I worked with Ambioris Lora to make sure my step function was correct.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I had a problem where I initially used the int type for the variable last in the step function, so when the int was being placed at the back of the string, a distinct character appeared which was definitely
a null byte. By returning a character in the step function, I also had to subtract the char by 48 in order to get it to be either 0 or 1, or else 48 or 49 would appear as the return in the step function

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/