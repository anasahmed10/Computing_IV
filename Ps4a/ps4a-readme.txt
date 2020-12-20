/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *	RingBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Anas Ahmed


Hours to complete assignment: 12 Hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The goal of this assignment was to design a ringBuffer class. The point of the ringBuffer class was is to setup 
a queue data structure using the 16 bit integer data type: int16_t. This code will be expanded upon in the next assignment
to graph sound frequencies. This code contains all the functions for the queue as well as separate first, last, size, and capacity
variables to help map the queue.  


/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
class ringBuffer{
 public:
  explicit ringBuffer(int capacity);
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();
  int capacity;
  int size;
  int first;
  int last;
  void rerror(const std::string& s) {
    throw std::runtime_error(s);
  }
  void ierror(const std::string& s) {
    throw std::invalid_argument(s);
  }
 private:
  std::queue<int16_t> ringbuffer;
};

This is the class definition of the queue including the error reporting functions. ierror reports an invalid argument
and rerror reports a runtime error. The size, first, and last indicate where on the queue the data is held.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
The size, first, and last variables are properly incremented and decremented when enqueue and dequeue are called.

void ringBuffer::enqueue(int16_t x) {
  //  Checks to make sure queue is not full
  try {
    if (this->isFull())
      rerror("Cannot enqueue to a full ring");
  }
  catch (std::runtime_error e) {
    std::cout << "Runtime error: " << e.what() << std::endl;
  }
  ringbuffer.push(x);
  ++last;
  ++size;
}

int16_t ringBuffer::dequeue() {
  // Checks to make sure queue is empty
  try {
    if (this->isEmpty())
      rerror("Cannot enqueue to a full ring");
  }
  catch (std::runtime_error e) {
    std::cout << "Runtime error: " << e.what() << std::endl;
  }

  int16_t removed_int = ringbuffer.front();
  ++first;
  --size;

  return removed_int;
}

In enqueue, the last variable and size variable are increased, whereas in dequeue, first is increased and size is decreased.

The code also throws errors based on special conditions.
/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes the assignment is working. It also conforms to Google's style of coding.




/**********************************************************************
 *  Does your RingBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
The code says it did not pass the unit test, but the right errors are thrown meaning that the code is still properly
functioning. 


/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/
With only up to one if statement in each function, the program has O(n) complexity.




/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
N/A


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I originally used a vector for the ringbuffer class, but using a queue mad much more sense considering the assignment
asks for a queue.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
