// Copyright (c) 2018, Peter Ohler, All rights reserved.

#ifndef __AGOO_REQUEST_H__
#define __AGOO_REQUEST_H__

#include "hook.h"

struct _Res;
struct _Server;

typedef struct _Str {
    char		*start;
    unsigned int	len;
} *Str;

typedef struct _Req {
    struct _Server	*server;
    Method		method;
    struct _Str		path;
    struct _Str		query;
    struct _Str		header;
    struct _Str		body;
    VALUE		handler;
    HookType		handler_type;
    struct _Res		*res;
    size_t		mlen;   // allocated msg length
    char		msg[8]; // expanded to be full message
} *Req;

extern void	request_init(VALUE mod);
extern VALUE	request_wrap(Req req);
extern VALUE	request_env(Req req);

#endif // __AGOO_REQUEST_H__
