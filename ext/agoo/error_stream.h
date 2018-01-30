// Copyright (c) 2018, Peter Ohler, All rights reserved.

#ifndef __AGOO_ERROR_STREAM_H__
#define __AGOO_ERROR_STREAM_H__

#include <ruby.h>

struct _Server;

extern void	error_stream_init(VALUE mod);
extern VALUE	error_stream_new(struct _Server *server);

#endif // __AGOO_ERROR_STREAM_H__
