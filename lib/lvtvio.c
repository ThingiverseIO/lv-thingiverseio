#include "thingiverseio.h"
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
	#define EXPORT __declspec(dllexport)
	#pragma comment(lib, "user32.lib")	// required when linking to labview
	#pragma warning(disable: 4996)
	// critical section/mutex check
#else
	#define EXPORT
#endif
#ifdef WIN32
    #undef WIN32
    #undef _WIN32
    #undef __WIN32__
    #undef _WIN32_WCE
    #define linux 1
#endif
#include "extcode.h"
#ifdef __WIN32__
    #undef linux
    #define WIN32 1
    #define _WIN32 1
    #define __WIN32__ 1
#endif
#ifndef _extcode_H
typedef char** UHandle;
#endif

typedef unsigned long u32;

extern int lvtvio_version(int* major, int* minor, int* fix) {
	return tvio_version(major, minor, fix);
}

extern void lvtvio_check_descriptor(char* descriptor, UHandle result) {
	char* p;
	int p_size;
	tvio_check_descriptor(descriptor, &p, &p_size);
	DSSetHandleSize(result, p_size+4 );
	*( u32* )*result = p_size;
	memcpy( *result+4, p, p_size);
}

extern int lvtvio_new_input(char* descriptor) {
	return tvio_new_input(descriptor);
}

extern int lvtvio_get_input_uuid(int input, UHandle uuid) {
	char* p;
	int p_size;
	int res = tvio_get_input_uuid(input, &p, &p_size);
	if (res == 0) {
		DSSetHandleSize(uuid, p_size+4 );
		*( u32* )*uuid = p_size;
		memcpy( *uuid+4, p, p_size);
	}
	return res;
}

extern int lvtvio_remove_input(int input) {
	return tvio_remove_input(input);
}

extern int lvtvio_connected(int input, int* is) {
	return tvio_connected(input, is);
}

extern int lvtvio_start_listen(int input, char* function) {
	return tvio_start_listen(input, function);
}

extern int lvtvio_stop_listen(int input, char* function) {
	return tvio_stop_listen(input, function);
}

extern int lvtvio_call(int input, char* function, void* params, int params_size, UHandle id){

	char* idp;
	int idp_size;

	int ret = tvio_call(input,function,params, params_size, &idp, &idp_size);

	if (ret == 0) {
		DSSetHandleSize( id, idp_size+4 );
		*( u32* )*id = idp_size;
		memcpy( *id+4, idp, idp_size);
	}
	free(idp);
	return ret;
}

extern int lvtvio_call_all(int input, char* function, void* params, int params_size, UHandle id){
	char* idp;
	int idp_size;

	int ret = tvio_call_all(input,function,params, params_size, &idp, &idp_size);

	if (ret == 0) {
		DSSetHandleSize( id, idp_size+4 );
		*( u32* )*id = idp_size;
		memcpy( *id+4, idp, idp_size);
	}
	free(idp);
	return ret;

}

extern int lvtvio_trigger(int input, char* function, void* params, int params_size){
	return tvio_trigger(input, function, params, params_size);
}

extern int lvtvio_trigger_all(int input, char* function, void* params, int params_size){
	return tvio_trigger_all(input, function, params, params_size);
}

extern int lvtvio_result_ready(int input, char* id, int* ready) {
	return tvio_result_ready(input, id, ready);
}

extern int lvtvio_retrieve_result_params(int input, char* id, UHandle params){
	void* p;
	int p_size;

	int ret = tvio_retrieve_result_params(input, id, &p, &p_size);

	if (ret == 0) {
		DSSetHandleSize(params, p_size+4 );
		*( u32* )*params = p_size;
		memcpy( *params+4, p, p_size);
	}
	free(p);
	return ret;
}

extern int lvtvio_listen_result_available(int input, int* is){
	return tvio_listen_result_available(input, is);
}

extern int lvtvio_retrieve_listen_result_id(int input, UHandle id){
	char* idp;
	int idp_size;

	int ret = tvio_retrieve_listen_result_id(input, &idp, &idp_size);

	if (ret == 0) {
		DSSetHandleSize( id, idp_size+4 );
		*( u32* )*id = idp_size;
		memcpy( *id+4, idp, idp_size);
	}
	free(idp);
	return ret;
}

extern int lvtvio_retrieve_listen_result_function(int input, UHandle function){
	char* fp;
	int fp_size;

	int ret = tvio_retrieve_listen_result_function(input, &fp, &fp_size);

	if (ret == 0) {
		DSSetHandleSize(function, fp_size+4 );
		*( u32* )*function = fp_size;
		memcpy( *function+4, fp, fp_size);
	}
	free(fp);
	return ret;

}

extern int lvtvio_retrieve_listen_result_params(int input, UHandle params) {
	void* p;
	int p_size;

	int ret = tvio_retrieve_listen_result_params(input, &p, &p_size);

	if (ret == 0) {
		DSSetHandleSize(params, p_size+4 );
		*( u32* )*params = p_size;
		memcpy( *params+4, p, p_size);
	}
	free(p);
	return ret;

}

extern int lvtvio_retrieve_next_call_all_result_params(int input, char* id, UHandle params) {
	void* p;
	int p_size;

	int ret = tvio_retrieve_next_call_all_result_params(input, id, &p, &p_size);

	if (ret == 0) {
		DSSetHandleSize(params, p_size+4 );
		*( u32* )*params = p_size;
		memcpy( *params+4, p, p_size);
	}
	free(p);
	return ret;
}

extern int lvtvio_new_output(char* descriptor) {
	return tvio_new_output(descriptor);
}

extern int lvtvio_remove_output(int output) {
	return tvio_remove_output(output);
}

extern int lvtvio_get_output_uuid(int output, UHandle uuid) {
	char* p;
	int p_size;
	int res = tvio_get_output_uuid(output, &p, &p_size);
	if (res == 0) {
		DSSetHandleSize(uuid, p_size+4 );
		*( u32* )*uuid = p_size;
		memcpy( *uuid+4, p, p_size);
	}
	return res;
}

extern int lvtvio_request_available(int output, int* is) {
	return tvio_request_available(output, is);
}

extern int lvtvio_get_next_request_id(int output, UHandle id) {
	char* idp;
	int idp_size;

	int ret = tvio_get_next_request_id(output, &idp, &idp_size);

	if (ret == 0) {
		DSSetHandleSize( id, idp_size+4 );
		*( u32* )*id = idp_size;
		memcpy( *id+4, idp, idp_size);
	}
	free(idp);
	return ret;
}

extern int lvtvio_retrieve_request_function(int output, char* id, UHandle function) {
	char* fp;
	int fp_size;

	int ret = tvio_retrieve_request_function(output, id, &fp, &fp_size);

	if (ret == 0) {
		DSSetHandleSize(function, fp_size+4 );
		*( u32* )*function = fp_size;
		memcpy( *function+4, fp, fp_size);
	}
	free(fp);
	return ret;
}

extern int lvtvio_retrieve_request_params(int output, char* id, UHandle params) {
	void* p;
	int p_size;

	int ret = tvio_retrieve_request_params(output, id, &p, &p_size);

	if (ret == 0) {
		DSSetHandleSize(params, p_size+4 );
		*( u32* )*params = p_size;
		memcpy( *params+4, p, p_size);
	}
	free(p);
	return ret;

}

extern int lvtvio_reply(int output, char* id, void* params, int params_size) {
	return tvio_reply(output, id, params, params_size);
};

extern int lvtvio_emit(int output, char* function, void* in_params, int in_params_size, void* params, int params_size) {
	return tvio_emit(output, function, in_params, in_params_size, params, params_size);
}


