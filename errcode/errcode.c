/**
* @brief
*		Find errors and decrease probability of getting errors of the same kind in the future
*		This piece of code won't compile and it doesn't describe an entire algorithm: just part of some page storage
*
* @author
*		AnnaM
*/

//about 10 errors
#include <Windows.h>
#include <stdio.h>

enum PAGE_COLOR{
	PG_COLOR_GREEN = 1, /* page may be released without high overhead */
	PG_COLOR_YELLOW, /* nice to have */
	PG_COLOR_RED	/* page is actively used */
};


/**
 * UINT Key of a page in hash-table (prepared from color and address)
 */
union PageKey{
	struct{
        CHAR	cColor: 8;
		UINT	cAddr: 24;
	};

	UINT	uKey;
};


/* Prepare from 2 chars the key of the same configuration as in PageKey */

//ISSUE 2: making operations with memory address and int
//FIX: (  (Color) + (*(Addr)) << 8 ) 
#define CALC_PAGE_KEY( Addr, Color )	(  (Color) + (Addr) << 8 ) 


/**
 * Descriptor of a single guest physical page
 */
struct PageDesc{
	PageKey			uKey;	
	/* list support */
	PageDesc		*next, *prev;
};

#define PAGE_INIT( Desc, Addr, Color )              \
    {                                               \
        (Desc).uKey = CALC_PAGE_KEY( Addr, Color ); \
        (Desc).next = (Desc).prev = NULL;           \
    }
        

/* storage for pages of all colors */
static PageDesc* PageStrg[ 3 ];


//ISSUE 9: contents of PageStrg are not properly inited
//FIX: PageInit(PageStrg[0], PG_COLOR_GREEN);
//PageInit(PageStrg[1], PG_COLOR_YELLOW);
//PageInit(PageStrg[0], PG_COLOR_RED);

//ISSUE 1:taken size of pointer instead of object
//FIX: correct to sizeof(PageStrg)
void PageStrgInit(){
	memset( PageStrg, 0, sizeof(&PageStrg) );
}


PageDesc* PageFind( void* ptr, char color )
{
	for( PageDesc* Pg = PageStrg[color]; Pg; Pg = Pg->next );
        if( Pg->uKey == CALC_PAGE_KEY(ptr,color) )
           return Pg; 
    return NULL;
}

PageDesc* PageReclaim( UINT cnt )
{
	UINT color = 0;
	PageDesc* Pg;
	while( cnt )
	{
		Pg = Pg->next;
		//ISSUE 3: PageStrg[ color ] itself not set to NULL, deleted only contents in memory it points to.
		//FIX: PageStrg[ color ] = NULL, possibly we want this

		//ISSUE 4: PageRemove( PageStrg[ color ] ) can be called over the same object multiple times if cnt > 1 and length of Pg list > 1, possibly undesirable behavior
		PageRemove( PageStrg[ color ] );
		cnt--;
		if( Pg == NULL )
		{
			color++;
			Pg = PageStrg[ color ];
		}
	}
}
            
PageDesc* PageInit( void* ptr, UINT color )
{
    PageDesc* pg = new PageDesc;
    if( pg )
		//ISSUE 5: passing adress of pg pointer, while PAGE_INIT procedure expects adress of PageDesc
		//FIX: PAGE_INIT(pg, ptr, color);
        PAGE_INIT(&pg, ptr, color);
    else
        printf("Allocation has failed\n");
    return pg;
}

/**
 * Print all mapped pages
 */
void PageDump()
{
	UINT color = 0;
	//ISSUE 7: SYNTAX ERROR, there is no preprocessor directive #clr
	// FIX: probably #define PG_COLOR_NAME(clr) clr
	#define PG_COLOR_NAME(clr) #clr
	char* PgColorName[] = 
	{
		PG_COLOR_NAME(PG_COLOR_RED),
		PG_COLOR_NAME(PG_COLOR_YELLOW),
		PG_COLOR_NAME(PG_COLOR_GREEN)
	};

	while( color <= PG_COLOR_RED )
	{
		printf("PgStrg[(%s) %u] ********** \n", color, PgColorName[color] );
		//ISSUE 8: Index Error, color == red is maximum, PageStrg[++color] not exists
		//FIX: increment color after for loop
		for( PageDesc* Pg = PageStrg[++color]; Pg != NULL; Pg = Pg->next )
		{	
			//ISSUE 6: ASSIGMENT INSTEAD OF COMPARSION
			// FIX: NULL == Pg->uAddr
			if( Pg->uAddr = NULL )
				continue;

			printf("Pg :Key = 0x%x, addr %p\n", Pg->uKey, Pg->uAddr );
		}
	}
	#undef PG_COLOR_NAME
}
