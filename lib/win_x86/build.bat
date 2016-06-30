cmd /c mklink /d lvlib "C:\Program Files\National Instruments\LabVIEW 2015\cintools"
del /F /Q liblvtvio*
gcc -c ../lvtvio.c -o lvtvio.o -lpthread -lzmq -lws2_32 -lntdll -L. -lthingiverseio -I../include -Ilvlib -Llvlib -llabviewv
gcc  -v -shared -o liblvtvio.dll lvtvio.o -lpthread -lzmq -lws2_32 -lntdll -I../include -Ilvlib -L. -lthingiverseio -Llvlib -llabviewv
del /F lvtvio.o
