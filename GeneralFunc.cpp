#define DEBUG_PRINT(var) debug_print(#var, var)

template <typename T>
void debug_print(const char* name, T value){
	std::cout << name << ": "<< value;
}
