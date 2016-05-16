
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <libgen.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <pthread.h>
#include <sysexits.h>
#include <ctype.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/param.h>

#include <xhyve/support/misc.h>
#include <xhyve/support/atomic.h>
#include <xhyve/support/segments.h>
#include <xhyve/support/cpuset.h>
#include <xhyve/vmm/vmm_api.h>

#include <xhyve/libxhyve.h>
#include <xhyve/acpi.h>
#include <xhyve/inout.h>
#include <xhyve/dbgport.h>
#include <xhyve/ioapic.h>
#include <xhyve/mem.h>
#include <xhyve/mevent.h>
#include <xhyve/mptbl.h>
#include <xhyve/pci_emul.h>
#include <xhyve/pci_irq.h>
#include <xhyve/pci_lpc.h>
#include <xhyve/smbiostbl.h>
#include <xhyve/xmsr.h>
#include <xhyve/rtc.h>

#include <xhyve/firmware/kexec.h>
#include <xhyve/firmware/fbsd.h>

void *
paddr_guest2host(uintptr_t gaddr, size_t len)
{
	return (xh_vm_map_gpa(gaddr, len));
}


