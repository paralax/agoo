// Copyright (c) 2018, Peter Ohler, All rights reserved.

#ifndef __AGOO_TYPES_H__
#define __AGOO_TYPES_H__

typedef enum {
    HTTP_CONNECT	= 'C',
    HTTP_DELETE		= 'D',
    HTTP_GET		= 'G',
    HTTP_HEAD		= 'H',
    HTTP_OPTIONS	= 'O',
    HTTP_POST		= 'P',
    HTTP_PUT		= 'U',
    HTTP_ALL		= 'A',
    HTTP_NONE		= '\0',
} Method;

#endif // __AGOO_TYPES_H__
