#include "init_jobj.h"
#include <stdio.h>

static void print_error(const char* key)
{
	printf("Error \\\"%s\\\"\n", key);
}

void init_jobj()
{
//Собираем root объект=================================================================
	//Создаём объеденение и инициализирум нужный тип значения
	Var_value_t var_value = { 0 };
	var_value.number = 777;
	//Инициализируем структуру которая описывает значение  
	//1:Тип значения, 2:Ключ, 3:Значение
	Value_t value = { NUMBER, "value one", var_value};
	//Создаём комплексный объект со значением
	//1:Тип комплексного обьекта, 2: значения для помещения в объект
	//(Может быть пустым если тип meaning J_NULL)
	Cmx_obj_t* root_obj = make_cmxobj(OBJ, value);
	//Создаём значения 
	
	//Инициализируем значение
	var_value.float_number = 24.33;
	value = (Value_t){ REAL_NUMBER, "value two", var_value };
	if (add_value(root_obj, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.boolean = true;
	value = (Value_t){ BOOLEAN, "value three", var_value };
	if (add_value(root_obj, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "Value string";
	value = (Value_t){ STRING, "value four", var_value };
	if (add_value(root_obj, value))				//Добавляем значение в объект
		print_error(value.key);

//Собираем массив=============================================================================
	//Создаём массив с первым элементом
	var_value.string = "element array one";
	value = (Value_t){ STRING, NULL, var_value };		//Ключ значения не нужен потому что это массив
	Cmx_obj_t* arr = make_cmxobj(ARR, value);

	var_value.string = "element array two";
	value = (Value_t){ STRING, NULL, var_value };
	if (add_value(arr, value))				//Добавляем значение в объект
		print_error("Element array");

	var_value.string = "element array three";
	value = (Value_t){ STRING, NULL, var_value };
	if (add_value(arr, value))				//Добавляем значение в объект
		print_error("Element array");

	var_value.string = "element array four";
	value = (Value_t){ STRING, NULL, var_value };
	if (add_value(arr, value))				//Добавляем значение в объект
		print_error("Element array");

	var_value.string = "element array fife";
	value = (Value_t){ STRING, NULL, var_value };
	if (add_value(arr, value))				//Добавляем значение в объект
		print_error("Element array");

//Дальше собираем root обект=====================================================
	//Добавляем созданный массив в объект
	var_value.cmx_obj = *arr;
	value = (Value_t){ CMX_OBJ, "Array one", var_value };
	if (add_value(root_obj, value))				//Добавляем значение в объект
		print_error(value.key);

//Собираем новый объект===============================================================
	//Создаём новый объект
	var_value.number = 333;
	value = (Value_t){ NUMBER, "New obj value one", var_value };
	Cmx_obj_t* new_obj = make_cmxobj(OBJ, value);

	//Инициализируем значение
	var_value.float_number = 44.63;
	value = (Value_t){ REAL_NUMBER, "New obj value two", var_value };
	if (add_value(new_obj, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.boolean = false;
	value = (Value_t){ BOOLEAN, "New obj value three", var_value };
	if (add_value(new_obj, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "Hello!";
	value = (Value_t){ STRING, "New obj value four", var_value };
	if (add_value(new_obj, value))				//Добавляем значение в объект
		print_error(value.key);

//Дальше собираем root обект=====================================================
	//Добавляем созданный объект в root объект
	var_value.cmx_obj = *new_obj;
	value = (Value_t){ CMX_OBJ, "New obj", var_value };
	if (add_value(root_obj, value))				//Добавляем значение в объект
		print_error(value.key);

	//Добавляем значение null
	var_value.null = 0;
	value = (Value_t){ J_NULL, "Empty value", var_value };
	if (add_value(root_obj, value))				//Добавляем значение в объект
		print_error(value.key);


//Создаём массив обектов=====================================================================
//Первый объект
	var_value.string = "88";
	value = (Value_t){ STRING, "id", var_value };
	Cmx_obj_t* test_obj1 = make_cmxobj(OBJ, value);

	var_value.string = "test 88";
	value = (Value_t){ STRING, "pagetitle", var_value };
	if (add_value(test_obj1, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "";
	value = (Value_t){ STRING, "longtitle", var_value };
	if (add_value(test_obj1, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "описание";
	value = (Value_t){ STRING, "description", var_value };
	if (add_value(test_obj1, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "test/id88";
	value = (Value_t){ STRING, "alias", var_value };
	if (add_value(test_obj1, value))				//Добавляем значение в объект
		print_error(value.key);

//Объект 2========================================================================
	var_value.string = "99";
	value = (Value_t){ STRING, "id", var_value };
	Cmx_obj_t* test_obj2 = make_cmxobj(OBJ, value);

	var_value.string = "test 88";
	value = (Value_t){ STRING, "pagetitle", var_value };
	if (add_value(test_obj2, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "";
	value = (Value_t){ STRING, "longtitle", var_value };
	if (add_value(test_obj2, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "описание";
	value = (Value_t){ STRING, "description", var_value };
	if (add_value(test_obj2, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "test/id99";
	value = (Value_t){ STRING, "alias", var_value };
	if (add_value(test_obj2, value))				//Добавляем значение в объект
		print_error(value.key);

//Объект 3========================================================================

	var_value.string = "150";
	value = (Value_t){ STRING, "id", var_value };
	Cmx_obj_t* test_obj3 = make_cmxobj(OBJ, value);

	var_value.string = "test 88";
	value = (Value_t){ STRING, "pagetitle", var_value };
	if (add_value(test_obj3, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "";
	value = (Value_t){ STRING, "longtitle", var_value };
	if (add_value(test_obj3, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "описание";
	value = (Value_t){ STRING, "description", var_value };
	if (add_value(test_obj3, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "test/id150";
	value = (Value_t){ STRING, "alias", var_value };
	if (add_value(test_obj3, value))				//Добавляем значение в объект
		print_error(value.key);

//Объект 4========================================================================

	var_value.string = "350";
	value = (Value_t){ STRING, "id", var_value };
	Cmx_obj_t* test_obj4 = make_cmxobj(OBJ, value);

	var_value.string = "test 88";
	value = (Value_t){ STRING, "pagetitle", var_value };
	if (add_value(test_obj4, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "";
	value = (Value_t){ STRING, "longtitle", var_value };
	if (add_value(test_obj4, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "описание";
	value = (Value_t){ STRING, "description", var_value };
	if (add_value(test_obj4, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.string = "test/id350";
	value = (Value_t){ STRING, "alias", var_value };
	if (add_value(test_obj4, value))				//Добавляем значение в объект
		print_error(value.key);

//Создание массива и добавления объектов в него========================================================================
	var_value.cmx_obj = *test_obj1;
	value = (Value_t){ CMX_OBJ, NULL, var_value };
	Cmx_obj_t* test_arr = make_cmxobj(ARR, value);

	var_value.cmx_obj = *test_obj2;
	value = (Value_t){ CMX_OBJ, NULL, var_value };
	if (add_value(test_arr, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.cmx_obj = *test_obj3;
	value = (Value_t){ CMX_OBJ, NULL, var_value };
	if (add_value(test_arr, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.cmx_obj = *test_obj4;
	value = (Value_t){ CMX_OBJ, NULL, var_value };
	if (add_value(test_arr, value))				//Добавляем значение в объект
		print_error(value.key);

	var_value.cmx_obj = *test_arr;
	value = (Value_t){ CMX_OBJ, "Test array", var_value };
	if (add_value(root_obj, value))				//Добавляем значение в объект
		print_error(value.key);

//Примеры использования библиотеки=========================================================================
	//Рекурсивный поиск в объекте значений по ключу
	Cmx_obj_t* obj = find_values(root_obj, "new obj");

//Задача вывести значение "alias" из массив объектов в объекте которого "id" == "350"
	{
		//Перебераем элементы массива
		for (uint8_t idx = 0; idx < test_arr->valCnt; ++idx)
		{
			//Функция возвращает значения из передонного объекта по ключу
			Value_t* val = find_value(&test_arr->value[idx].var_value.cmx_obj, "id");
			//Если значения "id" == "350"
			if (val->var_value.string == "350")
			{
				//Ищем в этом оBбъекте значение с ключём "alias"
				val = find_value(&test_arr->value[idx].var_value.cmx_obj, "alias");
				//Выводим значение
				printf("\"alias\" field value: %s",val->var_value.string);
			}
		}
	}
	
//Создание сообщения для передачи
	init_msgarr();			//Выделяем память под массив сообщения
	make_msg(root_obj);		//Собираем сообщение

//Извлечение сообщения из массива
	Cmx_obj_t* my_obj = extract_msg(msg_arr);	//Извлекаем сообщение

//Освобождаем память
	free_obj(root_obj);
	free_obj(my_obj);
	free(msg_arr);
}
