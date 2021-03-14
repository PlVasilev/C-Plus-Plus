int main_pitfall() {
	int* numbers = new int[3]{ 1, 2, 3 };
	int* otherPtr = numbers;

	delete[] numbers;
	delete[] otherPtr; // undefined behavior

	return 0;
}
