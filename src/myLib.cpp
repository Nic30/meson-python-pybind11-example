#include <mesonPythonPybind11Example/myLib.h>

int is_even(int num) {
	if (num % 2)
		return false;
	else
		return true;
}
