#ifndef SEZNAM_INC
#define SEZNAM_INC
#include <stdlib.h>
#include <stdint.h>
#include "list_settings.hh"

#if (USE_FREERTOS == 1)
	#include "FreeRTOS.h"
#endif

#if (INCLUDE_IOSTREAM == 1)
    #include <iostream>
#endif




template <typename tip>
class class_LIST
{
private:

    struct vpdt
    {
        friend class class_LIST<tip>;
    private:
        vpdt *naslednji;
        vpdt *prejsnji;
        tip podatek;
        
    };

    vpdt *glava = NULL;
    unsigned long count = 0;
    unsigned long glava_index = 0;

    void pojdi_zacetek();
    void pojdi_konec();
    void head_to_index(uint32_t &index);
    
public:

    unsigned short length();
	void add_front(tip vrednost);
    void add_end(tip vrednost);
    tip pop_end();

#if (INCLUDE_SORT == 1)
    void sort(tip(*comparator_fnct)(tip , tip));
#endif


#if (INCLUDE_IOSTREAM == 1)
    void print_console();
#endif

    void remove_by_index(uint32_t index);
    void splice(uint32_t index, uint32_t num_to_remove);


    /*************************************************/
#if (USE_OPERATORS == 1)
    tip &operator[](unsigned long index);
   
    class_LIST<tip> operator+(tip pod);
    
    void operator+=(tip pod);


#endif
};
    
#if (USE_OPERATORS == 1)
template <typename tip, class cl>
class_LIST<tip> operator+(tip pod, cl obj);
#endif




#include "llist_funct.hh"

#endif

