#include <iostream>

#include <Memory/Internal/Internal.h>

int main(void)
{
	float test = 1337.f;

	Etanol::Internal::Init();
	Etanol::Internal& rInternal = Etanol::Internal::GetInstance();

	printf("Base Address: 0x%X\n", rInternal.GetBase());

	ADDY test_addy = (ADDY)&test;
	printf("0x%X : %f\n", test_addy, rInternal.Read<float>((ADDY)&test));

	Etanol::Internal::Deinit();

	return 0;
}