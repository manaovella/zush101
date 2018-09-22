#include "../define.h"
#include "../vcamixer.h"

int main()
{
	streamdata_t val;
	streamdata_t out;

	for (int i = 0; i < 16; i++)
	{
		val.write(i);
	}

	vcamixer(&val, &out);
	data_t value = out.read();
	printf("%d\r\n", (unsigned int)value);

	return 0;
}
