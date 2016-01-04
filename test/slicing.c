_Bool nondet_bool();
_Bool x, y;
int z;

int main() {
	z = 0;
	while (nondet_bool()) {
		x = nondet_bool();
		z = z + 1 + x;
	}
	if (x)
	{
		__CPROVER_assert(z != 5, "");
	}
	else
		__CPROVER_assert(x, "");
	return 0;
}

