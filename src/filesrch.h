/// \file
/// \brief Support to find files

#ifndef __FILESRCH_H__
#define __FILESRCH_H__

#include "doomdef.h"
#include "d_netfil.h"

/**	\brief	The filesearch function

	This function search files, manly WADs and return back the status of the file

	\param	filename	the file to look for
	\param	startpath	where to start look from
	\param	wantedmd5sum	want to check with MD5
	\param	completepath	want to return the complete path of the file?
	\param	maxsearchdepth	the max depth to search for the file

	\return	filestatus_t


*/

filestatus_t filesearch(char *filename, const char *startpath, const UINT8 *wantedmd5sum,
	boolean completepath, int maxsearchdepth);

#define menudepth 20

extern char menupath[1024];
extern size_t menupathindex[menudepth];
extern size_t menudepthleft;

extern char **dirmenu;
extern size_t sizedirmenu;
extern size_t dir_on[menudepth];

typedef enum
{
	EXT_FOLDER = 0,
	EXT_UP,
	EXT_START,
	EXT_TXT = EXT_START,
	EXT_CFG,
	EXT_WAD,
	EXT_SOC,
	EXT_LUA, // allowed even if not HAVE_BLUA so that we can yell on load attempt
	NUM_EXT,
	NUM_EXT_TABLE = NUM_EXT-EXT_START
} ext_enum;

boolean preparefilemenu(void);

#endif // __FILESRCH_H__
