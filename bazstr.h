/*Сайт "Заводила" © Сафаров Олег Айратович 2014 г. инн 027304982940*/
/*BlackBase © Сафаров Олег Айратович 2001 г. инн 027304982940*/
#pragma once
#ifndef	_pragma_once_579072
#define	_pragma_once_579072


enum Radix {
    BINARY = 2,
    OCTOPLE = 8,
    DECIMAL100 = 10,
    HEXADEMICAL = 16
};


namespace NSMY {
namespace NSStr {

template<class Int, class Str>
void
//APIENTRY
itos(Int val, Str buf, unsigned int size, Radix r=DECIMAL100) throw()
{
    Str offset = buf;   // a pointer to a string
    Str first = offset; // a pointer to
                        // the first digit
    unsigned int delta_y;        // the value of a digit
    unsigned int count = 0;     // a number of digits
                        // in the string

    if (val == 0) {
        *offset++ = '0';
	 }
    // val is negative, so let's add '-' to
    // the begin of the string.
    if (val < 0) {
        *offset++ = '-';
        val = val*(-1);
        first = offset;
    }

    // Take special actions for hexademical and
    // octople countable systems and insert to the
    // begin of the string either the "\0x" or '0'
    // prefixes respectively.
    if (r == HEXADEMICAL) {
        *offset++ = '0';
        *offset++ = 'x';
        first = offset;
    }
    else if (r == OCTOPLE) {
        *offset++ = '0';
        first = offset;
    }

    // Read and store digits into the string.
    while (val > 0 && size-- >= 0) {
        delta_y = (Int)(val % r);
        val /= r;

        if (delta_y > 9)
            // The hexademical format.
       *offset++ = (delta_y - 10 + 'a');
        else
            // Binary, dicimal and octople formats.
            *offset++ = (delta_y + '0');
        count++;
    }

    // Points to the last digit.
    *offset-- = '\0';

    // Now our string corresponds to the integer
    // digits but it is in the reverse order. So make
    // the backward transformation of it. If it has
    // only two characters just swap them without any
    // additional actions.
    if (count == 1)
        return;
    else if (count == 2) {
        char temp = (char)*offset;
        *offset-- = *first;
        *first++ = temp;      
    }
    // For more than two characters in the string
    // reverse full string in the folowing cycle.
    else {
        delta_y = count / 2;

        while (delta_y--) {
            char temp = (char)*first;
            *first++ = *offset;
            *offset-- = temp;
        }
    }
}

class    		EXPORT_OR_IMPPORT		bazchar {
public:
	char note;
	bazchar() {};
	bazchar(char par) {			note=class_to_char::wtobaz(par);		};
	operator char()		{			return class_to_char::baztow(note);	};
};

#if TEST_V
	OK_EXTERN bool findendstr(anyp par, USI size);
#endif



OK_EXTERN bool test_right_wchar(char ch);
OK_EXTERN bool test_right_wstr(char * ch);
OK_EXTERN USI stringcopy(bazchar * ku, char * ot);
OK_EXTERN USI stringcopy(char * ku, bazchar * ot);
OK_EXTERN USI stringcopy(char * ku, char * ot);
OK_EXTERN USI stringcopy(bazchar * ku, bazchar * ot);
OK_EXTERN void stringcopy(bazchar * ku, char * ot, USI strsize);
OK_EXTERN void stringcopy(char * ku, bazchar * ot, USI strsize);
OK_EXTERN void stringcopy(char * ku, char * ot, USI strsize);
OK_EXTERN void stringcopy(bazchar * ku, bazchar * ot, USI strsize);

OK_EXTERN USI ppstringcopy(anyp ku, char * ot);
OK_EXTERN USI ppstringcopy(char * ku, anyp ot);

OK_EXTERN bool test_null_bazstr(bazchar * bch);
OK_EXTERN bool test_false_bazstr(bazchar * bch);

class   		EXPORT_OR_IMPPORT		bazstr  
{
public:


	static bool w_lr (char * ch1, char * ch2);

	static bool w_r (char * ch1, char * ch2);
	static bool w_nr (char * ch1, char * ch2);
	static bool w_bor (char * ch1, char * ch2);
	static bool w_mer (char * ch1, char * ch2);
	static bool w_me (char * ch1, char * ch2);
	static bool w_bo (char * ch1, char * ch2);



	static bool baz_lr (bazchar * ch1, bazchar * ch2);
	static bool baz_r (bazchar * ch1, bazchar * ch2);
	static bool baz_nr (bazchar * ch1, bazchar * ch2);
	static bool baz_bor (bazchar * ch1, bazchar * ch2);
	static bool baz_mer (bazchar * ch1, bazchar * ch2);
	static bool baz_me (bazchar * ch1, bazchar * ch2);
	static bool baz_bo (bazchar * ch1, bazchar * ch2);

};
//OK_EXTERN	char * itostr(		int	note, char * buf, int bufsize=255,  Radix r=DECIMAL100)		;
OK_EXTERN	char * itostrd(		double	note, char * buf, int bufsize=255,  Radix r=DECIMAL100)		;

OK_EXTERN	char * itostr(		double	note, char * buf, int bufsize=255,  Radix r=DECIMAL100)		;
OK_EXTERN	char * itostr(		float	note, char * buf, int bufsize=255,  Radix r=DECIMAL100)		;
OK_EXTERN	char * itostr(		S1	note, char * buf, int bufsize=255,  Radix r=DECIMAL100)		;
OK_EXTERN	char * itostr(		S2	note, char * buf, int bufsize=255,  Radix r=DECIMAL100)		;
OK_EXTERN	char * itostr(		S4	note, char * buf, int bufsize=255,  Radix r=DECIMAL100)		;
OK_EXTERN	char * itostr(		S8	note, char * buf, int bufsize=255,  Radix r=DECIMAL100)		;
OK_EXTERN	char * itostr(		U1	note, char * buf, int bufsize=255,  Radix r=DECIMAL100)		;
OK_EXTERN	char * itostr(		U2	note, char * buf, int bufsize=255,  Radix r=DECIMAL100)		;
#ifdef	UNIX_OPERACION_SYSTEM							 //	UNIX_OPERACION_SYSTEM	NOT_UNIX_OPERACION_SYSTEM	
OK_EXTERN	char * itostr(		U4	note, char * buf, int bufsize=255,  Radix r=DECIMAL100)		;
#endif
OK_EXTERN	char * itostr(		U8	note, char * buf, int bufsize=255,  Radix r=DECIMAL100)		;
OK_EXTERN	char * itostr(		NSMY::NSType::voidtype	note, char * buf, int bufsize=255,  Radix r=DECIMAL100)		;

OK_EXTERN 	S1	strtoi1	(char * str, char ** errorstr);
OK_EXTERN 	S2	strtoi2	(char * str, char ** errorstr);
OK_EXTERN 	S4	strtoi4	(char * str, char ** errorstr);
OK_EXTERN 	S8	strtoi8	(char * str, char ** errorstr);
OK_EXTERN	U1	strtou1	(char * str, char ** errorstr)			;
OK_EXTERN	U2	strtou2	(char * str, char ** errorstr)			;
OK_EXTERN	U4	strtou4	(char * str, char ** errorstr)			;
OK_EXTERN	U8	strtou8	(char * str, char ** errorstr)			;
OK_EXTERN 	F4	strtof4	(char * str, char ** errorstr);
OK_EXTERN 	F8	strtof8	(char * str, char ** errorstr);

OK_EXTERN 	void	StringToNumber(	S1	&ret, char * str, char ** errorstr = NULL);
OK_EXTERN 	void	StringToNumber(	S2	&ret, char * str, char ** errorstr = NULL);
OK_EXTERN 	void	StringToNumber(	S4	&ret, char * str, char ** errorstr = NULL);
OK_EXTERN 	void	StringToNumber(	S8	&ret, char * str, char ** errorstr = NULL);
OK_EXTERN 	void	StringToNumber(	U1	&ret, char * str, char ** errorstr = NULL);
OK_EXTERN 	void	StringToNumber(	U2	&ret, char * str, char ** errorstr = NULL);
OK_EXTERN 	void	StringToNumber(	U4	&ret, char * str, char ** errorstr = NULL);
OK_EXTERN 	void	StringToNumber(	U8	&ret, char * str, char ** errorstr = NULL);
OK_EXTERN 	void	StringToNumber(	F4	&ret, char * str, char ** errorstr = NULL);
OK_EXTERN 	void	StringToNumber(	F8	&ret, char * str, char ** errorstr = NULL);
}//namespace NSMY {
}//namespace NSStr {
using namespace NSMY::NSStr;

#endif //pragma once



