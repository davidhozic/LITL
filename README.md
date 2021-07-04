# LITL
The LITL library - Linked-list, Input, Timer, Library



- INPUT:
  - An input class for avr inputs
  - Supports: Rising Edge, Falling Edge, Filtering (requres castimer)
  - Initialization :  INPUT_t example("pin","port", bool invert state);  or  INPUT_t example = INPUT_t("pin","port", bool invert state);
                                                    If invert state is set to 1, the input's value will be inverted from the PIN register value
  - Functions: 
    - bool value(); -> Returns value of the input
    - bool risen_edge();  -> Returns 1 if input went from 0 to 1 from the last function call, the risen edge bit is cleared if this function is called or if input is 0
    - bool fallen_edge(); -> Returns 1 if input went from 1 to 0 from the last function call, the fallen edge bit is cleared if this function is called or if input is 1
  
- TIMER:
  - A universal timer class, if on interrupt mode, then it will only work on avr.
  - Supports interrupt mode (every timer is incremented in an ISR) or system time mode (time difference)
  - Functions: 
    - uint32_t value(); -> Starts the timer and returns the value
    - void reset();     -> Resets the timer and disables it
	  - void set_hook(function to call, calling period, pointer of parameter to send to function); [ ONLY AVAILABLE IN INTERRUPT MODE] -> attaches function to the timer which gets called every specified period, then the timer auto reloads. To reset back into normal mode, call this function again but with NULL, 0, NULL as parameters.
- LINKED LIST:
  - A linked list without constructor (can be used even before call of function main), supports operator overloads, and many other high language features.
  - It uses a TEMPLATE PARAMETER meaning you can tell it what the variable type will be.
  - FUNCTIONS:
        
     *  FUNCTION:    length()
     *  PARAMETERS:  void
     *  DESCRIPTION: Returns the number of elements in the list     
     *  RETURN:      void                                   
     

    unsigned short length();


    
     *  FUNCTION:    add_front()
     *  PARAMETERS:  custom_type value
     *  DESCRIPTION: adds element to the front of the list  
     *  RETURN:      void               
     

    void add_front(your_data_type value);

    
     *  FUNCTION:    add_end()
     *  PARAMETERS:  custom_type value
     *  DESCRIPTION: adds element to the end of the list        
     *  RETURN:      void         
     

    add_end(your_data_type value);


    
     *  FUNCTION:    pop_end()
     *  PARAMETERS:  void
     *  DESCRIPTION: removes the last element and returns it
     *  RETURN:      Custom type element at the end of the list                     
     

    your_data_type pop_end();



    
     *  FUNCTION:    sort()
     *  PARAMETERS:  int function_comparator_function (must return < 0 if element 1 is before element 2)
     *  DESCRIPTION: Sorts elements in the list                         
     *  RETURN:      void
     

    void sort(comparator function);

    
     *  FUNCTION:    print_console()
     *  PARAMETERS:  void
     *  DESCRIPTION: Prints the contents of the list to the console  ( elements must be a string or a number )                         
     *  RETURN:      void
     

    void print_console();


    
     *  FUNCTION:    remove_by_index ()
     *  PARAMETERS:  uint32_t index of element to remove
     *  DESCRIPTION: Removes the element by index,  moves the contents on the right to the left                        
     *  RETURN:      void
     

    remove_by_index(uint32_t index);


    
     *  FUNCTION:    splice ()
     *  PARAMETERS:  uint32 start_index, uint32 number of elements to remove
     *  DESCRIPTION: Removes the specified number of elements, starting at start index  
     *  RETURN:    void
     

    splice(uint32_t start_index, uint32_t num_to_remove);



    /
                                           OPERATORS                                              
    /

    
     *  OPERATOR:    [] 
     *  PARAMETERS:  unsigned long index
     *  DESCRIPTION: returns the element at specific index by reference                    
     *  RETURN:      Reference return of custom type data at specific index
     


    your_data_type &operator[](unsigned long index)

    
     *  OPERATOR:    +=
     *  PARAMETERS:  custom data
     *  DESCRIPTION: Adds data to the back of the list                   
     *  RETURN:      void
     

    operator+=(your_data_type pod);
