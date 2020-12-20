# Computing_IV

A collection of assignments completed for COMP.2040 at UMass Lowell


## PS0: Hello World with SFML

The goal of this assignment was to display a sprite, as well as adding the ability to move the sprite with the arrow keys. For this assignment, I used the Simple Fast Media Library (SFML). Additionally, I was instructed to add an extra feature for functionality. For my PS0, I ended up adding text mentioning the famous result of Super Bowl 51, where the New England Patriots made a comeback against the Atlanta Falcons when they were up 28-3. The purpose of this assignment was to get familiar with the SFML library. I was able to learn how to load fonts, images, and sprites as well as learn how to move sprites according to keyboard inputs

![PS0 Output](https://github.com/anasahmed10/Computing_IV/blob/main/images/PS0/screenshot.PNG)

## PS1: Linear Feedback Shift Register

The goal of the assignment was to apply a Fibonacci Linear Feedback Shift Register (FibLSFR). in order to encrypt and decrypt an image. That was done by feeding the input file name, output file name, and seed number in the command line when calling the program. Once started, the program will initialize a FibLSFR with the stated seed and proceed to run the generate(8) function for each pixel as part of the transform function. In doing so, each pixel is given a completely new value. Once the transform function is finished, two windows will appear one with the morphed image, another with the original. Executing the program again with the same seed on the encrypted image will transform it back into the original. This assignment helped acquaint me with the image transformation functions within the SFML library. I also learned how to output an image to file in C++.

![PS1 Output](https://github.com/anasahmed10/Computing_IV/blob/main/images/PS1/encode.png)

## PS2: Recursive Pythagoras Tree 

The goal of this assignment was to recursively draw a Pythagoras Tree using the SFML library. A Pythagoras Tree is created by drawing a base square, and then drawing one additional square on each side. The process is then repeated until the tree is complete. Originally, I used SFML’s draw convex shape method, but I then switched to the draw rectangle method which ended up benefiting my code greatly, as it took less steps to draw each square. I learned how to draw shapes using the SFML library and gained exposure to an advanced application of recursion. I normally prefer iterative programming, so it was beneficial to venture outside of my “comfort zone” in this project.

![PS2 Output](https://github.com/anasahmed10/Computing_IV/blob/main/images/PS2/output.PNG)

## PS3: N-Body Simulation 

The goal of this assignment was to render a galaxy using two classes, universe and cBody. cBody is a class which is made to represent any body rendered in the universe, whether it be the sun or a planet. Universe is a class which contains a vector of cBodies and has a function to draw the entire universe by accessing the vector. The universe is drawn by reading through a text file and assigning values from the file. The second part of this assignment was to add physics simulation and animation. The concepts applied were Newton’s law of universal gravitation and leapfrog finite difference approximation.  I used a smart pointer to represent the universe which helped avoid memory troubles.

![PS3 Output](https://github.com/anasahmed10/Computing_IV/blob/main/images/PS3/Screenshot_2020-05-01%20PS3a(1)%20pdf.png)

## PS4: Synthesizing a Plucked String Sound

The goal of this assignment was to implement the Karplus-Strong algorithm to represent audio and add the ability for users to be able to play notes from keyboard inputs.  The first class used was the ringBuffer class which implemented a queue data structure using the 16-bit integer data type to represent frequencies. Next, I created the StringSound class which, using the ringBuffer class, applies the Karplus-Strong algorithm to properly represent the values of the frequencies. This assignment taught me how to use SFML’s sound functions. I also formatted my code to comply with Google’s cpplint coding guidelines.

![PS4 Output](https://github.com/anasahmed10/Computing_IV/blob/main/images/PS4/screenshot.png)

## PS6: Markov Model of Natural Language

The goal of this assignment was to build a Markov model used to predict occurrences of letters of the alphabet with a fixed probability. To accomplish this, I created a class called MModel which was made to represent a Markov Chain. Using a k-gram which represents any string of k characters this program attempts to predict the next letter.
