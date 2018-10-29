T=doorsys
O=$T.obj
VSCG_DIR=$(VS_DIR)\cg
CFLAGS=-c -ML -O2 -G5 -Zi -Gs -I$(VSCG_DIR)\include
LDEB=
it:	$T.exe

$T.exe:  $O 
        link $(LDEB) $O $(VSCG_DIR)\lib\cg32.lib

$O: $(VSCG_DIR)\include\cg.h $(VSCG_DIR)\include\cgen.h
