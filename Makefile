all: netbinview

netbinview: src/netbinview.c
	$(CC) -Wall -o $@ $^


TDIR=/usr/local/bin

NTOHS=$(TDIR)/ntohs
NTOHL=$(TDIR)/ntohl
HTONS=$(TDIR)/htons
HTONL=$(TDIR)/htonl
TBIN=/usr/local/bin/netbinview

BINARIES=$(NTOHS) $(NTOHL) $(HTONS) $(HTONL) $(TBIN)

uninstall:
	rm -f $(BINARIES)

install: uninstall netbinview
	cp netbinview $(TDIR)
	ln -s $(TBIN) $(NTOHL)
	ln -s $(TBIN) $(NTOHS)
	ln -s $(TBIN) $(HTONL)
	ln -s $(TBIN) $(HTONS)
