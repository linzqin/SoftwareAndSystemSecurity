char code[]=

"\x31\xC0\xB8\x6F\x86\x67\x77\xFF\xD0";

int main(int argc, char **argv)
 {
int (*func)();
func = (int (*)()) code;
(int)(*func)();
}