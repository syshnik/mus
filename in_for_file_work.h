#pragma once
/*
#ifdef WIN_OPERACION_SYSTEM
#include <fstream>
#include <cstring>
#endif

#ifdef UNIX_OPERACION_SYSTEM
#include <stdio.h>
#include <stdlib.h>
#endif
#include "../cod_mus/in_for_file_work.h"

*/
#ifdef WIN_OPERACION_SYSTEM
#include <io.h>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>
#include <fstream>
#include <cstring>
#include <fcntl.h>
#endif

#ifdef UNIX_OPERACION_SYSTEM
//	#include <io.h>
//#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#endif

#ifndef O_BINARY
#define O_BINARY 0
#endif

using namespace std;
