/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#ifdef macroasmCCCCCCCCCCCCCCCCC
#else
#define macroasmCCCCCCCCCCCCCCCCC fffffffff

#define init_edi_esi(X1,X2) __asm mov edi, X1 __asm mov esi, X2

#define noteziro_1		__asm xor ah, ah\
		__asm mov byte ptr [edi], ah\
		__asm inc edi
#define noteziro_2		__asm xor ax, ax\
		__asm mov word ptr [edi], ax\
		__asm add edi, 2
#define noteziro_4		__asm xor eax, eax\
		__asm mov dword ptr [edi], eax\
		__asm add edi, 4
#define noteziro_x(X)			__asm		xor eax,eax\
		__asm mov ecx, X \
		__asm rep stosb
#define notecpy_1	__asm mov ecx,1\
			__asm rep movsb
#define notecpy_2	__asm mov ecx,1\
			__asm rep movsw
#define notecpy_4	__asm mov ecx,1\
			__asm rep movsd
#define notecpy_x(X)	__asm mov ecx, X \
			__asm rep movsb
#define big_notecpy_x(X)	__asm mov ecx, X \
		__asm mov eax,ecx\
		__asm and eax, 3\
		__asm shr ecx, 2\
		__asm rep movsd\
		__asm mov ecx, eax\
		__asm rep movsb




#endif



