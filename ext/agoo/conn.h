// Copyright (c) 2018, Peter Ohler, All rights reserved.

#ifndef __AGOO_CON_H__
#define __AGOO_CON_H__

// The name of the file is conn.h instead of con.h since windows sees to
// reserve that file name and hangs the compile if the file is named con.h.
#ifndef IS_WINDOWS
#include <poll.h>
#endif
#include <stdbool.h>
#include <stdint.h>

#define MAX_HEADER_SIZE	8192

struct _Err;
struct _Req;
struct _Res;
struct _Server;

typedef struct _Con {
    int			sock;
    struct pollfd	*pp;
    char		id[32];
    uint64_t		iid;
    char		buf[MAX_HEADER_SIZE];
    size_t		bcnt;

    ssize_t		msize; // size of complete message
    ssize_t		mcnt;  // how much has been read so far

    ssize_t		wcnt;  // how much has been written

    struct _Server	*server;
    double		timeout;
    bool		closing;
    struct _Req		*req;
    struct _Res		*res_head;
    struct _Res		*res_tail;
} *Con;

extern Con		con_create(struct _Err *err, struct _Server *server, int sock, uint64_t id);
extern void		con_destroy(Con c);
extern const char*	con_header_value(const char *header, int hlen, const char *key, int *vlen);

extern void*		con_loop(void *ctx);

#endif /* __AGOO_CON_H__ */
