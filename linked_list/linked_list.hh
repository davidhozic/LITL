#ifndef SEZNAM_INC
#define SEZNAM_INC

#include <stdlib.h>
#include <stdint.h>


#include "list_settings.hh"







#if (USE_FREERTOS_MALLOC == 1)
	#include "FreeRTOS.h"
#endif


template <typename tip>
class class_LIST
{
private:

    class vozlisce_data_obj_t
    {
    public:
        friend class class_LIST<tip>;

    private:
        vozlisce_data_obj_t *naslednji;
        vozlisce_data_obj_t *prejsnji;
        tip podatek;
    };

    vozlisce_data_obj_t *glava = NULL;
    unsigned short count = 0;
    unsigned short glava_index = 0;

    inline void pojdi_zacetek()
    {
        while (glava != NULL && glava->prejsnji != NULL)
        {
            glava = glava->prejsnji;
        }
    }

    inline void pojdi_konec()
    {
        while (glava != NULL && glava->naslednji != NULL)
        {
            glava = glava->naslednji;
        }
	}

public:



    inline unsigned short length()
    {
        return count;
    }
	
    void clear()
    {
        pojdi_zacetek();
        while (glava != NULL)
        {
            vozlisce_data_obj_t *temp = glava->naslednji;
		#if (AVR_MODE == 0)
            delete (glava);
		#else
			free(glava);
			#warning "WARNING! AVR_MODE is enabled which means free() will be used instead of delete() which WILL cause MEMORY leaks if you delete a MULTI-dimensional list. If 1D list is used, there will be no problems."
		#endif
            glava = temp;
        }
        count = 0;
    }

    /* Deconstructor to delete sub elements */
    ~class_LIST()
    {
        clear();    // Clears sub elements of the head in case head is another linked list
    }


    
	void add_front(tip vrednost)
    {
	#if (USE_FREERTOS_MALLOC == 1)
        vozlisce_data_obj_t *nov = (vozlisce_data_obj_t *) pvPortMalloc(sizeof(vozlisce_data_obj_t));
    #else
		vozlisce_data_obj_t *nov = (vozlisce_data_obj_t *) malloc(sizeof(vozlisce_data_obj_t));
	#endif
		pojdi_zacetek();

        if (glava != NULL)
        {
            glava->prejsnji = nov;
        }
        nov->prejsnji = NULL;
        nov->naslednji = glava;
        nov->podatek = vrednost;
        glava = nov;
        count++;
        glava_index = 0;
    }

    void add_end(tip vrednost)
    {

	#if (USE_FREERTOS_MALLOC == 1)
		vozlisce_data_obj_t *nov = (vozlisce_data_obj_t *) pvPortMalloc(sizeof(vozlisce_data_obj_t));
	#else
		vozlisce_data_obj_t *nov = (vozlisce_data_obj_t *) malloc(sizeof(vozlisce_data_obj_t));
	#endif

        pojdi_konec();
        if (glava != NULL)
        {
            glava->naslednji = nov;
        }
        nov->prejsnji = glava;
        nov->naslednji = NULL;
        nov->podatek = vrednost;
		glava = nov;
        count++;
        glava_index = count - 1;
    }

    tip &operator[](unsigned short index)
    {
		while (glava_index < index)
        {
            glava = glava->naslednji;
            glava_index++;
        }
		
        while (glava_index > index)
        {
            glava = glava->prejsnji;
            glava_index--;
        }

        return (glava->podatek);
    }
};


#endif
