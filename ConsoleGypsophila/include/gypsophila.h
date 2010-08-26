#include <stdio.h>
#include <curl/curl.h>
#define BUFFER_MAX_SIZE 1024
#define CACHE_INIT_SIZE 1024 * 32
#define CACHE_DEC_SIZE 1024 * 16

typedef enum _course_type
{
	CUR_COURSE,NEXT_COURSE,PRE_COURSE
}course_type;

typedef struct _cache_memory 
{
	char *mem;
	int offset;
	size_t size;
}cache_memory;

typedef struct _course 
{
	int course_id;
	char *course_name;
	char *course_term;
	course_type type;
	struct _course* next;
}course,*p_course;

extern char tsinghua_prefix[];
extern cache_memory cache;
extern p_course course_head;

// return the passwd pointer
char *getPasswd(const char *prompt, char *passwd, int MAX_LENGTH);


bool init_cache();
bool clean_cache();





void mirror_course_notice(CURL *curl_web_handler, char *prefix, int course_id);
void mirror_course_file(CURL *curl_web_handler, char *prefix, int course_id);
void mirror_course_assignment(CURL *curl_web_handler, char *prefix, int course_id);
void mirror_course_discussion(CURL *curl_web_handler, char *prefix, int course_id);
void mirror_course(CURL *curl_web_handler, char *prefix);
void mirror_course_frome_course_id(CURL *curl_web_handler, int course_id, char *prefix);


/*
Auth the user and Password.
*/
bool login_learn_tsinghua(CURL *curl_web_handler, char * username,char *password);