<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: ListBox - Win32 (WCE emulator) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x409 /fo"emulatorDbg/ListBox.res" /d UNDER_CE=500 /d _WIN32_WCE=500 /d "UNICODE" /d "_UNICODE" /d "DEBUG" /d "WCE_PLATFORM_STANDARDSDK_500" /d "_X86_" /d "x86" /d "_i386_" /d "_AFXDLL" /r "E:\归档（按日期）\20091104\MyListBox\ListBox.rc"" 
Creating temporary file "C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP117.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=500 /D _WIN32_WCE=500 /D "WCE_PLATFORM_STANDARDSDK_500" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"emulatorDbg/" /Fp"emulatorDbg/ListBox.pch" /Yu"stdafx.h" /Fo"emulatorDbg/" /Fd"emulatorDbg/" /Gs8192 /GF /c 
"E:\归档（按日期）\20091104\MyListBox\ListBox.cpp"
"E:\归档（按日期）\20091104\MyListBox\ListBoxDlg.cpp"
"E:\归档（按日期）\20091104\MyListBox\MyListBox.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP117.tmp" 
Creating temporary file "C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP118.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "_i386_" /D UNDER_CE=500 /D _WIN32_WCE=500 /D "WCE_PLATFORM_STANDARDSDK_500" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "_WIN32_WCE_CEPC" /D "_AFXDLL" /FR"emulatorDbg/" /Fp"emulatorDbg/ListBox.pch" /Yc"stdafx.h" /Fo"emulatorDbg/" /Fd"emulatorDbg/" /Gs8192 /GF /c 
"E:\归档（按日期）\20091104\MyListBox\StdAfx.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP118.tmp" 
Creating temporary file "C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP119.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:yes /pdb:"emulatorDbg/ListBox.pdb" /debug /out:"emulatorDbg/ListBox.exe" /subsystem:windowsce,5.00 /MACHINE:IX86 
".\emulatorDbg\ListBox.obj"
".\emulatorDbg\ListBoxDlg.obj"
".\emulatorDbg\MyListBox.obj"
".\emulatorDbg\StdAfx.obj"
".\emulatorDbg\ListBox.res"
]
Creating command line "link.exe @C:\DOCUME~1\ADMINI~1\LOCALS~1\Temp\RSP119.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
ListBox.cpp
ListBoxDlg.cpp
MyListBox.cpp
Generating Code...
Linking...
corelibc.lib(wwinmain.obj) : warning LNK4209: debugging information corrupt; recompile module; linking object as if no debug info
corelibc.lib(onexit.obj) : warning LNK4209: debugging information corrupt; recompile module; linking object as if no debug info
corelibc.lib(crt0dat.obj) : warning LNK4209: debugging information corrupt; recompile module; linking object as if no debug info
corelibc.lib(crt0init.obj) : warning LNK4209: debugging information corrupt; recompile module; linking object as if no debug info
Creating command line "bscmake.exe /nologo /o"emulatorDbg/ListBox.bsc"  ".\emulatorDbg\StdAfx.sbr" ".\emulatorDbg\ListBox.sbr" ".\emulatorDbg\ListBoxDlg.sbr" ".\emulatorDbg\MyListBox.sbr""
Creating browse info file...
<h3>Output Window</h3>




<h3>Results</h3>
ListBox.exe - 0 error(s), 4 warning(s)
</pre>
</body>
</html>
