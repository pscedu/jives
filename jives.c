/* $Id$ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pfl/fs.h"

void
jives_fsop_open(struct pscfs_req *pfr, pscfs_inum_t inum, int oflags)
{
	pscfs_reply_open(pfr, NULL, 0, 0);
}

void
jives_fsop_read(struct pscfs_req *pfr, size_t size, off_t off, void *data)
{
	pscfs_reply_read(pfr, NULL, 0, 0);
}

void
jives_fsop_write(struct pscfs_req *pfr, const void *buf, size_t size,
    off_t off, void *data)
{
	pscfs_reply_write(pfr, 0, 0);
}

void
pscfs_module_load(struct pscfs *m)
{
	m->pf_handle_open = jives_fsop_open;
	m->pf_handle_read = jives_fsop_read;
	m->pf_handle_write = jives_fsop_write;
}
