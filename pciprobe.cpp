//-------------------------------------------------------------------
//	pciprobe.cpp
//
//	This program performs a PCI bus-scan and displays the vendor
//	and device identification for each device-function detected.
//
//		compile using:  $ g++ pciprobe.cpp -o pciprobe
//		execute using:  $ sudo ./pciprobe
//
//	NOTE: This program needs to execute privileged instructions.
//
//				------------
//
//	Reference:
//	Shanley and Anderson, "PCI System Architecture (4th Edtion)"
//	MindShare, Inc (Addison-Wesley, 1999).
//
//	programmer: ALLAN CRUSE
//	written on: 28 NOV 2006
//	revised on: 11 DEC 2006 -- to display each PCI Class Code
//	revised on: 15 APR 2009 -- to display each PCI Class Name
//-------------------------------------------------------------------

#include <stdio.h>  // for printf(), perror()
#include <sys/io.h> // for iopl(), in(), out()
#include <unistd.h> // for gethostname()

#define CONFADD 0x0CF8
#define CONFDAT 0x0CFC
#define PMC 0x0CFB

const char *classname[] = {"LEGACY",        // CLASS 0x00
                           "MASS STORAGE",  // CLASS 0x01
                           "NETWORK",       // CLASS 0x02
                           "DISPLAY",       // CLASS 0x03
                           "MULTIMEDIA",    // CLASS 0x04
                           "MEMORY",        // CLASS 0x05
                           "BRIDGE",        // CLASS 0x06
                           "COMMUNICATION", // CLASS 0x07
                           "PERIPHERAL",    // CLASS 0x08
                           "INPUT",         // CLASS 0x09
                           "DOCKING",       // CLASS 0x0A
                           "PROCESSOR",     // CLASS 0x0B
                           "SERIAL-BUS",    // CLASS 0x0C
                           "?"};

const int classmax = sizeof(classname) / sizeof(char *);

int main(int argc, char **argv)
{
  // adjust processor's IOPL-field in the FLAGS register
  if (iopl(3))
  {
    perror("iopl");
    return 1;
  }

  // enable PCI configuration mechanism #1
  outb(inb(PMC) | 1, PMC);

  // obtain hostname for displaying station-ID in printouts
  char hostname[64] = {0};
  gethostname(hostname, 63);

  // perform a pci bus scan operation
  printf("\nSCANNING FOR PCI DEVICES on station \'%s\'\n\n", hostname);
  int ndevs = 0;
  for (int bus = 0; bus < (1 << 8); bus++)
  {
    for (int dev = 0; dev < (1 << 5); dev++)
    {
      int busdev = (bus << 16) | (dev << 11) | (1 << 31);
      int pcidat, header, vendor, device, classc;

      outl(busdev, CONFADD);
      pcidat = inl(CONFDAT);
      if (pcidat == ~0)
        continue;

      outl(busdev + (3 << 2), CONFADD);
      header = (inl(CONFDAT) >> 16) & 0xFF;

      vendor = (pcidat >> 0) & 0xFFFF;
      device = (pcidat >> 16) & 0xFFFF;

      outl(busdev + (2 << 2), CONFADD);
      classc = inl(CONFDAT) >> 8;

      printf("bus=%-3d dev=%-2d ", bus, dev);
      if (header & 0x80)
      {
        printf(" (multi-function device) \n");
        for (int fun = 0; fun < (1 << 3); fun++)
        {
          outl(busdev + (fun << 8), CONFADD);
          pcidat = inl(CONFDAT);
          if (pcidat == ~0)
            continue;
          ++ndevs;

          vendor = (pcidat >> 0) & 0xFFFF;
          device = (pcidat >> 16) & 0xFFFF;

          int busdevfun = busdev + (fun << 8);
          outl(busdevfun + (2 << 2), CONFADD);
          classc = inl(CONFDAT) >> 8;

          printf("\tfunction %d ", fun);

          printf(" VENDOR=%04X ", vendor);
          printf(" DEVICE=%04X ", device);
          printf(" CLASS=%06X", classc);
          int c = (classc >> 16);
          if (c < classmax)
            printf(" %s", classname[c]);
          printf("\n");
        }
      }
      else
      {
        ++ndevs;
        printf(" VENDOR=%04X ", vendor);
        printf(" DEVICE=%04X ", device);
        printf(" CLASS=%06X", classc);
        int c = (classc >> 16);
        if (c < classmax)
          printf(" %s", classname[c]);
        printf("\n");
      }
      printf("\n");
    }
  }
  printf("Identified %d PCI device-functions ", ndevs);
  printf("on station \'%s\' \n\n", hostname);
}
