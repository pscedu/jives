/* $Id$ */
/* %PSC_COPYRIGHT% */

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pfl/cdefs.h"
#include "pfl/ctl.h"
#include "pfl/ctlcli.h"
#include "pfl/fmt.h"
#include "pfl/getopt.h"
#include "pfl/log.h"
#include "pfl/pfl.h"
#include "pfl/str.h"

#include "../mount_jives/mount_jives.h"
#include "../mount_jives/ctl.h"

const char	*progname;
const char	*daemon_name = "mount_jives";

void
ctlcmd_stop(int ac, __unusedx char *av[])
{
	if (ac > 1)
		errx(1, "stop: invalid arguments");
	psc_ctlmsg_push(CMT_STOP, 0);
}

struct psc_ctlshow_ent psc_ctlshow_tab[] = {
	PSC_CTLSHOW_DEFS
};

struct psc_ctlmsg_prfmt psc_ctlmsg_prfmts[] = {
	PSC_CTLMSG_PRFMT_DEFS
};

psc_ctl_prthr_t psc_ctl_prthrs[] = {
};

struct psc_ctlcmd_req psc_ctlcmd_reqs[] = {
	{ "stop",	ctlcmd_stop }
};

PFLCTL_CLI_DEFS;

__dead void
usage(void)
{
	fprintf(stderr,
	    "usage: %s [-HIn] [-p paramspec] [-S socket] [-s value] [cmd arg ...]\n",
	    progname);
	exit(1);
}

struct psc_ctlopt opts[] = {
	{ 'H', PCOF_FLAG, &psc_ctl_noheader },
	{ 'I', PCOF_FLAG, &psc_ctl_inhuman },
	{ 'n', PCOF_FLAG, &psc_ctl_nodns },
	{ 'p', PCOF_FUNC, psc_ctlparse_param },
	{ 's', PCOF_FUNC, psc_ctlparse_show },
};

int
main(int argc, char *argv[])
{
	pfl_init();
	progname = argv[0];
	psc_ctlcli_main(PATH_CTLSOCK, argc, argv, opts, nitems(opts));
	exit(0);
}
