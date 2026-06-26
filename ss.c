#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

//gcc ss.c -o ss.exe

const char *answers1[] = {
	"Sha pasru, podoshdi",
	"5 sekundochek, 4 nanominutochek",
	"Nihuya sebe, zagruska \"ZOV OS\" dlya obrabotki takoy imby",
	"V tvoih myslyah posmotry otvet",
	"Chto za huinya? Lan otvechy",
	"Blya, eto roza sredi navoza, shdi",
	"Preobrazuyu eto v chitabelny tekst",
	"Oi, eto eshe Shirinovskiy predskazival",
	"Hm, kak budto huinya ne idi naxui"
};

const char *answers2[] = {
	"Ya posral, tak vot",
	"Ya zdes, gotov nasrat v chemodan",
	"ZOV OS: ",
	"Otvet: furry porn... oi blyat, ne to... vo, vot eto!",
	"Blya, ril zalupa, dershi takuyu huinu ne sprashivai bolshe",
	"Eto imba, osobenno mesto, gde ti skazal, shto ty priemny",
	"Vo, adekvatni tekst nahu, otvechay:",
	"Kak skazal Shirinovskiy, ti dau... oy, ne eto, vot:",
	"Poshel v shopu"
};

const char *answers3[] = {
	"Interesno,ya polagayu, chto eto svyazano s kul\'turoj i istoriej.",
	"Analiz pokazyvaet, chto eto mozhet imet\' tebya i glubokij smysl.",
	"Dumayu, chto eto vopros, trebuyushchij bolee tshchatel\'nogo issledovaniya.",
	"Vozmozhno, eto otrazhaet vash vnutrennij mir.",
	"Eto napominaet mne o teorii strun, znaete li.",
	"Dejstvitel\'no mudro, pryamo kak v 1984",
	"Soglasen, v kazhdom voprose skryt otvet.",
	"Nu, kak by skazat\'... ochen\' glubokaya mysl\'.",
	"Eto mne napomnilo razmyshleniya Sokrata"
};

unsigned int seed = 0;
char buffer[512];

void print_with_delay(const char *text);

int main(void){
	srand(time(NULL));
	system("cls");
	print_with_delay("=== So Smart 1.0 ===\n");
	print_with_delay("Hello! ");
	while(1){
		while (_kbhit()){
			char ch = _getch();
		}
		print_with_delay("How can i help you? (q - quit): ");
		
		if (fgets(buffer, sizeof(buffer), stdin) != NULL){
			buffer[511] = '\0';
			if (strncmp(buffer, "quit", 4) == 0){
				print_with_delay("Net idi nahui\n");
				continue;
			}
			if (strncmp(buffer, "q", 1) == 0){
				print_with_delay("Bye!");
				break;
			}
			
			seed = (rand() % (9 - 1 + 1)) + 1;
			
			print_with_delay(answers1[seed - 1]);
			print_with_delay("\n...\n");
			Sleep(2000);
			print_with_delay(answers2[seed - 1]);
			putchar('\n');
			
			if (seed != 9){
			
				seed = (rand() % (9 - 1 + 1)) + 1;
			
				print_with_delay(answers3[seed - 1]);
				putchar('\n');
				
			}
			seed = 0;
			memset(buffer, 0, 512);
		}
	}
	
	return 0;
}

void print_with_delay(const char *text){
	for (int i = 0; i < strlen(text); i++){
		putchar(text[i]);
		Sleep(50);
	}
}