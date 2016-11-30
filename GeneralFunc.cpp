#define DEBUG_PRINT(var) debug_print(#var, var)

template <typename T>
void debug_print(const char* name, T value){
	std::cout << name << ": "<< value;
}

// in case DEBUG_PRINT("aaa");
void debug_print(const char* name, const char* value){
	std::cout << value << std::endl;
}