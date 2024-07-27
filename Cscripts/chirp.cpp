#include <windows.h>

int main() {
	while(1){
	for(int i=0;i<256;i++){
    Beep(1000+i, 5.0/128.0);
	}
}
    return 0;
}
