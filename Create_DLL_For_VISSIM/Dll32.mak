
T=doorsys
O=$T.obj

CGDIR=$(VS_DIR)\cg
CGINC=$(CGDIR)\include
CGLIB=$(CGDIR)\lib
VSDK=$(VS_DIR)\vsdk
CFLAGS=-c -nologo -Zi -O2 -G5 -Gs -I$(CGINC) -I$(VSDK)
LDEB=
LFLAGS=-nologo -dll $(LDEB)
LIBS=$(VSDK)\lib\vissim32.lib user32.lib kernel32.lib
USERLIBS=

it:     $T.dll

$T.dll:  $O 
        link $(LFLAGS) $O $(CGLIB)\cgdll32.lib $(LIBS) $(USERLIBS)

$O: $(CGINC)\cg.h $(CGINC)\cgen.h
