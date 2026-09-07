#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// #pragma warning(disable : 4996)
#define DONE 0
#define KEY_ERROR 0x31
#define MEMORY_ERROR 0x32
#define j_null NULL

typedef struct Value Value_t;
//Перечесление для получения нужного значения из union
typedef enum Type_JObj
{
	J_NULL = 0,
	NUMBER,
	REAL_NUMBER,
	BOOLEAN,
	STRING,
	CMX_OBJ
} Type_JObj;

//Тип состовного объекта
typedef enum Type_cmxobj
{
	ARR = 0,
	OBJ
} Type_cmxobj;

//Структура которая описывает объект или массив
typedef struct Complex_obj
{
	uint8_t valCnt;
	Type_cmxobj type;
	//const char* key = NULL;
	Value_t* value;

}Cmx_obj_t;

//Объеденение описывающее варианты возможных значений
typedef union Var_value_t
{
	int number;
	float float_number;
	bool boolean;
	const char* string;
	Cmx_obj_t cmx_obj;
	uint8_t null;
} Var_value_t;

//Структура описывающая значение
struct Value
{
	Type_JObj type;			//Тип значения, для получения значения из union
	const char* key;			//Ключ для поиска и получения значения
	Var_value_t var_value;	//объеденение разных значений
};

Cmx_obj_t* make_cmxobj(Type_cmxobj type, Value_t meaning);
uint8_t add_value(Cmx_obj_t* cmx_obj, Value_t meaning);
Cmx_obj_t* find_values(Cmx_obj_t* source_obj, const char* key);
Value_t* find_value(Cmx_obj_t* cmx_obj, const char* key);
void make_msg(Cmx_obj_t* cmx_obj);
Cmx_obj_t* extract_msg(uint8_t* msg);
bool init_msgarr();
void free_obj(Cmx_obj_t* cmx_obj);

extern uint8_t* msg_arr;

